## Corewar
Corewar is game where programs (a.k.a champions) fight till death in a memory area (a.k.a the Arena) managed by a Virtual Machine.

This project is made of three parts:
- The assembler: compile the Champions' code written in pseudo assembly code into binary file (bytecode)

- The Virtual Machine: manage the arena where the champion's fight. Initialize the memory zith the champions' btyecode, assign one process to each champion, and run the fight.

- The Champion: fight in the arena and (try) to win.

## List of instruction

Mnemonic | Opcode | Effect
----|----|----
sti | 0x0b | Take a registry, and two indexes (potentially registries) add the two indexes, and use this result as an address where the value of the first paramete will be copied.
lfork | 0x10 | Long fork. Same as fork but with no address restriction

Suivie de 4 octets qui représente le numéro du joueur. Cette instruction indique que ce joueur est en vie. Pas d’octet de codage des paramètres.

## compatibility
Mac OS 

## compile

make

## run

./fractal mandelbort

## Install löve for graphic output:

ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null ; brew install caskroom/cask/brew-cask 2> /dev/null
brew cask install love

## keys

KEY | FUNCTION
----|----
→ | +x translation
← | -x translation
↑ | +y translation
↓ | -y translation
c | switch color scale
space bar | reset view
Mouse left clic | zoom in
esc | close window & exit program

## Mandelbrot fractal

![alt text](https://raw.githubusercontent.com/kylax/fractol/master/img/mandelbrot.png)
