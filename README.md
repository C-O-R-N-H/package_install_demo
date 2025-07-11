<!-- # Package Demo

We will look at two ways of using packages. The first is with python and the second is with C++. Both of these packages have the same content in them, just in different languages.

## Python
Navigate to `external_packages/python`. In here you will see this:
```bash
.
├── math_pkg
│   ├── advanced
│   │   ├── divide.py
│   │   ├── __init__.py
│   │   └── multiply.py
│   ├── basic
│   │   ├── add.py
│   │   ├── __init__.py
│   │   └── sub.py
│   └── __init__.py
└── setup.py
```
In this we have 1 package that has two sub-modules. Each of the python files have the implementations of the functions that will be a part of this package. The `__init__.py` files in each submodule say what will be exposed when we turn this into a package (sometimes we don't want everything). The whole `math_pkg` itself has its own init that is used to expose the elements from the subpackage that need to be exposed. The `setup.py` is the descriptor of the package itself. It acts kind of like an XML descriptor, defining the name, author, version... 
```bash
from setuptools import setup

setup(
    name='math_pkg',
    version='0.1',
    description='A simple Python package',
    author='WP',
    author_email='WP@example.com',
    packages=['math_pkg'],
    install_requires=[
        'numpy',
        'pandas',
    ],
)
```
Note the install requires is not needed for this packages but is put there as an example. This is especially useful for specifying versions of requirements.

One annoying quirk or python is the use of `pip`. Most programers do not use rigorous methods when testing their install requirements and often put whatever version they have on their system for the dependencies when much older versions will suffice. This causes issues as `pip` tends to auto update these libraries which is often undesirable. 

To install the package, when in the `math_pkg` directory, run:
```bash
pip install -e .
```
This is saying, install the package in the current directory with edit perms, meaning that you don't need to reinstall the library after each edit.

This library can then be accessed as if it were any other library. If you navigate to `implementation/python`, you can run the python script which imports the package and uses it.

## C++
C++ is a bit more complicated. First lets cover CMakeLists.txt:
### CMakeLists.txt
These are the more modern version of MakeFiles. Once you have written your CMakeList, your workflow to build becomes:
```bash
mkdir build                  # Make a build directory
cd build                     
cmake ..                     # Compile the CMakeLists into a Makefile
make                         # Build the executable
sudo make install            # Install the executable
```

### C++ Packages
Once again, navigate to `external_packages/cpp/maths_pkg/`. In this directory you will see:
```bash
.
├── advanced
│   ├── CMakeLists.txt
│   ├── include
│   │   └── advanced
│   │       ├── divide.hpp
│   │       └── multiply.hpp
│   └── src
│       ├── divide.cpp
│       └── multiply.cpp
├── basic
│   ├── CMakeLists.txt
│   ├── include
│   │   └── basic
│   │       ├── add.hpp
│   │       └── sub.hpp
│   └── src
│       ├── add.cpp
│       └── sub.cpp
└── CMakeLists.txt
```
In here we can see the two sub modules in the one main package. Each submodule acts as its own package when installed given the way we have named everything. The top level CMakeLists simply calls each of the sub modules which in turn build their packages.

Again, the build procedure, if in the `maths_pkg/` directory is:
```bash
mkdir build                  # Make a build directory
cd build                     
cmake ..                     # Compile the CMakeLists into a Makefile
make                         # Build the executable
sudo make install            # Install the executable
```
Once the package has been installed, you need to update the system cache. At this stage, if you try to run the files they will compile as you can see the headers, but the system doesn't know where to find the `.so` files for their implementation. To do this, run:
```bash
sudo ldconfig
```

Then, to test this, navigate to `implementation/cpp`. You will see an `/src` with the test script. This can be run and compiled directly from the command line with:
```bash
g++ test.cpp -o test_cpp -lmath_basic -lmath_advanced
```
And run the resulting executable. 

Alternatively you can build it using the CMakeLists following the same process:
```bash
mkdir build                  # Make a build directory
cd build                     
cmake ..                     # Compile the CMakeLists into a Makefile
make                         # Build the executable
```
Note: without running `sudo make install` we can see the executable in the build directory and can run it. we are just not installing it to the system.

 -->


#  Package Demo: Python vs C++

This demonstration explores two approaches to building and using packages — one in **Python** and the other in **C++**. Both packages implement the same mathematical operations but differ in structure and build systems according to their respective languages.

---

##  Python Package

Navigate to `external_packages/python`. The directory structure looks like this:

```bash
.
├── math_pkg
│   ├── advanced
│   │   ├── divide.py
│   │   ├── multiply.py
│   │   └── __init__.py
│   ├── basic
│   │   ├── add.py
│   │   ├── sub.py
│   │   └── __init__.py
│   └── __init__.py
└── setup.py
```

### Package Structure

* `math_pkg/` is the root of the Python package.
* It contains two submodules: `basic/` and `advanced/`, each with their respective operations.
* Each submodule has an `__init__.py` file to define what gets exposed when the submodule is imported.
* The top-level `__init__.py` controls which parts of the submodules are available at the package level.
* `setup.py` serves as the package descriptor and installer.

### Example `setup.py`

```python
from setuptools import setup

setup(
    name='math_pkg',
    version='0.1',
    description='A simple Python package',
    author='WP',
    author_email='WP@example.com',
    packages=['math_pkg'],
    install_requires=[
        'numpy',
        'pandas',
    ],
)
```

>  The `install_requires` section is optional here but demonstrates how to include dependencies. In real-world usage, it's often abused — developers tend to list unnecessarily strict or inflated dependency versions, which can break downstream compatibility.

### Installing the Package

From the `external_packages/python` directory:

```bash
pip install -e .
```

* The `-e` flag installs the package in **editable mode**, meaning changes to source files take effect immediately without needing a reinstall.
* Once installed, this package can be imported like any other Python module.

### Running the Demo

To test the package:

```bash
cd implementation/python
python test.py
```

This will execute a script that imports and uses the `math_pkg`.

---

##  C++ Package

Navigate to `external_packages/cpp/maths_pkg`. You will see the following structure:

```bash
.
├── advanced
│   ├── include/
│   │   └── advanced/
│   │       ├── divide.hpp
│   │       └── multiply.hpp
│   ├── src/
│   │   ├── divide.cpp
│   │   └── multiply.cpp
│   └── CMakeLists.txt
├── basic
│   ├── include/
│   │   └── basic/
│   │       ├── add.hpp
│   │       └── sub.hpp
│   ├── src/
│   │   ├── add.cpp
│   │   └── sub.cpp
│   └── CMakeLists.txt
└── CMakeLists.txt
```

* Each submodule (`basic`, `advanced`) is structured as a mini-package.
* Each has its own CMakeLists.txt that is called from the top-level `CMakeLists.txt`.

### Building the C++ Package

In the `maths_pkg/` directory:

```bash
mkdir build
cd build
cmake ..
make
sudo make install
```

* `cmake ..` generates Makefiles from the `CMakeLists.txt`.
* `make` compiles the libraries.
* `sudo make install` installs the shared libraries (`.so` files) system-wide.

### Post-Installation Step

After installation, ensure your system knows where to find the new libraries:

```bash
sudo ldconfig
```

This updates the system's dynamic linker cache.

---

##  Testing the C++ Package

Navigate to `implementation/cpp`. There is a test script in the `src` folder.

### Quick Compile Without CMake

```bash
g++ src/test.cpp -o test_cpp -lmath_basic -lmath_advanced
./test_cpp
```

This command compiles the test script using the installed shared libraries.

### Using CMake to Build the Test

```bash
mkdir build
cd build
cmake ..
make
./test_cpp
```

>  Note: Skipping `make install` means the executable will still build and run from the local build directory instead of needing to be installed system-wide.

---

## Summary

| Aspect       | Python                             | C++                                       |
| ------------ | ---------------------------------- | ----------------------------------------- |
| Package Tool | `setuptools` (`setup.py`)          | `CMake`                                   |
| Structure    | Module directories + `__init__.py` | Header/source split + `CMakeLists.txt`    |
| Install      | `pip install -e .`                 | `cmake .. && make && sudo make install`   |
| Run          | Directly via Python                | Compile via `g++` or `cmake`, then run    |
| Linkage      | Handled by Python interpreter      | Must configure `.so` linking + `ldconfig` |

---

# Inspecting Install Structure
## C++ Structure
After building and installing the C++ components, navigate to:
```bash
cd /usr/local/lib
ls | grep "libmath"
```
You should observe two `.so` files—these are the shared library binaries produced during the build process. These libraries are used during linking when other programs depend on the functionality provided by your package.

The corresponding C++ header files are located in:
```bash
/usr/local/include/maths_pkg/basic
/usr/local/include/maths_pkg/advanced
```
Note that the structure of the directories matches what was set in the CMakeLists. It should also be noted that the `/usr/local/include` directory is one of the standard locations for the compiler to look when including headers.

## Python Structure
For the Python packages, because we installed it in editable mode, the package is not copied into the Python `site-packages` directory. Instead, Python creates an `.egg-link` file in your user or environment-specific site-packages directory. This file contains a path to your source directory and effectively acts like a symbolic link. To locate this file:
```bash
cd ~/.local/lib/python<version>/site-packages
cat math_pkg.egg-link
```
> Replace `<version>` with your Python version, such as `python3.8`. 

The contents of the `.egg-link` file will be the path to your package’s source directory (e.g., `~/src/tmp/package_install_demo/external_packages/python`), which Python uses to dynamically resolve imports. This is ideal for development as it allows changes to the source code to take effect without reinstalling the package.

