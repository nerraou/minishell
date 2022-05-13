NAME = minishell
CFLAGS = -Wall -Wextra -Werror 
HEADERS = ./includes/minishell.h

SRC =  src/test.c\
		src/main.c


OBJ =  $(SRC:.c=.o)

INCLUDES_PATH = -I./includes/

all: $(NAME)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) $(INCLUDES_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	gcc -o $(NAME) $^ $(INCLUDES_PATH) 

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_BONUS)

re: fclean all