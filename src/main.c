#include "minishell.h"

int	empty_prompt(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\n' ||\
		cmd[i] == '\v' || cmd[i] == '\f' || cmd[i] == '\r'))
		i++;
	if (!cmd[i])
		return (1);
	return (0);
}

void	prompt(char *_prompt, char **envp)
{
	char	*cmd;
	while (1)
	{
		struct termios tp;
		if (tcgetattr(STDIN_FILENO, &tp))
			perror("tcgetattr");
		tp.c_lflag &= ~ECHOCTL;
		if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp))
			perror("tcsetattr");
		cmd = readline(_prompt);
		if (!empty_prompt(cmd))
		{
			history(cmd, envp);
			printf("DONE\n");
			/* CHECK syntax => DO parsing */
		}
		free(cmd);
	}
}


int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	update_shlvl(envp);
	history(NULL, envp);
	prompt("$minishll ", envp);


}
