NAME = minishell
CFLAGS = -Wall -Wextra -Werror 
HEADERS = ./includes/minishell.h

SRC = src/list/add_back.c\
		src/list/add_front.c\
		src/list/elem_new.c\
		src/list/list_del.c\
		src/list/list_new.c\
		src/list/list_new.c\
		src/libft/ft_substr.c\
		src/libft/ft_strncpy.c\
		src/libft/ft_strlen.c\
		src/libft/ft_isspace.c\
		src/libft/ft_strdup.c\
		src/libft/ft_strncmp.c\
		src/libft/ft_malloc.c\
		src/libft/ft_memset.c\
		src/lexer/lexer.c\
		src/lexer/set_newline.c\
		src/lexer/set_d_string.c\
		src/lexer/set_s_string.c\
		src/lexer/set_less.c\
		src/lexer/set_great.c\
		src/lexer/set_dless.c\
		src/lexer/set_dgreat.c\
		src/lexer/set_pipe.c\
		src/lexer/set_word.c\
		src/lexer/ft_skip_spaces.c\
		src/lexer/ft_new_token.c\
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