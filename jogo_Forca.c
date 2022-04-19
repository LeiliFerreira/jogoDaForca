#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

void forca(int estado) {
	if(estado ==0) {
		printf("----------\n" );
		printf("|        |\n" );
		printf("|         \n" );
		printf("|         \n" ); 
		printf("|         \n" );
		printf("|         \n" );
		printf("|         \n" );
		printf("|         \n" );		
	}

	if(estado ==1) {
		printf("----------\n" );
		printf("|        |\n" );
		printf("|        O\n" );
		printf("|         \n" ); 
		printf("|         \n" );
		printf("|         \n" );
		printf("|         \n" );
		printf("|         \n" );		
	}

	else if(estado==2) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" );
		 printf("|        | \n" ); 
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );	
	}

	else if(estado==3) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" );
		 printf("|       /| \n" ); 
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );	
	}

	else if(estado==4) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" ); 
		 printf("|       /|\\\n" ); 
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );	
	}
	
	else if(estado==5) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" );
		 printf("|       /|\\\n" ); 
		 printf("|       /  \n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );	
	}
	
	else if(estado==6) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" );
		 printf("|       /|\\\n" ); 
		 printf("|       / \\\n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("| Você perdeu!\n" );
		
	}
}

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	system("cls");
	printf("----JOGO DA FORCA----\n\n"); 
	sleep(1); 
	printf("- Sorteando palavra...\n"); 
	sleep(2); 
	printf("- Preparando forca...\n"); 
	sleep(2); 
	printf("- Começando em...\n"); 
	sleep(1); 
	printf("3\n");
	sleep(1); 
	printf(" 2\n"); 
	sleep(1); 
	printf("  1...");
	sleep(1); 
	
	fflush(stdin);	
	char bancoPalavras[10][30] = {"abacate", "caracol", "notbook", "programar", "laranja", "sushi", "internet", "cpu", "python", "computador"}; 
	char palavra[30];
	int c,i,a,b;
	int num=0;
	char palavraTela[30]; 
	int erros =0; 
	int errouLetra = 1; 
	char letra; 

	srand(time(NULL));
	num = rand() % 9;
	for(c=0;c<10;c++){
	palavra[c]=bancoPalavras[num][c];
	}
	system("cls");

	palavra[strlen(palavra)] = '\0'; 
	strcpy(palavraTela, palavra); 
	
	for(i=0;i<strlen(palavraTela);i++){
	palavraTela[i] = '_'; 
	}
 
	while(1){
		forca(erros); 
		printf("\nAdivinhe: "); 
		for(a=0;a<strlen(palavraTela);a++){
			printf("%c ", palavraTela[a]); 
		}
	
		printf("\nLetra: "); 
		scanf(" %c", &letra); 
		
		int errouLetra = 1; 
		int b; 
		for(b = 0; b<strlen(palavraTela);b++) {
		if(letra == palavra[b]) {
			palavraTela[b] = letra; 
			errouLetra = 0; 		
		}
	}
	
	if (errouLetra == 1) {
		erros++; 
	}
		
	if(strcmp(palavraTela,palavra)==0) {
		printf("\nVocê venceu! Parabéns!!!!");
		printf("\n---------------------------");
		printf("\nResposta: %s", &palavra);
		
		int jogarNovamente; 
		printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
		scanf("%d", &jogarNovamente); 
	
   		while (jogarNovamente != 1 && jogarNovamente != 2) {
			
			printf("\nOpção inválida!!!");
			printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
			scanf("%d", &jogarNovamente); 
		}
	
		if (jogarNovamente == 1) {
			return main();
		} else if (jogarNovamente == 2) {
			printf("\nVocê saiu, obrigada por jogar!");
			break;
		}
	}
		
	if (erros == 6){
		forca(erros);
		printf("\n---------------------------");
		printf("\nResposta: %s", &palavra);
		
	int jogarNovamente; 
		printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
		scanf("%d", &jogarNovamente); 
	
   		while (jogarNovamente != 1 && jogarNovamente != 2) {
			
			printf("\nOpção inválida!!!");
			printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
			scanf("%d", &jogarNovamente); 
		}
	
		if (jogarNovamente == 1) {
			return main();
		} else if (jogarNovamente == 2) {
			printf("\nVocê saiu, obrigada por jogar!"); 
			break; 
			}
		}
	}
}

