# Options + settings for makefile for each 'Main'

## Build mode (changes warnings + optimisation level)
Build=release
#Build=dev
#Build=debug

# runs make in //
ifneq ($(Build),debug)
  MAKEFLAGS += -j12
endif

#Warnings:
WARN=-Wall -Wpedantic -Wextra -Wdouble-promotion -Wconversion -Wshadow
# -Weffc++
# -Wfloat-equal
# -Wsign-conversion

# Changes to warning based on compiler:
ifeq ($(CXX),clang++)
  WARN += -Wno-sign-conversion -Wheader-hygiene
endif
ifeq ($(CXX),g++)
  WARN += -Wsuggest-override -Wsuggest-final-types #-Wsuggest-final-methods
endif

# Changes to optimisation based on build setting:
OPT=-O3
ifeq ($(Build),release)
  WARN=-w
endif
ifeq ($(Build),debug)
	WARN+=-Wno-unknown-pragmas
	OPT=-O0 -g
endif


CXXFLAGS= $(CXXSTD) $(OPT) $(WARN) -I$(SD)
LIBS=-lgsl -lgslcblas

#Command to compile objects and link them
COMP=$(CXX) -c -o $@ $< $(CXXFLAGS)
LINK=$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)
