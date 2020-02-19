#Instalation
run `make` to build binaries, then `make install` to create symlink to game in /usr/bin so that it can be run from terminal

#Uninstallation
just run `make uninstall` to remove the game

#TODO
- optimization - edit makefile to compile with -O2 flag
- installation - edit makefile to create symlink in /usr/bin instead of copying the whole game.. adjust `make clean` and `make uninstall` to fallow changes
	- sudo ln -s "$(pwd)"/thegame /usr/bin/thegame

#GIT flags
- `FEATURE`  - add new funcionality
- `REFACTOR` - code cleanup/optimization
- `FIX` 	 - errors fixes
- `PATCH` 	 - update existing functionality
