#!/bin/bash

for c in {a..f}; do
    cp temp.cpp "$c.cpp"
    echo "$c" > "$c.txt"
    if [ "$c" = "$letter" ]; then
        break
    fi
done