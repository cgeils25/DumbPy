#!/bin/bash

# Directory containing the .py files
TEST_DIR="tests"

# Collect all .py files in the directory
PY_FILES=$(find "$TEST_DIR" -type f -name "test_*.py")

# Loop through each .py file
for f in tests/test_*.py; do
    echo "Running: $f"
    python "$f"
done
