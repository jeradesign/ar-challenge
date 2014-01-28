INCLUDES = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv)
CXX = clang++
CXXFLAGS = -g -Wall -std=c++11 $(INCLUDES)
LDFLAGS = $(LIBS)

.PHONY: run

run: camera_calibration
	./camera_calibration in_camera0.xml

camera_calibration: camera_calibration.cpp

clean:
	rm camera_calibration
