#include "../lib/STC89C5xRC.h"
unsigned char dofly_DuanMa[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66,
                                0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char dofly_WeiMa[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
sbit dula = P2 ^ 2;
sbit wela = P2 ^ 3;
void delay(unsigned int time) {
  int i;
  for (i = 0; i < 100; i++) {
    for (; time >= 0; time--)
      ;
  }
}
void display(unsigned int number) {
  int i;
  int array[5];

  array[0] = number / 10000;
  array[1] = (number - array[0] * 10000) / 1000;
  array[2] = (number - array[0] * 10000 - array[1] * 1000) / 100;
  array[3] =
      (number - array[0] * 10000 - array[1] * 1000 - array[2] * 100) / 10;
  array[4] = number % 10;
  for (i = 0; i < 5; i++) {
    P0 = dofly_DuanMa[array[i]];
    dula = 1;
    dula = 0;
    P0 = dofly_WeiMa[i];
    wela = 1;
    wela = 0;
    delay(1000);
  }
}
int main(void) {
  TMOD = 0x5;
  TCON = 0x10;
  unsigned int counter;
  unsigned int counter_l, counter_h;
  while (1) {
    counter_l = TL0;
    counter_h = TH0;
    counter = counter_h | counter_l;
    display(counter);
  }

  return 0;
}
