## Points and Arrays
    Pointer is a variable that contains the address of a variable

    Pointers are often used in C:
        Makes some computations easier to express
        Lead to more compaact and efficient code


    The type void * pointer replaces char * as the proper type for a generic pointer


#### 5.1 Pointers and Addresses
    A typical machine has an array of consecutively numbered or addressed memory cells

    Any byte can be a __char__ type

    A pair of bytes can be treated as __short__

    four adjacent ones can be a __long__

    A __pointer__ is a group of cells that can hold an address.

    We can assume that on most 32 bit machines a pointer represents 4 bytes and 8 on 64


    p = &c; /* assigns the addrse of c to the variable p */


    P then is said to point to c

    & only applies to objects within memory (variables and array elements)

    It cannot be used with:
        * Expressions
        * Constants
        * Register variables

    The unary operator _*_ is the __indrection__ or __dereferencing__ operator

    When used with a point it accesses the value of the pointer

    see example1.c


    The declaration of x, y, and z are what we have seen all along.

    So the declaration of:
    int *ip;

    Is a mnemonic that says that the expression *ip is an int

    The syntax of expressions of declarions for a variables
    must mimic the sytanx of expresssions in which the
    variable might appear

    Example:
        double *dp, atof(char *);

    *Both the function and the pointer have the value double

    A pointer is constrainted to point to a particular type of obj
        * Each have their own data type

    ONE EXCEPTION: void * can point to any pointer, but cannot
        be dereferenced itself

    Example:
        If *ip points to an integer x
            then it can be replaced anywhere x could be used

            *ip = *ip + 10;
        Increments the value of ip by 10;

        The unary operators * and & bind


    ++*ip will increment the value within the pointer
    *ip++ is wrong! it will increment the pointer itself
    (*ip)++ correct since ++ and * evaluate from right to left

    since pointers are variables they can be used without dereferencing

        iq = ip

    copies the contents of ip into iq making iq point to what ip did



#### 5.2 Pointer and Function Arguments
    C passes function arguments by value

    This means there is no direct way to for a function to alter a variable
    within a calling function

    Example
        void swap(int x, int y) {
            int temp;
            temp = x;
            x = y;
            y = temp;
        }
    swap(x, y); /* This is incorrect and will only swap within the function */


    This actually does not affect the arguments that are passed by value
    These are temporary local copies to the function within C

    The way to achieve actually changing the passed arugment values are
    to pass pointers (Pass by reference)

    Example:
        void swap(int *x, int *y) {
            int temp;
            temp = *x;
            *x = *y;
            *y = *temp;
        }
    swap(&a, &b); /* This will achieve the desired result */


    Let us now create a function called getint that will perform
    free-format input conversion

    This will be achieved by breaking a stream of characters into
    integer values, one integer per call.

    getint must return the value it found and also signal EOF

    These values have to be passed back with seperate paths, no matter what value is used for EOF

    *  One solution is to have getint return EOF as function value
    *  While also using a pointer argument to store the converted int
        ^ This same scheme is used by scanf, which will allow us to identify when we are done reading input from STDIN

#### 5.3 Pointers and Arrays
    Any operation that can be done by an array can be done by a pointer as well

    The pointer will be faster/but harder to understand

    The declaration of:
        int a[10];

    defines an array of size 10

    a[i] refers to the i-th element within an array

    if we have:
        int *pa;

    then:
        pa = &a[0];

    sets pa to point to element zero of a

        thus pa = address of a[0]

    then
        x = *pa;

    will copy the contents of a[0] into x

    if pa points to an element in the array

    then pa + 1 points to the next element and pa + i points to the ith element

    pa -i points to i elements before

    thus, if pa points to a[0]

    *(pa + i) points to the ith value of the array

    pa + 1 points to the next object and i points to ith

    pa = &a[0] will have same value and can be re-written as
    pa = a

    a[i] can also be written as *(a + i)

    a[i] already converts it to *(a+i)

    &a[i]  a+i are identical

    p[i] is identical to *(pa + i)

    There is no difference between ab array name and a pointer

    however, a pointer is a variable and,
    pa++ is legal but an array is not a variable so a++ is not legal

    When an array is passed to a function the inital element is passed

    The argument is a local variable

    so
        int strlen(char *s) {
            int n;
            for (n = 0; *s != '\0'; s++)
                n++;
            return n;
        }

    strlen("hellow")
    strlen(array);
    strlen(ptr) are all equivalent

    char s[] and char *s are equivalent however we prefer the latter saying parameter is a pointeer

    we can pass part of an array via a pointer
        f(&a[2])
        f(a+2)

    it is also legal to index backwards in an array but must be within bounds

