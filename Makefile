CC 		= gcc
OP 		= -Wall -lm -lncurses
OP_E1	= -lGL -lGLU -lglut

NAME 	= simulation

FILE 	= main
FILE1 	= mathEQ
FILE2 	= windowsMenus

FOLD_C  = code
FOLD_O  = object_files

EXT 	= c

all:		app

app:		${NAME}

${NAME}:	${FILE}.o ${FILE1}.o ${FILE2}.o 
			${CC} -o ${NAME} ${FOLD_O}/${FILE}.o ${FOLD_O}/${FILE1}.o ${FOLD_O}/${FILE2}.o ${OP} 

${FILE}.o:	${FOLD_C}/${FILE}.${EXT}
			${CC} ${FOLD_C}/${FILE}.${EXT} ${OP} -c  ; mv ${FILE}.o ${FOLD_O}/

${FILE1}.o:	${FOLD_C}/${FILE1}.${EXT}
			${CC} ${FOLD_C}/${FILE1}.${EXT} ${OP} -c ; mv ${FILE1}.o ${FOLD_O}/

${FILE2}.o:	${FOLD_C}/${FILE2}.${EXT}
			${CC} ${FOLD_C}/${FILE2}.${EXT} ${OP} -c ; mv ${FILE2}.o ${FOLD_O}/

clean:
			rm ${FOLD_O}/*.o
