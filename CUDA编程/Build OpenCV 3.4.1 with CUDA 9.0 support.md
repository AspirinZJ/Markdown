## Environment

- Ubuntu 16.04
- Anaconda 4.5.4
- CUDA 9.0
- OpenCV 3.4.1
- Python 3.6
- Git
- GeForce GTX 1070 Ti (Pascal GPU)



## Prerequisites

- Python environment (anaconda/conda)
- CUDA 9.0 libraries installed



## Install dependencies

#### Step 1: Update/Upgrade pre-installed packages

```bash
$ sudo apt-get update
$ sudo apt-get upgrade
```

#### Step 2: Install developer tools used to compile OpenCV 3.x

```bash
$ sudo apt-get install build-essential cmake pkg-config
```

#### Step 3: Install libraries and packages used to read various image formats from disk

```bash
$ sudo apt-get install libjpeg8-dev libtiff5-dev libjasper-dev libpng12-dev libtbb2 libtbb-dev
```

#### Step 4: Install a few libraries used to read video formats from disk.

```bash
$ sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
$ sudo apt-get install libxvidcore-dev libx264-dev
```

#### Step 5: Install GTK to use OpenCV’s GUI features

```bash
$ sudo apt-get install libgtk-3-dev
```

#### Step 6: Install packages that are used to optimize various functions inside OpenCV, such as matrix operations

```bash
$ sudo apt-get install libatlas-base-dev gfortran
```

#### Step 7: Clone `opencv` with 3.4.1 from GitHub. Make sure you have git installed.

```bash
$ OPENCV_VERSION=3.4.1
$ git clone https://github.com/opencv/opencv.git
$ cd opencv
$ git checkout -b v${OPENCV_VERSION} ${OPENCV_VERSION}
$ git merge ec0bb66
$ git cherry-pick 549b5df
$ cd ..
```

#### Step 8: Clone `opencv_contrib` from GitHub.

```bash
$ git clone https://github.com/opencv/opencv_contrib.git
$ cd opencv_contrib
$ git checkout v${OPENCV_VERSION} ${OPENCV_VERSION}
$ cd ..
```

#### Step 9: Now set up the build.

```bash
$ cd opencv
$ mkdir build
$ cd build
```

#### Step 10: Run CMAKE command with appropriate options

In my case, I used GTX 1070 Ti (a Pascal GPU). Replace `CUDA_GENERATION` with a proper one. `CUDA_GENERATION` is used for specification of `Auto`, `Fermi`, `Pascal`, `Maxwell` or `Volta`, etc. and limits the code generation only for specific architecture.

```bash
 cmake -D CMAKE_BUILD_TYPE=RELEASE \
       -D CMAKE_INSTALL_PREFIX=$(python -c "import sys; print(sys.prefix)") \
       -D BUILD_EXAMPLES=ON \
       -D BUILD_opencv_python2=OFF \
       -D INSTALL_C_EXAMPLES=OFF \
       -D INSTALL_PYTHON_EXAMPLES=ON \
       -D ENABLE_FAST_MATH=ON \
       -D CUDA_FAST_MATH=ON \
       -D CUDA_GENERATION=Maxwell \
       -D WITH_FFMPEG=1 \
       -D WITH_CUDA=ON \
       -D WITH_CUBLAS=1 \
       -D WITH_OPENGL=ON \
       -D WITH_TBB=ON \
       -D WITH_LAPACK=OFF \
       -D OPENCV_EXTRA_MODULES_PATH="../../opencv_contrib/modules" \
       -D PYTHON3_EXECUTABLE=$(which python) \
       -D PYTHON3_INCLUDE_DIR=$(python -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())") \
       -D PYTHON3_LIBRARY=$(python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())")/../../libpython3.6m.so \
       -D PYTHON3_PACKAGES_PATH=$(python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())") \
       -D PYTHON3_NUMPY_INCLUDE_DIRS=$(python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())")/numpy/core/include ..
```

