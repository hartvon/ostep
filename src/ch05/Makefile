SRC := $(wildcard hw/*.c *.c)
TAR := $(SRC:%.c=%)

all: $(TAR)

%: %.c
	$(CC) $< -o $@

.PHONY: clean
clean:
	rm -f $(TAR) *.output