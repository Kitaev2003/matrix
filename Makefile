all:
	g++ -g -Wall -Warray-bounds -Wdouble-promotion -Wold-style-cast -Wfloat-equal -Wextra -Wpedantic matrix_functions.cpp matrix_operators.cpp main.cpp  -o start
test:
	g++ -g -Wall -Warray-bounds -Wdouble-promotion -Wold-style-cast -Wfloat-equal -Wextra -Wpedantic matrix_functions.cpp matrix_operators.cpp Test/test.cpp -o start -lgtest -lgmock -pthread
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./start
begin:
	./start
debug:
	gdb start