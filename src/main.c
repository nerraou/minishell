#include "minishell.h"

void	prompt(char *_prompt, char **envp)
{
	char	*cmd;
	while (1)
	{
		struct termios tp;
		if (tcgetattr(STDIN_FILENO, &tp))
			perror("tcgetattr");

		tp.c_lflag &= ~ECHO;
		if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp))
			perror("tcsetattr");
		cmd = readline(_prompt);
		if (cmd)
			history(cmd, envp);
	}
}


int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	update_shlvl(envp);
	history(NULL, envp);
	prompt("$minishll ", envp);






	// char *str = strdup("cat -e <<EOF\nA\nB\nEOF");
	char *str = strdup("cat -e <<EOF |");
	t_list *list = list_new();
	int i;
	lexer(str, list);
	i = 0;
	t_element *elem;
	t_token *token;
	elem = list->head;
	// while (i < list->size)
	// {
	// 	token = (t_token *)elem->content;
	// 	if (token->value[0] == '\n')
	// 		printf("value [NEWLINE]; ");
	// 	else
	// 		printf("value [%s]; ", token->value);
	// 	printf("type is %d\n", token->type);
	// 	elem = elem->next;
	// 	i++;
	// }
	t_element *prev;
	while (i < list->size)
	{
		prev = elem->prev;
		if (prev)
		{
			token = (t_token *)prev->content;
			printf("%s -> ", token->value);
		}
		else
			printf("NULL -> ");
		token = (t_token *)elem->content;
		printf("%s\n", token->value);
		elem = elem->next;
		i++;
	}
}
