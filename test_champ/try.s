.name "blip"
.comment "blop"

#REG = 1
#DIR = 2
#IND = 3

ici:
#live %15
ld %-7, r5
#ld 1,r5
#ld %:ici,r5
sti r5,%:ici,%0
and %1,%0,r3
zjmp %:ici
#zjmp %65499
