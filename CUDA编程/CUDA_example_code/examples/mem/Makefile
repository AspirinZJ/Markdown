#  -O0: no optimization when compiling
#  -O1: default optimization
#  -O2: level2 optimization
#  -O3: highest level optimization
#  -Wall: print all warnings and error
#  -Wextra: print extra warings

default: mem

mem: mem.cu
	nvcc -O3 -Xcompiler "-Wall -Wextra" mem.cu -o mem

clean:
	rm -f mem
