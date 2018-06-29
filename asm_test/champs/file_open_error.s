.name "open error"
.comment "what happens if a file is with champ 
name already exist and is protected 
from read/write"

ld %1060, r2
st r2, 58
ld %1, r3
st r3, 59
