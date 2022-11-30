CXX := g++
CXXFLAGS := -g -Wall --std=c++11
GTESTCFLAGS := -DGTEST_HAS_PTHREAD=1  
GTESTLIBS := -lgtest -lpthread
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS=llrec-test
CPP=llrec-test.cpp llrec.cpp
all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: 
	$(CXX) $(CXXFLAGS) $(GTESTCFLAGS) $(CPP) -o $(OBJS) $(GTESTLIBS)

test: llrec-test
	./llrec-test llrec-test1.in  

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 
