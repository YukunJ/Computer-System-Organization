# Homework 5 (45 Points)

The deadline for Homework 5 is Tuesday, December 10, 8pm. The late
submission deadline is Monday, December 16, 8pm.

## Getting the code template

Before you perform the next steps, you first need to create your own
private copy of this git repository. To do so, click on the link
provided in the announcement of this homework assignment on
Piazza. After clicking on the link, you will receive an email from
GitHub, when your copy of the repository is ready. It will be
available at
`https://github.com/nyu-cso-005-fa19/hw05-<YOUR-GITHUB-USERNAME>`.  
Note that this may take a few minutes.

* Open a browser at `https://github.com/nyu-cso-005-fa19/hw05-<YOUR-GITHUB-USERNAME>` with your Github username inserted at the appropriate place in the URL.
* Choose a place on your computer for your homework assignments to reside and open a terminal to that location.
* Execute the following git command: <br/>
  ```git clone https://github.com/nyu-sco-005-fa19/hw05-<YOUR-GITHUB-USERNAME>.git```<br/>
  ```cd hw05-<YOUR-GITHUB-USERNAME>```

Put your solution into the file `solution.md`.

## Submitting your solution

Once you have completed the assignment, you can submit your solution
by pushing the modified code template to GitHub. This can be done by
opening a terminal in the project's root directory and executing the
following commands:

```bash
git add .
git commit -m "solution"
git push
```

You can replace "solution" by a more meaningful commit message.

Refresh your browser window pointing at
```
https://github.com/nyu-cso-005-fa19/hw05-<YOUR-GITHUB-USERNAME>/
```
and double-check that your solution has been uploaded correctly.

You can resubmit an updated solution anytime by reexecuting the above
git commands. Though, please remember the rules for submitting
solutions after the homework deadline has passed.

## Problem 1: Address translation (15 Points)

Consider a memory system with 13-bit wide virtual addresses, 11-bit
wide physical addresses, and the following features:

* Page table: 32 bytes page size, single level (i.e. 256 entries)

* TLB: 4 sets, 4-way set associative.

Further consider the following state of the page table and TLB.

Page table (only the first 16 PTEs are shown):

| VPN | PPN | V | VPN | PPN | V |
|-----|-----|---|-----|-----|---|
| 00  | 28  | 1 | 08  | 13  | 1 |
| 01  | -   | 0 | 09  | 17  | 1 | 
| 02  | 33  | 1 | 0A  | 09  | 1 | 
| 03  | 02  | 1 | 0B  | -   | 0 | 
| 04  | -   | 0 | 0C  | -   | 0 | 
| 05  | 16  | 1 | 0D  | 2D  | 1 | 
| 06  | -   | 0 | 0E  | 11  | 1 | 
| 07  | -   | 0 | 0F  | 0D  | 1 | 

Each PTE consists of a triple "VPN/PPN/V". The "VPN" is the virtual
page number and the column marked "PPN" is the physical page number
that the VPN is mapped to. The "V" column indicates whether the
corresponding PTE is valid.

TLB:

| Idx | Tag | PPN | V | Tag | PPN | V | Tag | PPN | V | Tag | PPN | V |
|-----|-----|-----|---|-----|-----|---|-----|-----|---|-----|-----|---|
|  0  | 03  | -   | 0 | 09  | 0D  | 1 | 00  | -   | 0 | 07  | 02  | 1 |
|  1  | 03  | 2D  | 1 | 02  | -   | 0 | 04  | -   | 0 | 0A  | -   | 0 |
|  2  | 02  | -   | 0 | 08  | -   | 0 | 06  | -   | 0 | 03  | -   | 0 |
|  3  | 07  | -   | 0 | 03  | 0D  | 1 | 0A  | 34  | 1 | 02  | -   | 0 |

Here, the column "Idx" indicates the set index and each "Tag/PPN/V"
triple constitutes one of the four entries in the set where "Tag" is
the tag of the entry, "PPN" is the associated physical page number,
and "V" is the valid bit.

1. Indicate which bits of the 13-bit virtual address are used to
   represent:

   a. The VPN

   b. The page table offset (PTO)
   
   c. The TLB set index
   
   d. The TLB tag

   where the least significant bit of the address is bit 0 and the
   most significant bit is bit 12.

2. For each of the virtual addresses given below, calculate (i) the VPN
   and (ii) the page table offset. Moreover, indicate the TLB entry
   accessed by calculating (iii) the TLB set index and (iv) the associated
   tag, (v) whether there is a TLB hit/miss, (vi) whether there is a page
   fault, and (vii) if there is no page fault, calculate the resulting
   physical address.
   
   a. Virtual address: 0x027C
   
   b. Virtual address: 0x03a9
   
   c. Virtual address: 0x0040

   Example:
   
   Virtual address: 0x1B7
   
   1. VPN: 0xD
   2. PTO: 0x17
   3. Idx: 0x1
   4. Tag: 0x03
   5. TLB hit
   6. no page fault
   7. PA: 0x5B7

