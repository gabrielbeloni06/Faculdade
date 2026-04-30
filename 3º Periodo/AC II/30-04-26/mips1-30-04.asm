#a->$s0
#b->$s1
#c->$s2

#sub $t0,$t0,$t0 #t0=0

aqui: addi $s0, $zero, 10 # a=0+10
addi $s1, $zero, -1 #b=0-1
add $t0, $s0, $s0 #t0=2a
add $t0, $t0, $t0 #t0=4a
addi $s0, $t0, 1 #a=t0+1
add $s2, $s0, $s1 #c=a+b
j aqui