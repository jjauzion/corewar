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
ldi 3,%5,r0
sti r0,%0,%1000