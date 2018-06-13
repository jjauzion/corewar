.name "fork2"
.comment "fork2"

lfork %:la
ld %0,r3
live %1
zjmp %:fin 
la:
fork %10
aff r1
fin:
