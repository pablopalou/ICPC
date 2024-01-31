
import random

# File path for saving
file_path = 'C++/TrainingCampBrasil/SegmentTrees/A.in'

# Generating 1 million random numbers
random_numbers = [random.randint(1, 100000000) for _ in range(1000000)]

# Writing to the file
with open(file_path, 'w') as file:
    file.write("1000000\n")  # Writing the number 1000000 on the first line
    file.write(' '.join(map(str, random_numbers)))  # Writing the random numbers on the next line

file_path