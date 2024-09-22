add t0, x5,  x0
sub    x7 , x8		,x	9
xori x5,x6,	7
beq x4,x31,L1
and x1,	sp	,	x	4
sll x1,x10    , x	1	2
sd	x5,8(x7)
sd  x1   9,-5	4(     x1)
sh x5	,	4	(	x	4	)
L1:  sw  x6,		8(x4)
L2:	ld x4,8(x3)
lw     x5,	8	0a(x3)
bne x4,x5,L2
lui x6,0x1	7772
lui x17,-127987
lh   x17,12(x	1	4)
addi x4	,x6	,-	8
	slli x14,x1	3,  6   3
andi x5,x6,4
jalr x	5,8(	x7)
lh x7,5(x8)
lui	x2  3,	87	8	54
jal x15,L	2
