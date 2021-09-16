;; Defines taken from ThePernProject 
;; and specially treated for ASM
;; by GbaGuy.

@define REG_BG0CNT  0x4000008
@define REG_BG1CNT  0x400000A
@define REG_BG2CNT  0x400000C
@define REG_BG3CNT  0x400000E
@define REG_BG0HOFS 0x4000010
@define REG_BG0VOFS 0x4000012
@define REG_BG1HOFS 0x4000014
@define REG_BG1VOFS 0x4000016
@define REG_BG2HOFS 0x4000018
@define REG_BG2VOFS 0x400001A
@define REG_BG3HOFS 0x400001C
@define REG_BG3VOFS 0x400001E
@define REG_BG2PA   0x4000020
@define REG_BG2PB   0x4000022
@define REG_BG2PC   0x4000024
@define REG_BG2PD   0x4000026
@define REG_BG2X    0x4000028
@define REG_BG2X_L  0x4000028
@define REG_BG2X_H  0x400002A
@define REG_BG2Y    0x400002C
@define REG_BG2Y_L  0x400002C
@define REG_BG2Y_H  0x400002E
@define REG_BG3PA   0x4000030
@define REG_BG3PB   0x4000032
@define REG_BG3PC   0x4000034
@define REG_BG3PD   0x4000036
@define REG_BG3X    0x4000038
@define REG_BG3X_L  0x4000038
@define REG_BG3X_H  0x400003A
@define REG_BG3Y    0x400003C
@define REG_BG3Y_L  0x400003C
@define REG_BG3Y_H  0x400003E

@define BG_MOSAIC_ENABLE 0x40
@define BG_COLOR_256 0x80
@define BG_COLOR_16 0x0

@define TEXTBG_SIZE_256x256 0x0
@define TEXTBG_SIZE_256x512 0x8000
@define TEXTBG_SIZE_512x256 0x4000
@define TEXTBG_SIZE_512x512 0xC000

@define ROTBG_SIZE_128x128 0x0
@define ROTBG_SIZE_256x256 0x4000
@define ROTBG_SIZE_512x512 0x8000
@define ROTBG_SIZE_1024x1024 0xC000

@define WRAPAROUND 0x2000

;#define CharBaseBlock(n) (((n)*0x4000)+0x6000000) //16k * number + start of VRAM = address of character base block
;#define ScreenBaseBlock(n) (((n)*0x800)+0x6000000) //2k * number + start of VRAM = address of screen base block

@define CHAR_SHIFT 2 ;;used to shift the number over to the right place in REG_BGxCNT
@define SCREEN_SHIFT 8

;; Defines for all 32 screen (map data) blocks and 4 character (bitmap data) blocks

@define CHAR_BLOCK_0 0x6000000
@define CHAR_BLOCK_1 0x6004000
@define CHAR_BLOCK_2 0x6008000
@define CHAR_BLOCK_3 0x600C000
@define SCREEN_BLOCK_0 0x6000000
@define SCREEN_BLOCK_1 0x6000800
@define SCREEN_BLOCK_2 0x6001000
@define SCREEN_BLOCK_3 0x6001800
@define SCREEN_BLOCK_4 0x6002000
@define SCREEN_BLOCK_5 0x6002800
@define SCREEN_BLOCK_6 0x6003000
@define SCREEN_BLOCK_7 0x6003800
@define SCREEN_BLOCK_8 0x6004000
@define SCREEN_BLOCK_9 0x6004800
@define SCREEN_BLOCK_10 0x6005000
@define SCREEN_BLOCK_11 0x6005800
@define SCREEN_BLOCK_12 0x6006000
@define SCREEN_BLOCK_13 0x6006800
@define SCREEN_BLOCK_14 0x6007000
@define SCREEN_BLOCK_15 0x6007800
@define SCREEN_BLOCK_16 0x6008000
@define SCREEN_BLOCK_17 0x6008800
@define SCREEN_BLOCK_18 0x6009000
@define SCREEN_BLOCK_19 0x6009800
@define SCREEN_BLOCK_20 0x600A000
@define SCREEN_BLOCK_21 0x600A800
@define SCREEN_BLOCK_22 0x600B000
@define SCREEN_BLOCK_23 0x600B800
@define SCREEN_BLOCK_24 0x600C000
@define SCREEN_BLOCK_25 0x600C800
@define SCREEN_BLOCK_26 0x600D000
@define SCREEN_BLOCK_27 0x600D800
@define SCREEN_BLOCK_28 0x600E000
@define SCREEN_BLOCK_29 0x600E800
@define SCREEN_BLOCK_30 0x600F000
@define SCREEN_BLOCK_31 0x600F800

;; wow that was alot! :)
;; I think some of that is wrong, so to help:

@macro LoadScreenBlockAddr Register, SBlock
ldr Register,=(((SBlock)*0x800)+0x6000000)
@endm

@macro LoadCharBlockAddr Register, CBlock
ldr Register,=(((CBlock)*0x4000)+0x6000000)
@endm
