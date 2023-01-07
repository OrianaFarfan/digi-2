// vi: ts=4 shiftwidth=4

#define SRAM_SIZE		((uint32_t) 0x00005000)
#define SRAM_BASE		((uint32_t) 0x20000000)
#define STACKINIT		((interrupt_t)(SRAM_BASE+SRAM_SIZE))

int main();
void delay_ms(unsigned int delay);
void SysTick_Handler();

typedef int			   int32_t;
typedef short		   int16_t;
typedef char		   int8_t;
typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;

typedef void(*interrupt_t)(void);

const interrupt_t vector_table[] __attribute__ ((section(".vtab"))) = {
	STACKINIT,												// 0x0000_0000 Stack Pointer
	(interrupt_t) main,										// 0x0000_0004 Reset
	0,														// 0x0000_0008
	0,														// 0x0000_000C
	0,														// 0x0000_0010
	0,														// 0x0000_0014
	0,														// 0x0000_0018
	0,														// 0x0000_001C
	0,														// 0x0000_0020
	0,														// 0x0000_0024
	0,														// 0x0000_0028
	0,														// 0x0000_002C
	0,														// 0x0000_0030
	0,														// 0x0000_0034
	0,														// 0x0000_0038
	SysTick_Handler,										// 0x0000_003C SYSTICK
};

//Habilito los registros
int *APB2 = 0x40021000+0x18;
int *CRH_C = 0x40011000 + 0x04;
int *ODR_C = 0x40011000 + 0x0C;

volatile int *SYST_CSR = 0xE000E010;
int *SYST_RVR = 0xE000E014;
int *SYST_CVR = 0xE000E018;
int *SYST_CALIB = 0xE000E01C;

//Systick
int contador = 0;

void SysTick_Handler(void)
{
	contador++;
}

void delay_ms(unsigned int delay)
{
	while(contador < (delay/10)){

	};

	contador = 0;
}

int main(void)
{
	*APB2 |= (1 << 4); //Lo mismo que arriba
	*CRH_C = 0x33333333; // Se configura CRH con General Purpose open drain y outputmode max speed 50 MHz
	*ODR_C = 0x0000FFFF; //Se colocan las salidas en 1 porque el led se prende con 1

	*SYST_RVR = *SYST_CALIB & 0xFFFFFF;
	*SYST_CSR = 0x00000;
	*SYST_CSR |= 0x03;
	*SYST_CVR = 0x00000000;
	for(;;){
		*ODR_C ^= 0x02000;
		delay_ms(1000);
	};
	return 0;
}
