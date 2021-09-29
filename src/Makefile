OBJS = uiMain.o tokenizer.o history.o

CFLAGS = -g -O3

all: uiMain

uiMain:$(OBJS)

	cc -o uiMain $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o uiMain

run:uiMain
	./uiMain
