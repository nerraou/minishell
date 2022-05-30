NAME = minishell
CFLAGS = -Wall -Wextra -Werror 
HEADERS = ./includes/minishell.h

SRC = src/list/add_back.c\
		src/list/add_front.c\
		src/list/elem_new.c\
		src/list/list_del.c\
		src/list/list_new.c\
		src/main.c

OBJ =  $(SRC:.c=.o)

INCLUDES_PATH = -I./includes/

all: $(NAME)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) $(INCLUDES_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	gcc -o $(NAME) $^ $(INCLUDES_PATH) -lreadline -lncurses

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_BONUS)

re: fclean all