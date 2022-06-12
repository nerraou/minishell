NAME = minishell
CFLAGS = -Wall -Wextra -Werror
HEADERS = ./includes/minishell.h

SRC =\
	src/libft/ft_atoi.c\
	src/libft/ft_indexof.c\
	src/libft/ft_isspace.c\
	src/libft/ft_itoa.c\
	src/libft/ft_malloc.c\
	src/libft/ft_memset.c\
	src/libft/ft_strdup.c\
	src/libft/ft_strlen.c\
	src/libft/ft_strncmp.c\
	src/libft/ft_strncpy.c\
	src/libft/ft_substr.c\
	src/libft/ft_strjoin.c\
	src/libft/ft_strlcpy.c\
	src/libft/ft_memcpy.c\
	src/libft/ft_isalnum.c\
	src/libft/ft_isalpha.c\
	src/libft/ft_isdigit.c\
\
	src/lexer/ft_new_token.c\
	src/lexer/ft_skip_spaces.c\
	src/lexer/lexer.c\
	src/lexer/set_d_string.c\
	src/lexer/set_dgreat.c\
	src/lexer/set_dless.c\
	src/lexer/set_great.c\
	src/lexer/set_less.c\
	src/lexer/set_newline.c\
	src/lexer/set_pipe.c\
	src/lexer/set_s_string.c\
	src/lexer/set_word.c\
	src/lexer/set_or.c\
	src/lexer/set_and.c\
	src/lexer/set_l_parenth.c \
	src/lexer/set_r_parenth.c \
\
	src/list/add_back.c\
	src/list/add_front.c\
	src/list/elem_new.c\
	src/list/list_del.c\
	src/list/list_new.c\
\
	src/get_next_line/get_next_line.c\
	src/get_next_line/get_next_line_utils.c\
\
	src/initialing/shlvl.c\
	src/initialing/history.c\
	src/initialing/prompt.c\
\
	src/execute/execut.c\
	src/execute/expanding.c\
	src/execute/env_value.c\
	src/execute/cmd_exe.c\
	src/execute/dividing_cmd.c\
\
	src/main.c\

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