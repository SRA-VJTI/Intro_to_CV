#!/bin/bash

# Check if OpenCV is installed
echo "Checking if OpenCV is installed..."
if pkg-config --exists opencv4 sdl2; then
    echo "OpenCV is installed"
else
    echo "OpenCV is not installed"
    echo "Installing OpenCV..."

    # Detect OS and install dependencies accordingly
    if grep -qi "debian" /etc/os-release; then
        echo "Detected Debian-based system"
        sudo apt-get update -y
        sudo apt-get install build-essential libopencv-dev libsdl2-2.0-0 libsdl2-image-dev libsdl2-dev -y
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        echo "Detected macOS"
        brew install opencv sdl2
    elif grep -qi "arch" /etc/os-release; then
        echo "Detected Arch Linux"
        sudo pacman -Sy base-devel opencv hdf5 glew vtk fmt sdl2
    else
        echo "Unknown OS, cannot install OpenCV"
        exit 1
    fi
fi
