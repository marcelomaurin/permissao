

all: clean compile

clean:
	rm *.o
	rm permissao

compile:
	gcc permissao.c -o permissao


