all: core_program printing_program

core_program: core_program.c
	cc -o core_program core_program.c

printing_program: printing_program.c
	cc -o printing_program printing_program.c

clean:
	rm -f core_program printing_program