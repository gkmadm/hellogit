# Targets for conversion (to binary file input)

convert:
	g++ -std=c++14 src/convert.c++ -o bin/convert.out

run-convert:
	 bin/convert.out
