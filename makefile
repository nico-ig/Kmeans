CC = g++
CFLAGS = -g -std=c++20 
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = kmeans

all: $(TARGET)

$(TARGET): $(OBJ)

clean:
	rm -f *.o vgcore* 

purge: clean
	rm -f $(TARGET)
