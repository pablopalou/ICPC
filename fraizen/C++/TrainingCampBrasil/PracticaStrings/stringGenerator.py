# Writing to the file
import random

# File path for saving
file_path = 'A.in'

# Open file for writing
with open(file_path, 'w') as file:
    # Step 1: Write "100 100000" followed by a newline
    file.write("100 100000\n")
    
    # Step 2: Generate 100 strings of 'a's, each with increasing length
    for i in range(1, 101):
        file.write('a' * i + '\n')
    
    # Step 3: Generate a string of 100000 'a's
    file.write('a' * 100000 + '\n')
    
    # Step 4: Generate 100 random numbers each followed by a lowercase letter and a newline
    for _ in range(100000):
        num = random.randint(1, 100000)
        letter = random.choice('abcdefghijklmnopqrstuvwxyz')
        file.write(f"{num} {letter}\n")

# Output the file path
file_path