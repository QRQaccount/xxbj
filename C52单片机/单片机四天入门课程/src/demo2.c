#include <STC89C5xRC.h>
void delay(unsigned int time){
    for(int i = 0;i<100;i++)
    for(; time>=0; i--);
 
}
int main(void)
{
    while(1){
        P2 = 0xfe;
        P2 = ~P2;
        delay(10000);
        P2 = P2<<1;
        delay(10000);    
        }
    
    return 0;
}
