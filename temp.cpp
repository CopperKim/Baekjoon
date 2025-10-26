#include <stdio.h>
#include <iostream>

using namespace std; 

// int conditional(int x, int y, int z) {
//   // var condition is 11... when x is nonzero, else 00... 
//   int condition = ~(!!x) + 1 ; 
//   return (y & condition) | (z & ~condition) ; 
// }
// /* 
//  * LSBFillLeftShift - shift x to the left by n, while filling bit at LSB
//  *   Can assume that 0 <= n <= 31
//  *   Examples: LSBFillLeftShift(0x87654321,8) = 0x654321ff
//  *             LSBFillLeftShift(0x87654300,8) = 0x65430000
//  *   Legal ops: ! ~ & ^ | + << >>
//  *   Max ops: 20
//  *   Rating: 3
//  */
// int LSBFillLeftShift(int x, int n) {
//   // calculate the compliment, which is lsb * 111...  
//   int lsb = x & 1 ; 
//   int compliment = (lsb << n) + ~lsb + 1 ; 
//   return (x << n) + compliment ; 
// }
// /*
//   * hexAlphabetCount - returns count of number of alphabet in hexadecimal
//   *   Examples: hexAlphabetCount(0xABCDEF00) = 6
//   *             hexAlphabetCount(0x12345600) = 0
//   *             hexAlphabetCount(0xABC45600) = 3
//   *   Legal ops: ! ~ & ^ | + << >>
//   *   Max ops: 70
//   *   Rating: 4
//   */
// int hexAlphabetCount(int x) {
//     int res = 0; 
//     int temp ; 
//     temp = (x & 15) + ~9; 
//     res += !(temp & (1 << 31));
//     x = x >> 4 ; 
//     temp = (x & 15) + ~9; 
//     res += !(temp & (1 << 31));
//     x = x >> 4 ; 
//     temp = (x & 15) + ~9; 
//     res += !(temp & (1 << 31));
//     x = x >> 4 ; 
//     temp = (x & 15) + ~9; 
//     res += !(temp & (1 << 31));
//     x = x >> 4 ; 
//     temp = (x & 15) + ~9; 
//     res += !(temp & (1 << 31));
//     x = x >> 4 ; 
//     temp = (x & 15) + ~9; 
//     res += !(temp & (1 << 31));
//     x = x >> 4 ; 
//     temp = (x & 15) + ~9; 
//     res += !(temp & (1 << 31));
//     x = x >> 4 ; 
//     temp = (x & 15) + ~9; 
//     res += !(temp & (1 << 31));
//     x = x >> 4 ; 
    
//     return res; 
// }
// /*
//   * patternMatching - return the number of found 4 pattern p in the given number x.
//   *   Examples: patternMatching(11, 11) = 1, patternMatching(245, 13) = 1,
//   *             patternMatching(170, 15) = 0, patternMatching(23397, 11) = 3
//   *   Legal ops: ! ~ & ^ | + << >>
//   *   Max ops: 73
//   *   Rating: 6
//   */
// int patternMatching(int x, int p) {
//   // each digit (4 - 32) of var info has an information about if the i-3-th digit to i-th digit matches the given pattern 
//   // each mask helps to get var info, first-fourth value is "if p's nth digit is 1, then x<<n, else ~(x << n)"
//   // for example, if p = 1101(2), then we do "and bitwise operation" with x << 3 and x << 2 and ~(x << 1) and x << 0 
//   // which returns return 1 only when the digit matches the pattern 
//   int firstMask = ~(((p >> 3) & 1)) + 1 ;
//   int first = (x & firstMask) | (~x & ~firstMask) ; // if (p's first bit is 1) then x else ~x 
//   int secondMask = ~(((p >> 2) & 1)) + 1 ;
//   int second = ((x << 1) & secondMask) | (((~x) << 1) & ~secondMask) ; 
//   int thirdMask = ~(((p >> 1) & 1)) + 1 ;
//   int third = ((x << 2) & thirdMask) | (((~x) << 2) & ~thirdMask) ; 
//   int fourthMask = ~(((p >> 0) & 1)) + 1 ;
//   int fourth = ((x << 3) & fourthMask) | (((~x) << 3) & ~fourthMask) ; 

//   int info = first & second & third & fourth; 
//   // printf("%x\n", info); 

//   // from now on, we have to get a sum of all bits of info, additionally 1-3th digit is guaranteed to be 0 
//   int mask1 = 85; // 01010101...
//   mask1 = mask1 | (mask1 << 8); 
//   mask1 = mask1 | (mask1 << 16); 

