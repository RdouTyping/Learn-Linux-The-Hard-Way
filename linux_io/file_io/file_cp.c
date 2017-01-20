#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/* 
 * This a simple version of cp command. 
 */
int main(int argc, char *argv[])
{
    int fd1, fd2;
    ssize_t rd_size;
    char buffer[128];
    
    if (argc != 3) {
        printf("You should enter enter 2 parameters\n"); 
        return -1;
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
        printf("File %d does not exist...\n", fd1);
        return -1; 
    }
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 511); 
    if (fd2 < 0) {
        printf("File %d open fail...\n", fd2);
        return -1; 
    }

    while(read(fd1, buffer, 1))
        write(fd2, buffer, 1);

    close(fd1);
    close(fd2);
    
    return 0; 
}
