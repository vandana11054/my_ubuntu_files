.data
# sample values for testing
#If number of number pairs is less than the first number in data segment then simulator will automatically  initialise unprovided numbers to zero
.dword 5,13,32,59,99,10,100,24,32,07,57

.text
lui x3,0x10000                          # loaded with data segment start address
ld x12,0(x3)                            # number of pairs left whose gcd to be found
addi x13,x3,8                           # address of first element of pair stored in x13
GCD:
#loop from smaller number to 1 and check wheather both nums are divisible by same number
#as we are iterating from back greatest common divisor will be encountered first
    beq x12,x0,exit                                              # if number of pairs left is 0 then exit
    ld x4,0(x13)                                                 # First element of pair stored in x4
    ld x5,8(x13)                                                 # Second element of pair stored in x5
    beq x4,x0,zero                                               # If one element is zero then GCD is zero 
    beq x5,x0,zero
    addi x11,x11,0                                               # variable to stop infinite loop-as multiples of gcd can cause infinite loop between div and check labels
    blt x4,x5,Loop                                               # ensure lesser number of pair stored in x4
swap: 
    ld x4,8(x13)                        # if x4 value greater than x5 value then swap
    ld x5,0(x13)
Loop:                                   # Loop label is to separate load and add instructions
   add x7,x0,x5     
   add x6,x4,x0                         # x6 runs from smaller number to 1
div:                                                            # Loop to check value in x7 is divisible by value in x6
   beq x7,x0,check                                              # if first number is divisible by x6 value then to check if second number is divisible by x6 value or not
   sub x7,x7,x6                                                 # repeated subtraction of x6 from x7
   bge x7,x0,div                                                # Until repeated subtraction of x7 value becomes zero or less loop
   blt x7,x0,next                                               # if x7 value not divisible by x6 value then go to next label
check:         
   beq x11,x0,Ans
   add x7,x0,x4                        # now initialise x7 with x4(smaller number)
   addi x11,x0,0                       # here x11 updated so that infinite loop between div and check ,stopped
   beq x0,x0,div  
next:                                                           # to check x7 value is divisible by x6-1
    addi x11,x11,1                                              # x11 value changed in next to stop infinite loop between div and check
    add x7,x5,x0
    addi x6,x6,-1
    addi x9,x0,1                                                # to compare gcd with 1
    blt  x9,x6,div
Ans:
    sd x6,512(x3)  
    beq x0,x0,final
zero:
    sd x0,512(x3)
    beq x0,x0,final
final:
    addi x12,x12,-1                    # one pair GCD calculated
    addi x13,x13,16                    # x13 initialised to next pair's first element
    addi x3,x3,8                       # next answer to be stored in next address of previous GCD address
    beq x0,x0,GCD                      # again run GCD for next pair of elements
exit:
    addi x0,x0,1                       # just for exit label instruction requirement writes to x0
    
    
