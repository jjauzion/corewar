.name "blip"
.comment "blop"

ici:
sti r1, 15, %1000
ld %8,r2
sti r2, %:ici, %1000
sti r1, r2, %1002
sti r2, 1, r1
sti r2, r1, r1
sti r0, r1, %0
sti r1, r0, r0
