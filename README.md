# interface_implementation_test

This project contains 2 implementations of COLLECTION Interface-- LIFO (last-in, first-out) and FIFO (first-in, first-out). The Collection interface comprises the following operations

• Add(number) - adds the number to the queue

• Get() - removes the next number from the queue and returns it

• IsEmpty() - returns whether the queue is empty

• Size() - returns the queue's size


## FOLDER STRUCTURE

An xUnit Architecture based unit testing framework was used to write Test codes for both the LIFO and FIFO classes. After compiling, the folder structure looks like this

```bash
interface_implementation_test/
├── CMakeLists.txt
├── README.md
├── build
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   ├── Makefile
│   ├── bin
│   ├── cmake_install.cmake
│   ├── lib
│   ├── src
│   └── tst
├── lib
│   └── googletest
├── src
│   ├── AddException.hpp
│   ├── CMakeLists.txt
│   ├── FIFO.hpp
│   ├── GetException.hpp
│   ├── LIFO.hpp
│   ├── ZException.hpp
│   ├── collection.hpp
│   └── main.cpp
└── tst
├── CMakeLists.txt
├── FIFOTests.cpp
├── LIFOTests.cpp
└── main.cpp
```
## PREREQUISITES

Inside the directory interface_implementation_testt, create a folder lib and clone the github repository of googletest in it . Instructions are shown below

```bash
cd interface_implementation_test
mkdir lib
git clone https://github.com/google/googletest
```

## COMPILE

Now that we have sourcecode and testcode in place we can compile everything (both the binary and the tests).

To compile the code, please create a build folder in the directory interface_implementation_test.

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
```
There are now a bunch of files and folders in the build folder, most important, the Makefile. You can now compile the project:

```bash
make all
```
You now have two executable files, as defined in the CMakeLists.txt:

```bash
$ find . -executable -type f
./tst/interface_implementation_test_tst
./src/interface_implementation_test_run
```

## RUN

The main.cpp from src should run by typing

```bash
./src/interface_implementation_test_run
```
Output:
```bash
Entering main code
0
10
1
Empty Stack Error: Trying to Get when Stack is empty
0
10
1
Empty Queue Error: Trying to Get when Queue is empty
```


The tests as well:
```bash
./tst/interface_implementation_test_tst
```

A quick one-liner to compile and run the tests. You can run this whenever you want to re-run the tests
```bash
make interface_implementation_test_tst; tst/interface_implementation_test_tst
```
Sample Output of all testruns:
```bash
[ 25%] Built target gtest
[ 50%] Built target interface_implementation_test_lib
[100%] Built target interface_implementation_test_tst
[==========] Running 8 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 4 tests from FIFOTestCase
[ RUN      ] FIFOTestCase.testisEmpty
[       OK ] FIFOTestCase.testisEmpty (0 ms)
[ RUN      ] FIFOTestCase.testsize
[       OK ] FIFOTestCase.testsize (0 ms)
[ RUN      ] FIFOTestCase.testAdd
[       OK ] FIFOTestCase.testAdd (0 ms)
[ RUN      ] FIFOTestCase.testGet
Empty Queue Error: Trying to Get when Queue is empty
[       OK ] FIFOTestCase.testGet (0 ms)
[----------] 4 tests from FIFOTestCase (0 ms total)

[----------] 4 tests from LIFOTestCase
[ RUN      ] LIFOTestCase.testisEmpty
[       OK ] LIFOTestCase.testisEmpty (0 ms)
[ RUN      ] LIFOTestCase.testsize
[       OK ] LIFOTestCase.testsize (0 ms)
[ RUN      ] LIFOTestCase.testAdd
[       OK ] LIFOTestCase.testAdd (0 ms)
[ RUN      ] LIFOTestCase.testGet
Empty Stack Error: Trying to Get when Stack is empty
[       OK ] LIFOTestCase.testGet (0 ms)
[----------] 4 tests from LIFOTestCase (0 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 8 tests.


```
