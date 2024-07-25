import os
import subprocess

def main():
    target_dir = "/home/xinyang/labs/cact-master-1/cact-master/test/samples_codegen_functional"
    
    os.chdir(target_dir)
    
    subprocess.run(["python3", "0_test_functional.py"], check=True)

if __name__ == "__main__":
    main()
