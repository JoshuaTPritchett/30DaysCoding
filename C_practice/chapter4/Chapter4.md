## Functions

## 4.1 Basics of Functions

    _return-type_ _function-name_ (_arguemnt delcarations_) {
        _declarations and statements_
    }

    Some parts within a function may not exist
        _dummy () {}_
            * does nothing and returns nothing
            * useful place holder during program development



    IF return type is omitted then int will be assumed

    A program is just definitions of variables and functions

    Communication between the functions is by arguments and values returned by the functions
        * through external variables

    Functions can occur in any order within a source file
        * source program can be split into multiple files
        * as long as no function is split

    __ Return statements are as follows __
            _return expression;_

    Parentheses can be used around expression, but they are optional

    Calling function can ignore the returned value

    No expression after return
    Control also returns to caller with no value when execution _"falls off the end"_
        * function has reached the closing right brace

    Compilation and loading of a c program vary baesd on the system you work on

    Suppose the C program resides on multiple source files
        Three functions stored in files
            * main.c
            * getline.c
            * strindex.c

        Then gcc main.c getline.c strindex.c
            Compiles the three files
            places object code in files
                * main.o
                * getline.o
                * strindex.o

        and loads hem into executable file called a.out

        If there a specific error in one file for example: main.c
            Recompliation occurs as follows:
                gcc main.c getline.o strindex.o

## 4.2 Function Returning Non-integers
    what if a value must return another type other than int or void?

    Many functions like sqrt, sin, cos return double

    Let's write atof(s)
        * Just an extension of atoi

    atof is declared in <stdlib.h>

    BAD example:
        Declations much match definitions
        Imagine: sum += atof(line);
        This would be first apperance of atof thus it would retun an int and nothing about arugments

    Function dlecation does not include arugments
        double atof();

    Taken to mean that nothing is assumed about the arguments of atof
        All parameter checking is off
        Empty argument list is inteded to permit older C programs to complie with new compilers
        Bad in new programs USE __VOID__

    _IF_ you cast a return statement the compiler would assume this wanted and surpress any errors



## 4.3 External Variables
    Internal variables are arugments and variables defined inside functions

    _External_ variables are defined outside any function

    Functions are always external because functions cannot be defined inside functions

    External variables and functions have the property that all references to them by the same name
        Even from functions compiled seperately are references to the same thing

    * CALLED _external linkage_

    External variables are globally accessible they provide an alternative to function arguments and return values for communicating data between functions

    Any function may access an external variable by referring to it by name, if the name has been declared somehow

    If a large number of variables must be shared among functions external variables are more convenient and efficient than long arugment lists

    External variables are useful because:
        * Greater scope
        * lifetime

    Automatic variables are internal to a function
        * Appear when function is entered
        * Disappear when function is left

    External variables are permanent so they retain values from one function invocation to the next

    IF two functions share same data, yet neither calls the other then external variable is good


    Reverse Polish Notation:
        Used in many caluclators
        Also known as postfix notation
        Stacked based language construct

    Implementation
        Each operand is pushed onto stack
        When operator arrives
        Number of operands (two for binary) is popped
        Operator is applied to them
        Then result is pushed back on stack

        The structure is just a loop thus:
            while (_next operator or operand is not EOF_)
                if (_number_)
                    push(_number_)
                else if (operator)
                    pop operands
                    do operation
                    push result
                else if (new line)
                    pop and print top of stack
                else
                    error

    There should be functions for
        push
        pop
        next operand/operator

    Next is to where to store the stack
            Keep it in main and pass current stack position to routines
            Main shouldn't know these variables
        Thus, make external variable

    #includes
    #defines

    function delcarations for main

    main () {...}

    external variables for push and pop

    void push(double f) {..}
    double pop(void) {...}

    int getop(char a[]) {...}

    routines called by getop



## 4.4 Scope Rules

    Functions and external variables that comprise a C program need not all be compiled at once

    Source text of the program may be kept in several files

    Questions to consider:
        How are declarations written so that variables are properly declared during compilation?

        How are declarations arragned so that all the pieces will be properly connected when
        then program is loaded?

        How are declarations organized so there is only one copy?

        How are external varaibles initialized?

        __ scope __ of a name is the part of the program which the name can be used

        Automatic variables declared at the beginning of a funtion the scope is the function

        Local variables in different functions are unrelated

        Parameteres of the function are different than local variables

        sp and val may be used to push and pop simply by naming them; no further delcarations are needed
            Not visible in main

        if an external variable is referred to before it is defined or in a different file
            EXTERN is mandatory

        There must be a difference between __ declaration __ and __definition__

        Definition:
            int sp;
            double val[MAXVAL];

            * Storage is set aside and serve as the declaration for the rest of that source file

        Declaration:
            extern int sp;
            extern double val[];

            declare for the rest of the source file that sp is an int
            val is a double array

            * They do not create or reserve storage for them


    _ There must be one defintion of an external variable among all files that use it _
        * Others must use extern

    Initialization only goes with the defintion

    example

        File1:
            extern int sp;
            extern double val[];

        file2:
            int sp = 0;
            double val[MAXVAL];



## 4.5 Header Files
    Divide calculator program into severl source files



## 4.6 Static Variables
    Variables sp and val in stack.c and buff and buffp in getch.c

    Are for the private use in their respective source files not meant to be accessed by anything else

    Static declaration applied to an external variable or function limits scope of that object
    to the rest of the source file being compiled

    Static provides a way to hide external variables to the scope of the source file
    that it is being compiled with, while making the variables invisible to users
    outside of the file.
        GOOD for external variables that must be shared

    example:
        static char buff[BUFFSIZE];
        static int buffp = 0;

    No other routine can now access buff and buffp those names will not conflict with same names
    in other files of the same program

    Static is most often used for variables

    applied to functions (which are typically global)

    if a function is static it's name is invisible outside of the file in which it is declared

    __static can also be applied to internal variables__
        *Local to function
        * remain in existence rather than coming and going each time function is activated
        * PROVIDES INTERNAL, PRIVATE, PERMANENT STORAGE


    ** modify getop so it doesn't need ungetch (just make the c static within the function)



