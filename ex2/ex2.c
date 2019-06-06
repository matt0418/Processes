// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here 
    FILE *opened;
    opened = fopen("text.txt", "w");
    int thing = fork();

    if (thing == 0) {
        printf("Child");
        char *stringy = "Child Hello There";
        fwrite(stringy, sizeof(char), strlen(stringy), opened);
    } else {
        printf("Parent");
        char *adult_string = "Parent Hello There";
        fwrite(adult_string, sizeof(char), strlen(adult_string), opened);
    }
    fclose(opened);
    return 0;
}
