#include <stdio.h>
#include <math.h>


#define PI 3.0

#define TIMES10(x)  x*10
#define SQUARE(args) ((args)*(args))

#define SWAP(v1, v2) {int temp=v1; v1=v2; v2=temp; }



int main(int argc, char *argv[])
{
    printf("PI: %lf\n", M_PI);

    printf("--> %d\n", TIMES10(42));

    double d = SQUARE(sqrt(2));
    printf("%lf\n", d);

    double d2 = SQUARE(1+2);
    printf("%lf\n", d2);


    int x=8;
    int y =9;

    SWAP(x,y);

    printf("x: %d\ny: %d\n", x, y);


    int a=1;
    int temp=10;
    SWAP(a,temp);

    printf("a: %d\ntemp: %d\n", a, temp);





    return 0;
}
