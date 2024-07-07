#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"



DMA_info DMA_config{
	.NUMBER			     = DMA1,
	.STREAM_NUM			 = DMA_STREAM_0,
	.CHANNEL			 = DMA_CHANNEL_0,
	.DIRECTION			 = MEMORY_TO_MEMORY,
	.PRIORITY			 = DMA_LOW,
	.CIRCULAR_MODE		 = DMA_DISABLED,
	.PER_INCREMENT		 = DMA_ENABLED,
	.MEM_INCREMENT		 = DMA_ENABLED,
	.PER_SIZE			 = DMA_BYTE,
	.MEM_SIZE			 = DMA_BYTE,
	.PER_INC_OFFSET_SIZE = DMA_DISABLED,
}