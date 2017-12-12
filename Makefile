all: count doc

count: counter.cc
	g++ -o count counter.cc -g

doc:
	doxygen config.txt
