#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    unsigned char c;
    int contador = 0;

    while (read(STDIN_FILENO, &c, 1) > 0)
    {
        contador++;
        if (contador == 8)
        {
            write(STDOUT_FILENO, &c, 1);
            contador = 0;
        }
    }

    exit(EXIT_SUCCESS);
}
