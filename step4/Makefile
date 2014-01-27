INCLUDES = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv)
CXX = clang++
CXXFLAGS = -Wall -std=c++11 $(INCLUDES)
LDFLAGS = $(LIBS)

.PHONY: run

run: ar
	./ar

ar: ar.cpp

squares: squares.cpp

clean:
	rm ar
