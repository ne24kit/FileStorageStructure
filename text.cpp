#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN_STR 51
#define MAX_NUM_STR 20

char * AddressElem(char * data, int j, int i);

int ReadFile(FILE * fp, char * text);
void PrintText(char * text, int size);

char * AddressElem(char * data, int j, int i)
{
	return data + j * MAX_LEN_STR + i;
}

int ReadFile(FILE * fp, char * text)
{
    int size = 0;
    
    while(fgets(AddressElem(text, size, 0), MAX_LEN_STR, fp) != NULL)
        size++;
    return size;
}

void PrintText(char * text, int size)
{
    for(int i = 0; i < size; i++)
        printf("%s", AddressElem(text, i, 0));

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

    char *text = (char *)calloc(MAX_NUM_STR, sizeof(char) * MAX_LEN_STR);

    PrintText(text, ReadFile(fp, text));

    free(text);

    if (fclose(fp) != 0)
        fprintf(stderr, "File close error: <%s>\n", filename);
    
    return 0;
}

