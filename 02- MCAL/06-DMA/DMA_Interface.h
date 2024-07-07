#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

typedef struct
{
	uint8 NUMBER				;
	uint8 STREAM_NUM			;
	uint8 CHANNEL				;
	uint8 DIRECTION				;
	uint8 PRIORITY				;
	uint8 CIRCULAR_MODE			;
	uint8 PER_INCREMENT			;
	uint8 MEM_INCREMENT			;
	uint8 PER_SIZE				;
	uint8 MEM_SIZE				;
	uint8 PER_INC_OFFSET_SIZE	;
}DMA_info;

DMA_info DMA_config;

typedef enum{
	DMA1,
	DMA2
}DMA_NUM_E;

typedef enum{
	DMA_LOW,
	DMA_MEDIUM,
	DMA_HIGH,
	DMA_VERY_HIGH
}DMA_PRIOTITY_E;

typedef enum{
	DMA_BYTE,
	DMA_HALF_WORD,
	DMA_WORD
}DMA_DATA_SIZE_E;


typedef enum{
	DMA_CHANNEL_0,
	DMA_CHANNEL_1,
	DMA_CHANNEL_2,
	DMA_CHANNEL_3,
	DMA_CHANNEL_4,
	DMA_CHANNEL_5,
	DMA_CHANNEL_6,
	DMA_CHANNEL_7
}DMA_CHANNEL_SELECTION_E;

typedef enum{
	DMA_STREAM_0,
	DMA_STREAM_1,
	DMA_STREAM_2,
	DMA_STREAM_3,
	DMA_STREAM_4,
	DMA_STREAM_5,
	DMA_STREAM_6,
	DMA_STREAM_7
}DMA_STREAM_SELECTION_E;

typedef enum{
	PER_TO_MEMORY,
	MEMORY_TO_PER,
	MEMORY_TO_MEMORY,
	PER_TO_PER
}DMA_DATA_TRANSFER_DIR_E;

typedef enum{
	DMA_DISABLED,
	DMA_ENABLED
}EN_DIS_E;

void DMA_init(void);

void DMA_voidStart(uint32 *ptrUint32SourceAddress, uint32 *ptrUint32DistinationAddress, uint16 copy_uint16BlockSize);

#endif