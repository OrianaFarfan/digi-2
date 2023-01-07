#define SRAM_SIZE		((uint32_t) 0x00005000)
#define SRAM_BASE		((uint32_t) 0x20000000)
#define STACKINIT		((interrupt_t)(SRAM_BASE+SRAM_SIZE))

typedef int			   int32_t;
typedef short		   int16_t;
typedef char		   int8_t;
typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;

typedef void(*interrupt_t)(void);
int main(void); //Faltaba esto

const interrupt_t vector_table[256] __attribute__ ((section(".vtab"))) = {
	STACKINIT,												// 0x0000_0000 Stack Pointer
	(interrupt_t) main,										// 0x0000_0004 Reset
};

int main(void)
{


//Clock
int *RCC_C = (int *)(0x40021018);
*RCC_C |= (1<<4); //Habilito el clock para write y read del IOPC
*RCC_C |= (1<<2);

//PORT C
int *CRL_C = (int *)(0x40011000+0x00); //Modos de salida(modo 7), salida del GPIO
*CRL_C = 0x33333333; //Seteo los modos de salida
int *CRH_C = (int *)(0x40011004);
*CRH_C = 0x33333333; //Todos los puertos C los convertimos en salida
int *ODR_C = (int *)(0x4001100C);

//PORT A
int *CRL_A = (int *)(0x40010800+0x00);
*CRL_A = 0x44444444; //Seteo los modos de entrada
int *CRH_A = (int *)(0x40010800+0x04);
*CRH_A = 0x44444444;//Seteo para que sea de entrada
volatile int *IDR_A = (int *)(0x40010800+0x08);
*IDR_A = 0x44444444;

//  DMA code
//	DEVMAP->RCC.REGs.APB2ENR |= (1 << 4);					// Enable GPIOC clock.

//	DEVMAP->GPIOs[GPIOC].REGs.CRL  = 0x33333333;			// Make low GPIOC output
//	DEVMAP->GPIOs[GPIOC].REGs.CRH  = 0x33333333;			// Make high GPIOC output
//	DEVMAP->GPIOs[GPIOC].REGs.ODR ^= -1;


for(;;)
{
	if(*IDR_A & (1<<0)){
		*ODR_C = (0 << 13);
	}
	else
	{
		*ODR_C = (1 << 13);
	}
};
	return 0;
}