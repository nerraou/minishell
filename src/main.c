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
	char *str = strdup(" >>   << \'test\' word  |              ");
	t_list *list = list_new();
	int i;
	int len;

	len = 0;
	i = 0;
	while (str[i])
	{
		i += ft_skip_spaces(str + i);
		len = set_d_string(str + i, list);
		if (len == -1)
			len = set_s_string(str + i, list);
		if (len == -1)
			len = set_dless(str + i, list);
		if (len == -1)
			len = set_dgreat(str + i, list);
		if (len == -1)
			len = set_great(str + i, list);
		if (len == -1)
			len = set_less(str + i, list);
		if (len == -1)
			len = set_pipe(str + i, list);
		if (len == -1)
			len = set_word(str + i, list);
		if (str[i] && len == -1)
			i++;
		else if (str[i])
			i += len;
	}
	i = 0;
	t_element *elem;
	t_token *token;
	elem = list->head;
	while (i < list->size)
	{
		token = (t_token *)elem->content;
		printf("value [%s]; ", token->value);
		printf("type is %d\n", token->type);
		elem = elem->next;
		i++;
	}
}
