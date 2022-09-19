SRC := $(wildcard *.c)
TARGET := $(patsubst %.c, %, $(SRC))
threads_FLAGS := -pthread
all: $(TARGET)

%: %.c
	# Use Constructed Macro Names
	$(CC) $($*_FLAGS) -o $@ $<

.PHONY: clean
clean:
	rm $(TARGET)