all: count doc

count: counter.cc
	g++ -o count counter.cc -g

check:
	valgrind ./a.out

doc:
	doxygen config.txt
