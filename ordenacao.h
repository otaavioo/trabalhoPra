void ordenar(int opcao)
{
	int * posicoes_tamanho;
	int total_indices = 1;
	int i;

	posicoes_tamanho = ordenar_arquivo_parte_um(opcao,&total_indices);
	ordenar_arquivo_parte_dois(opcao,posicoes_tamanho);
}

Jogo * ordena_fragmento(int opcao, int * tam, int * posicao)
{
	Jogo * jogos;
	jogos = le_jogos(jogos,TAM_MAX,(*posicao),ARQUIVO,tam);
	if(jogos != NULL){
		quick(jogos, 0, (*tam)-1, opcao);
	}
	(*posicao) += TAM_MAX * sizeof(Jogo);
	return jogos;
}

int * ordenar_arquivo_parte_um(int opcao,int * total_indices)
{
	Jogo * jogos;
	int tamanho = TAM_MAX;
	int * posicoes_tamanho;
	int posicao = 0;

	remove(ARQUIVO_TEMP);

	aloca_posicoes_tamanho(&posicoes_tamanho);
	while((jogos = ordena_fragmento(opcao,&tamanho,&posicao)) != NULL){
		grava_jogos(jogos,tamanho,ARQUIVO_TEMP);

		add_posicoes_tamanho(&posicoes_tamanho,(*total_indices));
		posicoes_tamanho[(*total_indices) - 1] = tamanho;

		(*total_indices)++;
	}
	(*total_indices)--;
	
	return posicoes_tamanho;
}

void aloca_jogos(Jogo **jogos)
{
	(*jogos)	= (Jogo *) malloc(sizeof(Jogo));
	if(!(*jogos)){
		exit(EXIT_FAILURE);
	}
}

void add_jogos(Jogo **jogos, int tam)
{
	Jogo * temp;
	if((temp = (Jogo *) realloc((*jogos),tam * sizeof(Jogo))) == NULL){
		printf("Erro alocando memória \n");
		exit(1);
	}
	(*jogos) = temp;
}

void aloca_posicoes(long **posicoes)
{
	(*posicoes)	= (long *) malloc(sizeof(long));
	if(!(*posicoes)){
		exit(EXIT_FAILURE);
	}
}

void add_posicoes(long **posicoes, int tam)
{
	long *temp;
	if((temp = (long *) realloc((*posicoes),tam * sizeof(long))) == NULL){
		printf("Erro alocando memória \n");
		exit(1);
	}
	(*posicoes) = temp;
}

void aloca_posicoes_posicoes(int **posicoes_posicoes)
{
	(*posicoes_posicoes)	= (int *) malloc(sizeof(int));
	if(!(*posicoes_posicoes)){
		exit(EXIT_FAILURE);
	}
}

void add_posicoes_posicoes(int **posicoes_posicoes, int tam)
{
	int *temp;
	if((temp = (int *) realloc((*posicoes_posicoes),tam * sizeof(int))) == NULL){
		printf("Erro alocando memória \n");
		exit(1);
	}
	(*posicoes_posicoes) = temp;
}

void aloca_posicoes_tamanho(int ** posicoes_tamanho)
{
	(*posicoes_tamanho) = (int *) malloc(sizeof(int));
	if(!(*posicoes_tamanho)){
		exit(EXIT_FAILURE);
	}
}

void add_posicoes_tamanho(int **posicoes_tamanho, int tam)
{
	int *temp;
	if((temp = (int *) realloc((*posicoes_tamanho),tam * sizeof(int))) == NULL){
		printf("Erro alocando memória \n");
		exit(1);
	}
	(*posicoes_tamanho) = temp;
}

