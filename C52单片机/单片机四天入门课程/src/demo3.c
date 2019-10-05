#include "../lib/STC89C5xRC.h"
unsigned char dofly_DuanMa[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66,
                                0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char dofly_WeiMa[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
dula = P2 ^ 3;
wela = P2 ^ 3;
void delay(unsigned char time) {
  int k = 0;
  for (; k < 100; k++) {
    for (; time >= 0; time--)
      ;
  }
}
int main() {
  int i = 0;
  int number = 233;
  int array[3];
  int array[0] = number / 100;
  int array[1] = (number - array[0] * 100) / 10;
  int array[2] = number % 10;
  while (1) {
    for (i = 0; i < 3; i++) {
      P0 = dofly_WeiMa[array[i]];
      wela = 1;
      wela = 0;
      P0 = dofly_DuanMa[i];
      dula = 1;
      dula = 0;
      delay(1000);
    }
    i = 0;
  }

  return 0;
}
