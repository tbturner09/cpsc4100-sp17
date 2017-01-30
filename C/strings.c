#include <stdio.h>
#include <string.h>

static int global=999999;



char* subroutine()
{
    // char* x = "goodbye";
    static char x[] = "goodbye";

    return x;
}

int counter()
{
    static int c=0;
    return c++;
}


int main(int argc, char *argv[])
{

    char* literal = "hello";
    char* lit2 = "ello";
    char* a = strdup(literal);
    char* b = strdup("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZz");
    


    /* printf("%ld\n%ld\n%ld\n", literal, lit2, a); */

    printf("%s\n", a);
    printf("%s\n", a+1);

    int c=0;
    while (a[c] != 0)
    {
        printf("- %c - \n", a[c]);
        c++;
    }

    a[0]='y';
    printf("%s\n", a);

    /* a[strlen(a)]='X'; */
    /* printf("%s\n", a); */

    strcpy(b, a);
    printf("%s\n", b);

    b[strlen(b)]='X';
    printf("%s\n", b);


    char* str = subroutine();
    printf("%s\n", str);

    printf("counter: %d\n", counter());
    printf("counter: %d\n", counter());
    printf("counter: %d\n", counter());
    printf("counter: %d\n", counter());
    printf("counter: %d\n", counter());
    printf("counter: %d\n", counter());
    printf("counter: %d\n", counter());
    printf("counter: %d\n", counter());
    printf("counter: %d\n", counter());
    printf("counter: %d\n", counter());

    return 0;
}
