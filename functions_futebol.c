#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "futebol.h"
#include "gera_aleatorios.h"
#include "quick_sort.h"
#include "ordenacao.h"
#include "ordenar_vetor.h"

Jogo* gera_jogos_aleatorios(Jogo *pJogo, int quantidade)
{
	FILE * arquivo;

	if((arquivo = fopen(ARQUIVO,"wb")) == NULL){
		printf("Erro ao criar arquivo!\n");
	}

	pJogo	= (Jogo *) malloc(quantidade * sizeof(Jogo));
	if(!pJogo){
		exit(EXIT_FAILURE);
	}

	if(gera_jogo(pJogo, quantidade) != 0 ){
		printf("Erro ao gerar jogos.\n");
		exit(1);
	}

	if(fwrite(pJogo,sizeof(Jogo),quantidade,arquivo) != quantidade){
		printf("Não foi possivel gravar dados!\n");
	}

	fclose(arquivo);
	return pJogo;
}

void grava_jogo(Jogo *jogo, char *arquivo_str)
{
	FILE * arquivo;

	if((arquivo = fopen(arquivo_str,"ab")) == NULL){
		printf("Erro ao criar arquivo!\n");
	}

	if(fwrite(jogo,sizeof(Jogo),1,arquivo) != 1){
		printf("Não foi possivel gravar o dado!");
	}

	fclose(arquivo);
}

void grava_jogos(Jogo * jogos, int quantidade,char *arquivo_str)
{
	FILE * arquivo;

	if((arquivo = fopen(arquivo_str,"ab")) == NULL){
		printf("Erro adicionar dados ao arquivo!\n");
	}
	if(fwrite(jogos,sizeof(Jogo),quantidade,arquivo) != quantidade){
		printf("Não foi possivel gravar dados!\n");
	}

	fclose(arquivo);
}

Jogo* le_jogos(Jogo* jogos, int quantidade,int posicao,char *arquivo_str, int * tam)
{
	FILE * arquivo;
	int i;

	if((arquivo = fopen(arquivo_str,"rb+")) == NULL){
		printf("Erro ao criar arquivo!\n");
	}

	if( jogos != NULL){
		jogos = NULL;
		free(jogos);
	}

	jogos	= (Jogo *) malloc(quantidade * sizeof(Jogo));
	if(!jogos){
		exit(EXIT_FAILURE);
	}

   fseek(arquivo, posicao, SEEK_SET);
	int retorno = fread(jogos,sizeof(Jogo),quantidade,arquivo);

	fclose(arquivo);

	if(retorno == 0){
		return NULL;
	}

	if(retorno != quantidade){
		Jogo * jogosd;
		jogosd = (Jogo *) malloc(retorno * sizeof(Jogo));
		if(!jogosd){
			exit(EXIT_FAILURE);
		}
		for(i = 0;i < retorno;i++){
			jogosd[i] = jogos[i];
		}
		(*tam) = retorno;
		free(jogos);
		return jogosd;
	}

	return jogos;
}

Jogo * le_um_jogo(long posicao, char *arquivo_str)
{
	FILE * arquivo;
	int num = 0;
	Jogo * jogo;

	if((arquivo = fopen(arquivo_str,"rb+")) == NULL){
		printf("Erro ao criar arquivo!\n");
	}

	jogo = (Jogo *) malloc(sizeof(Jogo));
	if(!jogo){
		exit(EXIT_FAILURE);
	}

	if(posicao == -1){
		printf("Informe o jogo a ser lido:");
		scanf("%d",&num);
		fseek(arquivo,sizeof(Jogo)*(num-1), SEEK_SET);
	}else{
		fseek(arquivo, posicao, SEEK_SET);
	}

	if(fread(jogo,sizeof(Jogo),1,arquivo) != 1){
		jogo = NULL;
	}

	fclose(arquivo);
	return jogo;
}

void imprime_jogos(Jogo * jogos, int quantidade)
{
	int i;
	printf("\n\nIMPRIMINDO JOGOS\n\n");
	for(i = 0;i < quantidade;i++){
		printf("Codigo:  %d \n"
				"Publico: %d \n"
				"Local:   %s \n"
				"Time a:  %s \n"
				"Time b:  %s \n"
				"Placar a:  %d \n"
				"Placar b:  %d \n"
				"Data jogo: %.2d/%.2d/%.4d \n\n",
				jogos[i].codigo,
				jogos[i].quantidade_publico,
				jogos[i].local,
				jogos[i].time_a,
				jogos[i].time_b,
				jogos[i].placar_a,
				jogos[i].placar_b,
				jogos[i].data_jogo.dia,
				jogos[i].data_jogo.mes,
				jogos[i].data_jogo.ano);
	}
}

int existe_arquivo()
{
	FILE * arquivo;
	int retorno;
	if((arquivo = fopen(ARQUIVO,"r")) == NULL){
		printf("O arquivo nao existe, primeiro gere os jogos nas opcoes 1 e 2!\n");
		retorno = 0;
	}else{
		retorno = 1;
	}
	fclose(arquivo);

	return retorno;
}
