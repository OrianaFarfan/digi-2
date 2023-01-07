#define SRAM_SIZE		((uint32_t) 0x00005000)
#define SRAM_BASE		((uint32_t) 0x20000000)
#define STACKINIT		((interrupt_t)(SRAM_BASE+SRAM_SIZE))

#define RCC_BASE 0x40021000 // direccion base del
#define RCC_CR_OFFSET 0x00
#define RCC_CFGR_OFFSET 0x04
#define APB2ENR_OFFSET 0x18

#define FLASH_BASE 0x40022000
#define FLASH_ACR_OFFSET 0x00


typedef int			   int32_t;
typedef short		   int16_t;
typedef char		   int8_t;
typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;

volatile int flag = 0;
typedef void(*interrupt_t)(void);
int main(void); //Faltaba esto
void handler_systick(void)
{
	flag = 1;
}


const interrupt_t vector_table[256] __attribute__ ((section(".vtab"))) = {
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
	handler_systick,										// 0x0000_003C
};


int main(void)
{


	int *RCC_APB2ENR_ptr = (int *)(RCC_BASE + APB2ENR_OFFSET);
	int *RCC_CR_ptr = (int *)(RCC_BASE + RCC_CR_OFFSET);
	int *RCC_CFGR_ptr = (int *)(RCC_BASE + RCC_CFGR_OFFSET);
	int *FLASH_ACR_ptr = (int *)(FLASH_BASE + FLASH_ACR_OFFSET);

	*RCC_CR_ptr |= (1 << 16); // Enable HSE
	while (!(*RCC_CR_ptr & (1 << 17))); // Wait for HSE is locked

	*RCC_CR_ptr &= ~(1 << 24); // Disable PLL
	*RCC_CFGR_ptr |= (0b0111 << 18);        // Set PLLMULL to 9. Set PLL output clock to 72 Mhz
	*RCC_CFGR_ptr |= (1 << 16);             // Select HSE as the PLL source clock
	*RCC_CR_ptr |= (1 << 24);               // Enable PLL
	while (!(*RCC_CR_ptr & (1 << 25))); // Wait for PLL to lock

	*FLASH_ACR_ptr |= (0b010 << 0); // Set FLASH WAIT STATE to 2
	*RCC_CFGR_ptr |= (0b0000 << 4);         // Set AHB HPRE division to 1. Set AHB clock to 72 Mhz
	*RCC_CFGR_ptr |= (0b100 << 8);          // Set APB1 PPRE1 division to 2. Set AHB clock to 36 Mhz
	*RCC_CFGR_ptr |= (0b10 << 14);          // Set ADCPRE 72Mhz/6 = 12Mhz

	*RCC_CFGR_ptr |= (0b10 << 0); // Select PLL clock as the system clock
	while (!(*RCC_CFGR_ptr & (0b10 << 2))); // Wait for PLL clock to be selected



//Clock
int *RCC_C = (int *)(0x40021018);
*RCC_C |= (1<<4); //Habilito el clock para write y read del IOPC

//PORT C
int *CRL_C = (int *)(0x40011000+0x00); //Modos de salida(modo 7), salida del GPIO
*CRL_C = 0x33333333; //Seteo los modos de salida
int *CRH_C = (int *)(0x40011004);
*CRH_C = 0x33333333; //Todos los puertos C los convertimos en salida
int *ODR_C = (int *)(0x4001100C);

int *SYST_CSR = 0xE000E010; //SysTick Control and Status Register, enables the SysTick features
int *SYST_RVR = 0xE000E014; //SysTick Reload Value Register, specifies the start value to load into the SYST_CVR register
int *SYST_CVR = 0xE000E018; //SysTick Current Value Register, contains the current value of the SysTick counter
int *SYST_CALIB = 0xE000E01C; //SysTick Calibration Value Register, indicates the SysTick calibration properties

//Primero inicializa calibrando con el RVR con el CALIB para que cuente 10ms
*SYST_RVR = 9000000;

//Pongo en 0 el counter flag para que luego lo ponga en 0 cuando llego al final de la cuenta(Directamente no lo toco)
//Pongo en 0 el CLKSOURCE para que use el clock del procesador
//Pongo en 1 el TICKINT para hacerlo por interrupcion
//Pongo el ENABLE en 1 para que cuente
*SYST_CSR = 0x00000000;
*SYST_CSR |= (1<<0);
*SYST_CSR |= (1<<1);

//Seteo el CVR despues de configurar el reload para que ande bien
*SYST_CVR = 0x00;


while(1)
{
	if (flag )
	{
		*ODR_C ^= (1 << 13);
		flag = 0;
	}
}


return 0;
}
