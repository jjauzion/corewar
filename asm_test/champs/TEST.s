.name "TEST_champ"
.comment "TEST TEST TEST"

aff r4
ici: st r3, r6
live %4
ic1:
sti r3, r4, %:ici
add r1, r2, r3  #comment
sub r1, r2, r3
sti r3, r4, %:ici
and %5345677, 16, r7
or 5, 9, r12
xor %19, 3, r8
zjmp %4
ldi %4, %4, r3
