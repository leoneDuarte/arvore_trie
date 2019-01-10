//leone duarte de oliveira
#include "trie.h"
main(){
	T_no filho, raiz;
	T_item item;
	char vetor[10] ={'0','1','2','3','4','5','6','7','8','9'};
	int sair = 1,i=0,j,contador=0;
	char cpf_d[11],cpf_b[11];
	int posicao;
	trie_vazia(&raiz);
	
	while(sair != 0){	
		printf("\t\t\tINSIRA NOME:>>");
		scanf("%s",&item.nome);
		fflush(stdin);
		printf("\t\t\tINSIRA COR:>>");
		scanf("%s",&item.cor);
		printf("\t\t\tINSIRA A DATA DE NASCIMENTO:>>");
		scanf("%s",&item.data);	
		fflush(stdin);
		printf("\t\t\tINSIRA CPF:>>");
		scanf("%s",&item.cpf);
		strcpy(cpf_d,item.cpf);
		
		for(i=0; i<10; i++){
			raiz.digito[i] = NULL;
		}
		
		inserir(&item, &raiz, 0, cpf_d, contador);
		contador++;			
			
		printf("\n\n\t\t\t[0]-PARA SAIR\n\n\t\t\t[1]-PARA BUSCAR\n\n\t\t\t[3]-PARA INSERIR >>");
		scanf("%d",&sair);
		
		if(sair==1){
			fflush(stdin);
			printf("\n\n\t\t\tDIGITE O CPF PARA ENCONTRAR O USUARIO >>");
			gets(cpf_b);		
			buscar(&raiz, cpf_b, 0);	
		}
		printf("\n\n");
	}
	
}
