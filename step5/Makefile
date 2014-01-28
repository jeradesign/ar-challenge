INCLUDES = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv)
CXX = clang++
CXXFLAGS = -g -Wall -std=c++11 $(INCLUDES)
LDFLAGS = $(LIBS)

.PHONY: run

run: ar
	./ar

ar: ar.cpp

clean:
	rm ar
