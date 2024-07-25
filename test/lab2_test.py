import os
import glob
from help_functions import create_dirs, remove_and_touch, execute

def log_stage(stage, theme):
    print(f"\n=== {stage}: {theme} ===")

def log_file_processing(file):
    print(f"\033[31mProcessing: {file}\033[0m")

def log_filename(filename):
    print(f"Filename: {filename}")

def log_separator():
    print("\033[31m-----------------------------------------------------\033[0m\n")

def main():
    dirs = [
        "../test/Generated_IR",
        "../test/Generated_IR/samples_lex_and_syntax",
        "../test/Generated_IR/samples_semantic",
        "../test/Interpret_Execution",
        "../test/Interpret_Execution/samples_lex_and_syntax",
        "../test/Interpret_Execution/samples_semantic"
    ]
    create_dirs(dirs)

    result_file = "../test/Generated_IR/test.txt"
    remove_and_touch(result_file)

    flag = 0

    log_stage("Stage 1", "Lexical and Syntax Analysis")

    for file in sorted(glob.glob('../test/samples_lex_and_syntax/*.cact')):
        log_file_processing(file)
        filename = os.path.basename(file).replace('.cact', '')
        log_filename(filename)
        irfile = f"../test/Generated_IR/samples_lex_and_syntax/{filename}.txt"
        remove_and_touch(irfile)

        command = f"./compiler -O0 {file} -emit-IR {irfile}"
        execute(command)

        if not os.path.getsize(irfile):
            if "true" in filename and "15" not in filename:
                with open(result_file, 'a') as rf:
                    rf.write(f"samples_lex_and_syntax/{filename}\n")
                flag = 1
            os.remove(irfile)
        elif "false" in filename:
            with open(result_file, 'a') as rf:
                rf.write(f"samples_lex_and_syntax/{filename}\n")
            flag = 1
        log_separator()

    log_stage("Stage 2", "Semantic Analysis")

    for file in sorted(glob.glob('../test/samples_semantic/*.cact')):
        log_file_processing(file)
        filename = os.path.basename(file).replace('.cact', '')
        log_filename(filename)
        irfile = f"../test/Generated_IR/samples_semantic/{filename}.txt"
        remove_and_touch(irfile)

        command = f"./compiler -O0 {file} -emit-IR {irfile}"
        execute(command)

        if not os.path.getsize(irfile):
            if "true" in filename:
                with open(result_file, 'a') as rf:
                    rf.write(f"samples_semantic/{filename}\n")
                flag = 1
            os.remove(irfile)
        elif "false" in filename:
            with open(result_file, 'a') as rf:
                rf.write(f"samples_semantic/{filename}\n")
            flag = 1
        log_separator()

    log_stage("Stage 3", "Results Summary")

    if flag == 0:
        print("Lex and Semantic -- PASS")
    else:
        with open(result_file, 'r') as rf:
            print(rf.read())
        print("Lex and Semantic -- FAILED")

    log_stage("Stage 4", "Interpretation Execution for Lexical and Syntax")

    for file in sorted(glob.glob('../test/Generated_IR/samples_lex_and_syntax/*.txt')):
        filename = os.path.basename(file).replace('.txt', '')
        cactfile = f"../test/samples_lex_and_syntax/{filename}.cact"
        interpretfile = f"../test/Interpret_Execution/samples_lex_and_syntax/{filename}.txt"
        remove_and_touch(interpretfile)
        
        if "14" not in filename:
            command = f"./compiler -O0 {cactfile} {file} -simulate -verbose {interpretfile}"
        else:
            command = f'echo "1" | ./compiler {cactfile} {file} -simulate -verbose {interpretfile}'
        execute(command)

    log_stage("Stage 6", "Interpretation Execution for Semantic")

    for file in sorted(glob.glob('../test/Generated_IR/samples_semantic/*.txt')):
        filename = os.path.basename(file).replace('.txt', '')
        cactfile = f"../test/samples_semantic/{filename}.cact"
        interpretfile = f"../test/Interpret_Execution/samples_semantic/{filename}.txt"
        remove_and_touch(interpretfile)

        if "20" not in filename:
            command = f"./compiler -O0 {cactfile} {file} -simulate -verbose {interpretfile}"
        else:
            command = f'echo -e "1\n1\n" | ./compiler {cactfile} {file} -simulate -verbose {interpretfile}'
        execute(command)

if __name__ == "__main__":
    main()