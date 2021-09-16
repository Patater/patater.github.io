; KEY PAD DEFINES
@define KEY_A 1
@define KEY_B 2
@define KEY_SELECT 4
@define KEY_START 8
@define KEY_RIGHT 16
@define KEY_LEFT 32
@define KEY_UP 64
@define KEY_DOWN 128
@define KEY_R 256
@define KEY_L 512
@define KEYS 0x04000130

@macro IsKeyDown keydef
ldr r3,=KEYS
ldr r2,=keydef
ldr r4,[r3]
ands r4,r4,r2
@endm

; Goldroad has a define-in-macro
; won't-work problem, so the above
; macro won't work