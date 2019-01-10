//leone duarte de oliveira
#include "trie.h"
#include<string.h>

void trie_vazia(T_no *raiz){
	int i=0;	
	for(i=0; i<10; i++){
		raiz->digito[i] = NULL;
	}
	raiz->cpf = '\0';	
}

int inserir(T_item *item, T_no *filho, int posicao_atual, char cpf[11], int contador){
 	int i=0,digit;
	T_no *nod;		
	T_item *item_t;
	int digito_atual=atoi(&cpf[posicao_atual]);
		
	if(posicao_atual <= 11){		
		printf("\no CPF e : %s  digito a ser inserido: %c   posicao: %d\n",cpf,cpf[posicao_atual], posicao_atual);
		
		if(filho->digito[posicao_atual] == NULL){
					
			nod = (T_no *) malloc(1*sizeof(T_no));
					
			for(i=0; i<10; i++){
				nod->digito[i] = NULL;			
			}			
			nod->cpf = cpf[posicao_atual];			
			filho->digito[posicao_atual] = nod;
			
		
		  if(cpf[posicao_atual+1] == '\0'){
		  		  							
				item_t = (T_item *) malloc(1*sizeof(T_item));							
				nod->users[contador] = item_t; 
				strcpy(item_t->cor, item->cor);
				strcpy(item_t->nome, item->nome);
				strcpy(item_t->data,item->data);
				strcpy(item_t->cpf,item->cpf);		
				contador++;	
					
				printf("\no cpf %s do %s de cor %s nascido em %s foi inserido com sucesso\n\n\n\n---------------------------------------------\n\n",item_t->cpf, item_t->nome, item_t->cor,item_t->data);
				return 0;
			}
		
			inserir(item,filho, posicao_atual+1, cpf,contador);	
		}		
		else{
			digit = atoi(&cpf[posicao_atual]);
			inserir(item, filho->digito[digit], posicao_atual, cpf,contador);		
		}		
	}	
}

int buscar(T_no *no_atual,char cpf[11], int digito_atual){
	char aux;
	aux = cpf[digito_atual];
	int posicao = atoi(&aux);
	no_atual = no_atual->digito[posicao];
	printf("aqui %c cpf %c \t\t\n",cpf[digito_atual], no_atual->digito[posicao]->cpf);	
	
	if(cpf[digito_atual+1] != '\0'){		
		printf("no_atual %c   cpf: %c posicao %d",no_atual->digito[posicao]->cpf,cpf[digito_atual +1], posicao);		
		printf("\nBUSCANDO CPF\n");	
		
		if(digito_atual ==10){
			printf("\nNOME: %s \n COR: %s DATA DE NASCIMENTO: %s CPF: %s",no_atual->users[0]->nome, no_atual->users[0]->cor, no_atual->users[0]->data, cpf);
		}
		
		buscar(no_atual->digito[posicao], cpf, digito_atual+1);	
				
	}else{	
		printf("ERRO AO BUSCAR");	
	
	}
}

