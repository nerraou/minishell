#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	update_shlvl(envp);
	history(NULL, envp);
	prompt("$minishll ", envp);
}
