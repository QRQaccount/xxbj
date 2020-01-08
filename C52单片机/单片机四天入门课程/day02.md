### 按键

### 定时器/计数器

1. 计数器的功能实现
   1. 打开所需要的开关
      1. TMOD
      2. TCON
2. 定时器功能

### 串口通信

1. UART串口通信
   1. 波特率
   2. 检验位/停止位
   3. RxD/TxD
2. UART与定时器1
3. RS232，RS485,TTL
4. UART转USB
5. 相应寄存器的使用
   1. SCON用于设置串口通信方式
   2. TH1，TMOD,PCON(其中的SMOD)
   3. TCON，TR
      
      ```c
      void Uart(){
      SCON = 0x50;
      TMOD = 0x20;
      TH1 = 0xfe;
      TR = 1;
      }
      ```

int main(void){
    Uart();
    while(1){
        SBUFF  = 'A';
    }
    return 0;
}
```

### 中断

1. 外部中断
   - IT0,IT1tt
   - EX0 = 0;
   - EA全局中断是
