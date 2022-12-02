CXX = g++
CXXFLAGS = -std=c++14 -g -MMD -Wall -Wextra \
		   -I display -I pieces -I players
EXEC = main
OBJECTS = main.o move.o\
		  graphicalObserver.o subject.o textObserver.o\
		  board.o piece.o king.o knight.o pawn.o queen.o rook.o bishop.o\
		  game.o shared.o\
		  computer.o human.o levelOne.o player.o
DEPENDS = ${OBJECTS:.o=.d}
# The only real change from the canonical Makefile,
# 	mirror changes in CXXFLAGS with -I
VPATH=display:pieces:players

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS}

