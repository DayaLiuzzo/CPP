#!/bin/bash

# Check if the class name was provided
if [ -z "$1" ]; then
  echo "Usage: $0 <ClassName>"
  exit 1
fi

# Class name
class_name=$1

# Directories
header_dir="inc"
source_dir="src"

# Create directories if they don't exist
mkdir -p "$header_dir" "$source_dir"

# Filenames
header_file="$header_dir/$class_name.hpp"
source_file="$source_dir/$class_name.cpp"

# Canonical form class content
header_content="#ifndef ${class_name^^}_HPP
#define ${class_name^^}_HPP

#include <iostream>

class $class_name {
private:
    // Class members go here
public:
    $class_name(); // Default constructor
    $class_name(const $class_name &other); // Copy constructor
    $class_name &operator=(const $class_name &other); // Copy assignment operator
    ~$class_name(); // Destructor
};

#endif // ${class_name^^}_HPP
"

source_content="#include \"$header_file\"
#include \"utils.hpp\"

$class_name::$class_name() 
{
    std::cout << GREEN_COLOR << \"$class_name default constructor called\" << RESET_COLOR << std::endl;
}

$class_name::$class_name(const $class_name &other) 
{
    std::cout << GREEN_COLOR << \"$class_name copy constructor called\" << RESET_COLOR << std::endl;
    *this = other;
}

$class_name &$class_name::operator=(const $class_name &other) 
{
    std::cout << GREEN_COLOR << \"$class_name copy assignment operator called\" << RESET_COLOR << std::endl;
    if (this != &other) {
        // Copy the data from 'other' to 'this'
    }
    return *this;
}

$class_name::~$class_name() 
{
    std::cout << GREEN_COLOR << \"$class_name destructor called\" << RESET_COLOR << std::endl;
}
"

# Create the .hpp file in the inc directory
if [ -f "$header_file" ]; then
  echo "$header_file already exists."
else
  echo "$header_content" > "$header_file"
  echo "$header_file created."
fi

# Create the .cpp file in the src directory
if [ -f "$source_file" ]; then
  echo "$source_file already exists."
else
  echo "$source_content" > "$source_file"
  echo "$source_file created."
fi

