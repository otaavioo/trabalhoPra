#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "futebol.h"

int main()
{
	Jogo * jogo;
	Jogo * jogos;
	Jogo jogop;
	srand(time(NULL));

	jogo	= (Jogo *) malloc(sizeof(Jogo));
	if(!jogo){
		exit(EXIT_FAILURE);
	}

	int continuar = 1, num;

	do
	{
		printf("%c",201);
		int c;
		for(c = 0; c<44;c++){
			printf("%c",205);
		}
		printf("%c\n%c   Gerador de Jogos de Futebol Aleatorios   %c\n%c",187,186,186,204);
		for(c = 0; c<44;c++){
			printf("%c",205);
		}
		printf("\n%c 1. Gravacao de um registro individual      %c\n",185,186);
		printf("%c 2. Gravacao de um bloco de N registros     %c\n",186,186);
		printf("%c 3. Leitura de um registro individual       %c\n",186,186);
		printf("%c 4. Leitura do bloco de registros           %c\n",186,186);
		printf("%c 5. Gerar Aleatoriamente                    %c\n",186,186);
		printf("%c 6. Ordenar dados                           %c\n",186,186);
		printf("%c 0. Sair                                    %c\n%c",186,186,200);
		for(c = 0; c<44;c++){
			printf("%c",205);
		}

		printf("%c\n   Opcao %c ",188,175);
		scanf("%d", &continuar);
		system("cls || clear");

		switch(continuar)
		{
			case 1://gravar um jogo
				gera_jogo(jogo, 1);
				grava_jogo(jogo,ARQUIVO);
			break;

			case 2://gravar varios jogos
				printf("Informe a quantidade de jogos a serem gerados: ");
				scanf("%d",&num);
				jogos	= (Jogo *) malloc(num * sizeof(Jogo));
				if(!jogos){
					continuar = 0;
				}
				gera_jogo(jogos, num);
				grava_jogos(jogos, num,ARQUIVO);
			break;

			case 3://ler um jogo
				if(existe_arquivo()){
					jogo = le_um_jogo(-1,ARQUIVO);
					if(jogo == NULL){
						printf("Jogo nao encontrado!\n");
					}else{
						imprime_jogos(jogo,1);
					}
				}
			break;

			case 4://ler varios jogos
				if(existe_arquivo()){
					printf("Informe a quantidade de jogos a serem lidos: ");
					scanf("%d",&num);
					jogos = le_jogos(jogos,num,0,ARQUIVO,0);
					if(jogos == NULL){
						printf("Erro ao ler dados");
					}else{
						imprime_jogos(jogos,num);
					}
				}
			break;

			case 5://gera aleatorios
				gera_jogos_aleatorios(jogos,QUANTIDADE_ALEATORIOS);
			break;

			case 6://ordenar
				sub_menu_ordenar();
			break;

			case 0:
			break;

			default:
				printf("Digite uma opcao valida\n");
		}
		printf("\n");
	} while(continuar);

	free(jogos);

	return( 0 );
}
