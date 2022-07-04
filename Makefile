NAME = minishell
CFLAGS = -Wall -Wextra -Werror -g
HEADERS = ./includes/minishell.h
READLINE = -L /goinfre/$(USER)/.brew/opt/readline/lib -lreadline
READLINE_INCLUDE = -I /goinfre/$(USER)/.brew/opt/readline/include
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
	src/libft/ft_strcmp.c\
	src/libft/ft_strncpy.c\
	src/libft/ft_substr.c\
	src/libft/ft_strjoin.c\
	src/libft/ft_strlcpy.c\
	src/libft/ft_memcpy.c\
	src/libft/is_long.c\
	src/libft/ft_atol.c\
	src/libft/ft_isalnum.c\
	src/libft/ft_isalpha.c\
	src/libft/ft_isdigit.c\
	src/libft/ft_putchar_fd.c\
	src/libft/ft_putstr_fd.c\
	src/libft/ft_putendl_fd.c\
	src/libft/ft_split.c\
	src/libft/ft_tolower.c\
\
	src/lexer/ft_new_token.c\
	src/lexer/del_token.c\
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
	src/lexer/is_joinable.c\
\
	src/list/add_back.c\
	src/list/add_front.c\
	src/list/elem_new.c\
	src/list/list_del.c\
	src/list/list_new.c\
	src/list/del_element.c\
\
	src/parser/expect.c\
	src/parser/is_dless.c\
	src/parser/is_separator.c\
	src/parser/is_redirection.c\
	src/parser/is_word_string.c\
	src/parser/separator_expect.c\
	src/parser/symbol_expect.c\
	src/parser/dless_expect.c\
	src/parser/check_start.c\
	src/parser/print_syntax_error.c\
	src/parser/move_heredoc_content.c\
	src/parser/parser.c\
	src/parser/heredoc.c\
	src/parser/is_parentheses_balanced.c\
	src/parser/lparenthesis_expect.c\
	src/parser/rparenthesis_expect.c\
	src/parser/is_l_parenthesis.c\
	src/parser/is_r_parenthesis.c\
	src/parser/wordstring_expect.c\
\
	src/builtins/env.c\
	src/builtins/ft_echo.c\
	src/builtins/export.c\
	src/builtins/unset.c\
	src/builtins/pwd.c\
	src/builtins/cd.c\
	src/builtins/ft_exit.c\
	src/builtins/is_var_name.c\
\
	src/env/init_env.c\
	src/env/new_env.c\
	src/env/del_env.c\
	src/env/ft_getenv.c\
	src/env/ft_setenv.c\
	src/env/ft_unsetenv.c\
	src/env/list_to_array.c\
	src/env/sort_array.c\
\
	src/get_next_line/get_next_line.c\
	src/get_next_line/get_next_line_utils.c\
\
	src/initialing/history.c\
	src/initialing/prompt.c\
\
	src/execute/priority.c\
	src/execute/expanding.c\
	src/execute/expanding_utils.c\
	src/execute/env_value.c\
	src/execute/execute.c\
	src/execute/execute_utils.c\
	src/execute/dividing_cmd.c\
	src/execute/join.c\
	src/execute/io_files.c\
	src/execute/fork.c\
	src/execute/args.c\
	src/execute/check_cmd.c\
	src/execute/check_cmd_utils.c\
	src/execute/handling.c\
	src/execute/wildcard.c\
	src/execute/wildcard_utils.c\
	src/execute/open_file.c\
	src/execute/built.c\
	src/execute/error_msg.c\
	src/execute/forking.c\
\
	src/main.c\

OBJ =  $(SRC:.c=.o)

INCLUDES_PATH = -I./includes/

all: $(NAME)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) $(INCLUDES_PATH) $(READLINE_INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(READLINE) $^ $(INCLUDES_PATH)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_BONUS)

re: fclean all