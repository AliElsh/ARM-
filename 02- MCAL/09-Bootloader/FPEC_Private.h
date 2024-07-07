#ifndef BL_PRIVATE_H_
#define BL_PRIVATE_H_

typedef struct{
	uint32 ACR;
	uint32 KEYR;
	uint32 OPTKEYR;
	uint32 SR;
	union{
		uint32 R;
		struct{
			uint32 PG		: 1;
			uint32 SER		: 1;
			uint32 MER		: 1;
			uint32 SNB		: 4;
			uint32 RESD1	: 1;
			uint32 PSIZE	: 2;
			uint32 RESD2	: 6;
			uint32 STRT		: 1;
			uint32 RESD3	: 7;
			uint32 EOPIE	: 1;
			uint32 ERRIE	: 1;
			uint32 RESD4	: 1;
			uint32 LOCK		: 1;
		}B;
	}CR;
	uint32 OPTCR;
}FLASH_type;

#define FLASH	((volatile FLASH_type*)0x40023C00)


#endif
