CFLAGS = -std=c99 -Wall

test: ../src/ex_string.o test_ex_string.o test_main.o
	$(CC) $^ -o $@ -lcunit

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -f test *.o

.PHONY: clean