int peenche_vetores(Jogo ** jogos, long ** posicoes, int ** posicoes_posicoes, int vez, int indice)
{
	Jogo * jogo;
	int i;
	static long posicao = 0;
	static int total_indices = 0;

	if(vez == 0){
		aloca_jogos(&(*jogos));
		aloca_posicoes(&(*posicoes));
		aloca_posicoes_posicoes(&(*posicoes_posicoes));

		while((jogo = le_um_jogo(posicao, ARQUIVO_TEMP)) != NULL){
			total_indices++;

			add_jogos(&(*jogos),total_indices);
			(*jogos)[total_indices - 1] = jogo[0];

			add_posicoes(&(*posicoes),total_indices);
			(*posicoes)[total_indices - 1] = posicao;

			add_posicoes_posicoes(&(*posicoes_posicoes),total_indices);
			(*posicoes_posicoes)[total_indices - 1] = 0;

			posicao += (TAM_MAX * sizeof(Jogo));
		}
	}else{
		posicao = (long)((*posicoes)[indice] + sizeof(Jogo));
		static int cont = 0;
		jogo = le_um_jogo(posicao,ARQUIVO_TEMP);
		if(jogo != NULL){
			cont++;
			(*jogos)[indice] = jogo[0];
			(*posicoes)[indice] = posicao;
			(*posicoes_posicoes)[indice] += 1;
			return cont;
		}else{
			return 0;
		}
	}

	return total_indices;
}

void ordenar_arquivo_parte_dois(int opcao,int * posicoes_tamanho)
{
	Jogo * jogos;
	long * posicoes;
	int * posicoes_posicoes;
	Jogo jogo;
	int total_indices, i, menor;
	int indice = 0;

	remove(ARQUIVO);

	total_indices = peenche_vetores(&jogos,&posicoes,&posicoes_posicoes,0,0);
	indice = ordena_vetor(jogos,total_indices,opcao);
	grava_jogo(&jogos[indice],ARQUIVO);

	while(total_indices != 0){
		int retorno = peenche_vetores(&jogos,&posicoes,&posicoes_posicoes,1,indice);
		if(posicoes_posicoes[indice] >= posicoes_tamanho[indice] || retorno == 0){
			for(i = indice;i < total_indices;i++){
				jogos[i] = jogos[i+1];
				posicoes[i] = posicoes[i+1];
				posicoes_posicoes[i] = posicoes_posicoes[i+1];
				posicoes_tamanho[i] = posicoes_tamanho[i+1];
			}
			total_indices--;
		}
		if(total_indices != 0){
			indice = ordena_vetor(jogos,total_indices,opcao);
			grava_jogo(&jogos[indice],ARQUIVO);
		}
	}
}

void sub_menu_ordenar(){
	int opcao;
	do {
		printf("%c",201);
		int c;
		for(c = 0; c<35;c++){
			printf("%c",205);
		}
		printf("%c\n%c        Ordenador Dados            %c\n%c",187,186,186,204);
		for(c = 0; c<35;c++){
			printf("%c",205);
		}
		printf("\n%c 1. Ordenar por quantidade_publico %c\n",185,186);
		printf("%c 2. Ordenar por local              %c\n",186,186);
		printf("%c 3. Ordenar por time_a             %c\n",186,186);
		printf("%c 4. Ordenar por time_b             %c\n",186,186);
		printf("%c 5. Ordenar por placar_a           %c\n",186,186);
		printf("%c 6. Ordenar por placar_b           %c\n",186,186);
		printf("%c 7. Ordenar por Data               %c\n",186,186);
		printf("%c 0. Retornar                       %c\n%c",186,186,200);
		for(c = 0; c<35;c++){
			printf("%c",205);
		}

		printf("%c\n   Opcao %c ",188,175);
		scanf("%d", &opcao);
		system("cls || clear");

		if(opcao > 0 && opcao < 8){
			ordenar(opcao);
		}else if(opcao == 0){
			return;
		}else{
			printf("Digite uma opção válida.\n");
		}
	} while(opcao);
}

int concatena_data(int dia, int mes, int ano){
	char temp[9];
	sprintf(temp,"%.4d%.2d%.2d",ano,mes,dia);
	return atoi(temp);
}
