#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	FIFO = 1,
	LIFO = 2
} type;

typedef struct s_node {
	int				value;
	// char			*pos;
	// int 			status;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// t_node *create(int value, char *pos)
t_node *create(int value)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	// node->pos = pos;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node *last_node(t_node *head)
{
	t_node *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void del_node(t_node **head, type x)
{
	t_node *tmp;

	tmp = *head;
	if (!(*head)->next)
	{
		*head = NULL;
		return ;
	}
	if (x == FIFO)
		*head = tmp->next;
	else if (x == LIFO)
	{
		tmp = last_node(tmp)->prev;
		tmp->next = NULL;
	}
}

void add_tail(t_node **old, t_node *new)
{
	new->next = *old;
	if (*old)
		(*old)->prev = new;
	*old = new;
}

void print(t_node *head)
{
	t_node *tmp;

	tmp = head;
	while (tmp)
	{
		// printf("%s -> %d - %d\n", tmp->pos, tmp->value, tmp->status);
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

void add_head(t_node **old, t_node *new)
{
	t_node *tmp;

	if (*old == NULL)
	{
		*old = new;
		return ;
	}
	tmp = last_node(*old);
	new->prev = tmp;
	tmp->next = new;
}

/**
 * @brief list functions
 * add current pos to queue
 * pop current pos to visited list
 * add adjacent pos to queue
 * repeat
*/

int main()
{

	t_node *queue;
	int vals[4] = {1,2,3,4};
	int grid[4][4] = {
		1,2,3,4,
		5,6,7,8,
		9,10,11,12,
		13,14,15,16,
	};
	int i = 0;

	queue = (t_node *)malloc(sizeof(t_node));
	queue = NULL;
	while (i < 4)
	{
		add_head(&queue, create(vals[i]));
		i++;
	}
	add_tail(&queue, create(9));

	print(queue);
	return (0);
}