```bash
我用的命令
 cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D BUILD_EXAMPLES=ON -D BUILD_opencv_python2=OFF -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D WITH_CUDNN=ON -D OPENCV_ENABLE_NONFREE=ON -D ENABLE_FAST_MATH=ON -D CUDA_FAST_MATH=ON -D CUDA_GENERATION=Maxwell -D WITH_FFMPEG=1 -D WITH_CUDA=ON -D OPENCV_DNN_CUDA=ON -D WITH_CUBLAS=1 -D WITH_OPENGL=ON -D WITH_TBB=ON -D WITH_LAPACK=OFF -D OPENCV_EXTRA_MODULES_PATH="../../opencv_contrib/modules" -D PYTHON3_EXECUTABLE=$(which python) -D PYTHON3_INCLUDE_DIR=$(python -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())") -D PYTHON3_LIBRARY=$(python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())")/../../libpython3.6m.so -D PYTHON3_PACKAGES_PATH=$(python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())") -D PYTHON3_NUMPY_INCLUDE_DIRS=$(python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())")/numpy/core/include ..
```



#### Step 11: Make the build now.

```bash
$ make -j $(nproc)
```

Bash

Copy



#### Step 12: Install OpenCV

```bash
$ sudo make install
```

Bash

Copy



#### Step 13: Verify OpenCV

To access OpenCV from Python under Anaconda environment, the directory site-packages contains shared object `cv2.cpython-36m-x86_64-linux-gnu.so` after successful installation.

```python
$ python
Python 3.6.5 |Anaconda, Inc.| (default, Apr 29 2018, 16:14:56) 
[GCC 7.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import cv2
>>> print(cv2.getBuildInformation())
...
...
  NVIDIA CUDA:                   YES (ver 9.0, CUFFT CUBLAS FAST_MATH)
    NVIDIA GPU arch:             60 61
    NVIDIA PTX archs:
...
```

Python

Copy



#### Step 14: Add environment variables to `.bashrc`Environment
Ubuntu 16.04
Anaconda 4.5.4
CUDA 9.0
OpenCV 3.4.1
Python 3.6
Git
GeForce GTX 1070 Ti (Pascal GPU)

Prerequisites
Python environment (anaconda/conda)
CUDA 9.0 libraries installed

Install dependencies
Step 1: Update/Upgrade pre-installed packages
$ sudo apt-get update
$ sudo apt-get upgrade
BashCopy

Step 2: Install developer tools used to compile OpenCV 3.x
$ sudo apt-get install build-essential cmake pkg-config
BashCopy

Step 3: Install libraries and packages used to read various image formats from disk
$ sudo apt-get install libjpeg8-dev libtiff5-dev libjasper-dev libpng12-dev libtbb2 libtbb-dev
BashCopy

Step 4: Install a few libraries used to read video formats from disk.
$ sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
$ sudo apt-get install libxvidcore-dev libx264-dev
BashCopy

Step 5: Install GTK to use OpenCV’s GUI features
$ sudo apt-get install libgtk-3-dev
BashCopy

Step 6: Install packages that are used to optimize various functions inside OpenCV, such as matrix operations
$ sudo apt-get install libatlas-base-dev gfortran
BashCopy

Step 7: Clone opencv with 3.4.1 from GitHub. Make sure you have git installed.
$ OPENCV_VERSION=3.4.1
$ git clone https://github.com/opencv/opencv.git
$ cd opencv
$ git checkout -b v${OPENCV_VERSION} ${OPENCV_VERSION}
$ git merge ec0bb66
$ git cherry-pick 549b5df
$ cd ..
BashCopy

Step 8: Clone opencv_contrib from GitHub.
$ git clone https://github.com/opencv/opencv_contrib.git
$ cd opencv_contrib
$ git checkout v${OPENCV_VERSION} ${OPENCV_VERSION}
$ cd ..
BashCopy

Step 9: Now set up the build.
$ cd opencv
$ mkdir build
$ cd build
BashCopy

