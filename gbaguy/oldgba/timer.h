;; defines from ThePernProject.com

@define TIME_FREQUENCY_SYSTEM 0x0
@define TIME_FREQUENCY_64 0x1
@define TIME_FREQUENCY_256 0x2
@define TIME_FREQUENCY_1024 0x3
@define TIME_OVERFLOW 0x4
@define TIME_ENABLE 0x80
@define TIME_IRQ_ENABLE 0x40

;;register defines added by GbaGuy. have fun. :)

@define REG_TM0D   0x4000100
@define REG_TM0CNT 0x4000102
@define REG_TM1D   0x4000104
@define REG_TM1CNT 0x4000106
@define REG_TM2D   0x4000108
@define REG_TM2CNT 0x400010A
@define REG_TM3D   0x400010C
@define REG_TM3CNT 0x400010E

;; Macros to enable certain timers, by GbaGuy

@macro EnableTM0 Register
ldr r0,=REG_TM0CNT
orr Register,Register,#TIME_ENABLE
strh Register,[r0]
@endm

@macro EnableTM1 Register
ldr r0,=REG_TM1CNT
orr Register,Register,#TIME_ENABLE
strh Register,[r0]
@endm

@macro EnableTM2 Register
ldr r0,=REG_TM2CNT
orr Register,Register,#TIME_ENABLE
strh Register,[r0]
@endm

@macro EnableTM3 Register
ldr r0,=REG_TM3CNT
orr Register,Register,#TIME_ENABLE
strh Register,[r0]
@endm

;; waitseconds macro by GbaGuy
;; use like this: WaitSeconds 30, label31
;; the first thing is the number of seconds to wait
;; the second is a label to use for the loop
;; note that there are other identical macros:
;; WaitSeconds0, WaitSeconds1 ... all the way to 3

@macro WaitSeconds0 Number, arglabel
ldr r2,=Number  
arglabel  
ldr r1,=REG_TM0D
ldrh r3,[r1]
ldr r4,=0 
cmp r3,r4    
bne arglabel
subs r2,r2,#1
bne arglabel
@endm

@macro WaitSeconds1 Number, arglabel
ldr r2,=Number  
arglabel  
ldr r1,=REG_TM1D
ldrh r3,[r1]
ldr r4,=0 
cmp r3,r4    
bne arglabel
subs r2,r2,#1
bne arglabel
@endm

@macro WaitSeconds2 Number, arglabel
ldr r2,=Number  
arglabel  
ldr r1,=REG_TM2D
ldrh r3,[r1]
ldr r4,=0 
cmp r3,r4    
bne arglabel
subs r2,r2,#1
bne arglabel
@endm

@macro WaitSeconds3 Number, arglabel
ldr r2,=Number  
arglabel  
ldr r1,=REG_TM3D
ldrh r3,[r1]
ldr r4,=0 
cmp r3,r4    
bne arglabel
subs r2,r2,#1
bne arglabel
@endm

;; good luck!


