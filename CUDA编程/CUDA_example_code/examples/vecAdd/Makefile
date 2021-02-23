#  -O0: no optimization when compiling
#  -O1: default optimization
#  -O2: level2 optimization
#  -O3: highest level optimization
#  -Wall: print all warnings and error
#  -Wextra: print extra warings

default: vec_add

vec_add: vec_add.cu
	nvcc -O3 -Xcompiler "-Wall -Wextra" vec_add.cu -o vec_add

clean:
	rm -f vec_add 1B-reduction reduction_1 reduction_2 mem mem-host vec_dot
