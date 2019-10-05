#include <STC89C5xRC.h>
int main(void) {
  TMOD = 0x01;
  IT0 = 1;
  TR0 = 1;
  EX0 = 1;
  ET0 = 1;
  EA = 1;
  TH0 = 0x3C;
  TL0 = 0xAF;
  while (1)
    ;
  return 0;
}

void timer1() interrupt 1 {
  ET0 = 0;
  while (1)
    ;
}

void int0() interrupt 0 { P0 = 0x01; }
