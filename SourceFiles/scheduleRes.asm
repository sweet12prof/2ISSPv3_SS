mfc0 $2 $3
nop
someotherlabel: addi $4 $2 2890
nop
beq $4 $1 jLabel
nop
sub $5 $3 $1
jLabel: addi $3 $4 1
mfc0 $3 $5
someLabel: add $12 $2 $1
lw $3 180($30)
nop
sw $3 180($30)
addi $2 $3 890
