## Part 3

1. ux > 0 || ux -1 > 0 
This is true always, evaluating to 1. Because we are in the unsigned type, and it's always non-negative. 
If it's positive, then "ux>0" evaluate to true and we are done. If it's 0, then "ux-1" would overflow down and become T_max for unsigned, then the second condtion would evaluate to true.

2. y-2 <0 || y>=2
This depends on our assumption.  If we assume signed integer operations does not overflow, then this test conditon is "y<2 or y>=2" which is always true, evaluting to 1.
However, if we drop the assumption,
This is false. When y= T_min for signed, for sure "y>=2" evaluates to false. And "y-2" would negative overflow and becomes a very large positive number, then the first condition also evaluate to false, evaluting to 0.

3. (x >> 31) == (ux >> 31)
This is false. Let x to T_min for signed, whose bit representation is "0B10000000000000000000000000000000".Because first at beginning , x and ux have the same bit representation.When we first do shifting, recall we assume that Right shifts are performed
arithmetically for signed values and logically for unsigned values. So after shift right 31 bits, the bit representation for x is "0B11111111111111111111111111111111", while the bit representation for ux is "0B00000000000000000000000000000001". Now when we do "==" , x as a signed value got converted to unsigned value, which is T_max for unsigned, and ux is just 1. So It evaluates to false.

4. x + uy == ux + y
This is true always, evaluating to 1. In a word, Two's-complement and unsigned addition have the same bit-level behavior. Because (x and ux) and (y and uy) have the same bit-level representation. And in this case all the x,y are converted to unsigned type implicitly. Then the result of addition will always to the same, regardless of our assumption of whether the signed integer operation would overflow or not.

5. 0 <= y * y
This depends on our assumption. If we assume signed integer operations does not overflow, then for sure the square of a number is always non-negative, then this would always evaluate to true.
However, if we drop that assumption, 
take "y=0xFFFF=65535" the y*y would positive overflow and create a very big negative value, evaluating the expression to be false.

6. -x == ~x * y + uy * ux
This is false,evaluating to 0. Because ~x=-x-1, and we expand the right hand side, all values are converted to unsigned types, so ~x*y + uy*ux = (-x-1)*y + uy*ux = -y  -x*y + uy*ux = -y. So the condition is equivalent to "-x == -y". we can just take x=1 and y=2 then this is false.

### As we have already argued above,(2) (5) is susceptible to our assumption of no overflow. If no such assumption,in (2) "y-2" could do negative overflow and becomes a very very big positive number. Similarly, If no such assumption, (5) could evaluate to false because positive overflow might happen on "y*y" and become a very big negative number.

## Part 4
1. x = 0 10110 011
   Sign bit s is 0
   Exponent indicates normalized form:
   exp = 2+4+16 = 22 => E = 22 - 15 = 7
   frac = 1/4+1/8 = 3/8 > M = 1 + 3/8 = 11/8
   Hence
   w = (-1)^s M * 2^E = 1 * 11/8 * 2^7 = 176
   
   
   2. y= 1 00111 010
   Sign bit s is 1
   Exponent indicates normalized form:
   exp = 1+2+4 = 7 => E = 7 - 15 = -8
   frac = 1/4 > M = 1 + 1/4 = 5/4
   Hence
   w = (-1)^s M * 2^E = -1 * 5/4 * 2^-8 = -5/1024 
   
   3. z=0 00000 111
   Sign bit s is 0
   Exponent indicates de-normalized form:
   exp = 00000 de-normalized => E = 1 - 15 = -14
   frac = 1/2+1/4+1/8=7/8 > M = 0 + 7/8 = 7/8
   Hence
   w = (-1)^s M * 2^E = 1 * 7/8 * 2^-14 = 7/131072
   
   4.  u=1 11100 000
   Sign bit s is 1
   Exponent indicates normalized form:
   exp = 4+8+16 = 28 => E = 28 - 15 = 13
   frac = 0 > M = 1 + 0 = 1
   Hence
   w = (-1)^s M * 2^E = -1 * 1 * 2^13 = -8192
   
   5. v=0 10111 100
   Sign bit s is 0
   Exponent indicates normalized form:
   exp = 1+2+4+16= 23 => E = 23 - 15 = 8
   frac = 1/2 > M = 1 + 1/2 = 3/2
   Hence
   w = (-1)^s M * 2^E = 1 * 3/2 * 2^8 = 384
