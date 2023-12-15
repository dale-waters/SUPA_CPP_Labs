
# Title: SUPACOO 2023 - Assignment 2
# Subtitle: Makefile
# Editor: Dale Waters
# Last edited: 13/12/2023


# Changelog:

# 13/12/2023 Added "CustomFunctions" files - D.Waters

# 12/12/2023 Code runs and produces graph with normalised f(x) - D.Waters

CC=g++ #Name of compiler
FLAGS=-std=c++20 -w #Compiler flags (the s makes it silent)
TARGET=Test #Executable name
# Added CustomFunctions.o
OBJECTS=Test.o FiniteFunctions.o CustomFunctions.o 
LIBS=-I ../../GNUplot/ -lboost_iostreams

#First target in Makefile is default
${TARGET}:${OBJECTS} #Make target from objects
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} ${LIBS} -o ${TARGET}
	@make clean

# Added CustomFunctions.h
Test.o : Test.cxx FiniteFunctions.h CustomFunctions.h
	${CC} ${FLAGS} ${LIBS} -c Test.cxx

FiniteFunctions.o : FiniteFunctions.cxx FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c FiniteFunctions.cxx

# Added CustomFunctions.o
CustomFunctions.o: CustomFunctions.cxx CustomFunctions.h FiniteFunctions.h
	$(CC) $(FLAGS) -c CustomFunctions.cxx

clean: #No targets just run shell command to rm object files and emacs backups
	@rm -f *.o *~

cleantarget: #Delete the exectuable
	@rm -f ${TARGET}
