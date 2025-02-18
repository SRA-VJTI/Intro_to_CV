#!/bin/bash
set -e

# Function to check if a command exists
command_exists() {
    command -v "$1" &>/dev/null
}

# Detect OS
OS=""
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    if grep -qE "debian|ubuntu" /etc/os-release; then
        OS="debian"
    elif grep -q "arch" /etc/os-release; then
        OS="arch"
    fi
elif [[ "$OSTYPE" == "darwin"* ]]; then
    OS="macos"
elif grep -q "WSL" /proc/version &>/dev/null; then
    OS="wsl"
fi

# Check if OpenCV is installed
if pkg-config --exists opencv4 sdl2; then
    echo "OpenCV is already installed."
    exit 0
else
    echo "OpenCV not found. Installing dependencies..."
fi

# Install dependencies based on OS
case "$OS" in
    "debian" | "wsl")
        echo "🔹 Detected Debian/Ubuntu or WSL"
        
        # Install sudo if not available (for containers)
        if ! command_exists sudo; then
            su -c "apt update && apt install sudo -y"
        fi
        
        # Install tzdata non-interactively
        sudo apt install tzdata -y
        export DEBIAN_FRONTEND=noninteractive
        sudo ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime
        echo "Etc/UTC" | sudo tee /etc/timezone > /dev/null
        sudo dpkg-reconfigure --frontend noninteractive tzdata

        # Install pkg-config and OpenCV dependencies
        sudo apt update -y
        sudo apt install -y pkg-config build-essential make g++ git libopencv-dev libsdl2-2.0-0 libsdl2-image-dev libsdl2-dev
        ;;
    "arch")
        echo "🔹 Detected Arch Linux"
         # Install sudo if missing
        if ! command_exists sudo; then
            su -c "pacman -Sy --noconfirm sudo"
        fi

        sudo pacman -Sy --noconfirm base-devel opencv hdf5 glew vtk fmt sdl2 pkg-config
        ;;
    "macos")
        echo "🔹 Detected macOS"
        if ! command_exists brew; then
            echo "Homebrew not found. Installing Homebrew..."
            /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
        fi
        brew install git cmake opencv sdl2
        ;;
    *)
        echo "Unsupported OS"
        exit 1
        ;;
esac

echo "Installation complete!"
