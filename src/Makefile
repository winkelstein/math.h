CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -c 
LFLAGS=--coverage

SOURCES=s21_math_functions/s21_abs.c s21_math_functions/s21_fabs.c s21_math_functions/s21_log.c s21_math_functions/s21_pow.c s21_math_functions/s21_exp.c s21_math_functions/s21_acos.c s21_math_functions/s21_asin.c s21_math_functions/s21_atan.c s21_math_functions/s21_sqrt.c s21_math_functions/s21_ceil.c s21_math_functions/s21_floor.c s21_math_functions/s21_fmod.c s21_math_functions/s21_cos.c s21_math_functions/s21_sin.c s21_math_functions/s21_tan.c
OBJS=$(SOURCES:.c=.o)

TESTS_SRC=test.c tests/s21_abs_test.c tests/s21_fabs_test.c tests/s21_ceil_test.c tests/s21_floor_test.c tests/s21_fmod_test.c tests/s21_sqrt_test.c tests/s21_log_test.c tests/s21_exp_test.c tests/s21_pow_test.c tests/s21_cos_test.c tests/s21_sin_test.c tests/s21_tan_test.c tests/s21_asin_test.c tests/s21_acos_test.c tests/s21_atan_test.c
TESTS_TARGET=s21_math_test

TARGET=s21_math.a

ifeq ($(shell uname -s),Linux)
	LIBS=-lm -lrt -lpthread -lcheck
endif

ifeq ($(shell uname -s),Darwin)
	LIBS=-lcheck
endif

all: $(SOURCES) $(TARGET)

clean: clean_gcov
	rm -rf $(OBJS) $(TARGET) $(TESTS_OBJS) $(TESTS_TARGET)
	

clean_gcov:
	rm -rf *.gcno *.gcda tests.info report

rebuild: clean all

test: $(TESTS_SRC) $(TARGET)
	$(CC) $(SOURCES) $(TESTS_SRC) $(LIBS) --coverage -fprofile-arcs -ftest-coverage -o $(TESTS_TARGET)
	./$(TESTS_TARGET)

format:
	clang-format -i $(SOURCES) $(TESTS_SRC) tests/*.h *.h

check-format:
	clang-format -n $(SOURCES) $(TESTS_SRC) tests/*.h *.h

check:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES) $(TESTS_SRC)

gcov_report: test
	lcov -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html

$(TARGET): $(OBJS)
	ar rcs $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@
