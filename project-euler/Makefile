#!/usr/bin/env bash

# Running "make" will compile all the programs. Running "make testall" will
# test all programs and compare their answers again answers.txt.

CXX := clang++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++17 -O2

SRCS := $(wildcard *.cpp)
EXES := $(patsubst %.cpp, build/%, $(SRCS))
STDOUT := $(patsubst %.cpp, build/%.stdout, $(SRCS))
TESTS := $(patsubst problem%.cpp, test%, $(SRCS))

.PHONY: all clean testall test%

# Make deletes these files otherwise.
.PRECIOUS: $(STDOUT)

all: $(EXES)

testall: $(TESTS)

build/problem%.answer: answers.txt
	@awk -v k="$*" '$$1==k":" {print $$2; exit}' answers.txt > $@

test%: build/problem%.stdout build/problem%.answer
	@diff $^

build/%.stdout: build/%
	$< > $@

build/%: %.cpp
	mkdir -p build/
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf build/
