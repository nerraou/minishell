#include "minishell.h"
#include "list.h"
#include <string.h>

int main()
{
	t_list *list;
	t_element *elem;
	int i;

	i = 0;
	list = list_new();
	add_back(list, strdup("first"));
	add_back(list, strdup("second"));
	elem = list->head;
	while (list->size > i)
	{
		printf("%s\n", elem->content);
		elem = elem->next;
		i++;
	}
}
