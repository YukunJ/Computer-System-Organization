# Homework 4 (45 Points)

The deadline for Homework 4 is Monday, December 2, 8pm. The late
submission deadline is Monday, December 9, 8pm.

## Getting the code template

Before you perform the next steps, you first need to create your own
private copy of this git repository. To do so, click on the link
provided in the announcement of this homework assignment on
Piazza. After clicking on the link, you will receive an email from
GitHub, when your copy of the repository is ready. It will be
available at
`https://github.com/nyu-cso-005-fa19/hw04-<YOUR-GITHUB-USERNAME>`.  
Note that this may take a few minutes.

* Open a browser at `https://github.com/nyu-cso-005-fa19/hw04-<YOUR-GITHUB-USERNAME>` with your Github username inserted at the appropriate place in the URL.
* Choose a place on your computer for your homework assignments to reside and open a terminal to that location.
* Execute the following git command: <br/>
  ```git clone https://github.com/nyu-sco-005-fa19/hw04-<YOUR-GITHUB-USERNAME>.git```<br/>
  ```cd hw04-<YOUR-GITHUB-USERNAME>```

Put your solution directly into the files `src/ex1.c` to `src/ex5.c`.

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
https://github.com/nyu-cso-005-fa19/hw04-<YOUR-GITHUB-USERNAME>/
```
and double-check that your solution has been uploaded correctly.

You can resubmit an updated solution anytime by reexecuting the above
git commands. Though, please remember the rules for submitting
solutions after the homework deadline has passed.


## Binary Mystery (5 + 10 + 10 + 10 + 10 = 45 Points)

In this homework, we give you 5 object files, `ex1_sol.o`,
`ex2_sol.o`, ..., `ex5_sol.o`, and withhold their corresponding C
sources. The relevant files are located in the `objs/` subdirectory if you are
on Linux/WSL and in the `objs-mac/` subdirectory if you are on Mac OS. Each
object file implements a particular mystery function (e.g. `ex1_sol.o`
defines function `ex1`). We ask you to deduce what these mystery
functions do based on their x86-64 assembly code and write the
corresponding C function that accomplishes the same thing for each of
the five functions. The files you will be modifying to implement these
functions are `src/ex{1-5}.c`.

### Uncover the mystery of assembly

Put your C code corresponding to `ex1_sol.o` in file `src/ex1.c`. Put your C code corresponding to `ex2_sol.o` in file `src/ex2.c`, and so on.

Suppose you want to figure out what function `ex1` (implemented in
`objs/ex1_sol.o` respectively `objs-mac/ex1_sol.o`) does. There are two approaches to do this. We
suggest to use both to help uncover the mystery.

#### Approach 1:

Disassemble the object files. Read the assembly and try to understand what the function tries to achieve. To disassemble `ex1_sol.o`, type:

```bash
    $ objdump -d objs/ex1_sol.o
```

respectively


```bash
    $ objdump -d objs-mac/ex1_sol.o
```

#### Approach 2

Run the function `ex1` in gdb.

You might wonder how to run `ex1` in gdb, since not knowing the function signature of `ex1` makes it hard to write your own C code to correctly invoke `ex1`. How to run `ex1` then? It turns out that you can utilize the tester that we have given you to run `ex1` and observe how it executes.

To run the test with the given `ex1` function, you need to link the
test object file `objs(-mac)/tester.o` together with the given
`objs(-mac)/ex*_sol.o` files. We have made this step easy by including an
appropriate `CMakeLists.txt` to set up the compilation process. Make
sure that you have `cmake` installed and execute the following command
in the root directory of your homework repository:

```bash
$ cmake .
```

You only need to do this once. When you subsequently execute

```bash
$ make
```

you will see that there are two binary executables being generated: `tester` and `tester-sol`. The executable file `tester` links our `tester.o` file with your object files `ex*.o` which are generated from your `ex*.c` files. The executable file `tester-sol` links our `tester.o` file with the given object file `ex*-sol.o`. Thus, when you run `./tester-sol`, the tester invokes the given functions, and needless to say, all tests should pass.

To examine the execution of `ex1` in `tester-sol` proceed as
follows. Execute

```bash
$ gdb ./tester-sol
```

to start gdb. Then set a break point at the entry to function `ex1`
and run the tester by executing the following two commands in gdb:

```
(gdb) break ex1
(gdb) run
```

The execution of `tester-sol` will then proceed up to the point when
function `ex1` is called for the first time and stop. You can now
disassemble the object code at the current point of execution
(i.e. function `ex1`) by issuing the command

```
(gdb) disassemble
```

The output will show the disassembly of function `ex1` and should look
similar to this:

```assembly
Dump of assembler code for function ex1:
=> 0x0000555555555750 <+0>:     add    %rsi,%rdi
   0x0000555555555753 <+3>:     cmp    %rdx,%rdi
   0x0000555555555756 <+6>:     je     0x55555555575e <ex1+14>
   0x0000555555555758 <+8>:     mov    $0x0,%eax
   0x000055555555575d <+13>:    retq
   0x000055555555575e <+14>:    mov    $0x1,%eax
   0x0000555555555763 <+19>:    retq
