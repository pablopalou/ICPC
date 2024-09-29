import random

# File path for saving
file_path = 'G.in'

# Number of integers
n = 200000
m = 200000

# Generating sorted numbers for the first list
sorted_numbers = sorted([random.randint(1, 100000000) for _ in range(n)])

# Generating random numbers for the second list
random_numbers = [random.randint(1, 100000000) for _ in range(m)]

# Writing to the file
with open(file_path, 'w') as file:
    file.write(f"{n} {m}\n")  # Writing the numbers n and m on the first line
    file.write(' '.join(map(str, sorted_numbers)) + '\n')  # Writing sorted numbers on the next line
    file.write(' '.join(map(str, random_numbers)))  # Writing random numbers on the next line

file_path