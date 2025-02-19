# PIXELS

`PIXELS` is an introduction to Computer Vision and Image Processing. Similar to a `pixel` which is the fundamental unit of any digital image, the objective is to emphasise the fundamental ideas of image and its algorithm in relation to contemporary technologies, such as the industry standard `OpenCV`. A thorough understanding of the fundamentals can aid in research and system redesign for domain-specific optimisations to meet the hardware needs of edge devices.

Every program is written in `C++` to provide the flexibility required by programmers. It also includes principles of essential development tools such as `Make` and `Git`.

## Demonstration 
<img src="./assets/images/blob_demo_2023.gif" width="800" />

This repository includes basics to :
1. [C++](./1_cpp_basics/README.md) 
2. [Build Systems](./2_build_systems/README.md) 
3. [Git and GitHub](./3_git_github/README.md)
4. [Computer Vision](./4_cv_basics) 
5. [Assignments](./5_assignments)  

### The aim of this repository is to provide:  
- A brief idea of algorithms involved in **Computer Vision** . 
- Introduction to Version Control System: **Git** and **GitHub**. 
- Computer Vision and Image Processing basics, idea of implementation of various algorithms involved from scratch (instead of any dedicated image processing library like OpenCV.)
- Introduction to a commonly used Image Processing Library: **OpenCV**
- Functionality of **Blob detection** using ROI (Region of Interest).

## Table Of Contents
- [Table Of Contents](#table-of-contents)
- [C++ basics](./1_cpp_basics/README.md)
    - [Typecasting](./1_cpp_basics/0_typecasting/explicit_typecasting.cpp)
    - [Namespace](/./1_cpp_basics/1_namespace/namespace.cpp)
    - [Conditional Statements](./1_cpp_basics/2_conditional_statements/if.cpp)
    - [Enumeration](./1_cpp_basics/3_enumeration/enumeration.cpp)
    - [Functions](./1_cpp_basics/4_functions/function.cpp)
    - [Classes and Objects](./1_cpp_basics/5_classes_and_objects/classes_and_objects.cpp)
    - [Templates](./1_cpp_basics/6_templates/class_template.cpp)
    - [Arrays](./1_cpp_basics/7_arrays/arrays2d.cpp)
    - [Pointers](./1_cpp_basics/8_pointers/pointers.cpp)
    - [Vectors](./1_cpp_basics/9_vectors/access_vector.cpp)
- [Build System](./2_build_systems/README.md)
- [Introduction to Git and GitHub](./3_git_github/README.md)
    - [Intro to Git](./3_git_github/1_git_intro%20.md)
    - [Git Workflow](./3_git_github/2_git_workflow.md)
    - [Git commands](./3_git_github/3_git_commands.md)
- [Image Processing](./4_cv_basics)
    - [Image Representation](./4_cv_basics/1_image_representation/README.md)
    - [Playing with Images](./4_cv_basics/2_playing_with_images/README.md)
    - [Interpolation](./4_cv_basics/3_interpolation/README.md)
    - [Convolution](./4_cv_basics/4_convolutions_filtering/README.md)
    - [Masking](./4_cv_basics/5_masking/README.md)
    - [Morphology](./4_cv_basics/6_morphology/README.md)
    - [OpenCV](./4_cv_basics/7_opencv_overview/README.md)
    - [Blob Detection](./4_cv_basics/8_blob_detection/README.md)
- [Assignments](./5_assignments)
- [Installation Instructions](#installation-instructions)

## Installation Instructions

OpenCV library and other dependencies need to be installed on your system. Follow these steps:

### **Step 1: Clone the Repository**
If `git` is installed, clone the repository:
```sh
git clone https://github.com/SRA-VJTI/Pixels_Seminar.git
```

If `git` is **not installed**, proceed to **Step 2** to download the installation script first.

### **Step 2: Run the Installation Script**
Change to the cloned directory (if you have cloned the repository):
```sh
cd Pixels_Seminar
```

#### **Check if `make` is Installed**
Run:
```sh
make --version
```
If `make` is installed, it will output something like:
```sh
GNU Make 4.3
Built for x86_64-pc-linux-gnu
```
If `make` is **not installed**, or you get an error like:
```sh
command not found: make
```
proceed with the installation script.

#### **Download and Run the Installation Script**
If `git` is missing, manually download the script:
```sh
wget https://raw.githubusercontent.com/SRA-VJTI/Pixels_Seminar/main/install.sh -O install.sh
```
Make the script executable and run it:
```sh
chmod +x install.sh
./install.sh
```
This will install the necessary dependencies for the project.

