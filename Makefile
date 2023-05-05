##
## EPITECH PROJECT, 2023
## ANTMAN
## File description:
## Makefile
##

all :
	make re -C solver/
	make re -C generator/

clean:
	make clean -C solver/
	make clean -C generator/

fclean:
	make clean -C solver/
	make clean -C generator/

re:	all
