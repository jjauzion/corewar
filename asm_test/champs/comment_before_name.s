.name #"25 Bonus Points"
.comment"Thx for the bonus points"

begin:
	sti r1, %:live, %1
	ld	%747522,r2
	ld %0,r3

live:
	live %1
	fork %:somewhere
	zjmp %:begin

somewhere:
	sti r2,%511,%0
	zjmp %511

	
