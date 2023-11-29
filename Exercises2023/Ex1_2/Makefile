# // Title: SUPACOO 2023 - Assignment 1
# // Subtitle: Makefile
# // Editor: Dale Waters
# // Last Edited: 29/11/2023

# Compiler
CC = g++
# Compiler flags
CFLAGS = -std=c++11

# Source files
SOURCES = CustomFunctions.cxx AnalyseData.cxx
# Object files
OBJECTS = $(SOURCES:.cxx=.o)

# Executable
EXECUTABLE = AnalyseData

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cxx
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)