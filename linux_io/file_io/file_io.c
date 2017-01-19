#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * This is a simple example for using open(), write(), read(), lseek() and close().
 */
int main(int argc, char *argv[])
{
    int fd;
    ssize_t wr_size, rd_size;
    char buffer[128];
    char string_1[30], string_2[30] = "This is the second line!\n";
    char *path = "./file_io.log"; 
    
    fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 511);
    if (fd < 0) {
        printf("File create fail...\n");
        return -1; 
    } else {
        printf("File create success...\n");
    }
    
    /* write the first line to file_io.log */
    strcpy(string_1, "This is a demo for file_io!\n");
    wr_size = write(fd, string_1, strlen(string_1));
    if (wr_size < 0) {
        printf("File write 1 fail...\n");
        printf("wr_size = %d\n", wr_size);
        return -1; 
    } else {
        printf("File write 1 success...\n");
        printf("wr_size = %d\n", wr_size);
    }
    
    /* write the second line to file_io.log 
     * in this case, we only write 10 bytes data from string_2 to file.
     */
    wr_size = write(fd, string_2, 10);
    /* add "\0"(not '\0'!!) to the end of the second line */ 
    wr_size = write(fd, "\0", 1);
    if (wr_size < 0) {
        printf("File write 2 fail...\n");
        printf("wr_size = %d\n", wr_size);
        return -1; 
    } else {
        printf("File write 2 success...\n");
        printf("wr_size = %d\n", wr_size);
    }
    
    lseek(fd, -20, SEEK_CUR);

    rd_size = read(fd, buffer, 100); 
    if (rd_size < 0) {
        printf("File read_1 fail...\n");
        printf("rd_size = %d\n", rd_size);
        return -1; 
    } else {
        printf("File read_1 success...\n");
        printf("rd_size = %d,\nbuffer = %s\n", rd_size, buffer);
    } 

    close(fd);
    
    return 0; 
}