#### 5.4 Address Arithmetic
    If p is a pointer to an element in an array

    P++ increments p to the next element

    p+= i increments to the ith element beyond it's current position


    Let us illustrate this with an example of two functions
        1) alloc(n) -- returns a pointer p to n-consectuvie character positions
        2) afree(p) -- releases the storage thus acquired so it can be re-used later

    ** Calls to afree must be after calls to alloc

    The storage managed by alloc and afree is a stack or last-in, first-out

    These are malloc and free (however these standard library functions provide no restrictions)
        #define <stdlib.h>
    The way to best implement this is to allow alloc to hand out large pieces of memory on the stack

    The array being used to allocate must not be accessible by any other source file

    In practice this is maintained by malloc and we don't know how it is being handled by the OS

    In order to maintain state information about the allocated buffer we will use a pointer
        this pointer will point to the next free space in the buffer

    When alloc is asked for n characters it will check allocbuf

    if so alloc then returns the current value of allocp(how much it could allocate)

    it then increments the pointer by n (which points to the next free area)

    If there is no room alloc will return zero

    afree(p) then just sets allocp to p if p is inside the allocbuf

    Pointer and integers are not interchangeable

        ** ZERO IS THE SOLE EXCEPTION**

    The constant zero maby be assigned to a pointer
    A pointer can also be compared to the constant 0
    NULL however is often used in place of zero for a special value of pointer
        #define <stdio.h>

    pointers are interesting if you have p & q which point to various locations
        p < q and other conditionals will work

    any pointer can be compared to zero, but the implementation is undefined for anything past the bounds


    the construction:
        p+n
    means the address for the n-th object beyond one p currently points to.

    in this case the pointer p has a the value n added to it
        p + n = p + (n * sizeof(value));

    pointer subtraction is valid
        p < q
        q - p  + 1 = number of elements in the array

    check new strlen version

    interesting two important value for pointer arithmetic
        #include <stddef.h>
            ptrdiff_t -- signed int value the holds the difference of two pointer values
            size_t -- unsigned int value for the difference between two pointers

    Pointer arithmetic is consistent if type is float it will increase by float size
    Luckily this means converting rom pointer types is easy.


    You can only compare pointers for the same type:
        Addition with an integer
        Subtraction with an integer
        Comparison (same members or zero)
    ** EVERYTHING ELSE IS ILLEGAL **
        Add two pointers
        Shift
        Divide
        Mask
        Two different types
        Assign a pointer to another without a cast


#### 5.5 Character Pointers and Functions
    When printf("hello world");
        printf actually accesses the first address of a pointer


    Example:
        char *pmessage;
        pmessage = "now is the time"; /* will assign pmessage to the first value of a char array */

    C does not provide any operators for processing an entire array of pointers

    Important difference between:
        char amessage[] = "now is the time";
        char *pmessage = "now is the time";

    amessage will always point to the zero address
    however the value of pmessage may change

    we should love to do
        char *s, t[10];
        s = t; /* This just points to the first address doesn't copy */

    check those versions of strcpy

#### 5.6 Pointer Arrays; Pointers to Pointers

    Since pointers are variables they can be stored in arrays
    just as other variables can

    In order to illustrate this process we will create a stripped
    down version of sort

    We will attempt to sort lines of text with quicksort

    In order to perform this operation we will need a structure for data
        * This structure must be able to handle variable lengths of text

    This is where arrays of pointers enter

    Each line can be accessed by a pointer to it's first character

    The pointers can then be stored within an array

    Any two lines can then be compared by passing strcmp

    When two lines that are not sorted appropriately the pointers can be swapped not the line

    Provides two benefits:
        1) Non-complicated storage management
        2) No requirement for high overhead with moving the actual lines




