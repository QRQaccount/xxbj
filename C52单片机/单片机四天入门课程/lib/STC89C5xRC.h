
#define sfr  int
#define sbit  int

/*  BYTE Registers  */

/*  用于定义单片机的P0 IO口  */
sfr P0 = 0x80;

/*  用于定义单片机的P1 IO口  */
sfr P1 = 0x90;

/*  用于定义单片机的P2 IO口  */
sfr P2 = 0xA0;

/*  用于定义单片机的P3 IO口(控制特殊寄存器启用第二功能)  */
sfr P3 = 0xB0;

/*  程序状态寄存器  */
sfr PSW = 0xD0;

/*  累加器,与各种运算类指令相关  */
sfr ACC = 0xE0;

/*  B寄存器  */
sfr B = 0xF0;

/*  堆栈指针寄存器  */
sfr SP = 0x81;

/*  数据指针寄存器,低八位  */
sfr DPL = 0x82;

/*  数据指针寄存器,高八位  */
sfr DPH = 0x83;

/*  即功率控制寄存器。包含SMOD，SMOD0，LVDF，POF，GF1，GF0，PD，IDL等控制位。  */
sfr PCON = 0x87;

/*  T0/T1的定时器计数器控制寄存器*/
sfr TCON = 0x88;

/*  T0/T1的定时器计数器方式控制寄存器  */
sfr TMOD = 0x89;

/*  定时器/计数器 0(低八位)  */
sfr TL0 = 0x8A;

/*  定时器/计数器 1(低八位)  */
sfr TL1 = 0x8B;

/*  定时器/计数器 0(高8位)  */
sfr TH0 = 0x8C;

/*  定时器/计数器 1(高8位)  */
sfr TH1 = 0x8D;

/*  中断允许控制寄存器  */
sfr IE = 0xA8;

/*  中断优先级控制器  */
sfr IP = 0xB8;

/*  串行口寄存器  */
sfr SCON = 0x98;

/*  串行口锁存器  */
sfr SBUF = 0x99;

/*  80C51Fx/Rx Extensions  */
sfr AUXR = 0x8E;
sfr AUXR1 = 0xA2;
sfr SADDR = 0xA9;
sfr IPH = 0xB7;
sfr SADEN = 0xB9;
sfr T2CON = 0xC8;
sfr T2MOD = 0xC9;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2 = 0xCC;
sfr TH2 = 0xCD;

/*  BIT Registers  */
/*  PSW   */
sbit CY = PSW^7;
sbit AC = PSW^6;
sbit F0 = PSW^5;
sbit RS1 = PSW^4;
sbit RS0 = PSW^3;
sbit OV = PSW^2;
sbit P = PSW^0;

/*  TCON  */
sbit TF1 = TCON^7;
sbit TR1 = TCON^6;
sbit TF0 = TCON^5;
sbit TR0 = TCON^4;
sbit IE1 = TCON^3;
sbit IT1 = TCON^2;
sbit IE0 = TCON^1;
sbit IT0 = TCON^0;

/*  IE   */
sbit EA = IE^7;
sbit EC = IE^6;
sbit ET2 = IE^5;
sbit ES = IE^4;
sbit ET1 = IE^3;
sbit EX1 = IE^2;
sbit ET0 = IE^1;
sbit EX0 = IE^0;

/*  IP   */
/*	sbit PPC  = IP^6;*/
sbit PT2 = IP^5;
sbit PS = IP^4;
sbit PT1 = IP^3;
sbit PX1 = IP^2;
sbit PT0 = IP^1;
sbit PX0 = IP^0;

/*  P3  */
sbit RD = P3^7;
sbit WR = P3^6;
sbit T1 = P3^5;
sbit T0 = P3^4;
sbit INT1 = P3^3;
sbit INT0 = P3^2;
sbit TXD = P3^1;
sbit RXD = P3^0;

/*  SCON  */
sbit SM0 = SCON^7; // alternatively "FE"
sbit FE = SCON^7;
sbit SM1 = SCON^6;
sbit SM2 = SCON^5;
sbit REN = SCON^4;
sbit TB8 = SCON^3;
sbit RB8 = SCON^2;
sbit TI = SCON^1;
sbit RI = SCON^0;

/*  P1  */
/* PCA
sbit CEX4 = P1^7;
sbit CEX3 = P1^6;
sbit CEX2 = P1^5;
sbit CEX1 = P1^4;
sbit CEX0 = P1^3;
sbit ECI  = P1^2;
*/

sbit T2EX = P1^1;
sbit T2 = P1^0;

/*  T2CON  */
sbit TF2 = T2CON^7;
sbit EXF2 = T2CON^6;
sbit RCLK = T2CON^5;
sbit TCLK = T2CON^4;
sbit EXEN2 = T2CON^3;
sbit TR2 = T2CON^2;
sbit C_T2 = T2CON^1;
sbit CP_RL2 = T2CON^0;

/*  CCON  */
/*  PCA
sbit CF    = CCON^7;
sbit CR    = CCON^6;

sbit CCF4  = CCON^4;
sbit CCF3  = CCON^3;
sbit CCF2  = CCON^2;
sbit CCF1  = CCON^1;
sbit CCF0  = CCON^0;
*/

/////////////////////////////////////////////////
