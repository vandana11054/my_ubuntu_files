.section .data
L1: .word 100000
.section .text
.global main
main:
la x3,L1
lw x3,0(x3)
lui x1,0x10012
lui x2,0x00000
addi x1,x1,0x004
addi x2,x2,0x000
sw x2,0(x1)
addi x13,x1,4
addi x4,x2,32
sw x4,0(x13)
lui x5,0x10012
addi x5,x5,0x00C
addi x6,x3,0
 add x7,x0,x0
 addi x15,x0,0
Loop:
 addi x15,x0,0
 addi x7,x7,1
 sw x4,0(x5)
 beq x6,x7,LED_OFF
 bne x6,x7,Loop

LED_OFF:
  add x7,x0,x0
  addi x15,x15,1
  sw x2,0(x5)
  blt x15,x3,LED_OFF
  beq x0,x0,Loop
Lwhile1: j Lwhile1