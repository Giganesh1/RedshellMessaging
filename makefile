# Compiler and flags
CC = gcc
CFLAGS = -I. -I./messages -Wall -Wextra -Werror

# Source and object files
SRC = main.c
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = my_program

# Default target
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build directory
clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets
.PHONY: all clean
