# Problem 1
This is a complicated calculatio, Let's do it slowly.
we are given 13-bit wide virtual addresses, and the page table have 2^8=256 entries. 
Thus in each virtual page we need to represent 2^13/2^8=2^5 byte address. This tells us we need last 5 bit for offset.
Then naturally the leftmost 8 bit is used for Virtual Page Number.
As for the TLB, it's 4-way set associative, so we need 2 bit (left to the offset) to represent the set index, and then the rest leftmost 6 bits for TLB tag.
Thus, the solution is:

## 1.
### a. The VPN: bit 12,11,10,9,8,7,6,5
### b. The page table offset(PTO): bit 4,3,2,1,0
### c. The TLB set index: bit 6,5
### d. The TLB tag index: bit 12,11,10,9,8,7

## 2.
### a.Virtual address: 0x027C
0x027C = 0b 000100 11 11100
(i). VPN: 0x13
(ii). PTO: 0x1C
(iii). Idx: 0x3
(iv). Tag: 0x04
(v). TLB miss
(vi). page fault
(vii). thus unknown PA

### b. Virtual address: 0x03a9
0x03a9 = 0b 000111 01 01001
(i). VPN: 0x1D
(ii). PTO: 0x09
(iii). Idx: 0x1
(iv). Tag: 0x07
(v). TLB miss
(vi). page fault
(vii). thus unknown PA

### c. Virtual address: 0x0040
0x0040 = 0b 000000 10 00000
(i). VPN: 0x02
(ii). PTO: 0x00
(iii). Idx: 0x2
(iv). Tag: 0x00
(v). TLB miss
(vi). no page fault, PPN=33
(vii). PA = 0x660



# Problem 2
We are given 13 bit wide Address. The cache is 2-way set-associative, 4-byte cache line and there are 8 sets.
So starting from right to left, first we need 2 bit to determine the byte offset in each cache line. Then we need 3 bit to determine the set index. Then the rest left 8 bit can be used to determine the TAG.
Thus the solution is:
## 1.
### a. The offset within the cache line (block offset): bit 1, 0
### b. The cache set index: bit 4,3,2
### c. The cache tag: bit 12,11,10,9,8,7,6,5

## 2.
### (a). Address 0x0FD1
0x0FD1 = 0b  0 0000 1111 1101 0001
(i). Block offset: 0x1
(ii). Set index: 0x4
(iii). Tag: 0x7E
(iv). Cache hit
(v). Cache byte returned: 0x21

### (b). Address 0x071A
0x071A = 0b  0 0000 0111 0001 1010
(i). Block offset: 0x2
(ii). Set index: 0x6
(iii). Tag: 0x38
(iv). Cache miss, the "V" is set to 0
(v).  thus unknown

### (c). Address 0x1407
0x1407 = 0b  0 0001 0100 0000 0111
(i). Block offset: 0x3
(ii). Set index: 0x1
(iii). Tag: 0xA0
(iv). Cache miss, the "V" is set to 0
(v). thus unknown

## 3. Calculate the address for byte 1 of the valid cache line (tag 8A) in set 7
Let's do a backward calculation. 
The byte offset is 1, gives 2 bit 0b 01
The set index is 7, gives 3 bit 0b 111
The Tag is 8A, gives 8 bit 0b 1000 1010                                              
Combine them together, it gives us the address for this byte: 0b 0 0001 0001 0101 1101 = 0x115D

# Problem 3
We are given sizeof(int)= 4 bytes and our cache is designed such that it has 4KB(4098 bytes)/ 16 bytes = 256 lines, with
each cache line capable of storing 16 bytes, namely 4 intgers in our specific example.
And we need to remember the way array is stored in memory is "row-major" ordering.

### (a) int sumA(array_t a)
This code sum up row by row.  In the sense that once there is a cache miss, the cache will drag 4 contiguous integers into the cache lines (namely array_t[0][0-3]), and then the next 3 contiguous access is "free", there will be cache hit. Thus, the cache miss ratio is 1/4=0.25=25%

### (b) int sumB(array_t a)
This code sum up column by column. Since each cache line can hold 4 integers and has 256 lines, the way we module the line and put it into cache is to count its module by 256 every 4. For example, array[0][0-3] would take first row. Then array[0][4-7] would take second row, etc. namely a row need to be stored in 16 lines continuously. So when we iterate column by column, the second row array[1][0-3] would be placed at 17th line, the third row would be placed at 33rd line, etc... Notice this leads to overwrite, when we iterate to row 17, it needs to be stored at 16*16%256+1=1st cache line, which overwrites the cache for first row's data array[0][0-3]. In this sense, when we iterate to second column, all we meet is cache miss. The same situation repeats. Thus overall, the cache miss ratio is 1=100%

### (c) Give the smallest value N for which the cache miss ratios of the two functions differ.
In theory, we know sum up row by row should have better cache performance than column by column. The cache miss ratio for summation row by row is always around 0.25=25%, it has nothing to do with the size of the matrix. And as we already see in last example, "overwriting" impacts the performance of summation column by column. 

The good case would be, you iterate through the whole first column, and there are not overwriting, in the sense that iterating 2nd, 3rd and 4th column would be "free", cache hit. This require that N*N*4<= 4096, N<=32. We can do a mental calculation. When N=32, each row can be cut into 8 chunks (lines) each chunk store 4 integers. Then store 32 rows need 32*8=256 cache lines, which equals our cache size. This is the limiting state.

Hence, the answer is that: the smallest value N is N=33.

# Problem 4

### (a). malloc(3)
So we ask for 3 bytes. The header takes 2 bytes. Now we need in total 5 bytes. By the padding rule of 16 bytes alignment, we upgrade to 16 bytes. And 16 bytes= 0b 1 0000 and turn on the last bit, we get 0b 1 0001
Thus,
Block size = 16 bytes
header value = 0x11

### (b). malloc(11)
So we ask for 11 bytes. The header takes 2 bytes. Now we need in total 13 bytes. By the padding rule of 16 bytes
alignment, we upgrade to 16 bytes. And 16 bytes = 0b 1 0000 and turn on the last bit, we get 0b 1 0001
Thus,
Block size = 16 bytes
header value = 0x11

### (c). malloc(20)
So we ask for 20 bytes. The header takes 2 bytes. Now we need in total 22 bytes. By the padding rule of 16 bytes
alignment, we upgrade to 32 bytes. And 32 bytes = 0b 10 0000 and turn on the last bit, we get 0b 10 0001
Thus,
Block size = 32 bytes
header value = 0x21

### (d). malloc(21)
So we ask for 21 bytes. The header takes 2 bytes. Now we need in total 23 bytes. By the padding rule of 16 bytes
alignment, we upgrade to 32 bytes. And 32 bytes = 0b 10 0000 and turn on the last bit, we get 0b 10 0001
Thus,
Block size = 32 bytes
header value = 0x21

