CXX = g++
CXXFLAGS = -std=c++14 -g -MMD -Wall -Wextra \
		   -I display -I gameFolder -I pieces -I players
EXEC = main
OBJECTS = main.o \
		  display.o graphicalObserver.o observer.o subject.o textObserver.o\
		  pieces.o board.o motion.o piece.o king.o knight.o pawn.o queen.o rook.o bishop.o\
		  gameFolder.o game.o move.o\
		  players.o computer.o human.o levelOne.o player.o
DEPENDS = ${OBJECTS:.o=.d}
# The only real change from the canonical Makefile,
# 	mirror changes in CXXFLAGS with -I
VPATH=display:gameFolder:pieces:players

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS}

