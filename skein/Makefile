all: c a m u
a: c
	clang -fsanitize=address *.c && ./a.out
m: c
	clang -fsanitize=memory *.c && ./a.out
u: c
	clang -fsanitize=undefined *.c && ./a.out

	gcc *.c && ./a.out
c:
	rm -rf *.o *.out
