#include "minishell.h"
#include "list.h"
#include <string.h>

int main()
{

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
