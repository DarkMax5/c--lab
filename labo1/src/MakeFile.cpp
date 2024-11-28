CC = g++
CFLAGS = -std = c++17 - Wall - Wextra - Werror
LDFLAGS = -L. / lib - lsfml - graphics - lsfml - window - lsfml - system -


SOURCES = src/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = tic_tac_toe

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

lib/libtic.a: lib/tic_tac_toe.o
	ar
