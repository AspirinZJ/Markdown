
#  -O0: no optimization when compiling
#  -O1: default optimization
#  -O2: level2 optimization
#  -O3: highest level optimization
#  -Wall: print all warnings and error
#  -Wextra: print extra warings

default: vec_dot

vec_dot: vec_dot.cu
	nvcc -O3 -Xcompiler "-Wall -Wextra" vec_dot.cu -o vec_dot

clean:
	rm -f vec_dot
