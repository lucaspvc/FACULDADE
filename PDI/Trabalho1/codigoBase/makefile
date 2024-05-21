CC=gcc
#CCFLAGS=-Wall
CCFLAGS=-g
LDFLAGS=-lm 
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=main

ifeq ($(OS), Windows_NT)
   LIB = ..\\utils\\imagelib.o
else
   LIB = ../utils/imagelib.o
endif

all: $(TARGET)

$(TARGET): $(OBJECTS);\
    $(CC) -g -o $@ $(LIB) $^ $(LDFLAGS)

%.o: %.c %.h;\
    $(CC) $(CCFLAGS) -c $<

%.o: %.c;\
    $(CC) $(CCFLAGS) -c $<

clean:;\
    rm -f *.o *-result.p*m $(TARGET);\

