#!/bin/bash

# Compile the C source files with optimizations and error checks
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 18-main.c 18-binary_tree_uncle.c 0-binary_tree_node.c -o 18-uncle

# Check if compilation was successful (exit code 0 indicates success)
if [[ $? -eq 0 ]]; then
  # Execute the compiled program (assuming it's in the current directory)
  ./18-uncle
else
  echo "Error: Compilation failed."
  exit 1
fi
