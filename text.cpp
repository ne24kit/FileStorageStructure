#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_STR 50
#define MAX_NUM_STR 25

int ReadFile(FILE * fp, char * text[]);

void PrintText(char * text[], int size);

void ClearText(char *text[], int size);

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

    char *text[MAX_NUM_STR] = {};

    int size = ReadFile(fp, text);
    
    PrintText(text, size);
    
    ClearText(text, size);

    if (fclose(fp) != 0)
        fprintf(stderr, "File close error: <%s>\n", filename);
    
    return 0;
}

int ReadFile(FILE * fp, char * text[])
{
    int i = 0;

    char buffer[MAX_LEN_STR] = {};
    
    while(fgets(buffer, MAX_LEN_STR, fp) != NULL) {
        text[i] = strdup(buffer);
        i++;
    }
    
    return i;
}

void PrintText(char * text[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%s", text[i]);

    printf("\n");
}

void ClearText(char *text[], int size)
{
    for(int i = 0; i < size; i++)
        free(text[i]);
}