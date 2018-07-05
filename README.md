## Corewar
Corewar is a very peculiar game. It’s about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions to stay “alive”.
The game ends when all the processes are dead. The winner is the last player
reported to be “alive”.

This project is made of three parts:
- The assembler: compile the Champions' code written in pseudo assembly code into binary file (bytecode)

- The Virtual Machine: manage the arena where the champion's fight. Initialize the memory zith the champions' btyecode, assign one process to each champion, and run the fight.

- The Champion: fight in the arena and (try) to win.

## Assembly language

Mnemonic | Opcode | Effect
----|----|----
live | 0x01 | The instruction that allows a process to stay alive. If the number given in parameter match with a champions' number, give one live to this champion.
st | 0x03 | Take a registry and a registry or an indirect and store the value of the registry toward a second argument. For example, st r1, 42 store the value of r1 at the address (PC + (42 % IDX_MOD)).
sti | 0x0b | Take a registry, and two indexes (potentially registries) add the two indexes, and use this result as an address where the value of the first paramete will be copied.
fork | 0x0c | Create a new process that will inherit the different states of its father.
lfork | 0x10 | Long fork. Same as fork but with no address restriction.
ld | 0x02 | Take an argument and a registry. Load the value of the first argument in the registry.
ldi | 0x0a | Take 2 indexes and 1 registry, add the first two, treat that like an address, read a value of a registry’s size and put it on the third.
lld | 0x0d | Same as ld, but with no address restriction.
lldi | 0x0e | Same as ldi, but does not apply any modulo to the addresses.
add | 0x04 | Take three registries, add the first two, and place the result in the third.
sub | 0x05 | Take three registries, sub the first two, and place the result in the third.
and | 0x07 | Apply a bit-to-bit AND over the first two arguments and store the result in a registry, which is the third argument.
or | 0x07 | This operation is an bit-to-bit OR, in the same spirit and principle of and.
xor | 0x07 | This operation is an bit-to-bit XOR.
zjmp | 0x09 | Take an index and jump to this address if the carry is 1.

Suivie de 4 octets qui représente le numéro du joueur. Cette instruction indique que ce joueur est en vie. Pas d’octet de codage des paramètres.

## compatibility
Mac OS 

## compile

make

## run

Assembler:
./asm [-a] <file.s>

Option: 
  * -a : verbose mode

./corewar [-d N -coplkv] <champion1.cor> <...>

Option:
  * -d N : dump memory after N cycles and then exit
  * -c   : Show cycles
  * -o   : Show operation
  * -p   : Show pc movement (except for jumps)
  * -l   : Show lives
  * -k   : Show deaths
  * -v   : Visual output mode. Pipe output to love visu
    * Ex: ./corewar -v champ.cor | love visu

## Install löve for graphic output:

ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null ; brew install caskroom/cask/brew-cask 2> /dev/null

brew cask install love

## Mandelbrot fractal

![alt text](https://raw.githubusercontent.com/kylax/fractol/master/img/mandelbrot.png)
