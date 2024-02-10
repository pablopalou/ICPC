# Writing to the file
import random

# File path for saving
file_path = 'A.in'

# Open file for writing
with open(file_path, 'w') as file:
    file.write("100000\n")

    for _ in range(100000):
        num = -1
        file.write(f"{num}\n")

# Output the file path
file_path