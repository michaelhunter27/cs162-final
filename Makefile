CXX = g++
SRCS = main.cpp func.cpp game.cpp actor.cpp floor.cpp player.cpp swan.cpp
OBJS = main.o func.o game.o actor.o floor.o player.o swan.o
HEADERS = func.h game.h actor.h floor.h player.h swan.h

prog: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o maze

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)

clean: 
	rm -f *.o maze

backup: ${SRCS} ${HEADERS}
	cp -f -t backup ${SRCS} ${HEADERS}
