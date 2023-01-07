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
*SYST_RVR = *SYST_CALIB & 0xFFFFFF;

//Pongo en 0 el counter flag para que luego lo ponga en 0 cuando llego al final de la cuenta(DIrectamente no lo toco)
//Pongo en 0 el CLKSOURCE para que use el clock del procesador
//Pongo en 0 el TICKINT para hacerlo por polling(Lo pondria en 1 si hiciera el de la interrupcion)
//Pongo el ENABLE en 1 para que cuente
*SYST_CSR = 0x00000000;
*SYST_CSR |= (1<<0);

//Seteo el CVR despues de configurar el reload para que ande bien
*SYST_CVR = 0x00;


for(;;)
{
	if(*SYST_CSR & (1<<16)){ //Leo el bit 16 del CSR, si esta en 1 se prende
		*ODR_C = (0 << 13); //Prendo el LED
	}
	else
	{
		*ODR_C = (1 << 13); //Apago el LED
	}
};
	return 0;
}