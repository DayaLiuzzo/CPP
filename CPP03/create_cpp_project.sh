#!/bin/bash

# Check if the project name was provided
if [ -z "$1" ]; then
  echo "Usage: $0 <ProjectName>"
  exit 1
fi

# Project name
project_name=$1

# Create the main project directory
mkdir "$project_name" || exit

# Navigate into the project directory
cd "$project_name" || exit

# Create subdirectories
mkdir src inc obj dep

# Create the utils.hpp file in the inc directory
utils_file="inc/utils.hpp"

utils_content="#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

#define YELLOW_COLOR \"\\033[38;2;236;245;66m\"
#define LILAC_COLOR \"\\033[38;2;182;126;222m\"
#define RESET_COLOR \"\\033[0m\"
#define RED_COLOR \"\\033[38;2;201;59;40m\"
#define GREEN_COLOR \"\\033[38;2;50;227;79m\"

void print_message(std::string msg, std::string color);

#endif // UTILS_HPP
"

# Write the content to the utils.hpp file
echo "$utils_content" > "$utils_file"
echo "$utils_file created."

# Create the Makefile in the project root
makefile="Makefile"

makefile_content="NAME = $project_name

S = src/
O = obj/
I = inc/
D = dep/

CC = c++

LDFLAGS = -Wall -Werror -Wextra -std=c++98

CFLAGS	+=	-I\$(I) 

SRCS	=	\$(S)main.cpp \\
			\$(S)utils.cpp

RM	=	/bin/rm -rf

OBJS =	\$(SRCS:\$(S)%=\$(O)%.o)

DEP =	\$(SRCS:\$(S)%=\$(D)%.d)

all : \$(NAME)

\$(O):
	@mkdir -p \$(O)

\$(OBJS): | \$(O)

\$(OBJS): \$(O)%.o: \$(S)%
	@mkdir -p \$(dir \$@)
	@\$(CC) \$(CFLAGS) \$(LDFLAGS) -c \$< -o \$@

\$(D):
	@mkdir -p \$(D)

\$(DEP): | \$(D)

\$(DEP): \$(D)%.d: \$(S)%
	@mkdir -p \$(dir \$@)
	@\$(CC) \$(CFLAGS) -MM -MF \$@ -MT \"\$(O)\$*.o \$@\" \$<

\$(NAME): \$(OBJS) \$(DEP)
	@\$(CC) \$(CFLAGS) \$(OBJS) -o \$(NAME) \$(LDFLAGS)

cleanobjs:
	@\$(RM) \$(OBJS) \$(O)

cleandep: 
	@\$(RM) \$(DEP) \$(D)

clean: cleanobjs cleandep

fclean : clean 
	@\$(RM) \$(NAME)

re: fclean all

include \$(DEP)

.PHONY: all clean fclean re
"

# Write the content to the Makefile
echo "$makefile_content" > "$makefile"
echo "$makefile created."

# Create the create_class.sh script in the project root
create_class_script="create_class.sh"

create_class_content="#!/bin/bash

# Check if the class name was provided
if [ -z \"\$1\" ]; then
  echo \"Usage: \$0 <ClassName>\"
  exit 1
fi

# Class name
class_name=\$1

# Directories
header_dir=\"inc\"
source_dir=\"src\"

# Create directories if they don't exist
mkdir -p \"\$header_dir\" \"\$source_dir\"

# Filenames
header_file=\"\$header_dir/\$class_name.hpp\"
source_file=\"\$source_dir/\$class_name.cpp\"

# Canonical form class content
header_content=\"#ifndef \${class_name^^}_HPP
#define \${class_name^^}_HPP

#include <iostream>

class \$class_name {
private:
    // Class members go here
public:
    \$class_name(); // Default constructor
    \$class_name(const \$class_name &other); // Copy constructor
    \$class_name &operator=(const \$class_name &other); // Copy assignment operator
    ~\$class_name(); // Destructor
};

#endif // \${class_name^^}_HPP
\"

source_content=\"#include \\\"\$header_file\\\"
#include \\\"utils.hpp\\\"

\$class_name::\$class_name() 
{
    std::cout << GREEN_COLOR << \\\"\$class_name default constructor called\\\" << RESET_COLOR << std::endl;
}

\$class_name::\$class_name(const \$class_name &other) 
{
    std::cout << GREEN_COLOR << \\\"\$class_name copy constructor called\\\" << RESET_COLOR << std::endl;
    *this = other;
}

\$class_name &\$class_name::operator=(const \$class_name &other) 
{
    std::cout << GREEN_COLOR << \\\"\$class_name copy assignment operator called\\\" << RESET_COLOR << std::endl;
    if (this != &other) {
        // Copy the data from 'other' to 'this'
    }
    return *this;
}

\$class_name::~\$class_name() 
{
    std::cout << GREEN_COLOR << \\\"\$class_name destructor called\\\" << RESET_COLOR << std::endl;
}
\"

# Create the .hpp file in the inc directory
if [ -f \"\$header_file\" ]; then
  echo \"\$header_file already exists.\"
else
  echo \"\$header_content\" > \"\$header_file\"
  echo \"\$header_file created.\"
fi

# Create the .cpp file in the src directory
if [ -f \"\$source_file\" ]; then
  echo \"\$source_file already exists.\"
else
  echo \"\$source_content\" > \"\$source_file\"
  echo \"\$source_file created.\"
fi
"

# Write the content to the create_class.sh file
echo "$create_class_content" > "$create_class_script"
chmod +x "$create_class_script"
echo "$create_class_script created."

echo "Project $project_name initialized with src, inc, obj, dep directories, utils.hpp, Makefile, and create_class.sh."
