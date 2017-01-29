#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    
    fp = fopen("stdio.log", "r+");
    if (fp == NULL) {
        printf("File open fail...\n");
        return -1; 
    } else {
        printf("File open success...\n");
    }
    
    /* fread() function */ 
    char buffer_1[50]; 
    size_t rd_size = 0; 
    rd_size = fread(buffer_1, 1, 24, fp); 
    printf("rd_size = %d\n", rd_size); 
    printf("fread get: %s\n", buffer_1);

    /* fgets() function */ 
    char buffer_2[50];
    char *fgets_status; 
    fgets_status = fgets(buffer_2, 23, fp); 
    printf("fgets_status = %s", fgets_status); 
    printf("fgets get: %s", buffer_2);
    
    /* gets function */
    char buffer_3[50];
    gets(buffer_3);
    printf("gets get: %s", buffer_3);

    /* fgetc function */
    int ret;
    while ((ret = fgetc(fp)) != EOF)
       printf("%c", ret);

    fclose(fp);   

    return 0; 
}
