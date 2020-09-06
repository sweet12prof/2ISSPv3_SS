somelabelNext: mfc $2 $3

someotherlabel: addi $4 $2 2890


sub $12 $3 $1



jLabel                    :                     addi $3 $4 1


mfc $3 $5
someLabel     :       add $1 $2 $1


lw                      $4 180($30)
someLabel: sw $3 180($30) 
addi $3 $2 890
mfc $5, $2
someLabel2:jr $3

beq $2, $3, someLabel

J someLabel