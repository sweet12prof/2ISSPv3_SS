mfc $2 $3
nop
someotherlabel: addi $4 $2 2890
nop
beq $4 $1 jLabel
nop
sub $12 $3 $1
jLabel: addi $3 $4 1
mfc $3 $5
nop
someLabel: add $3 $2 $1
nop
lw $3 180($30)
nop
someLabel: sw $3 180($30)
addi $2 $3 890
