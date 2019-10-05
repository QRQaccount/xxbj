#include <STC89C5xRC.h>
void delay(unsigned int time){
    for(int i = 0;i<100;i++)
    for(; time>=0; i--);
 
}
int main(void)
{
    P2 = 0xfe;
    while(1){
        delay(1000);
        P2 = ~P2;
        P2 = P2<<1;
        P2 = ~P2;
    }
    
    return 0;
}
