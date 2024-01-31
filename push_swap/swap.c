#include "push_swap.h"

static void swap(t_stack_node **head)
{
    if (NULL == *head || NULL == head)
        return ;
    *head = (*head)->next;
    (*head)->prev->prev;
    (*head)->prev->next = (*head)->next;
    if ((*head) -> next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL; 
}

void    sa(t_stack_node **a, bool checker)
{
    swap(a);
    if(!checker)
    {
        write(1, "sa\n", 3);
    }
}

void    sb(t_stack_node **b, bool checker)
{
    swap(b);
    if(!checker)
    {
        write(1, "sb\n", 3);
    }
}

void    ss(t_stack_node **a,t_stack_node **b, bool checker)
{
    swap(a);
    swap(b);
    if(!checker)
    {
        write(1, "ss\n", 3);
    }
}