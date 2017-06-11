## STRUCTURES
    A structure is a collectino of one or more variables, group together under a single name
    Strucutres help organize complicated data, particularly in large programs
        * Permit group of related variables to be treated as a unit**

    One example is a payroll record
        Employee:
            name
            address
            SSN


    Another example is from graphics
        point (pair of coordinates)
        rectangle (pair of points)

    structures can be passed to functions and returned by functions


#### 6.1 Basics of structures
    For instance a point:
        struct point {
            int x;
            int y;
        };

`     the variables of the struct are called members
    a strucutre member or tag and non-member variable can have same name without conflcit

    The same name can even occur within different strucutres

    struct defines a type

    the right brace that terminates a list of members
        can be followed by a list of variables

    struct {...} x, y, z; -> int x, y, z;

    each statment decalres x y z as variables of the named type

    a struct declartion that is not followed by a list of variables reserves no storage

    it just describes the template or name

    example
        struct point pt;

    defines variable pt which is a strucutre of type struct point

    a struct can be init by follow it's definitino like this:
        struct point maxpt = {320,200};

    an automatic strucutre may be init by assignment or by callung a function that returns
    structure of the right type

    A member of a struct is called
        __struct-name__.member

    to print the value of the point we would do
        printf("%d,%d", pt.x, pt.y);

    we can compute the distance from origin (0,0) to pt
        double dist, sqrt(double);
        dist = sqrt((double) pt.x * pt.x + (double)pt.y * pt.y);

    structures can be nested too

    struct rect {
        struct point pt1;
        struct point pt2;
    };

    struct rect screen;

    screen.pt1.x

#### 6.2 Structures and Functions
    ONLY LEGAL OPERATIONS:
        * Copying
        * assignment
        * address
        * accessing memebers

    A structure may be init by a list of constant member values
    Automatic structures may be initilized by an assignment

    Checking main.c

If a large structure is to be passed to a function is it often better to pass a pointer

This prevents the need to copy the entire structure

    struct point *pp;
    pp = &origin;
    (*pp).x = 3;
    printf("origin is );

*pp.x is not legal because x is not a pointer

Since pointers to structs are so oftne used often better to use
    p -> member of structure

. and -> evaluate from left to right

these four are equivalent:
    r.pt1.x
    rp->pt1.x
    (r.pt1).x
    (rp->pt1).x

. -> () and [] are at the top of the precedenc heirarchy
thus,
    struct {
        int len;
        char *str;
    } *p;

    then
        ++p->len

    increments len and not p because pars are implied by precedence level

    (++p)->len increments p first

    (p++)->len increments p afterward

    *p->str fetches what even string str ponints to
    *p->str++ increments str after access what it points to
        like *s++

    (*p->str)++ increments what ever str points to
    *p++->str increments p after accessing whatever str points to

#### 6.3 Arrays of Structures
    Imagine writing a program in which we count the occurences of each C keyword

    we must have a variable length character array
    and an array of integer counts

    one possibility is to have two parallel arrays
        char *keyword[nkeys];
        int keycount[nkeys];

    Instead, maybe we should have an array of structures
    which has the word and a count to the number of times the word appears

    struct key {
        char *word;
        int count;
    } keytab[NKEYS];

    an array of keytab of structures of this type
    Each element within the array is a structure

    This can also be written as:

    struct key {
        char *word;
        int count;
    };

    struct key keytab[NKEYS];

    Also,
        struct key {
            char *word;
            int count;
        } keytab[] = {
            {"auto", 0},
            {"break", 0},
            {"case", 0},
            {"char", 0}
        };



    we could count the number of keys in the keytab array
    but it would be easier to do it by machine

    One idea would be to null terminate the array

    This is wayyy more than needed since the array is completely determined at compile time

    The size of the array is size of one entry times the number of entries so:


    sizeof(keytab) / sizeof(struct key);
    which will yield an integer equal to the size of the specified object or type in bytes

    so we want
        check main.c keys

    we cannot use #if line cause the preprocessor does not parse type names

    we must used #define since it is not evaluated by the preprocessor


#### 6.4 Pointers to structures

    You cannot add two pointers therefore you must subtract

    You can never make assmptions about the size of a structure
        * This is due to alignment issues
        Thus,
            struct {
                char c;
                int i;
            };
        Might end up being eight bytes and not five


#### 6.4 Self-referential structure
    Suppose we want to count all the words in some input

    If we don't know the words before hand we cannot sort it then use BS

    However, we cannot do a linear search for each word as it arrives

    How can we organize the data to cope with an arbitrary number of words?

    One solutino is to keep the words sorted at all times
        * by placing eah word in it's proper position in the order as it arrives

    This shouldn't be done by shfiting words in a linear array

    Instead we will use a __binary tree__

        Node contains:
            Pointer to the word
            Count of the number of occurences
            A pointer to the left child node

