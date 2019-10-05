#include <STC89C5xRC.h>

int main(void) {
  TMOD = 0x01;
  TCON = 0x10;
  TH0 = 0x3C;
  TL0 = 0xAF;
  ET0 = 1;
  EA = 1;
  return 0;
}

void time interrupt 1() {}