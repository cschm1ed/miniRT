#!/bin/bash

# Function to check if a suppression block includes relevant functions
function includesRelevantFunctions() {
    local block="$1"
    if [[ $block =~ (fun:mlx_|fun:_X|ImageLoader|lib|dyld|lib|_NS|__CF|printf|???) ]]; then
        return 0
    else
        return 1
    fi
}

# Read input line by line
while IFS= read -r line; do
    # Check if a suppression block starts
    if [[ $line == "{" ]]; then
        # Initialize an empty array to store the lines of the suppression block
        suppression=()
        suppress_block=0
    fi

    # Add the line to the suppression block
    suppression+=("$line")

    # Check if the suppression block includes relevant functions
    if includesRelevantFunctions "$line"; then
        suppress_block=1
    fi

    # Check if a suppression block ends
    if [[ $line == "}" ]]; then
        # Join the suppression block lines into a single string
        suppression_block=$(printf '%s\n' "${suppression[@]}")

        # Include the suppression block if it includes relevant functions
        if [[ $suppress_block -eq 1 ]]; then
            echo "$suppression_block"
        fi
    fi
done
