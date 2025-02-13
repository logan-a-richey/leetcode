#!/bin/bash

# Loop through all .cpp files in the current directory
for file in *.cpp; do
    # Check if the .cpp file exists to avoid errors in case no .cpp files are present
    if [ -f "$file" ]; then
        # Get the filename without the extension
        filename="${file%.cpp}"

        # Check if the executable file exists or if the .cpp file is newer than the executable
        if [ ! -f "$filename" ] || [ "$file" -nt "$filename" ]; then
            # Compile the .cpp file using g++ if needed
            echo "g++ -o $filename $file"
            g++ -o "$filename" "$file"
            echo "Compiled: $filename"
        else
            echo "No changes detected for $file. Skipping compilation."
        fi
    fi
done

echo "All C++ files processed!"

