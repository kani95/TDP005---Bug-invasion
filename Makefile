CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17


# type 'make all' or 'gmake all' to build everything
all: game

game: Ant.o AntSwarm.o Character.o Enemy.o Game.o GameOverState.o LeaderboardState.o Leaf.o main.o MenuState.o Object.o Player.o PlayState.o Shot.o Spider.o SpiderSwarm.o State.o -lsfml-window -lsfml-graphics -lsfml-system

	$(CXX) $^ $(LDFLAGS) -o $@

# to build an *.o file we need corresponding *.cc file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# to clean up compiler-generated files
clean:
	\rm -f *.o *.stackdump game
