HEADERS   := hdr
SOURCEDIR := src/
BUILDDIR  := bin/
LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
CXX  := g++

all: thegame

$(BUILDDIR)%.o: $(SOURCEDIR)%.cpp
	@echo $@
	$(CXX) -c $< -o $@ -I $(HEADERS) 

thegame: $(BUILDDIR)main.o $(BUILDDIR)Game.o $(BUILDDIR)State.o $(BUILDDIR)GameState.o $(BUILDDIR)MainMenuState.o $(BUILDDIR)Entity.o $(BUILDDIR)Player.o $(BUILDDIR)MovementComponent.o $(BUILDDIR)AnimationComponent.o $(BUILDDIR)Button.o 
	@echo "** Building the game"
	$(CXX) -o thegame $(BUILDDIR)main.o $(BUILDDIR)Game.o $(BUILDDIR)State.o $(BUILDDIR)GameState.o $(BUILDDIR)MainMenuState.o $(BUILDDIR)Entity.o $(BUILDDIR)Player.o $(BUILDDIR)MovementComponent.o $(BUILDDIR)AnimationComponent.o $(BUILDDIR)Button.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f thegame $(BUILDDIR)*.o

install:
	@echo '** Creating symlink...'
	ln -s thegame /usr/bin/thegame
	@echo '** Game installed'

uninstall:
	@echo '** Uninstalling...'
	$(RM) /usr/bin/thegame