End of assembler dump.
```

The arrow symbol `=>` indicates the current value of the instruction
pointer register `%rip`. That is, it indicates which instruction will be
executed next. You can step through the assembly code line-by-line
using the command

```
(gdb) stepi
```

At each point you can inspect the current contents of the
registers and memory. For instance, if you are interested in the
current value of the instruction pointer register `%rip`, then you can
do this with the command

```
(gdb) info registers rip
```

Assuming the above disassembly, the output will look like this:

```
rip            0x555555555750      0x555555555750 <ex1>
```

You can similarly inspect the values of all other registers. 

For more information on how to use gdb
see
[the user manual](ftp://ftp.gnu.org/old-gnu/Manuals/gdb/html_chapter/gdb_toc.html).


**Important:** Do not try to match assembly. 

> It is not the right approach to try to match the object code of your C
> function line-by-line to those contained in `ex*-sol.o`. Doing so is
> painful and not necessary. Differences in the compiler versions,
> compilation flags, and small differences in C code will all result in
> different object code, although they do not affect the code's
> semantics. Therefore, trying to find a C function that generates the
> exact same object code is likely futile.


### Test your solution

After you have finished each function (remember to remove the
`assert(0)` statement), you can test its correctness as follows:

```bash
$ make
$ ./tester
Testing Ex1...
Ex1: your implementation passes the test
Testing Ex2...
Ex2: your implementation passes the test
Testing Ex3...
Ex3: your implementation passes the test
Testing Ex4...
Ex4: your implementation passes the test
Testing Ex5...
Ex5: your implementation passes the test
```

The above ouput occurs when all your `ex*` functions pass the tests.

To test multiple times, run `./tester -r` with the `-r` option. This
runs the tester using a new seed for its random number generator.

Some of you might want to skip around and implement the five `ex*`
functions in arbitrary order. This is a good strategy if you are stuck
on some function. To test just `ex2`, type `./tester -t 2`. Ditto with
other functions.

If you want to inspect the disassembly of your own implementations of
your functions, you can find the generated object files in the
directory `CMakeFiles/tester.dir/objs/` after you run
`make`. Alternatively, run `gdb ./tester` and proceed as detailed
above.

*Note:* Passing the test does not guarantee that you will get a
perfect grade (i.e. your implementation is not necessarily
correct). During grading, we may use a slightly different test or
manually examine your source code to determine its correctness.


### Explanations on some unfamiliar assembly

For this homework, you need to review the slides to refresh your
understanding of x86 assembly. Below is some specific information
that is helpful for this homework.

Recall that one can explicitly refer to lower-order bits of the
registers. The names that you may find used in the object code are:

```
register : name to refer its lower-order portion
%rax     : %eax(lower-32 bit), %ax(lower-16-bit), %al(lower-8-bit).
%rcx     : %ecx(lower-32 bit), %cx(lower-16-bit), %cl(lower-8-bit).
%rdx     : %edx(lower-32 bit), %dx(lower-16-bit), %dl(lower-8-bit).
%rbx     : %ebx(lower-32 bit), %bx(lower-16-bit), %bl(lower-8-bit).
%r8      : %r8d(lower-32 bit), %r8w(lower-16-bit),%r8b(lower-8-bit).
...
%r15     :%r15d(lower-32 bit),%r15w(lower-16-bit),%r15b(lower-8-bit).
```

Note: For some reason, gdb does not recognize `%r8b` to `%r15b` as
valid register names. To determine the value of `%r8b` (...`%r15b)`,
please just print register `%r8` (...`%r15`) and manually find out its
lowest byte to obtain the value.

* Often in the dissembled output, you encounter some instructions
  without any mnemonics suffix. For example, `mov` instead of `movl`
  or `movq` (where `l` or `q` indicate the size of the operands). In
  these scenarios, treat the missing suffix as one that corresponds to
  the size of the destination register operand. For example, `mov $1,
  %ebx` is equivalent to `movl $1, %ebx` and `mov %rax, %rbx` is
  equivalent to `movq %rax, %rbx`.

* Recall that the `movzbl` instruction moves the 1-byte source operand
  to the 4-byte destination operand with zero extension. Instruction
  `movslq` moves the 4-byte source operand to the 8-byte destination
  operand with sign extension. That is, if the source operand is
  negative in two's complement (i.e. has 1 in its most significant
  bit), then the instruction pads 1s (i.e. fills the most significant
  4-byte with 1s).

* The two byte instruction `repz retq` behaves identically to the one
  byte instruction `retq`.

* If you disassemble an object file, (e.g. `objdump -d
  objs/ex1_sol.o`), you should not expect valid addresses for functions,
  because linking has not yet happened. If you want to see valid
  function addresses (i.e. those that appear as the actual operand for the
  call instruction), disassemble the binary executable (`tester` or
  `tester-sol`) or disassemble in gdb.