#### 5.7 Multi-dimensional Arrays
    C can provide rectangular multi-dimensional arrays
    * These tend to be much less used than arrays of pointers

    Consider the issue of date conversion, from day of the month to day of the year

    March 1 is the 60th day of a non-leap year and 61st day of a leap year

    Defintion of two functions:
        day_of_year -- converts month and day into the day of the year
        month_day -- converts the day of the year into the month and day

    since the second function computes two values they will be pointers
    month_day(1988, 60, &m, &d);

    set m to 2 and d to 29

    these functions need the same information to access the values

    so we will create a 2-dimensional array to store the information

    check day.c

    A two dimensional array is initialized with {} and each sublist must contain  {}

    If a 2D array is passed to a function it must include the number of columns
        * Number of rows is irrelevant

    Since the rows is just a pointer to the cols itself therefore:
        f(int dt[2][3]) == f(int dt[][3]) == f(int (*dt)[3])

    the parens are ness since [] have a higher op precedence than *

    thus, int *daytab[13]; is an array of 13 pointers to integers

#### Initilization of Pointer Arrays
    Imagine a method in which we want to return the month name within an array
    check day.c



#### 5.9 Pointers vs multi-dimensional arrays
    People usually get confused between two-dimensional arrays and an array of pointers

    Given the defintions:
        int a[10][20];
        int *b[10];

    a will allocate 200 int-size locations for the integers
    b only allocates 10 pointers and does not initalize them
        * Must be done explicitly either statically or with code

    If each element of b does point to a 20 element array
        Then there will 200 ints plus 10 slots for points
        * Gains positive benefit that the indexes can be multi-sized versus static

    Imagine we have
        char *name[] = {"Illegal month", "Jan", "Feb", "Mar"}; //This would have a pointer per string with any length
        char aname[][15] = {"Illegal month", "Jan", "Feb", "Mar"}; // this would allocate 15 bytes per row

#### 5.10 Command-line Arugments
    The number of command line arguments is argc
    The arguments themselves are contained in the argv[] array


#### 5.11 Pointers to Functions
    A function itself is not a variable, however you can define pointers to functions

    These pointers can then be passed to functions and returned by functions

    We will show this by modifying the sort procedure we wrote in the earlier portions of the chapter
        if we pass -n then the procedure will sort the input lines numerically instead of lexographically

    Sort typically comprises of three parts
        1) a comparison that determines the ordering of any pair of objects
        2) an exchange that reverses their order
        3) sorting algorithm that exchanges until the objects are in order

    Lexographic comparisions are done with strcmp
    Where as numeric can be done with self made num comp where it converts them to atof


#### 5.12 Complicated Declarations
    Sometimes the syntax if it's declarations are unclear especially those with pointers

    The syntax is an attempt to make the declaration and the use agree

    Good for simple cases, however can be confusing for harder ones

    Declarations cannot be read left to right and parens are often over used

    for instance:
        int *f() /* function returning pointer to int */

        int (*pf)(); /* pointer to function returning int */

    * is a prefix operator and lower precedence than ()

    We will create a pair of programs that convert calid C to a word description

    the word description reads left to right

    DCL is more complex, it converts c declaration into word description

    char **argv
        pointer to pointer to char

    int (*daytab)[13]
        pointer to array[13] of 13 ints

    int *daytab[13]
        array[13] of pointers to int

    void *comp()
        function retruning pointer to void

    void (*comp)()
        pointer to function returning void

    char (*(*x())[])()
        x:function returning pointer to array[] of
        pointer to function returning char

    char (*(*x[3])())[5]
        x is an array[3] of 3 pointers to a function returinging
        pointer to array[5] of 5 chars

    dcl is based on the grammar that specifies a declarator which
    is of the form

        dcl: options *'s direct-dcl
        direct-dcl: name
                    (dcl)
                    direct-dcl()
                    direct-dcl[optional size]

    in words, a dcl is a direct-dcl, prehaps preceded by *'s
