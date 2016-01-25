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
 * The main job of main is to call stats read function. On execution of the program,
 * an absolute path is printed out. File is then read and closed, and stats are
 * printed to stdout. Errors are printed out if 1. the user does not supply 
 * the correct number of args, 2. if the file cannot be opened. 
 *
 * @param argc is only used to make sure the user entered correct number of args.
 * @param argv a path to a single file as a string needs to be added.
 * @return 0 if it was ok
 */
int main(int argc, const char * argv[])
{
    List* list;
    const char* infile;
    FILE* in;
    char* real_path;
    char *realpath(const char *path, char *resolved_path);
    
    if(argc != 2)
    {
        fprintf(stderr, "wrong number of args. ./program path-to-file.txt\n");
        return 1;
    }
    infile = argv[1];

    in = fopen(infile, "rb");
    
    if(in == NULL)
    {
        fprintf(stderr, "couldn't open %s for reading\n", infile);
        return 2;
    }
    
    real_path = realpath(infile, NULL);

    /* print the path of the file */
    printf("File %7s %s\n", ":", real_path);
    free(real_path);

    /* create a list */
    list = create_empty_node();
    
    /* call the stats read function */
    read(in, list);
    
    fclose(in);
    
    /* print to stdbout */
    print_stats(list);
    
    return 0;
}


