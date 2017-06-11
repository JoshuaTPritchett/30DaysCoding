## Chapter 3 Control Flow
    Control-flow are the order in which computations are performed

#### 3.1 Statements & Blocks
    An expression becomes a _statement_ when it is followed by a semicolon

    Braces are used to declare a _compound statement_ {}

#### 3.2 If-Else
        If-Else is used to express decisions

        if(_expression_)
            _statement1_
        else
            _statement2_

        _Expression_ is evaluated if it has a non-zerio value (..., -1, 1, 2 ..)

        Often if-else is clear and other tims it can be cryptic

        __else__ part of if-else is optional
            * This can create ambiguity
            * Resolved by associating it with the nearest if sequence


        Example:
            if (n > 0)
                if (a > b)
                    z = a;
                else
                    z = b;

        This else will be associated with the second if statement

        **If you don't want this then use braces ***


        Example:
            if (n > 0) {
                if (a > b)
                    z = a;
            }
            else
                z = b;


