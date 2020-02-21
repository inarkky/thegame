# THEGAME

### Instalation
run `make` to build binaries, then `make install` to create symlink to game in /usr/bin so that it can be run from terminal

### Uninstallation
just run `make uninstall` to remove the game

### TODO
- optimization - edit makefile to compile with -O2 flag
- installation - edit makefile to create symlink in /usr/bin instead of copying the whole game.. adjust `make clean` and `make uninstall` to follow changes
	- `sudo ln -s "$(pwd)"/thegame /usr/bin/thegame`
	- longterm goal - make proper `makefile` script to place all of the game files to where they should be

### GIT flags
- `FEAT` - new feature
- `FIX` - bug fix
- `DOCS` - changes to documentation
- `STYLE` - formatting, missing semi colons, etc; no code change
- `REFACTOR` - refactoring production code
- `TEST` - adding missing tests, refactoring tests; no production code change
- `CHORE` - updating grunt tasks etc; no production code change

