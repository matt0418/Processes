// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 10;
    printf("Parent ID is %d\n", (int) getpid());
    int forky = fork();
    if (forky == 0) {
        printf("This is the child process and this is my ID: %d\n", (int) getpid());
        printf("This is the value of X from before %d\n", x);
        x *= 2;
        printf("Now this is the value of X %d\n", x);
    } else {
        printf("This is the parent process");
        printf("This is the current value of X %d\n", x);
        x++;
        printf("This is the value of X now %d\n", x);
    }

    return 0;
}

// int main(void)
// {
//     int x = 100;
//     printf("hello world (pid: %d)\n", (int) getpid());

//     int rc = fork();

//     if (rc < 0) {
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {
//         printf("hello, I am child (pid: %d) and x is: %d\n", (int) getpid(), x);
//         x++;
//         printf("child again, x is now: %d\n", x);
//     } else {
//         printf("hello, I am parent of %d (pid: %d) and x is: %d\n", rc, (int) getpid(), x);
//         x--;
//         printf("parent again, x is now: %d\n", x);
//     }

//     return 0;
// }
