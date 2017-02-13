/* One possible approach to building objects (data + methods) in C using macros.
   Craig Tanis
   Wed Feb 10 11:04:02 2016
*/


#include <stdio.h>


/* -- the `foo' class -- order of these parts matters */

/* definition of struct with instance data and methods

   no overloading
   no inheritance
 */
typedef struct foo
{
    int value;
    void (*setValue)(struct foo*,int);
    int (*getValue)(struct foo*);

} foo;


/* a method definition */
void foo_setValue(foo* this, int value)
{
    this->value=value;
}

/* a method definition */
int foo_getValue(foo* this)
{
    return this->value;
}

/* a constructor
   initializes instance variables
   makes sure method fields are bound to the right function pointers
 */
void foo_construct(foo* this, int value)
{
    this->setValue = foo_setValue;
    this->getValue = foo_getValue;
    this->value = value;
}

/* -- end `foo' class */


/* generic object construction and manipulation macros */
#define NEW(class, obj, ...) class obj; class ## _construct(&obj, ## __VA_ARGS__)
#define METHOD(this, method, ...) this.method(&this, ## __VA_ARGS__)


int main(int argc, char *argv[])
{
    /* this macro expansion declares struct myfoo in the current scope, and
     * calls the constructor associated with the class */
    NEW(foo, myfoo, 100);


    /* see, it's a real data structure with a size... */
    printf("size: %lu\n", sizeof(myfoo));


    /* call the getValue method */
    printf("initial: %d\n", METHOD(myfoo, getValue));


    /* change value with this other macro call, and print out the changed
     * result */
    METHOD(myfoo, setValue, 10);
    printf("changed: %d\n", METHOD(myfoo, getValue));

    /* the above macros expand to something much like this: */
    myfoo.setValue(&myfoo, 99);
    printf("changed differently: %d\n", myfoo.getValue(&myfoo));


    return 0;
}

