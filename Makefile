#Compiler#
CC = g++

#Files, wich use 
FILES = matrix_methods/matrix_functions.cpp matrix_methods/matrix_square_function.cpp matrix_methods/matrix_operators.cpp

#Flags#
CFLAGS = -g -Wall -Warray-bounds -Wdouble-promotion -Wold-style-cast -Wfloat-equal -Wextra -Wpedantic

#Flags for library: gtest and gmock#
GTEST = -lgtest -lgmock -pthread

#Name executable file
FILE_NAME = start

all:
	$(CC) $(CFLAGS) $(FILES) main.cpp -o $(FILE_NAME)
test:
	$(CC) $(CFLAGS) $(FILES) test/test.cpp -o $(FILE_NAME) $(GTEST)
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(FILE_NAME)
begin:
	./$(FILE_NAME)
debug:
	gdb $(FILE_NAME)