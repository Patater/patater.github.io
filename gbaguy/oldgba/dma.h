; dma.h, assembly header file for DMA
; this and all my asm headers are converted/ripped by hand
; from ThePernProject.com, go there, the C tutorials there
; rule. :)

;these defines let you control individual bit in the control register

@define DMA_ENABLE 0x80000000
@define DMA_INTERUPT_ENABLE 0x40000000
@define DMA_TIMEING_IMMEDIATE 0x00000000
@define DMA_TIMEING_VBLANK 0x10000000
@define DMA_TIMEING_HBLANK 0x20000000
@define DMA_TIMEING_SYNC_TO_DISPLAY 0x30000000
@define DMA_16 0x00000000
@define DMA_32 0x04000000
@define DMA_REPEATE 0x02000000
@define DMA_SOURCE_INCREMENT 0x00000000
@define DMA_SOURCE_DECREMENT 0x00800000
@define DMA_SOURCE_FIXED 0x01000000
@define DMA_DEST_INCREMENT 0x00000000
@define DMA_DEST_DECREMENT 0x00200000
@define DMA_DEST_FIXED 0x00400000
@define DMA_DEST_RELOAD 0x00600000

;register defines, ripped from GBA.h from DevKitAdvanced

@define REG_DMA0SAD   0x40000B0
@define REG_DMA0SAD_L 0x40000B0
@define REG_DMA0SAD_H 0x40000B2
@define REG_DMA0DAD   0x40000B4
@define REG_DMA0DAD_L 0x40000B4
@define REG_DMA0DAD_H 0x40000B6
@define REG_DMA0CNT   0x40000B8
@define REG_DMA0CNT_L 0x40000B8
@define REG_DMA0CNT_H 0x40000BA
@define REG_DMA1SAD   0x40000BC
@define REG_DMA1SAD_L 0x40000BC
@define REG_DMA1SAD_H 0x40000BE
@define REG_DMA1DAD   0x40000C0
@define REG_DMA1DAD_L 0x40000C0
@define REG_DMA1DAD_H 0x40000C2
@define REG_DMA1CNT   0x40000C4
@define REG_DMA1CNT_L 0x40000C4
@define REG_DMA1CNT_H 0x40000C6
@define REG_DMA2SAD   0x40000C8
@define REG_DMA2SAD_L 0x40000C8
@define REG_DMA2SAD_H 0x40000CA
@define REG_DMA2DAD   0x40000CC
@define REG_DMA2DAD_L 0x40000CC
@define REG_DMA2DAD_H 0x40000CE
@define REG_DMA2CNT   0x40000D0
@define REG_DMA2CNT_L 0x40000D0
@define REG_DMA2CNT_H 0x40000D2
@define REG_DMA3SAD   0x40000D4
@define REG_DMA3SAD_L 0x40000D4
@define REG_DMA3SAD_H 0x40000D6
@define REG_DMA3DAD   0x40000D8
@define REG_DMA3DAD_L 0x40000D8
@define REG_DMA3DAD_H 0x40000DA
@define REG_DMA3CNT   0x40000DC
@define REG_DMA3CNT_L 0x40000DC
@define REG_DMA3CNT_H 0x40000DE

;these defines group common options to save typing. You may notice that I don't have to include the option to increment the source and address register as that is the default.

;;;@define DMA_32NOW DMA_ENABLE|DMA_TIMEING_IMMEDIATE|DMA_32 
;;;@define DMA_16NOW DMA_ENABLE|DMA_TIMEING_IMMEDIATE|DMA_16 

@define DMA_32NOW 0x84000000
@define DMA_16NOW 0x80000000

;;;I had to explicitly make that define, because Goldroad couldn't handle the expression
;;;in the original versions of DMA_32NOW and DMA_16NOW. they both work the same so
;;;it doesn't really matter. just so ya know.
