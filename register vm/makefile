flags = -g -Iinclude
ldflags = -lkernel32 -luser32

src = $(wildcard src/*.c)
obj = $(src:src/%.c=bin/%.o)
target = bin/app


all: $(target)

$(target): $(obj)
	gcc $(ldflags) $^ -o $@ 

bin/%.o: src/%.c
	gcc $(flags) -c $< -o $@