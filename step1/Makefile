INCLUDES = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv)
CXX = clang++
CXXFLAGS = -Wall -Werror $(INCLUDES)
LDFLAGS = $(LIBS)

.PHONY: run

run: step1
	./step1

bender: step1.cpp

clean:
	rm step1
