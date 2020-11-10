#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define length 50

typedef char pilha;
pilha stack[length];
int top = -1, front = 0;

void push (char);
void pop();

void main () {
	setlocale(LC_ALL,"Portuguese");
	char palavra[length], b;
	int i;
	printf("----------------------------\n");
	printf("IDENTIFICADOR DE PALÍNDROMOS\n");
	printf("----------------------------\n");
	printf("Digite uma palavra: ");
	fflush(stdin);
	scanf("%s", palavra);
	for (i=0;i<palavra[i] != '\0';i++) {
		b = palavra[i];
		push(b);
	}
	for (i=0;i<(strlen(palavra)/2);i++) {
		if (stack[top] == stack[front]) {
			pop();
			front++;
		} else {
			printf("Não é palíndromo.\n");
			break;
		}	
	}
	if ((strlen(palavra)/2 == front)) {
		printf("É palíndromo");
		front = 0;
		top = -1;
	}
}

void push (char elemento) {
		top++;
		stack[top] = elemento;
}

void pop () {
		top--;
}
