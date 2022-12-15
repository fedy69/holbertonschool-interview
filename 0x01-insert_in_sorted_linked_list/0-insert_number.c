#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Function
 * Return: new node, or NULL
 * @head: Pointer to the pointer
 * @number: Data
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *p, *node;


    node = (listint_t *)malloc(sizeof(listint_t));
    if(node)
    {
        node->n = number;
        node->next = NULL;
    }
    else
    {
        free(node);
        return(NULL);
    }
    if(head == NULL || number <= 0)
    {
        return NULL;
    }
    if(*head == NULL )
    {
        *head = node;
        return(*head);
    }
    p = *head;
    if(p->n >= number)
    {
        node->next = p;
        *head = node;
        return(*head);
    }
    while(p->next)
    {
        if(number >= p->n && number < p->next->n)
        {
            node->next = p->next;
            p->next = node;
            return(node);
        }
        p = p->next;
    }
    p->next = node;
    return(node);
}
