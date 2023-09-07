#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN_STR 51
#define MAX_NUM_STR 20

int ReadFile(FILE * fp, char text[][MAX_LEN_STR])
{
    int size = 0;
    
    while(fgets(text[size], MAX_LEN_STR, fp) != NULL)
        size++;
    
    return size;
}

void PrintText(char text[][MAX_LEN_STR], int size)
{
    for(int i = 0; i < size; i++)
        printf("%s", text[i]);

    printf("\n");
}

int main(int argc, char *argv[])
{
    FILE *fp;
    
    if (argc != 2){
        fprintf(stderr, "Write ./a.out <filename.txt>\n");
        exit(0);
    }
    
    char *filename = argv[1];
    
    if ((fp = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "Сan't open file: <%s>\n", filename);
        exit(0);
    }

    char text[MAX_NUM_STR][MAX_LEN_STR] = {};

    PrintText(text, ReadFile(fp, text));

    if (fclose(fp) != 0)
        fprintf(stderr, "File close error: <%s>\n", filename);
    
    return 0;
}

