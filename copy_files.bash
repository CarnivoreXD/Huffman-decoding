#!/bin/bash


src="/home/faculty/kooshesh/cs315_fall2025/project4/data"
dst="./input_output"

# Check if destination directory exists
if [ ! -d "$dst" ]; then
  echo "Error: Destination directory '$dst' does not exist."
  exit 1
fi

# Copy files from source to destination
# -a preserves attributes, -v is verbose

for ext in tokens code hdr txt; do
    cp -av "$src"/*.${ext} "$dst"/
done

echo "Files copied from '$src' to '$dst'."
