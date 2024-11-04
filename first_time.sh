clear
echo This script it meant to get used when the 'balens' executable file doesnt works.
echo If it works already there is no need to recompile it, Just execute it and you are done.

g++ -o balens src/args.cpp src/Balens.cpp src/BLSRC.cpp src/compile.cpp src/config.cpp src/link.cpp src/DataShop.cpp
./balens
