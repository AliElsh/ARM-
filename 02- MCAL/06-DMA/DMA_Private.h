#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H
/*
* No fetch, decode, or excute as CPU.
* DMA is faster than CPU in this case.
* DMA is just a peripherial not as CPU.
* Flah needs high power to write in it because it is built 
* by floating get mosfet that need high power to R/W.
* DMA OR CPU can not R/W from the flash.
* Peripheral has fixed address.
* The DMA has higher priority than CPU in transfering data.
* 
*/

/*Stream registers*/
typedef struct{
	union{
		uint32 R;
		struct{
			uint32 EN		   : 1;
			uint32 DMEIE	   : 1;
			uint32 TEIE		   : 1;
			uint32 HTIE		   : 1;
			uint32 TCIE		   : 1;
			uint32 PFCTRL	   : 1;
			uint32 DIR		   : 2;
			uint32 CIRC		   : 1;
			uint32 PINC		   : 1;
			uint32 MINC		   : 1;
			uint32 PSIZE	   : 2;
			uint32 MSIZE       : 2;
			uint32 PINCOS      : 1;
			uint32 PL		   : 2;
			uint32 DBM		   : 1;
			uint32 CT		   : 1;
			uint32 RESERVED_25 : 1;
			uint32 PBURST	   : 2;
			uint32 MBURST	   : 2;
			uint32 CHSEL	   : 3;
			uint32 RESERVED_26 : 4;
		}B;
	}SCR; //Stream Configuration Register
	uint32 SNDTR;
	uint32 SPAR;
	uint32 SM0AR;
	uint32 SM1AR;
	union{
		uint32 R;
		union{
			uint32 FTH		   : 2;
			uint32 DMDIS	   : 1;
			uint32 FS		   : 3;
			uint32 RESERVED_27 : 1;
			uint32 FEIE		   : 1;
			uint32 RESERVED_28 : 24;
		}B;
	}SFCR;
}STREAM_t;

/*DMA registers*/
typedef struct{
	union{
		const uint32 R;
		struct{
			const uint32 FEIF0	    : 1;
			const uint32 RESERVED_1 : 1;
			const uint32 DMEIF0	    : 1;
			const uint32 TEIF0	    : 1;
			const uint32 HTIF0	    : 1;
			const uint32 TCIF0	    : 1;
			const uint32 FEIF1	    : 1;
			const uint32 RESERVED_2 : 1;
			const uint32 DMEIF1	    : 1;
			const uint32 TEIF1	    : 1;
			const uint32 HTIF1	    : 1;
			const uint32 TCIF1	    : 1;
			const uint32 Reserved_3 : 4;
			const uint32 FEIF2	    : 1;
			const uint32 Reserved_4 : 1;
			const uint32 DMEIF2	    : 1;
			const uint32 TEIF2	    : 1;
			const uint32 HTIF2	    : 1;
			const uint32 TCIF2	    : 1;
			const uint32 FEIF3	    : 1;
			const uint32 Reserved_5 : 1;
			const uint32 DMEIF3	    : 1;
			const uint32 TEIF3	    : 1;
			const uint32 HTIF3	    : 1;
			const uint32 TCIF3	    : 1;
			const uint32 Reserved_6 : 4;
		}B;
	}LISR; // Low Interrupt Status Register stream(0...3)
	union{
		uint32 R;
		struct{
			const uint32 FEIF4	   	 : 1;
			const uint32 Reserved_7  : 1;
			const uint32 DMEIF4	     : 1;
			const uint32 TEIF4	     : 1;
			const uint32 HTIF4	     : 1;
			const uint32 TCIF4	     : 1;
			const uint32 FEIF5	     : 1;
			const uint32 Reserved_8  : 1;
			const uint32 DMEIF5	     : 1;
			const uint32 TEIF5	     : 1;
			const uint32 HTIF5	     : 1;
			const uint32 TCIF5	     : 1;
			const uint32 Reserved_9  : 4;
			const uint32 FEIF6	     : 1;
			const uint32 Reserved_10 : 1;
			const uint32 DMEIF6	     : 1;
			const uint32 TEIF6	     : 1;
			const uint32 HTIF6	     : 1;
			const uint32 TCIF6	     : 1;
			const uint32 FEIF7	     : 1;
			const uint32 Reserved_11 : 1;
			const uint32 DMEIF7	     : 1;
			const uint32 TEIF7	     : 1;
			const uint32 HTIF7	     : 1;
			const uint32 TCIF7	     : 1;
			const uint32 Reserved_12 : 4;
		}B;
	}HISR; // High Interrupt Status Register stream(4...7)
	union{
		uint32 R;
		struct{
			uint32 CFEIF0	   : 1;
			uint32 Reserved_13 : 1;
			uint32 CDMEIF0	   : 1;
			uint32 CTEIF0	   : 1;
			uint32 CHTIF0	   : 1;
			uint32 CTCIF0	   : 1;
			uint32 CFEIF1	   : 1;
			uint32 Reserved_14 : 1;
			uint32 CDMEIF1	   : 1;
			uint32 CTEIF1	   : 1;
			uint32 CHTIF1	   : 1;
			uint32 CTCIF1	   : 1;
			uint32 Reserved_15 : 4;
			uint32 CFEIF2	   : 1;
			uint32 Reserved_16 : 1;
			uint32 CDMEIF2	   : 1;
			uint32 CTEIF2	   : 1;
			uint32 CHTIF2	   : 1;
			uint32 CTCIF2	   : 1;
			uint32 CFEIF3	   : 1;
			uint32 Reserved_17 : 1;
			uint32 CDMEIF3	   : 1;
			uint32 CTEIF3	   : 1;
			uint32 CHTIF3	   : 1;
			uint32 CTCIF3	   : 1;
			uint32 Reserved_18 : 4;
		}B;
	}LIFCR; // Low Interrupt Flag Clear stream(0...3)
	union{
		uint32 R;
		struct{
			uint32 CFEIF4	   : 1;
			uint32 Reserved_19 : 1;
			uint32 CDMEIF4	   : 1;
			uint32 CTEIF4	   : 1;
			uint32 CHTIF4	   : 1;
			uint32 CTCIF4	   : 1;
			uint32 CFEIF5	   : 1;
			uint32 Reserved_20 : 1;
			uint32 CDMEIF5	   : 1;
			uint32 CTEIF5	   : 1;
			uint32 CHTIF5	   : 1;
			uint32 CTCIF5	   : 1;
			uint32 Reserved_21 : 4;
			uint32 CFEIF6	   : 1;
			uint32 Reserved_22 : 1;
			uint32 CDMEIF6	   : 1;
			uint32 CTEIF6	   : 1;
			uint32 CHTIF6	   : 1;
			uint32 CTCIF6	   : 1;
			uint32 CFEIF7	   : 1;
			uint32 Reserved_23 : 1;
			uint32 CDMEIF7	   : 1;
			uint32 CTEIF7	   : 1;
			uint32 CHTIF7	   : 1;
			uint32 CTCIF7	   : 1;
			uint32 Reserved_24 : 4;
		}B;
	}HIFCR; // Hign Interrupt Flag Clear stream(4...7)
	
	STREAM_t Stream[8];
}DMA_type;

#define DMA1 ((volatile DMA_type*)0x40026000)
#define DMA2 ((volatile DMA_type*)0x40026400)

#endif