## Problem 2: Cache Look-up (16 Points)

Suppose we have a system with the following properties:

* The memory is byte addressable

* Memory accesses are to 1-byte words

* Addresses are 13 bits wide

* The cache is 2-way set-associative with 4-byte cache lines and eight
  sets.

Consider the following cache state. All addresses, tags, and values
are given in hexadecimal format. The "Index" column contains the set
index for each set of two cache lines. The "Tag" columns contain the tag
value for each line. The "Bytes 0-3" columns contain the data for each
line, numbered left to right starting with byte 0 on the left.

| Index | Tag | V | Bytes 0-3   | Tag | V | Bytes 0-3   |
|-------|-----|---|-------------|-----|---|-------------|
|   0   | F0  | 1 | ED 32 0A A2 | 8A  | 1 | BF 80 1D FC |
|   1   | BC  | 0 | 03 3E CD 38 | A0  | 0 | 16 7B ED 5A |
|   2   | BC  | 1 | 54 9E 1E FA | B6  | 1 | DC 81 B2 14 |
|   3   | BE  | 0 | 2F 7E 3D A8 | C0  | 1 | 27 95 A4 74 |
|   4   | 7E  | 1 | 32 21 1C 2C | 8A  | 1 | 22 C2 DC 34 |
|   5   | 98  | 0 | A9 76 2B EE | 54  | 0 | 69 C2 8C 74 |
|   6   | 38  | 0 | 5D 4D F7 DA | BC  | 1 | 69 C2 8C 74 |
|   7   | 8A  | 1 | 04 2A 32 6A | 9E  | 0 | B1 86 56 0E |

1. Indicate which bits of each 13-bit address would be used to
   determine the following:

   a. The offset within the cache line (block offset).

   b. The cache set index.

   c. The cache tag.

   where the least significant bit of the address is bit 0 and the
   most significant bit is bit 12.


2. Suppose that a program performs a series of memory accesses, assuming
   the above cache state. For each of the potential accesses at the
   addresses given below, indicate the cache entry accessed by
   calculating (i) the block offset, (ii) set index, and (iii) cache
   tag. Moreover, indicate (iv) whether a cache miss occurs. If not, then indicate
   (v) the cache byte value returned *in hex*.
   
   a. Address 0x0FD1
   
   b. Address 0x071A
   
   c. Address 0x1407   


   Example:
   
   Address 0x179A
   
   1. Block offset: 0x2
   
   2. Set index: 0x6
   
   3. Tag: 0xBC

   4. Cache hit
   
   5. Cache byte returned: 0x8C


3. Calculate the address for byte 1 of the valid cache line (tag 8A) in set 7.


## Problem 3: Analysis of Cache Behavior (6 Points)

Consider the following C code:

```c
#define N 64
typedef int array_t[N][N];

int sumA(array_t a) {
  int sum = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      sum += a[i][j];
    }
  return sum;
}

int sumB(array_t a) {
  int sum = 0;
  for (int j = 0; j < N; j++)
    for (int i = 0; i < N; i++) {
      sum += a[i][j];
    }
  return sum;
}
```

Suppose we execute both `sumA` and `sumB` under the following
conditions:

* `sizeof(int)` = 4

* The machine has a single direct-mapped cache with 16-byte cache
  lines, holding a total of 4 KB (4096 bytes).

* Within the two loops of each function, the code uses memory accesses
  only for the array data. The loop indices and the value `sum` are
  held in registers.
  
* Array `a` is stored starting at memory address 0x08000000.

* The cache is empty before each function executes.

Calculate the cache miss ratio (i.e. the ratio between the total
number of cache misses and the total number of array accesses) for
each of the two functions. Explain your reasoning.

Give the smallest value `N` for which the cache miss ratios of the two
functions differ.

## Problem 4: Malloc/free (8 Points)

Consider an allocator implementation based on an implicit free list
with the following block format

```
 15         3 2 1 0
|------------|-----|
| Block size |0 0 a|
|------------------|
| Payload          |
|------------------|
| Padding          |
```

where a=1 means that the block is allocated and a=0 that it is
free. Further assume that the allocator maintains word (i.e. 16
bytes) alignment. Note that the full 16 bits of the header are used to
store the block size. However, since block sizes are multiples of 8
bytes, the lowest 3 bits of the block size are always 0. Hence, the
corresponding bits in the header can be repurposed to store other
information. In this case, only the least significant bit is used for
other purposes, namely to indicate whether the block is allocated.

Your task is to determine the block sizes and header values (in hex)
for each of the four malloc blocks that would result from the
following sequence of malloc requests:

```
malloc(3)
malloc(11)
malloc(20)
malloc(21)
```


