mfc $2 $3
someotherlabel : addi $4 $2 2890
beq $4 $1 jLabel
sub $5 $3 $1
jLabel : addi $5 $4 1
mfc $3 $5
someLabel     :       add $12 $2 $1
lw $3 180($30)
someLabel: sw $3 180($30) 
addi $3, $2, 890