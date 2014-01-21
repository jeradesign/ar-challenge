INCLUDES = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv)
CXX = clang++
CXXFLAGS = -Wall -Werror $(INCLUDES)
LDFLAGS = $(LIBS)

.PHONY: run

run: ar
	./ar

bender: ar.cpp

clean:
	rm ar
