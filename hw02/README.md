# Homework 2 (40 Points)

The deadline for Homework 2 is Monday, October 21, 8pm. The late
submission deadline is Monday, October 28, 8pm.

## Getting the code template

Before you perform the next steps, you first need to create your own
private copy of this git repository. To do so, click on the link
provided in the announcement of this homework assignment on
Piazza. After clicking on the link, you will receive an email from
GitHub, when your copy of the repository is ready. It will be
available at
`https://github.com/nyu-cso-005-fa19/hw02-<YOUR-GITHUB-USERNAME>`.  
Note that this may take a few minutes.

* Open a browser at `https://github.com/nyu-cso-005-fa19/hw02-<YOUR-GITHUB-USERNAME>` with your Github username inserted at the appropriate place in the URL.
* Choose a place on your computer for your homework assignments to reside and open a terminal to that location.
* Execute the following git command: <br/>
  ```git clone https://github.com/nyu-sco-005-fa19/hw02-<YOUR-GITHUB-USERNAME>.git```<br/>
  ```cd hw02```

Put your answers to parts 3 and 4 into the text file `solution.md`.

## Submitting your solution

Once you have completed the assignment, you can submit your solution
by pushing the modified code template to GitHub. This can be done by
opening a terminal in the project's root directory and executing the
following commands in the :

```bash
git add .
git commit -m "solution"
git push
```

You can replace "solution" by a more meaningful commit message.

Refresh your browser window pointing at
```
https://github.com/nyu-cso-005-fa19/hw02-<YOUR-GITHUB-USERNAME>/
```
and double-check that your solution has been uploaded correctly.

You can resubmit an updated solution anytime by reexecuting the above
git commands. Though, please remember the rules for submitting
solutions after the homework deadline has passed.


## Part 1: Bits and Bytes (17 Points)

Complete the programming tasks specified in the files
`src/part1.c`.

* Test each part individually by executing
  
  ```bash
  make build/part1
  build/part1
  ```
  and similarly for the other parts.
  
We encourage you to write your own supplementary testing code.

**Hint**: If you want to copy a `float` variable `f` to an `int`
variable `x` while preserving the exact same bit-level representation
(i.e. reinterpreting the bits of `f` as if they were representing an
`int`), then this can be done as follows:

```c
float f = ...;
int x = *((int*) &f);
```


## Part 2: File handling (10 Points)

Write a C program that takes two command line arguments

1. One of `-c`, `-w`, `-l`, and

2. a path to a text file.

Your program should then print:

* the number of characters in the given text file, if the first
  argument is `-c`,
  
* the number of words in the given text file, if the first argument
  is `-w`, and
  
* the number of newlines in the given text file, if the first
  argument is `-l`.

This value should be followed by a single space character (`' '`) and
the given path to the text file. For example, assuming that the
executable of your program is `build/mywc`, then executing

```bash
build/mywc -l README.md
```
should print
```bash
206 README.md
```
assuming `README.md` is this file.

In general, the output of your program should be *identical* to the
output produced by the `wc` command, given the same command line
arguments (the output of your program is allowed to differ from the
output of `wc` if the command line arguments are not as expected or
if some other user error occurs).

In the above specification, a word is a maximal sequence of characters
that does not include a white space character. For simplicity, the
only white space characters you need to consider are space (`' '`),
tab (`'\t'`), and newline (`'\n'`). If the last line in the file is
not terminated by a newline character, it is not counted for `-l`.

Make sure that your program handles error cases gracefully (e.g. if
the given file does not exist or the command line arguments are not as
expected).

Put your code into the file `src/mywc.c`. You can compile your code by
running 

```bash
make build/mywc
```

and run it, e.g., by calling

```bash
build/mywc -l README.md
```

## Part 3: Two's Complement (8 Points)

Assume the datatype `int` is 32 bits long and uses a two's complement
representation for signed values.  Right shifts are performed
arithmetically for signed values and logically for unsigned values.

Given the following variable declarations:

```c
int x = foo(); // Arbitrary value
int y = bar(); // Arbitrary value

unsigned ux = x;
unsigned uy = y;
```

For each of the following C expressions, either (1) argue that it is
true (evaluates to 1) for all values of `x` and `y`, or (2) give
values for `x` and `y` for which it is false (evaluates to 0):

1. ux > 0 || ux - 1 > 0
1. y - 2 < 0 || y >= 2
1. (x >> 31) == (ux >> 31)
1. x + uy == ux + y
1. 0 <= y * y
1. -x == ~x * y + uy * ux

In your analysis, you may assume that the values of `x` and `y` are
always chosen such that no overflow happens on signed integer
operations. Indicate for which of the expressions your answer would
change if this assumption were dropped. Explain why.

## Part 4: IEEE Floating Point (5 Points)

Consider a 9-bit floating point representation based on the IEEE floating
point format where

* There is one sign bit.

* There are k=5 exponent bits (i.e. the exponent bias is 15).

* There are n=3 fraction bits.

Decode the values represented by the following bit patterns.

1. x = 0 10110 011
2. y = 1 00111 010
3. z = 0 00000 111
4. u = 1 11100 000
5. v = 0 10111 100

Explain your decoding.

Example:

w = 1 01111 001 

- Sign bit s is 1

- Exponent indicates normalized form: 

  exp = 1+2+4+8 = 15 => E = 15 - 15 = 0

  frac = 1/8 => M = 1 + 1/8 = 9/8
  
- Hence
  
  w = (-1)^s M * 2^E = -1 * 9/8 * 2^0 = - 9/8
  
