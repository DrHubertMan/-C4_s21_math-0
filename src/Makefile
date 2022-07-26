CC=gcc

GCCFLAGS=Wall Werror Wextra
GFLAG=-g
SANITIZER:=#-fsanitize=address
SAN_G_FLAGS=$(GFLAG) $(SANITIZER) 
TEST_FLAGS=#$(shell pkg-config --cflags check)

SOURCES_DIR=.
OBJECTS_DIR=./obj

TEST_SOURCES_DIR=./tests
TEST_OBJECTS_DIR=./tests/obj

INCLUDES:=$(shell find $(SOURCES_DIR) -maxdepth 1 -name "s21_*.h")
SOURCES:=$(shell find $(SOURCES_DIR) -maxdepth 1 -name "s21_*.c")

TEST_INCLUDES:=$(shell find $(SOURCES_DIR) -maxdepth 1 -name "*.h")
TEST_SOURCES:=$(shell find $(SOURCES_DIR) -maxdepth 1 -name "*.c")

OBJECTS:=$(addprefix $(OBJECTS_DIR)/, $(notdir $(SOURCES:.c=.o)))
TEST_OBJECTS:=$(addprefix $(TEST_OBJECTS_DIR)/, $(notdir $(TEST_SOURCES:.c=.o))) #$(TEST_OBJECTS_DIR)/main.o

AR:= ar rc
RANLIB:= ranlib
RM:=rm -f
MK:=mkdir -p

TARGET?=s21_math.a

all: $(TARGET)


$(TEST_OBJECTS_DIR)/main.o: main.c 
	@$(MK) $(TEST_OBJECTS_DIR)
	$(CC) $(CFLAGS) $(SAN_G_FLAGS) -o $(TEST_OBJECTS_DIR)/main.o main.c  

$(TEST_OBJECTS_DIR)%.o: $(TEST_OBJECTS_DIR)%.c $(TEST_INCLUDES) 
	@$(MK) $(TEST_OBJECTS_DIR)
	$(CC) $(TEST_FLAGS) -o $@ -c $<

$(OBJECTS): $(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c $(INCLUDES) 
	@$(MK) $(OBJECTS_DIR)
	$(CC) $(CFLAGS) $(SAN_G_FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJECTS_DIR)
