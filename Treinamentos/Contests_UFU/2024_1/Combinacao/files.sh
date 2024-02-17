#!/bin/bash

for file in *; do
    if [ -f "$file" ]; then
        # Get the file name without extension
        filename=$(basename -- "$file")
        extension="${filename##*.}"
        filename="${filename%.*}"

        # Uppercase the filename and append "-Katia"
        new_filename=$(echo "$filename" | tr '[:lower:]' '[:upper:]')
        new_filename="${new_filename}-Katia"

        # Concatenate the new filename with the original extension
        new_file="${new_filename}.${extension}"

        # Rename the file
        mv "$file" "$new_file"
    fi
done
