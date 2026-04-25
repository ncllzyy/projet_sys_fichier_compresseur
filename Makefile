# Variables de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/fs.c src/huffman.c
OBJ = $(SRC:.c=.o)
EXEC = gestionnaire

# La règle principale
all: $(EXEC)

# Comment créer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Comment créer les fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pour nettoyer les fichiers inutiles
clean:
	rm -f src/*.o $(EXEC)
