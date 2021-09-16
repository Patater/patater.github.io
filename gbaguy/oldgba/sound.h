@define  REG_SOUND1CNT_L 0x04000060 ;Sound 1 Sweep control  
@define  REG_SOUND1CNT_H 0x04000062 ; Sound 1 Lenght, wave duty and envelope control 
@define  REG_SOUND1CNT_X 0x04000064 ; Sound 1 Frequency, reset and loop control 
@define  REG_SOUND2CNT_L 0x04000068 ; Sound 2 Lenght, wave duty and envelope control 
@define  REG_SOUND2CNT_H 0x0400006C ; Sound 2 Frequency, reset and loop control 
@define REG_SOUND3CNT_L 0x04000070  ;  Sound 3 Enable and wave ram bank control 
@define  REG_SOUND3CNT_H 0x04000072 ;  Sound 3 Sound lenght and output level control 
@define REG_SOUND3CNT_X 0x04000074  ; Sound 3 Frequency, reset and loop control 
@define  REG_SOUND4CNT_L 0x04000078 ; Sound 4 Lenght, output level and envelope control 
@define REG_SOUND4CNT_H 0x0400007C  ; Sound 4 Noise parameters, reset and loop control 
@define REG_SOUNDCNT_L 0x04000080  ; Sound 1-4 Output level and Stereo control 
@define REG_SOUNDCNT_H 0x04000082  ; Direct Sound control and Sound 1-4 output ratio 
@define REG_SOUNDCNT_X 0x04000084  ; Master sound enable and Sound 1-4 play status 
@define REG_SOUNDBIAS 0x04000088  ; Sound bias and Amplitude resolution control 
@define REG_WAVE_RAM0_L 0x04000090  ; Sound 3 samples 0-3 
@define REG_WAVE_RAM0_H 0x04000092  ; Sound 3 samples 4-7 
@define REG_WAVE_RAM1_L 0x04000094 ; Sound 3 samples 8-11 
@define REG_WAVE_RAM1_H 0x04000096  ;  Sound 3 samples 12-15 
@define REG_WAVE_RAM2_L 0x04000098  ; Sound 3 samples 16-19 
@define REG_WAVE_RAM2_H 0x0400009A  ; Sound 3 samples 20-23 
@define REG_WAVE_RAM3_L 0x0400009C  ; Sound 3 samples 23-27 
@define REG_WAVE_RAM3_H 0x0400009E  ; Sound 3 samples 28-31 
@define REG_FIFO_A_L 0x040000A0  ; Direct Sound channel A samples 0-1 
@define REG_FIFO_A_H 0x040000A2  ; Direct Sound channel A samples 2-3 
@define REG_FIFO_B_L 0x040000A4 ; Direct Sound channel B samples 0-1 
@define REG_FIFO_B_H 0x040000A6  ; Direct Sound channel B samples 2-3 

@macro SoundOn
ldr r1,=REG_SOUNDCNT_X
ldr r0,=0x0081
str r0,[r1]
@endm

@macro S1_Enable
ldr r1,=REG_SOUNDCNT_L
ldr r0,=0x00021177 
str r0,[r1]
@endm

@macro S2_Enable
ldr r1,=REG_SOUNDCNT_L
ldr r0,=0x00022277
str r0,[r1]
@endm

@macro S3_Enable
ldr r1,=REG_SOUNDCNT_L
ldr r0,=0x00024477
str r0,[r1]
@endm

@macro S4_Enable
ldr r1,=REG_SOUNDCNT_L
ldr r0,=0x00028877
str r0,[r1]
@endm
