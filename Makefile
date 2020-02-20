HEADERS   := lib
SOURCEDIR := src/
BUILDDIR  := bin/
LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
OBJ := 	$(BUILDDIR)main.o \
		$(BUILDDIR)Game.o \
		\
		$(BUILDDIR)State.o \
		$(BUILDDIR)GameState.o \
		$(BUILDDIR)MainMenuState.o \
		$(BUILDDIR)EditorState.o \
		\
		$(BUILDDIR)Entity.o \
		$(BUILDDIR)Player.o \
		\
		$(BUILDDIR)MovementComponent.o \
		$(BUILDDIR)AnimationComponent.o \
		$(BUILDDIR)HitboxComponent.o \
		\
		$(BUILDDIR)Button.o 
CXX  := g++
PROG := thegame


all: $(PROG)

$(BUILDDIR)%.o: $(SOURCEDIR)%.cpp
	@echo $@
	$(CXX) -I $(HEADERS) -c $< -o $@  

$(PROG): $(OBJ)
	@echo "** Building the game"
	$(CXX) -o $(PROG) $(OBJ) $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f $(PROG) $(BUILDDIR)*.o

install:
	@echo '** Creating symlink...'
	ln -s $(PROG) /usr/bin/$(PROG)
	@echo '** Game installed'

uninstall:
	@echo '** Uninstalling...'
	$(RM) /usr/bin/$(PROG)