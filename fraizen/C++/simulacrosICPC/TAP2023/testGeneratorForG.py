# File path for saving
file_path = 'G.in'

# Number of lines
n = 100000

# Initialize the first numbers of each column
first_column_start = 1
second_column_start = 1
third_column_start = 10000

# Open the file to write the data
with open(file_path, 'w') as file:
    file.write(f"{n}\n")  # Writing the number 100000 on the first line
    
    for i in range(n):
        first_number = first_column_start + 3 * i
        second_number = second_column_start + i
        third_number = third_column_start + i
        file.write(f"{first_number} {second_number} {third_number}\n")

file_path
