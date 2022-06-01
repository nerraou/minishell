#include "minishell.h"
#include "list.h"
#include <string.h>

int main()
{
	// t_list *list;
	// t_element *elem;
	// int i;

	// i = 0;
	// list = list_new();
	// add_back(list, strdup("first"));
	// add_back(list, strdup("second"));
	// elem = list->head;
	// while (list->size > i)
	// {
	// 	printf("%s\n", elem->content);
	// 	elem = elem->next;
	// 	i++;
	// }
	char *str = strdup("\"hello\" world \"$HOME hi\"          \'test\'");
	t_list *list = list_new();
	int i;
	int len;

	len = 0;
	i = 0;
	while (str[i])
	{
		len = set_d_string(str + i, list);
		if (len == -1)
			len = set_s_string(str + i, list);
		if (len == -1)
			i++;
		else
			i += len;
		i += ft_skip_spaces(str + i);
	}
	i = 0;
	t_element *elem;
	t_token *token;
	elem = list->head;
	while (i < list->size)
	{
		token = (t_token *)elem->content;
		printf("it's a string %s\n", token->value);
		elem = elem->next;
		i++;
	}
}
