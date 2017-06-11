#### IEEE Standard 754 Floating Point Numbers
    IEEE Standard 754 floating point is the common representation for real numbers

## What are floating point numbers?
    Several variations to represent real numbers on computers

    One way is to use fixed point
        * Places a radix point somewhere in the middle of digits
        * Equivalent to using integers that represent portions of some unit
            __ Example: __
                * 1/100ths of a unit can be either 10.82 or 00.01
                * Use rationsl and represent numbers as a ratio of two ints

    Floating-point representation is the most common solution
        Uses scientific notation to encode numbers
            Base number and exponent

    Exmples:
       * __ Decimal:__ 123.456 can be represented as 1.23456 x 10 ^ 2
       * __ Hex __ 123.abc X 16 ^ 2
       * __ Binary: __ 1.0100110 X 2 ^ 4

    Floating-point solves number of representation problems

    Fix-point has a fixed window of representation which limits representing large or small numbers

    Fixed-point is prone to loss of precision when two large numbers are devided

    Floating-point employs a "sliding window" of precision to the scale of the number

    can represent numbers from 1,000,000,000,000 to 0.00000000001 with ease

    While giving max precision at both ends of the scale



## Storage Layout
    IEEE floating point has three basic components:
    :   * Sign
        * Exponent
            + implicit and need not be stored
        * Mantissa
            + fraction and leading digit

    Figure describes the layout of a single (32-bit) and double (64-bit) precision
    floating-point values. The number of bits for each field are shown. 00 = LSB

    |                  | __Sign__   | __Exponent__   | __Fraction__   |
    | -----------------| :---------:| :------------: | :-------------:|
    | Single Precision | 1 [31]     | 8 [30-23]      | 22 [22-00]     |
    | Double Precision | 1 [63]     | 11 [62-52]     | 52 [51-00]     |


    Laid out as bits looks like

    _Single_: SEEEEEEEE EMMMMMMM MMMMMMMMM MMMMMMMM
    _Double_: SEEEEEEEE EEEEMMMM MMMMMMMMM MMMMMMMM MMMMMMMM MMMMMMMM MMMMMMMM MMMMMMMM

# The Sign bit
    Sign bit is simple it gets either:
        * 0 denotes a _positive_ number
        * 1 denotes a _negative_ number

# The Exponent
    The Exponent field needs to represent both positive and negative exponents

