##
## EPITECH PROJECT, 2023
## B-CPE-200-MPL-2-1-dante-aurelien.baraquin
## File description:
## Makefile
##

CC = gcc
TARGET = ncurses_maze
CFLAGS = -lncurses
SRC = $(wildcard *.c) \
	$(wildcard solver/*.c)

all :	$(TARGET)

$(TARGET) :
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET) -g3

clean :
	rm -rf $(TARGET)

fclean : clean

re : fclean all
