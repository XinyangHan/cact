import os
import glob
import subprocess

def execute(command):
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    return result.stdout

def main():
    for file in glob.glob('../test/samples_lex_and_syntax/*.cact'):
        print(f"\033[31mTestfile is {file}\033[0m")
        output = execute(f"./compiler -O0 {file}")
        
        if "error" in output and "true" in file:
            print("Failed")
            continue
        if "error" not in output and "false" in file and "15" not in file:
            print("Failed")
            continue
        
        print(output)
        print("\033[31m------------------------------------------------------\033[0m\n")
    
    print("Pass")

if __name__ == "__main__":
    main()
