#include <stdio.h>

int main(int argc, char *argv[])
{

#if 0
    j;lskdjga;kdsjfv;aklsdjv;ai    printf("in a conditionally compiled part\n");
#endif

#ifdef DEBUG
    printf("in debug mode\n");
#endif
    
#warning you should not be compiling this


    printf("after that thing\n");


    return 0;
}
