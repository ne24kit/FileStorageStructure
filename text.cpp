#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_STR 50

void ReadFile(FILE *fp, char *text[], int *size);

void PrintText(char *text[], int size);

void ClearText(char *text[], int size);

FILE *InitFile(int argc, char *argv[]);
void  CloseFile(FILE * fp, char * filename);

int main(int argc, char *argv[])
{
    FILE * fp = InitFile(argc, argv);

    int n_lines = 0;
    fscanf(fp, "%d\n", &n_lines);

    char **text = (char **)calloc(n_lines, sizeof(char *));
    
    ReadFile(fp, text, &n_lines);

    PrintText(text, n_lines);
    
    ClearText(text, n_lines);

    CloseFile(fp, argv[1]);

    return 0;
}

FILE * InitFile(int argc, char *argv[])
{
    FILE *fp;
    
    if (argc != 2){
        fprintf(stderr, "Write ./a.out <filename.txt>\n");
        exit(0);
    }
    
    if ((fp = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "Сan't open file: <%s>\n", argv[1]);
        exit(0);
    }
    return fp;
}

void ReadFile(FILE *fp, char *text[], int *size)
{
    int i = 0;

    char buffer[MAX_LEN_STR] = {};
    
    while(fgets(buffer, MAX_LEN_STR, fp) != NULL && (i < *size) ) {
        text[i] = strdup(buffer);
        i++;
    }
    *size = i;
}

void PrintText(char *text[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%s", text[i]);

    printf("\n");
}

void ClearText(char *text[], int size)
{
    for(int i = 0; i < size; i++)
        free(text[i]);
    
    free(text);
}

void CloseFile(FILE * fp, char * filename)
{
    if (fclose(fp) != 0)
        fprintf(stderr, "File close error: <%s>\n", filename);
}