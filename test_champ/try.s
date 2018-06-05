.name "blip"
.comment "blop"

init: 
fork %30
and %1,%0,r2
zjmp %:init
