# C++ Set Data Structure
A command-line interface application for managing sets of integers using a custom Set implementation built on a doubly linked list data structure.

## Description

This project implements a Set data structure in C++ that maintains a collection of unique integers. The application provides an interactive command-line interface that allows users to create two sets, perform various set operations, and manipulate the data through intuitive commands.

The Set class is built using a custom doubly linked list implementation, demonstrating fundamental data structure concepts and object-oriented programming in C++.

## Features

- **Set Operations**
  - Add unique elements to sets
  - Remove elements from sets
  - Check if a set contains a specific value
  - Print set contents with size information
  
- **Advanced Set Operations**
  - **Union**: Combine two sets (all elements from both sets)
  - **Intersection**: Find common elements between two sets
  - **Difference**: Find elements in one set but not in the other

- **Interactive CLI**
  - Manage two independent sets simultaneously
  - Real-time feedback for all operations
  - Easy-to-use command interface

## Prerequisites

To build and run this project, you need:

- C++ compiler with C++14 support (GCC, Clang, or MSVC)
- CMake 3.21 or higher
- Make (or alternative build system)

## Building the Project

### Using CMake (Recommended)

```bash
# Create a build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build the executable
make
```

The executable will be created as `HW4` in the build directory.

### Alternative Build

You can also compile directly with g++:

```bash
g++ -std=c++14 set.cpp -o HW4
```

## Usage

### Running the Application

```bash
# From the build directory
./HW4

# Or from the root directory (if built there)
./HW4
```

### Interactive Setup

When you start the application, you'll be prompted to:

1. Enter the initial size of Set #1
2. Enter the initial size of Set #2
3. Enter the values for Set #1
4. Enter the values for Set #2

**Example:**
```
Enter the starting size of Set #1: 3
Enter the starting size of Set #2: 3
Enter 3 values for Set #1: 1 2 3
Enter 3 values for Set #2: 2 3 4
Now accepting commands (quit to exit program):
```

### Available Commands

Once the sets are initialized, you can use the following commands:

#### `contains <value> <set_number>`
Check if a value exists in the specified set.

**Example:**
```
contains 2 1
true
```

#### `add <value> <set_number>`
Add a value to the specified set. Returns `false` if the value already exists.

**Example:**
```
add 5 1
true
add 5 1
false
```

#### `remove <value> <set_number>`
Remove a value from the specified set. Returns `false` if the value doesn't exist.

**Example:**
```
remove 3 1
true
```

#### `print <set_number>`
Display all elements in the specified set along with its size.

**Example:**
```
print 1
set contents(3): 1 2 5
```

#### `union`
Display the union of Set #1 and Set #2 (all unique elements from both sets).

**Example:**
```
union
set contents(5): 1 2 3 4 5
```

#### `intersection`
Display the intersection of Set #1 and Set #2 (common elements).

**Example:**
```
intersection
set contents(2): 2 3
```

#### `difference`
Display the difference between the two sets in both directions.

**Example:**
```
difference
First - Second
set contents(1): 1
Second - First
set contents(1): 4
```

#### `quit`
Exit the program.

**Example:**
```
quit
Exiting Program
```

## Project Structure

```
.
├── CMakeLists.txt          # CMake build configuration
├── set.cpp                 # Main program with Set class implementation
├── list.h                  # Doubly linked list implementation
└── README.md               # This file
```

### Key Components

- **ListNode**: Node structure for the doubly linked list
- **List**: Doubly linked list implementation with add, remove, and search operations
- **Set**: Set data structure built on top of the List class, ensuring uniqueness

## Implementation Details

- The Set class uses a custom doubly linked list for internal storage
- Duplicate values are automatically prevented when adding elements
- All set operations create new Set objects without modifying the originals
- The implementation uses dynamic memory allocation with proper cleanup

## Example Session

```
Enter the starting size of Set #1: 4
Enter the starting size of Set #2: 3
Enter 4 values for Set #1: 1 2 3 4
Enter 3 values for Set #2: 3 4 5
Now accepting commands (quit to exit program):
print 1
set contents(4): 1 2 3 4
print 2
set contents(3): 3 4 5
union
set contents(5): 1 2 3 4 5
intersection
set contents(2): 3 4
difference
First - Second
set contents(2): 1 2
Second - First
set contents(1): 5
add 6 1
true
print 1
set contents(5): 1 2 3 4 6
remove 2 1
true
contains 2 1
false
quit
Exiting Program
```

## Notes

- Set numbers are 1-based (use 1 or 2 to specify which set)
- The program maintains exactly two sets throughout execution
- All set operations (union, intersection, difference) create new temporary sets
- Input validation is minimal - ensure you enter valid integers for values and set numbers

## License

This project was created as a programming assignment for CMPSC 122 at Penn State University.

## Author

Robert Bennethum (rmb6287@psu.edu)
