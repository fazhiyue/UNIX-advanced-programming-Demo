INC_DIR=./inc
BIN_DIR=./bin
SRC_DIR=./src
OBJ_DIR=./obj

SRC=${wildcard ${SRC_DIR}/*.c}
OBJ=${patsubst %.c, $(OBJ_DIR)/%.o, ${notdir ${SRC}}}
LIB+= -lpthread

TARGET=my_cp
BIN_TARGET=${BIN_DIR}/${TARGET}

CC=gcc
CFLAGS= -g -Wall -I${INC_DIR}

${BIN_TARGET}:${OBJ}
	${CC} ${OBJ} -o $@ ${LIB}

${OBJ_DIR}/%.o:${SRC_DIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@ 

#test:
#	echo $(SRC)
#	echo $(OBJ)
clean:
	find ${OBJ_DIR} -name *.o -exec rm -rf {} \;
