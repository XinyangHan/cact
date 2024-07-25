import os
import subprocess

# 定义目录路径和命令
examples = ['fib_subseq', 'matrix', 'tim_sort']
base_dir = '/home/xinyang/labs/cact-master-1/cact-master/test/samples_codegen_O0'
compiler_path = '/home/xinyang/labs/cact-master-1/cact-master/build/compiler'
pk_path = '/home/xinyang/labs/cact-master-1/riscv-gnu-toolchain/pk/build/pk'
gcc_command = 'riscv64-unknown-elf-gcc'
spike_command = 'spike'

def run_command(command):
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Command failed: {command}\nError: {result.stderr}")
    else:
        print(result.stdout)
    return result.returncode

def compile_and_run_example(example, optimization_level):
    example_dir = os.path.join(base_dir, example)
    os.chdir(example_dir)
    
    # 编译 .cact 文件
    cact_file = f"{example}.cact"
    compile_command = f"{compiler_path} -{optimization_level} {cact_file}"
    if run_command(compile_command) != 0:
        return

    # 重命名生成的文件
    generated_s_file = f"-{optimization_level}.s"
    renamed_s_file = f"{example}_{optimization_level}.s"
    if os.path.exists(generated_s_file):
        os.rename(generated_s_file, renamed_s_file)
    else:
        print(f"Error: {generated_s_file} not found.")
        return
    
    # 列出目录文件
    print(run_command("ls"))
    
    # 切换回示例目录并链接生成的汇编文件
    exe_file = f"{example}_{optimization_level}.exe"
    link_command = f"{gcc_command} {renamed_s_file} -L. -lcactio -o {exe_file}"
    if run_command(link_command) != 0:
        return
    
    # 执行生成的可执行文件
    execute_command = f"{spike_command} {pk_path} ./{exe_file}"
    run_command(execute_command)

def main():
    for example in examples:
        for optimization_level in ['O0']:
            print(f"\nRunning example: {example} with -{optimization_level}")
            compile_and_run_example(example, optimization_level)

if __name__ == "__main__":
    main()