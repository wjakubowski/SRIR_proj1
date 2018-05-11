########################
source1=srir1
source2=PropertyFileConfiguration
########################


CXX=c++
CXXFLAGS= -g -Wall -std=c++11

main : main.o $(source1).o $(source2).o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(source1).o :   $(source1).cpp
	$(CXX) $(CXXFLAGS) $< -c
	
$(source2).o :   $(source2).cpp
	$(CXX) $(CXXFLAGS) $< -c

main.o : main.cpp
	$(CXX) $(CXXFLAGS) $< -c

clean:
	rm -rf *.o main

run: main
	./main

valgrind: main
	valgrind -v ./main

gdb : main
	gdb ./main 
