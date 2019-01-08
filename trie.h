#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item{
	char nome[10], cor[10], data[10];
	char cpf[11];
};

typedef struct item T_item;

struct no {
	struct no *digito[10]; 
	struct item *users[1000];
	char cpf;
};

typedef struct no T_no;


