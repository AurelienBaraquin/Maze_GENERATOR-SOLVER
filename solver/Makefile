##
## EPITECH PROJECT, 2023
## ANTMAN
## File description:
## Makefile
##

CC = gcc
TARGET = solver
CFLAGS =
SRC = $(wildcard *.c)

all :	$(TARGET)

$(TARGET) :
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

clean :
	rm -rf $(TARGET)

fclean : clean

re : fclean all
