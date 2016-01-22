/**
 * @file stats.h
 * @author Javier Chavez
 * @date January 22, 2016
 * @brief Statistics header implementation.
 *
 * The head defines a read function which is passed a file. Once invoked the function 
 * reads the file and prints the statistics. print_stats is a functon to print the stats 
 * given a array of occurrences.
 * 
 */


#ifndef STATS_H
#define STATS_H

#include <stdio.h>
#include "linkedlist.h"

/**
 * @brief Takes a file reads and populates a list.
 *
 * File is read, when a new paragraph is found (defined as: /n/n) 
 * a new node is appended to the linked list.
 * 
 * @param in File pointer to the file that should be read
 * @param node Head node the node will be manipulated as the file is read.
 */
void read(FILE* in, List* node);


/**
 * @brief Prints the statistics of each node 
 *
 * Traverses the linked list, for each node print is called. 
 * 
 * @param node Head node of the list. Needed to traverse entire list.
 */
void print_stats(List* head);

/**
 * @brief Prints the statistics given a array of occurrences
 *
 * This will calculate how many words, characters, and lines, are present in the 
 * count array.
 * @param count Description of the first parameter of the function.
 * @param int representation of what paragraph these stats belong to.
 */
void print(unsigned long count[], int);

#endif
