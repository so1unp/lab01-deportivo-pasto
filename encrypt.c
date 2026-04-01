#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    unsigned char c;

    while (read(STDIN_FILENO, &c, 1) > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            unsigned char b = rand();
            write(STDOUT_FILENO, &b, 1);
        }
        write(STDOUT_FILENO, &c, 1);
        
    }

    exit(EXIT_SUCCESS);
}

