#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	if (NULL == *head || NULL == (*head)->next)
		return ;
    t_stack_node *first = *head;
	t_stack_node *second = (*head)->next;
    if (first->prev)
		first->prev->next = second;
	if (second->next)
        second->next->prev = first;
    first->next = second->next;
    second->prev = first->prev;
    first->prev = second;
    second->next = first;
    *head = second;
}

void	sa(t_stack_node **a, bool checker)
{
	swap(a);
	if (!checker)
	{
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
	{
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
	{
		write(1, "ss\n", 3);
	}
}