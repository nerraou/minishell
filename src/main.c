#include "minishell.h"
#include "parser.h"
#include <string.h>

// line = readline("$> ");
// result = parser(line, list, &heredoc_num);
// elm = list->head;

// while (elm)
// {
// 	token = (t_token *)elm->content;
// 	printf("%s \n", token->value);
// 	elm = elm->next;
// }

int main()
{

	char *line;
	int result;
	int heredoc_num = 0;
	t_list *list;
	t_list *heredoc_list;
	t_element *elm;
	list = list_new();

	while (1)
	{
		line = readline("$> ");
		result = parser(line, list, &heredoc_num);

		if (result == FT_SUCCESS)
		{
			// execute(cmd);
			printf("THIS MUS BE EXECUTED \n");
			return 0;
		}
		else if (result == FT_FAILURE)
		{
			// cmd = ft_strdup("");
			printf("IT'S FAILURE MUST TRY AGIN \n");
			return 1;
		}
		else if (result == FT_REPROMPT)
		{
			heredoc_list = heredoc(&heredoc_num, list);
		}
		if (heredoc_num == 0)
			break;
	}
	elm = heredoc_list->head;
	printf("----------------heredoc list content---------------\n");
	while (elm)
	{
		printf("%s", (char *)elm->content);
		elm = elm->next;
	}
}