## 4.7 Register Variables

    register declaration advises compiler that the variable will be heavily used

    register variables are placed in machine registers
        * SMALLER AND FASTER VARIABLES

    example:
        register int x;
        register char c;

    __ register can only be applied to automatic variables and formal parameters of a function __

    example:
        f (register unsigned m, register long n) {
            register int i;
        }

    This can greatly increase the speed in which computations on a variable work, however
    restricted to the number of variables that can be stored in registers

## 4.8 Block Structure
    Functions may not be declared inside other functions

    Delcaration of variables that indroduces any compound statement not just the one that
    begins a function.

    Varaibles declared in this way hide from any outside variables

    example
        int i;
        if (n > 0) {
            int i;
            for (i = 0; i < n; i++)
                ...
        }

    * DONT DO THIS SHIT


## 4.9 Initialization
    Rules of initilization
        external and static variables are guaranteed to be init to zero

        automatic and register variables have undefined values

        scalar variables (number or string)
            name with equals sign and expression
                int x = 1;
                char squote = '\'';
                long day = 1000L * 60L;

        external and static variables inits must be constant expression

        automatic and register variables are done each time function or block is entered
            * INITS are not restricted to being a constant
            * INITS of automatic variables are just shorthand for assignment statements


        array may be done with a list of initializers enclosed in braces and seperated by commas

        int days[] =  { 1, 2, 3, 4, 6};

        Size of the array is omitted

        *** IF there are fewer initializers for an array than the number specified **
        Missing elements will be zero for external, static, and automatic variables

        character arrays are a special case of initialization string may be used instead of braces
        Example
            char pattern[] = "ould";
            char pattern[] = {'o','u','l','d', '\0'};
        5 total in each but "ould" contains the null terminated string


## 4.11 The C Preprocessor
    C provides language facilities that happen before pre-compilation

    This is known as the pre-processor that is the first step in compilation

    The two most frequently used features that invovle a pre-processor directive are:
        #include
        #define


#### 4.11.1 File Inclusion
    File inclusion allows C to easily handle collections of #defines and delcarations

    There are two variations of file inclusion they are:
        #include "filename"
        #include <filename>

    If the filename is included with "" then the file is searched for where the source file is found

    If it is not foud there or the file is enclosed by <> then searching is done in an
    implementation-defined manner

    Any included file may also contain other #include files

    #include is the preferred way to include information from other files as a pre-processor
    directive

    Whenever an include file is changed then the files that include it must also be re-compiled



#### 4.11.2 Macro Substitution
    A definition in the form of
        #define __name__ __replacement text__

    IS a macro substituion of the simplest kind

    Normally any replacement text is invovled on the same line as the definition

    However, if you want to extend a defintion you can use  \

    #defines only follow from the beginning of the file to the end source file beign compiled

    A defintion may use previous definitions

    Substitutions are only makde for tokens that do not take place with quoted strings

    So if you have
        #define YES

    there would be no substitution for  printf("YES");

    Any name may be defined with any replacement text
        #define forever for(;;) /* infinite loop */

    You can also define macors with arguments
    #define max(A, B) ((A) > (B) ? (A) : (B))

    Even though this looks like a function call this macro will expand to one line of total code

    For example:
         x = max(p+1, r+1);

    will turn into
        x = ((p+1) > (r+1) ? (p+1) : (r+1));

    The argument can serve for any data type

    The expansion is clearly evaluated twice which is bad

    This can cause side effects such as a macro like:
        #define squared(x) x*x
        int i = squared(z+1);
        int i = z + 1 * z + 1;
        /* Incorrect implementation */

    There should be parenthesis around this macro to make sure order of evaluation is preserved

    so #define squared(x) (x) * (x)


    <stdio.h> getchar and putchar are both defined as macros
        * This avoids runtime overhead

    <ctype.h> are also implemented as macros

    Names be undefined with #undef

    example
        #undef getchar

        int getchar(void) {...}

    Formal parameters are not replaced with quoted strings

    If a parameter name is preceded by a # in the replacement text

    This will expand to a quoted string

    This can be combined with string concat to provide a powerful result

    Example:
        #define dprint(expr) printf(#expr " = %g\n", expr)

        __invoked__
            dprint(x/y);
            printf("x/y" " = %g\n", x/y); /* This will lead to the replacement text being replaced */
            printf("x/y = %g\n", x/y); /* Due to string concatentation */



## 4.11.3 Conditional Inclusion
    You can control pre-processing itself with conditional inclusion

    You can use #if line to evalue a constant integer expression

    IF the expression is non-zero, subsequent lines in until
    an #endif or #elif or #else are included

    The expression defined(name) in an #if is 1 if name has been defined 0 otherwise

    To make sure that the file is included once you can do:

    #if !defined(HDR)
    #define HDR

    /* contents hdr.h go here */

    #endif


    This form allows there not to be a need for an interdependce

    An alternative approach to the one defined above is

    #ifndef HDR
    #define HDR
    /* contents of hdr.h */
    #endif

    You can even use keywords to determine what to include

    #if SYSTEM == SYSV
        #define HDR "sysv.h"
    #elif SYSTEM == BSD
        #define HDR "bsd.h"
    #elif SYSTEM == MSDOS
        #define HDR "msdos.h"
    #else
        #define HDR "default.h"
    #endif
    #include HDR


