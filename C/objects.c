#include <stdio.h>

#define NEW(class, instance, ...) class instance; class ##_construct(&instance, ##__VA_ARGS__)
#define METHOD(this, method, ...) this.method(&this, ##__VA_ARGS__)

int global=3;

typedef struct foo
{
    int value;
    int (*getValue)(struct foo*);
    void (*setValue)(struct foo*,int v);
} foo;


void foo_setValue(foo* f, int v)
{
    f->value = v;
}

int foo_getValue(foo* f)
{
    return f->value;
}


void foo_construct(foo* f)
{
    f->value=0;
    f->getValue = foo_getValue;
    f->setValue = foo_setValue;
}




int main(int argc, char *argv[])
{
    /* foo f1; */
    /* foo_construct(&f1); */

    NEW(foo, f1);

    f1.value = 3;
    printf("%d\n", f1.value);

    foo_setValue(&f1, 100);
    printf("%d\n", f1.value);

    // f1.setValue(200)
    METHOD(f1, setValue, 900);
    printf("%d\n", f1.value);
    printf("%d\n", METHOD(f1, getValue));


    return 0;
}
