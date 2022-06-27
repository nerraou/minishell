/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:18:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/27 19:18:07 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// #include <stdbool.h>
// #include <stdio.h>
// #include <string.h>

// bool strmatch(char str[], char pattern[], int n, int m)
// {

//     bool lookup[n + 1][m + 1];

//     memset(lookup, false, sizeof(lookup));

//     lookup[0][0] = true;

//     for (int j = 1; j <= m; j++)
//         if (pattern[j - 1] == '*')
//             lookup[0][j] = lookup[0][j - 1];


//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {

//      		if (str[i - 1] == pattern[j - 1])
//                 lookup[i][j] = lookup[i - 1][j - 1];
//            	else  if (pattern[j - 1] == '*')
//                 lookup[i][j]= lookup[i][j - 1] || lookup[i - 1][j];
//         }
//     }
//     return lookup[n][m];
// }

// int main()
// {
//     char str[] = "baaabab";
//     char pattern[] = "*****ba*****ab";
//     // char pattern[] = "ba*****ab";
//     // char pattern[] = "ba*ab";
//     // char pattern[] = "a*ab";
//     // char pattern[] = "a*****ab";
//     // char pattern[] = "*a*****ab";
//     // char pattern[] = "ba*ab****";
//     // char pattern[] = "****";
//     // char pattern[] = "*";
//     // char pattern[] = "aa?ab";
//     // char pattern[] = "b*b";
//     // char pattern[] = "a*a";
//     // char pattern[] = "baaabab";
//     // char pattern[] = "?baaabab";
//     // char pattern[] = "*baaaba*";

//     if (strmatch(str, pattern, strlen(str), strlen(pattern)))
//         printf("YES\n");
//     else
//         printf("N0\n");
//     return 0;
// }