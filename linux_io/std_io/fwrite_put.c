#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    
    fp = fopen("stdio.log", "w+");
    if (fp == NULL) {
        printf("File create fail...\n");
        return -1; 
    } else {
        printf("File create success...\n");
    }
    
    /* fwrite() function */ 
    char buffer_1[] = "This is fwrite DEMO..."; 
    size_t wr_size = 0; 
    wr_size = fwrite(buffer_1, 1, sizeof(buffer_1), fp); 
    printf("wr_size = %d\n", wr_size); 

    /* fputs() function */ 
    char buffer_2[] = "\nThis is fputs DEMO...\n"; 
    int fputs_status = 0; 
    fputs_status = fputs(buffer_2, fp); 
    printf("fputs_status = %d\n", wr_size); 
    
    /* puts function */
    char buffer_3[] = "This is puts DEMO..."; 
    puts(buffer_3);

    /* fputc function */
    char buffer_4[] = "This is fputc DEMO...\n";
    int ret;
    for (int i = 0; i < sizeof(buffer_4); i++) {
        ret = fputc(buffer_4[i], fp);
        printf("%c", ret);
    }

    /* putc function */
    char buffer_5[] = "This is putc DEMO...\n";
    for (int i = 0; i < sizeof(buffer_5); i++) {
        ret = fputc(buffer_5[i], fp);
        printf("%c", ret);
    }
    
    fclose(fp);   

    return 0; 
}
