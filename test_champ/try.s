.name "blip"
.comment "blop"


debut: ld 6,r2
ici: live %1
st r2, 4000
and r2,%1,r4
zjmp %5000

ld %0,r3
sti r3,%:ici,%1
sti r3,%:ici,%0
sti	r1,%:live,%1
sti	r1,%:live2,%1

fork %:live
live2:
	live  %2
	and	%1,%0,r2
	zjmp %:live2

live:
	live  %2
	and	%1,%0,r2
	zjmp %:live
