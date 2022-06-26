#include "minishell.h"


int main(int argc, char **argv, char **envp)
{
	int	in;

	in = dup(STDIN_FILENO);
	(void)argc;
	(void)argv;
	signal(SIGINT, sig_handel);
	signal(SIGQUIT, sig_handel);
	update_shlvl(envp);
	history(NULL, envp);
	prompt("MiniShell_$ ", envp, in);
	return (0);
}
