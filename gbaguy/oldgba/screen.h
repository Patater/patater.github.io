@define MODE_0 0x00
@define MODE_1 0x01
@define MODE_2 0x02
@define MODE_3 0x03
@define MODE_4 0x04
@define MODE_5 0x05

@define BACKBUFFER 0x010
@define H_BLANK_OAM 0x020

@define OBJ_MAP_2D 0x00
@define OBJ_MAP_1D 0x040

@define FORCE_BLANK 0x080

@define BG0_ENABLE 0x0100
@define BG1_ENABLE 0x0200 
@define BG2_ENABLE 0x0400
@define BG3_ENABLE 0x0800
@define OBJ_ENABLE 0x01000 
@define WIN1_ENABLE 0x02000 
@define WIN2_ENABLE 0x04000
@define WINOBJ_ENABLE 0x08000
@define VRAM 0x06000000
@define VPAL 0x05000000
@define REG_DISPCNT 0x04000000
;VRAM
;	@DCD 0x06000000	;video ram address
;REG_DISPCNT 
;	@DCD 0x04000000 ;screenmode reg.

@macro DrawMode3Pic picDataLabel
ldr r1,=picDataLabel
ldr r0,=REG_DMA3SAD
str r1,[r0]
ldr r1,=VRAM
ldr r0,=REG_DMA3DAD
str r1,[r0]
ldr r1,=(19200|DMA_32NOW)
ldr r0,=REG_DMA3CNT
str r1,[r0]
@endm

;@macro SetMode modedef
;ldr r7,=REG_DISPCNT
;ldr r8,=modedef
;str r8,[r7]
;@endm
; the above don't work

@macro CLS
ldr r1,=REG_DISPCNT
ldr r2,=[r1]
ldr r0,=REG_DISPCNT
ldr r1,=0
str r1,[r0]
str r2,[r0]
@endm

@macro RandNum Seed
gba_rand:
ldr	r3, =Seed		;; Point at seeds.
ldmia	r3, {r1, r2}		;; Load them.
tst	r2, r2, lsr #1		;; Top bit into carry.
movs	r4, r1, rrx		;; 33 bit rotate right.
adc	r2, r2, r2		;; Carry into lsb of Rb.
eor	r4, r4, r1, lsl #12	;; (involved!)
eor	r1, r4, r4, lsr #20	;; (similarly involved!)
stmia	r3, {r1, r2}		;; Use these next time.
@endm