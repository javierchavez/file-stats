/**
 * @file linkedlist.c
 * @author Javier Chavez
 * @date January 22, 2016
 * @brief Linkedlist implementation.
 *
 */


#include "linkedlist.h"



int length ( List* head )
{
    List* current = head ;
    int len = 0;
    /* traverse the list */
    while ( current != NULL )
    {
        len++;
        current = current->next;
    }
    return len;
}


void add_last ( List* head, List* node)
{
    List* current = head;

    /* traverse the list to find end */
    while ( current->next != NULL )
    {
        current = current->next;
    }

    /* add the link to the last node */
    current->next = node;
}


List* poll(List** head)
{
    List* node = *head;
    unsigned long old_data[ASCII_MAX] = {0};
    /* copy the data to a new node */
    memcpy(old_data, node->occurrences, ASCII_MAX * sizeof(unsigned long));
    
    *head = node->next;
    /* remove the node from mem */
    free(node);
    
    return create_node(old_data);
}


List* create_empty_node()
{
    List* node = malloc(sizeof(List));
    int i = 0;

    if(node == NULL)
    {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(-1);
    }
    /* initialize next to null */
    node->next = NULL;
    /* initialize to 0 */
    for (i = 0; i < ASCII_MAX; i++)
    {
        node->occurrences[i] = 0;
    }


    return node;
}

List* create_node(unsigned long data[])
{
    List* node = create_empty_node();
    
    memcpy(node->occurrences, data, ASCII_MAX*sizeof(unsigned long));
    
    return node;
}

