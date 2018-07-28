.name "tracer"
.comment "tu me vois, tu me vois plus"

sti:	sti		r1, %:live, %1
		ld		%0,r9				#cpt
		ld		%4,r8				#increment
		ld		%88, r7				#limite
live:	live	%1
		zjmp	%:live
		ld		%0,r15
		fork	%:live
boucle:
		live	%1
		ldi		r9,%:boucle,r2
		sti		r2,r9,%400
		add		r8,r9,r9			#cpt++
		xor		r9,r7,r3
		zjmp	%:fin
		and		%1,%0,r4
		zjmp	%:boucle
fin:
		and		%1,%0,r3
		zjmp	%320
