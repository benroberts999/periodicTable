# Which compiler: (g++, clang++) [no spaces]
CXX=g++
#CXX=clang++

################################################################################
#Set directories for input files/source code (ID),
# output object files (OD)
ID=./src
OD=./src

WARN=-Wall -Wpedantic -Wextra
CXXFLAGS= -std=c++11 -O3 $(WARN) -I$(ID)
COMP=$(CXX) -c -o $@ $< $(CXXFLAGS)
LINK=$(CXX) -o $@ $^ $(CXXFLAGS)

#Default make rule:
all: periodicTable

################################################################################
## Dependencies:
$(OD)/AtomInfo.o: $(ID)/AtomInfo.cpp $(ID)/AtomInfo.hpp \
$(ID)/AtomInfo_PeriodicTable.hpp
	$(COMP)

$(OD)/periodicTable.o: $(ID)/periodicTable.cpp $(ID)/Nuclear.hpp \
$(ID)/Nuclear_DataTable.hpp $(ID)/AtomInfo.hpp \
$(ID)/AtomInfo_PeriodicTable.hpp
	$(COMP)

################################################################################
# Link + build all final programs

periodicTable: $(OD)/periodicTable.o $(OD)/AtomInfo.o
	$(LINK)

.PHONY: clean
clean:
	rm -f periodicTable $(OD)/periodicTable.o $(OD)/AtomInfo.o
