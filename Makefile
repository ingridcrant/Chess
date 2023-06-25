CXX = g++
CXXFLAGS = -std=c++14 -g -MMD -Wall -Wextra \
		   -I display -I pieces -I players
EXEC = chess
OBJECTS = main.o move.o\
		  graphicalObserver.o subject.o textObserver.o window.o\
		  board.o piece.o king.o knight.o pawn.o queen.o rook.o bishop.o\
		  game.o shared.o\
		  human.o levelOne.o player.o levelTwo.o
DEPENDS = ${OBJECTS:.o=.d}
# The only real change from the canonical Makefile,
# 	mirror changes in CXXFLAGS with -I
VPATH=display:pieces:players

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -I/usr/X11R6/include -L/usr/X11R6/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS}

