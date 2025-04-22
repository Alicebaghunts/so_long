#!/bin/bash

# Check if ImageMagick's convert is installed
if ! command -v convert &> /dev/null
then
    echo "ImageMagick's convert command could not be found, please install it first."
    exit 1
fi

# Loop through all PNG files in the current directory
for png_file in *.png; do
    # Check if there are any PNG files
    if [ -e "$png_file" ]; then
        # Convert the PNG to XPM using convert
        xpm_file="${png_file%.png}.xpm"
        convert "$png_file" "$xpm_file"
        echo "Converted $png_file to $xpm_file"
    else
        echo "No PNG files found in the current directory."
        break
    fi
done
