#!/bin/bash

# Dry run variable (0 for actual removal, 1 for dry run)
DRY=$1

# Loop through all files in the current directory
for file in *; do
    # Check if the file is executable and not a .sh file
    if [ -f "$file" ] && [ -x "$file" ] && [[ "$file" != *.sh ]]; then
        # Perform actions based on dry run variable
        if [[ $DRY -eq 0 ]]; then
            # If dry run is 0, remove the file
            rm "$file"
            echo "Removed: $file"
        else
            # If dry run is not 0, just show what would be removed
            echo "Would remove: $file"
        fi
    fi
done

