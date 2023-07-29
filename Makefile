#Compiler#
CC = g++

#Flags#
CFLAGS = -g -Wall -Warray-bounds -Wdouble-promotion -Wold-style-cast -Wfloat-equal -Wextra -Wpedantic

#Flags for library: gtest and gmock#
GTEST = -lgtest -lgmock -pthread

#Name executable file
FILE_NAME = start

all:
	$(CC) $(CFLAGS)  main.cpp -o $(FILE_NAME)
testing:
	$(CC) $(CFLAGS)  test/test.cpp -o $(FILE_NAME) $(GTEST)
memcheck: 
	valgrind --tool=memcheck --leak-check=full --leak-resolution=med --log-file=memory_info.txt ./$(FILE_NAME)
massif:
	valgrind --tool=massif --log-file=memory_info.txt ./$(FILE_NAME)
debug:
	gdb $(FILE_NAME)
begin:
	./$(FILE_NAME)
