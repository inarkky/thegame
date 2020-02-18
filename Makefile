HEADERS   := hdr
ENTITYDIR := ent/
SOURCEDIR := src/
BUILDDIR  := bin/
LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
CXX  := g++

all: thegame

$(BUILDDIR)%.o: $(SOURCEDIR)%.cpp
	@echo $@
	$(CXX) -c $< -o $@ -I $(HEADERS) 

$(BUILDDIR)%.o: $(ENTITYDIR)%.cpp
	$(CXX) -c $< -o $@ 

thegame: $(BUILDDIR)main.o $(BUILDDIR)Game.o $(BUILDDIR)State.o $(BUILDDIR)GameState.o $(BUILDDIR)MainMenuState.o $(BUILDDIR)Entity.o $(BUILDDIR)Button.o 
	@echo "** Building the game"
	$(CXX) -o thegame $(BUILDDIR)main.o $(BUILDDIR)Game.o $(BUILDDIR)State.o $(BUILDDIR)GameState.o $(BUILDDIR)MainMenuState.o $(BUILDDIR)Entity.o $(BUILDDIR)Button.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f thegame $(BUILDDIR)*.o

install:
	@echo '** Installing...'
	cp thegame /usr/bin/

uninstall:
	@echo '** Uninstalling...'
	$(RM) /usr/bin/thegame