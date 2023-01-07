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
*RCC |= (1<<2); //Habilito el clock para write y read del GIOPA
int *CRL = (int *)(0x40010800+0x00); //Modos de salida(modo 7), salida del GPIO
*CRL = 0x33333333; //Seteo los modos de salida
int *CRH = (int *)(0x40010800+0x04);
*CRH = 0x33333333; //Todos los puertos A los convertimos en salida
int *ODR = (int *)(0x40010800+0x0C);


for(;;)
{
	for(int i=0; i<1000000; i++);
	*ODR = (1 << 1);
	for(int i=0; i<1000000; i++);
	*ODR = (0 << 1);

};
	return 0;
}
