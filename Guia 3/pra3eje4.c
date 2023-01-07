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


int *RCC = (int *)(0x40021018);
//RCC = 0x40021018; //Designo y habilito el clock
*RCC |= (1<<4); //Habilito el clock para write y read del IOPC
int *CRL = (int *)(0x40011000+0x00); //Modos de salida(modo 7), salida del GPIO
*CRL = 0x33333333; //Seteo los modos de salida
int *CRH = (int *)(0x40011004);
*CRH = 0x33333333; //Todos los puertos C los convertimos en salida
int *ODR = (int *)(0x4001100C);


//  DMA code
//	DEVMAP->RCC.REGs.APB2ENR |= (1 << 4);					// Enable GPIOC clock.

//	DEVMAP->GPIOs[GPIOC].REGs.CRL  = 0x33333333;			// Make low GPIOC output
//	DEVMAP->GPIOs[GPIOC].REGs.CRH  = 0x33333333;			// Make high GPIOC output
//	DEVMAP->GPIOs[GPIOC].REGs.ODR ^= -1;


for(;;)
{
	for(int i=0; i<1000000; i++);
	*ODR = (1 << 13);
	for(int i=0; i<1000000; i++);
	*ODR = (0 << 13);

};
	return 0;
}