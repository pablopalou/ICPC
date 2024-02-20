import subprocess
import os

def compile_and_run_test_cases():
    compile_command = "g++ -o solution K.cpp"
    subprocess.run(compile_command, check=True, shell=True)
    
    for i in range(1, 118):  # Assuming 117 cases, adjust if necessary
        case_num = f"{i:04d}"
        input_file = f"input/K_{case_num}"
        output_file = f"output/K_{case_num}"
        
        with open(input_file, 'r') as fin, open(output_file, 'r') as fout:
            expected_output = fout.read().strip()
            # Run the solution and capture the output
            result = subprocess.run(["./solution"], stdin=fin, text=True, capture_output=True)
            actual_output = result.stdout.strip()

            if actual_output != expected_output:
                print(f"WRONG case: K_{case_num}")

# Execute the function
compile_and_run_test_cases()
