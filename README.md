# CACT Compiler Skeleton

## Using ANTLR4 to Generate Files from Grammar File

```bash
java -jar ../deps/antlr-4.13.1-complete.jar -Dlanguage=Cpp CACT.g4 -visitor -no-listener
```

## Compile the CMake Project

```bash
mkdir -p build
cd build
cmake ..
make -j
./compiler ../test/samples_lex_and_syntax/00_true_main.cact
```

## Testing Functionality

### 1. Lexical and Syntax Analysis Test (`lab2_test.py`)

This script runs lexical, syntax, and semantic analysis on a set of sample CACT files. To execute the test, navigate to the `build` directory and run:

```bash
cd /home/xinyang/labs/cact-master-1/cact-master/build
python ../test/lab2_test.py
```

### 2. RISC-V Assembly Test (`rv_test.py`)

This script tests the generated RISC-V assembly code. To execute the test, navigate to the `build` directory and run:

```bash
cd /home/xinyang/labs/cact-master-1/cact-master/build
python ../test/rv_test.py
```

### 3. Speedup Test (`speedup_test.py`)

This script evaluates the performance improvement of our compiler. To execute the test, navigate to the `build` directory and run:

```bash
cd /home/xinyang/labs/cact-master-1/cact-master/build
python ../test/speedup_test.py
```

### 4. Speedup Test with Optimization Level -O1 (`speedup_test1.py`)

This script evaluates the performance improvement of our compiler with optimization level -O1. To execute the test, navigate to the `build` directory and run:

```bash
cd /home/xinyang/labs/cact-master-1/cact-master/build
python ../test/speedup_test1.py
```
