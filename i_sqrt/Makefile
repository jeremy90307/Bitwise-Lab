PROJ := i_sqrt
SRC := $(PROJ).c
OBJ := $(PROJ)
all:
	$(CC) -o $(OBJ) $(SRC) -lm
format:
	clang-format -i $(SRC)
clean:
	$(RM) $(OBJ)

