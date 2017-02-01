#include <stdio.h>
#include <math.h>


void do_it()
{
    printf("in a subroutine\n");
}

typedef void (*funcptr)();


double calculate(int a, int b)
{
    printf("%d - %d\n", a, b);
    return sqrt(a+b);
}

typedef double (*calcptr)(int, int);


void do_something(funcptr f, int count)
{
    int c=0;
    for (c=0; c<count; c++)
    {
        f();
    }
}



int main(int argc, char *argv[])
{
    //do_it();
    // void (*func)() = do_it;

    funcptr func = do_it;


    double (*calc)(int,int) = calculate;


    printf("%ld\n", func);

    func();

    printf("%lf\n", calc(4,5));

    do_something(func, 5);
    
    printf("%d\n", calc);
    do_something(calc, 5);

    return 0;
}
