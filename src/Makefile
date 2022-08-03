CC:=gcc

MAKE_DIR:=mkdir -p
RM_DIR:= rm -f

SANITAZER:=#-fsanitize=address 
DEBUG_FLAG=-g

AR_RC:= ar rc
RAN:= ranlib

SCHOOL_FLAGS:=-c -Wall -Wextra -Werror -std=c11 
CFLAGS?= $(SCHOOL_FLAGS) $(DEBUG_FLAG) $(SANITAZER)
TESTS_CFLAGS:= -g $(SCHOOL_FLAGS) #$(shell pkg-config --cflags check)

GCOV_FLAGS?=-fprofile-arcs -ftest-coverage

TESTS_LIBS?=-lcheck

CPPLINT?=CPPLINT.cfg

TAGET?=s21_math.a

TESTS_TAGET?=tests_s21_math.a
TESTS_EXEC?=test
TESTS_GCOV_EXEC?=tests_gcov

GCOV_REPORT:=gcov_reports
GCOV_TARGET_RCGET:=./coverage
GCOV_INFO:=coverage.info

SOURCES_DIR?=.
TESTS_SOURCES_DIR?=./tests

OBJECTS_DIR?=./objects
TESTS_OBJECTS_DIR?=./tests/objects

INCLUDES:=$(shell find $(SOURCES_DIR) -maxdepth 1 -name "s21_*.h")
TESTS_INCLUDES:=$(shell find $(TESTS_SOURCES_DIR) -maxdepth 1 -name "*.h")

SOURCES:=$(shell find $(SOURCES_DIR) -maxdepth 1 -name "s21_*.c")
TESTS_SOURCES:=$(shell find $(TESTS_SOURCES_DIR) -maxdepth 1 -name "*.c")

OBJECTS:=$(addprefix $(OBJECTS_DIR)/, $(notdir $(SOURCES:.c=.o)))
TESTS_OBJECTS:=$(addprefix $(TESTS_OBJECTS_DIR)/, $(notdir $(TESTS_SOURCES:.c=.o))) #$(TESTS_OBJECTS_DIR)/main.o
GCOV_OBJECTS:=$(addprefix $(TESTS_OBJECTS_DIR)/, $(notdir $(SOURCES:.c=.o)))

GCDA:=$(shell find $(TESTS_OBJECTS_DIR) -maxdepth 1 -name "*.gcda")
GCNO:=$(shell find $(TESTS_OBJECTS_DIR) -maxdepth 1 -name "*.gcno")

all: $(TAGET) test gcov_report

gcov_objects: $(GCOV_OBJECTS) Makefile

$(TAGET): $(OBJECTS) Makefile
	$(AR_RC) $(TAGET) $(OBJECTS)
	$(RAN) $(TAGET)

$(TESTS_TAGET): $(GCOV_OBJECTS) $(INCLUDES)
	$(AR_RC) $(TESTS_TAGET) $(GCOV_OBJECTS)
	$(RAN) $(TESTS_TAGET)

test: $(TAGET) $(TESTS_OBJECTS_DIR)/main.o $(TESTS_OBJECTS) $(TESTS_INCLUDES) Makefile
	$(CC) $(TESTS_OBJECTS) -g $(TESTS_OBJECTS_DIR)/main.o $(SANITAZER) $(GCOV_FLAGS) -o $(TESTS_EXEC) $(TESTS_LIBS) -L. $(TAGET)
	./test

$(TESTS_OBJECTS_DIR)/main.o: main.c 
	@$(MAKE_DIR) $(TESTS_OBJECTS_DIR)
	$(CC) $(CFLAGS) -o $(TESTS_OBJECTS_DIR)/main.o main.c  

$(TESTS_OBJECTS_DIR)%.o: $(TESTS_SOURCES_DIR)%.c $(TESTS_INCLUDES) 
	@$(MAKE_DIR) $(TESTS_OBJECTS_DIR)
	$(CC) $(TESTS_CFLAGS) -o $@ -c $<

$(OBJECTS): $(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c $(INCLUDES) 
	@$(MAKE_DIR) $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

tests_gcov: $(TESTS_TAGET) $(TESTS_OBJECTS_DIR)/main.o $(TESTS_OBJECTS) 
	$(CC) $(TESTS_OBJECTS) $(TESTS_OBJECTS_DIR)/main.o $(GCOV_FLAGS) -o $(TESTS_GCOV_EXEC) $(TESTS_LIBS) -L. $(TESTS_TAGET)

$(GCOV_OBJECTS): $(TESTS_OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c $(TESTS_INCLUDES)
	@$(MAKE_DIR) $(TESTS_OBJECTS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

gcov_report: $(GCOV_TARGET_RCGET)
	gcov -f ./tests/objects/*.gcda
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info  --rc lcov_branch_coverage=1
	sleep 0.5
	open report/index.html

$(GCOV_TARGET_RCGET): CFLAGS += $(GCOV_FLAGS)

$(GCOV_TARGET_RCGET): $(GCOV_INFO)
	genhtml $(GCOV_INFO) -o $(GCOV_TARGET_RCGET)

$(GCOV_INFO): tests_gcov
	./$(TESTS_GCOV_EXEC)
	geninfo $(TESTS_OBJECTS_DIR) -b . -o ./$(GCOV_INFO)

open:
	open coverage/index.html

cpplint:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c ./*.c
	rm ./CPPLINT.cfg

leaks:
	leaks -atExit -- ./$(TESTS_EXEC) 

clean:
	$(RM_DIR) $(OBJECTS)
	$(RM_DIR) $(GCDA)
	$(RM_DIR) $(GCNO)
	$(RM_DIR) $(TESTS_OBJECTS)
	$(RM_DIR) $(TESTS_OBJECTS_DIR)/main.o
	$(RM_DIR) $(GCOV_OBJECTS)
	$(RM_DIR) $(CPPLINT)
	$(RM_DIR) *.gcov *.info

all_clean: clean
	$(RM_DIR) $(TAGET)
	$(RM_DIR) $(TESTS_EXEC)
	$(RM_DIR) $(TESTS_TAGET)
	$(RM_DIR) $(TESTS_GCOV_EXEC)
	$(RM_DIR) $(GCOV_INFO)
	$(RM_DIR) -r $(GCOV_TARGET_RCGET)
	$(RM_DIR) -r report
	$(RM_DIR) -r $(OBJECTS_DIR)

rebuild: all_clean all