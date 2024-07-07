#ifndef  SPI_Private_h
#define SPI_Private_h


typedef struct
{
	

	uint32 CR1;
	uint32 CR2;
	uint32 SR;
	uint32 DR;
	uint32 CRCPR;
	uint32 RXCRCR;
	uint32 TXCRCR;
	uint32 I2SCFGR;
	uint32 I2SPR;	

}SPI_t;


//SPI1&SPI4 IN APB2 BUS 
//SPI2&SPI3 IN APB1 BUS 
#define SPI_1BASE_ADRESS       0x40013000
#define SPI_2BASE_ADRESS       0x40003800
#define SPI_3BASE_ADRESS       0x40003C00
#define SPI_4BASE_ADRESS       0x40013400


#define SPI_1                ((volatile SPI_t*)SPI_1BASE_ADRESS)
#define SPI_2                ((volatile SPI_t*)SPI_2BASE_ADRESS)
#define SPI_3                ((volatile SPI_t*)SPI_3BASE_ADRESS)
#define SPI_4                ((volatile SPI_t*)SPI_4BASE_ADRESS)

#endif
