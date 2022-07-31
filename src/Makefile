CC = gcc -g
CFLAGSCOV = -Wall -Werror -Wextra -c -fprofile-arcs -ftest-coverage -lcheck
CFLAGS = -Wall -Werror -Wextra -c

all: test gcov_report 

gcov_report: test
	gcov -f *.gcda
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info  --rc lcov_branch_coverage=1
	# open repot/test.info

test: s21_math.a
	$(CC) --coverage -o test_coverage.out tests/tests.o -lcheck -L. s21_math.a 
	./test_coverage.out


s21_math.a: s21_math.o
	ar rc s21_math.a *.o
	ranlib s21_math.a

s21_math.o: tests.o
	$(CC) $(CFLAGSCOV) *.c

tests.o:
	mkdir tests 
	$(CC) $(CFLAGS) -o tests/tests.o tests.c

clean:
	rm -rf *.o *.gcno *.gcda *.info *.out *.a *.gcov report tests

rebuild: clean all
