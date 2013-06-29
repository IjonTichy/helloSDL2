CC = g++
LD = g++

CFLAGS = -pedantic -Wall -ansi -std=c++11
LFLAGS =
LIBS   = -lSDL -lSDL_image

OPT_LEVEL = 2
DBG_LEVEL = 0

SRCDIR   = src
BUILDDIR = build

CFILES = $(wildcard ${SRCDIR}/*.cpp)
HFILES = $(wildcard ${SRCDIR}/*.h)
OFILES = $(patsubst ${SRCDIR}/%.cpp, ${BUILDDIR}/%.o, ${CFILES})

EXE_NAME = helloSDL

.PHONY: default

default: all

all: ${OFILES}
	@[ -n "${OFILES}" ] || (echo "ERROR: Nothing to link" 1>&2; exit 1)
	${LD} ${LFLAGS} ${OFILES} ${LIBS} -o ${EXE_NAME} 

clean:
	@rm -f ${BUILDDIR}/*.o

${BUILDDIR}/%.o: ${SRCDIR}/%.cpp ${HFILES}
	@mkdir -p ${BUILDDIR}
	${CC} ${CFLAGS} -O${OPT_LEVEL} -g${DBG_LEVEL} -c $< -o $@
