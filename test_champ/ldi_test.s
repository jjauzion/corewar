.name "blip"
.comment "blop"

ici:
ldi 3,%4,r3
st r3,65520
ldi %65530,%2,r3
st r3,1000
ldi r3,%5,r3
st r3,1000
ldi %:ici,%0,r3
st r3,1000
ld 0,r6
zjmp %:ici
ld 50,r6
zjmp %:ici
