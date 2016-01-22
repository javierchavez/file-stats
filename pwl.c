/**
 * @file pwl.c
 * @author Javier Chavez
 * @date January 22, 2016
 * @brief Contains main
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "stats.h"
#include "linkedlist.h"

/**
 * @brief The main entry point to pwl.
 *
 * The main job of main is to call stats read function.
 *
 * @param argc not used.
 * @param argv path to a single file as a string.
 * @return 0 if it was ok
 */
int main(int argc, const char * argv[])
{
    List* list;
    const char* infile;
    FILE* in;
    char* real_path;

    if(argc != 2)
    {
        printf("wrong number of args\n");
        return 1;
    }
    infile = argv[1];

    in = fopen(infile, "rb");
    
    if(in == NULL)
    {
        printf("couldn't open %s for reading\n", infile);
        return 2;
    }
    
    real_path = realpath(infile, NULL);
    
    printf("File: %s\n", real_path);
    free(real_path);

    list = create_empty_node();
    
    read(in, list);
    
    fclose(in);
    /* print to stdbout */
    print_stats(list);
    
    return 0;
}


