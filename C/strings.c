/* The contents of the header files will copied to the code
below as one big source file during preprocessing. */
#include <stdio.h>
#include <string.h>

/* When used at the global level, the static keyword acts sort of like
the private modifier by preventing external linkage. */
static int global=999999;


/* char* is used for strings in C */
char* subroutine()
{
    // char* x = "goodbye";       /* This string allocates a pointer on the stack to read-only code segment. */
    static char x[] = "goodbye";  /* This string allocates in a special (writable) array of memory used for static variables */

    return x;
}

/* The static keyword used inside of a function
allows variable to keep its value between invocations.*/
int counter()
{
    static int c=0;
    return c++;
}

/* In this main code segment, srtdup is used to duplicate
the string literal to another area in memory that is writable */
int main(int argc, char *argv[])
{

    char* literal = "hello";
    char* lit2 = "ello";
    char* a = strdup(literal);
    char* b = strdup("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZz");



    /* printf("%ld\n%ld\n%ld\n", literal, lit2, a); */

    /* this printout demonstrates that the variable, a
    is a pointer to the first index in the character array*/
    printf("%s\n", a);
    printf("%s\n", a+1);

    /* this printout demonstrates that the
    strdup'd string's indexes can be iterated
    and that the last index is terminated by a zero */
    int c=0;
    while (a[c] != 0)
    {
        printf("- %c - \n", a[c]);
        c++;
    }

    /* this printout demonstrates that the strdup'd string's indexes can be overwritten*/
    a[0]='y';
    printf("%s\n", a);

    /* this printout enters an 'X' in the cell after the last character*/
    /* a[strlen(a)]='X'; */
    /* printf("%s\n", a); */

    /* in this case the value in the last index happens to be a zero */
    strcpy(b, a);
    printf("%s\n", b);

    /* in this case the value in the last index reflects the b variable declared above*/
    b[strlen(b)]='X';
    printf("%s\n", b);


    char* str = subroutine();
    printf("%s\n", str);

    /* this demonstrates the effect of the static keyword on int c*/
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
