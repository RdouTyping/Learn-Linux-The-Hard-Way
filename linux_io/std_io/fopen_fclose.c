#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    fp = fopen("stdio.log", "r+");
    //fp = fopen("stdio.log", "w+");
    if (fp == NULL) {
        printf("File create fail...\n");
        return -1; 
    } else {
        printf("File create success...\n");
    }
    
    fclose(fp);   

    return 0; 
}
