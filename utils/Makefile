#Needs this to find "*.h" files needed
CFLAGS=-O2 -g -Wall -W $(shell pkg-config --cflags librtlsdr)
#Needs this to find libraries that .h files point to
LDLIBS+=$(shell pkg-config --libs librtlsdr) -lpthread -lm
CC=g++
PROGNAME=get_1090_samples

#make print-VARIABLE
print-%  : ; @echo $* = $($*)

all: get_1090_samples

get_1090_samples: get_1090_samples.cpp
	$(CC) -g -o get_1090_samples get_1090_samples.cpp $(CFLAGS) $(LDLIBS)

clean:
	rm -f *.o get_1090_samples