//   int mask2 = 51; // 00110011...
//   mask2 += (mask2 << 8); 
//   mask2 += (mask2 << 16); 

//   int mask3 = 15; // 00001111...
//   mask3 += (mask3 << 8); 
//   mask3 += (mask3 << 16); 

//   int mask4 = 255; // 0000000011111111...
//   mask4 += (mask4 << 16); 

//   int mask5 = 255 + (255 << 8); 

//   printf("%x\n%x\n%x\n%x\n%x\n", mask1, mask2, mask3, mask4, mask5); 

//   info = (info & mask1) + ((info >> 1) & mask1); 
//   info = (info & mask2) + ((info >> 2) & mask2); 
//   info = (info & mask3) + ((info >> 4) & mask3); 
//   info = (info & mask4) + ((info >> 8) & mask4);
//   info = (info & mask5) + ((info >> 16) & mask5); 

//   return info; 
// }

// int averageOfTwo(int x, int y) {
//   return (x >> 1) + (y >> 1) + ((x & 1) & (y &  1)); 
// }

void print(int x) {
  for(int i=31;i>=0;i--) {
    printf("%d", (x >> i) & 1); 
  }
  printf("\n"); 
}

// int subOK(int x, int y) {
//   // overflow can only occur when signs of x and (-y) are equal 
//   // and we can check if there was overflow by comparing the sign of (x - y) and x (or -y)

//   int operand = (~y)+1; 
//   int sign = (x >> 31); // 1111...(2) when minus, 0000...(2) when plus 
//   int isSignSame = ~(sign ^ ((operand) >> 31)); // 111... when same, else 0  
//   int res = x + operand; 

//   // print(x); // minus
//   // print(operand); // minus 
//   // print(sign); // minus -> 1
//   // print(isSignSame); // same -> 1 
//   // print(res); // minus 
//   // print((sign ^ (res >> 31))); // is sign different ? 1 : 0 
//   // print(!(isSignSame & (sign ^ (res >> 31)))); 

//   return !(isSignSame & (sign ^ (res >> 31))); 
// }

int mulNineoverSixteen(int x) {
  // dividing 16 is same with x >> 4, and multiplying 9 is same with adding x << 3 and x 
  // but we have to think about overflow. 
  // so do the left-side bit operation first and add. 
  int rest = ((x & 15) + ((x & 1) << 3)); // (rest / 16) is floating point
  // printf("%d\n", rest);  
  int temp = (x >> 4) + (x >> 1) + (rest >> 4); 
  // printf("%d\n", temp); 
  rest = rest & 15; 
  temp += (!!rest & !!(temp >> 31)); 
  // printf("%d\n", (!!rest & !!(temp >> 31))); 
  return temp; 
}

unsigned float_quarter(unsigned uf) {
  // infinity, NaN => return uf 
  // exp = 1 or 2 => additional 1 at start , shifting, rounding by GRS rule
  // exp = 0 => shifting, rounding 
  // else => exp -= 2 
  unsigned sign = uf & 0x80000000;
  unsigned frac = uf & 0x007FFFFF;
  unsigned exp = (uf >> 23) & 0xFF;

  if (exp == 0xFF) return uf;
  if (exp > 0x2) return (sign | ((exp - 2) << 23) | frac);
  // exp is 0 or 1 or 2 
  else { 
    unsigned normalized = frac | ((exp != 0) << 23); 
    unsigned remainder = normalized & 0x3; 
    unsigned shifted = normalized >> 2; 

    // grs rounding
    unsigned guard = (remainder >> 1) & 1;
    unsigned round = remainder & 1;
    // unsigned sticky = 0; 
    unsigned lsb = shifted & 1;
    if (guard && (round | lsb)) // | sticky
      shifted++;
    return sign | shifted;
  }
}

unsigned float_quarter(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned frac = uf & 0x007FFFFF;
  unsigned exp = (uf >> 23) & 0xFF;

  if (exp == 0xFF) return uf; // NaN, Inf
  if (exp > 2) return sign | ((exp - 2) << 23) | frac;

  // exp == 0,1,2
  {
    unsigned normalized = frac | ((exp != 0) << 23); 
    unsigned remainder = normalized & 0x3; 
    unsigned shifted = normalized >> 2; 

    // guard-round-sticky rounding
    unsigned guard = (remainder >> 1) & 1;
    unsigned round = remainder & 1;
    unsigned sticky = 0; 
    unsigned lsb = shifted & 1;
    if (guard && (round | sticky | lsb))
      shifted++;

    return sign | shifted;
  }
}

int main() {
  unsigned x = 0x7; 
  print(x); 
  print(float_quarter(x)); 
}