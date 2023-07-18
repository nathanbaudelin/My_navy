##
## EPITECH PROJECT, 2022
## B-MUL-100-LYN-1-1-myradar-pierre.giordano
## File description:
## Makefile
##

NAME	=	navy

SRC =	src/main.c \
		src/boat.c	\
		src/map.c	\
		src/navy.c	\
		src/signal.c	\
		src/signal_mess.c	\
		src/recup_input.c	\
		src/display.c	\
		src/conditions.c	\
		src/fonctions_utiles.c	\

OBJ = $(SRC:.c=.o)

CC = gcc

RM = rm -Rf

CFLAGS = -L lib/printf/. -lprintf -g3 -Wall -Wextra -lm

PRINTF_CREATE = cd lib/printf && make && cd ../../

PRINTF_CLEAN  = cd lib/printf && make fclean && cd ../../

all:	$(NAME)

$(NAME):
	$(PRINTF_CREATE)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)
	$(PRINTF_CLEAN)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(PRINTF_CLEAN)

re: fclean all

.PHONY:all, clean, fclean, re
