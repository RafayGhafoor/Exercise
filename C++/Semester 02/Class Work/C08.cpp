#include <cmath>
#include <iostream>
// Define a new type which is byte but in actual it is unsigned char
// # is a pre-processor directive
#define byte unsigned char

#define BYTECOUNT(b) (int(ceil(b / 8)))

#define BYTENUM(b) (b / 8)

using namespace std;

class BitVector {
  byte *bits;
  const int nbits; // number of bits

public:
  BitVector(int bcount) : nbits(bcount) { bits = new byte[BYTECOUNT(bcount)]; }

  void set() {
    byte mask = 0x80;
    mask = mask << (b % 8);
    bits[BYTENUM(b)] |= mask;
  }

  bool test() {
    byte mask = 0x80;
    mask = mask >> (b % 8);
    mask = mask & bits[BYTENUM(b)];
    return mask != 0;
  }

  void reset(int b) {
    byte mask = 0x80;
    mask = ~(mask >> (b % 8));
    bits[BYTENUM(b)] &= mask;
  }
};