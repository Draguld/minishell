NAME=minishell

CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c99

HEADER=-I includes/

SRC=main.c
OBJ=$(SRC:.c=.o)

RM=rm -f

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME) $(HEADER)

DEBUG:
	$(CC) -g $(CFLAGS) -c $(SRC) $(HEADER)
	$(CC) -g $(CFLAGS) $(OBJ) libft.a -o $(NAME) $(HEADER)

all: $(NAME)

nflag:
	$(CC) -c $(SRC) $(HEADER)
	$(CC) $(OBJ) libft.a -o $(NAME) $(HEADER)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
