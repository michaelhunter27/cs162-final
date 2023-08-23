CXX = g++
SRCS = main.cpp func.cpp game.cpp
OBJS = main.o func.o game.o
HEADERS = func.h game.h

prog: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o prog

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)

clean: 
	rm -f *.o prog

backup: ${SRCS} ${HEADERS}
	cp -f -t ./backup/ ${SRCS} ${HEADERS}