Step 10: Run CMAKE command with appropriate options
In my case, I used GTX 1070 Ti (a Pascal GPU). Replace CUDA_GENERATION with a proper one. CUDA_GENERATION is used for specification of Auto, Fermi, Pascal, Maxwell or Volta, etc. and limits the code generation only for specific architecture.
 cmake -D CMAKE_BUILD_TYPE=RELEASE \
       -D CMAKE_INSTALL_PREFIX=$(python -c "import sys; print(sys.prefix)") \
       -D BUILD_EXAMPLES=ON \
       -D BUILD_opencv_python2=OFF \
       -D INSTALL_C_EXAMPLES=OFF \
       -D INSTALL_PYTHON_EXAMPLES=ON \
       -D ENABLE_FAST_MATH=ON \
       -D CUDA_FAST_MATH=ON \
       -D CUDA_GENERATION=Pascal \
       -D WITH_FFMPEG=1 \
       -D WITH_CUDA=ON \
       -D WITH_CUBLAS=1 \
       -D WITH_OPENGL=ON \
       -D WITH_TBB=ON \
       -D WITH_LAPACK=OFF \
       -D OPENCV_EXTRA_MODULES_PATH="../../opencv_contrib/modules" \
       -D PYTHON3_EXECUTABLE=$(which python) \
       -D PYTHON3_INCLUDE_DIR=$(python -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())") \
       -D PYTHON3_LIBRARY=$(python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())")/../../libpython3.6m.so \
       -D PYTHON3_PACKAGES_PATH=$(python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())") \
       -D PYTHON3_NUMPY_INCLUDE_DIRS=$(python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())")/numpy/core/include ..
BashCopy

Step 11: Make the build now.
$ make -j $(nproc)
BashCopy

Step 12: Install OpenCV
$ sudo make install
BashCopy

Step 13: Verify OpenCV
To access OpenCV from Python under Anaconda environment, the directory site-packages contains shared object cv2.cpython-36m-x86_64-linux-gnu.so after successful installation.
$ python
Python 3.6.5 |Anaconda, Inc.| (default, Apr 29 2018, 16:14:56) 
[GCC 7.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import cv2
>>> print(cv2.getBuildInformation())
>>> ...
>>> ...
>>> NVIDIA CUDA:                   YES (ver 9.0, CUFFT CUBLAS FAST_MATH)
>>> NVIDIA GPU arch:             60 61
>>> NVIDIA PTX archs:
>>> ...
>>> PythonCopy

Step 14: Add environment variables to .bashrc
$ cd $(python -c "import sys; print(sys.prefix)") && pwd
/home/chunming/anaconda3

# find cv2.cpython-36m-x86_64-linux-gnu.so
$ find . -iname cv2.cpython-36m-x86_64-linux-gnu.so
./lib/python3.6/site-packages/cv2.cpython-36m-x86_64-linux-gnu.so
BashCopy
Now we found that cv2.cpython-36m-x86_64-linux-gnu.so is under the path /home/chunming/anaconda3/lib/python3.6/site-packages and add it to .bashrc
export PYTHONPATH=$PYTHONPATH:/home/chunming/anaconda3/lib/python3.6/site-packages
export LD_LIBRARY_PATH="/home/chunming/anaconda3/lib:$LD_LIBRARY_PATH"
BashCopy

Uninstall OpenCV (optional)
$ sudo make uninstall
BashCopy

```bash
$ cd $(python -c "import sys; print(sys.prefix)") && pwd
/home/chunming/anaconda3

# find cv2.cpython-36m-x86_64-linux-gnu.so
$ find . -iname cv2.cpython-36m-x86_64-linux-gnu.so
./lib/python3.6/site-packages/cv2.cpython-36m-x86_64-linux-gnu.so
```

Bash

Copy

Now we found that `cv2.cpython-36m-x86_64-linux-gnu.so` is under the path `/home/chunming/anaconda3/lib/python3.6/site-packages` and add it to `.bashrc`

```bash
export PYTHONPATH=$PYTHONPATH:/home/chunming/anaconda3/lib/python3.6/site-packages
export LD_LIBRARY_PATH="/home/chunming/anaconda3/lib:$LD_LIBRARY_PATH"
```

Bash

Copy



## Uninstall OpenCV (optional)

```bash
$ sudo make uninstall
```

Bash

Copy