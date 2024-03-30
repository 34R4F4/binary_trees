#!/bin/bash

# Compile the C source files with optimizations and error checks
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 114-bst_remove.c 114-main.c 112-array_to_bst.c 111-bst_insert.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 114-bst_rm

# Check if compilation was successful (exit code 0 indicates success)
if [[ $? -eq 0 ]]; then
  # Execute the compiled program (assuming it's in the current directory)
  ./114-bst_rm
else
  echo "Error: Compilation failed."
  exit 1
fi
