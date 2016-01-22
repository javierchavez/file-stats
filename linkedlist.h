/**
 * @file linkedlist.h
 * @author Javier Chavez
 * @date January 22, 2016
 * @brief Linked list implementation.
 *
 * The Linked List is very simple and standard implementation. Uses a Node with a link
 * to another. 
 */

#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Use brief, otherwise the index won't have a brief explanation.
 *
 * The Node holds an array used to store occurrences of characters, also note
 * that the array is 256 in length. The index has a dual purpose, one to serve as
 * an index and two to server as the deciaml representation of a given character.
 * The data at the index is the occurrences of that character(index).
 */
struct Node
{
    unsigned long occurrences[256];
    struct Node* next;
};

typedef struct Node List;

/**
 * @brief Add a node to the end of the linked list.
 *
 * The function traverses the linked list until the end is reached then adds the node
 * to the end
 *
 * @param head Head of the list
 * @param node Node to be added to end
 */
void add_last(List* head, List* node);

/**
 * @brief Remove and return the element that was removed from list.
 *
 * Poll will remove the head of the list and return what was removed.
 *
 * @param head address to Head of the list. 
 * @return New Node containing the idetical data that was in the node 
 * that was removed.
 */
List* poll(List** head);

/**
 * @brief Create a node with no values.
 *
 * Detailed explanation.
 *
 * @return A empty node. Not connected to anything
 */
List* create_empty_node();

/**
 * @brief Creats a node that is filled with given data.
 *
 * First creates a empty node, then copies that data to the node.
 * 
 * @param data Data that is to be copied to the node.
 * @return Node containing no links but filled with array.
 */
List* create_node(unsigned long data[]);

/**
 * @brief Get the length of the linked list.
 *
 * Iterates through the list and counts how many nodes are present.
 *
 * @param head Head of the list.
 * @return int representaion of how many nodes present in the list.
 */
int length(List* head);


#endif
