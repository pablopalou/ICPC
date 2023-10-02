def watermelon(): 
    n = int(input())
    if n % 2 or n== 2: 
        print('NO')
    else: 
        print('YES')



# 8
# 0 8 => 4
# 1 7 => 5
# 2 6 => 4
# 3 5 => 5
# 4 4 => 4

# 5
# 0 5 => 3
# 1 4 => 3
# 2 3 => 3

def solve(n, l): 
    ans = 0
    actual = 0
    for val in l:
        if val == 1:
            actual += 1  
            ans += 1
        else: 
            ans = actual // 2 + 1

    print(ans)

#when the doctor comes the worst case will be having an even number of male or female pigs. In that case we have (n // 2 + 1) aviaries
def pigs(): 
    t = int(input())
    for _ in range(t):
        n = int(input())
        l = list(map(int, input().split()))
        solve(n, l)

def emptySquares():
    n, k, e = map(int, input().split())
    left = e
    right = n - e - k

    if right < left:
        left, right = right, left
    res = 0
    if left == 0:
        if right != k:
            res = 0
        else:
            if right >= 3:
                res = 0
            else: 
                res = 1
    if left == 1: 
        if right == 1:
            if k == 1:
                res = 2
            else:
                res = 1
        else:
            if k == 1:
                res += 1
                if right == 1:
                    res += 1
            if k == 2:
                if right == 2:
                    res += 2
                elif right == 1:
                    res += 1 
            if k == 3:
                if right == 3:
                    res = 1
            if k == 4:
                if right == 4:
                    res = 1
    if left == 2:
        if k == 1:
            if right == 2:
                res += 2
        elif k == 2:
            if right == 2: 
                res += 3
            else:
                res += 1
        elif k == 3:
            if right == 3:
                res += 2
            if right == 2:
                res += 1
        else: #k>=4
            if right == 2:
                res += 1
    if left == 3:
        if k == 1: 
            if right == 3:
                res += 1
        elif k == 2:
            if right == 3:
                res += 2
        elif k == 3:
            if right == 3:
                res += 3
        elif k == 4:
            if right == 4:
                res = 1
    if left == 4:
        if k == 1:
            if right == 4:
                res += 1
        if k == 3:
            if right == 4:
                res += 1
        if k == 4:
            if right == 4:
                res += 2

    print(res)

# import os

emptySquares()

# # Path to the input and output folders
# input_path = "input"
# output_path = "output"

# # Get a list of all the input and output files
# input_files = sorted(os.listdir(input_path))
# output_files = sorted(os.listdir(output_path))

# # Loop through each input file and compare it with the corresponding output file
# for i, input_file in enumerate(input_files):
#     # Extract the label from the input filename
#     label = input_file.split("_")[1]

#     # Make sure the corresponding output file exists
#     assert output_files[i] == f"E_{label}", f"Missing output file for input {input_file}"

#     # Read the input and output files
#     with open(os.path.join(input_path, input_file), "r") as f:
#         input_data = f.read()
#     with open(os.path.join(output_path, f"E_{label}"), "r") as f:
#         expected_output = f.read()

#     numbers = [int(x) for x in input_data.split()]

#     # Call your function or code with the input data to get the actual output
#     actual_output = emptySquares(numbers)  # Replace my_function with your function name

#     # Compare the actual and expected output
#     if int(str(actual_output)) != int(expected_output):
#         print(f"Test case {label} failed. Expected output: {expected_output}, Actual output: {actual_output}")
#     else:
#         print(f"Test case {label} passed.")