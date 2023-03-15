# CMake tests example (CTest)
An example to use cmake tests. 

Here we showcase how to separate tests from the main source code while still being able to build everyting at once with CMAKE. As an example we use a similar CMAKE structure as the NISE program.

The tests are not included in the build by default. To include them in the build follow these steps:
#### 1. Make a build dir
```
mkdir build
cd build
```

#### 2. Run cmake with tests
```
cmake .. -D BUILD_TESTING=YES
```

#### 3. Build source and tests
```
cmake --build .
```

#### 4. Run tests
To see the available tests (dry run)
```
ctest -N
```

To run the tests (with optional -VV flags to set verbosity)
```
ctest
```