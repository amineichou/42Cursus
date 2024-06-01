#include <libc.h>
#include <stdbool.h>

volatile bool done = false;

int main(void)
{
    printf("Waiting...\n");
    while(!done)
    {
        sleep(1);
    }
    printf("Done\n");
}
