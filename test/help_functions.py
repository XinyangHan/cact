import os
import subprocess
import glob

def create_dirs(dirs):
    for d in dirs:
        os.makedirs(d, exist_ok=True)

def remove_and_touch(file_path):
    if os.path.exists(file_path):
        os.remove(file_path)
    with open(file_path, 'w'):
        pass

def execute(command):
    result = subprocess.run(command, shell=True)
    return result.returncode
