#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DET.h"

#include "DMA_private.h"
#include "DMA_interface.h"
#include "DMA_config.h"

void DMA_init(void)
{
	switch(DMA_config.NUMBER)
	{
		case DMA1:
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.CHSEL  = DMA_config.CHANNEL;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.DIR    = DMA_config.DIRECTION;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.PL     = DMA_config.PRIORITY;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.CIRC   = DMA_config.CIRCULAR_MODE;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.PINC   = DMA_config.PER_INCREMENT;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.MINC   = DMA_config.MEM_INCREMENT;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.PSIZE  = DMA_config.PER_SIZE;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.MSIZE  = DMA_config.MEM_SIZE;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.PINCOS = DMA_config.PER_INC_OFFSET_SIZE;
			break;
		case DMA2:
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.CHSEL  = DMA_config.CHANNEL;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.DIR    = DMA_config.DIRECTION;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.PL     = DMA_config.PRIORITY;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.CIRC   = DMA_config.CIRCULAR_MODE;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.PINC   = DMA_config.PER_INCREMENT;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.MINC   = DMA_config.MEM_INCREMENT;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.PSIZE  = DMA_config.PER_SIZE;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.MSIZE  = DMA_config.MEM_SIZE;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.PINCOS = DMA_config.PER_INC_OFFSET_SIZE;
			break;
		default:
			//det

	}
}

void DMA_voidStart(uint32 *ptrUint32SourceAddress, uint32 *ptrUint32DistinationAddress, uint16 copy_uint16BlockSize)
{
	switch (DMA_config.NUMBER)
	{
		case DMA1:
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.EN = 0;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SPAR     = ptrUint32SourceAddress;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SM0AR    = ptrUint32DistinationAddress;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SNDTR    = copy_uint16BlockSize;
			DMA1 -> Stream[DMA_config.STREAM_NUM].SCR.B.EN = 1;
		break;
		case DMA2:
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.EN = 0;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SPAR  = ptrUint32SourceAddress;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SM0AR = ptrUint32DistinationAddress;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SNDTR = copy_uint16BlockSize;
			DMA2 -> Stream[DMA_config.STREAM_NUM].SCR.B.EN = 1;
		break;
		default:
		// det
	}
}