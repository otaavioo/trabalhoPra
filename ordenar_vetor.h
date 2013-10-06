int ordena_vetor(Jogo * jogos, int total_indices, int opcao)
{
	switch(opcao){
		case 1://quantidade_publico
			return ordena_quantidade_publico(jogos,total_indices);
		break;

		case 2://local
			return ordena_local(jogos,total_indices);
		break;

		case 3://time_a
			return ordena_time_a(jogos,total_indices);
		break;

		case 4://time_b
			return ordena_time_b(jogos,total_indices);
		break;

		case 5://placar_a
			return ordena_placar_a(jogos,total_indices);
		break;

		case 6://placar_b
			return ordena_placar_b(jogos,total_indices);
		break;

		case 7://data_jogo
			return ordena_data(jogos,total_indices);
		break;
	}
}

int ordena_quantidade_publico(Jogo * jogos, int total_indices)
{
	int i,menor;
	int indice = 0;
	for(i = 0;i < total_indices;i++){
		if(i == 0 && total_indices != 1){
			menor = jogos[i+1].quantidade_publico;
			indice = i+1;
		}
		if(total_indices == 1){
			menor = jogos[0].quantidade_publico;
			indice = 0;
		}else{
			menor = MIN(jogos[i].quantidade_publico,menor);
			if(menor == jogos[i].quantidade_publico){
				indice = i;
			}
		}
	}
	return indice;
}

int ordena_local(Jogo * jogos, int total_indices)
{
	int i;
	char menor[TAM_STR];
	int indice = 0;
	for(i = 0;i < total_indices;i++){
		if(i == 0 && total_indices != 1){
			strcpy(menor, jogos[i+1].local);
			indice = i+1;
		}
		if(total_indices == 1){
			strcpy(menor, jogos[0].local);
			indice = 0;
		}else{
			if( strcmp(jogos[i].local,menor) < 0 ){
				strcpy(menor, jogos[i].local);
			}
			if(menor == jogos[i].local){
				indice = i;
			}
		}
	}
	return indice;
}

int ordena_time_a(Jogo * jogos, int total_indices)
{
	int i;
	char menor[TAM_STR];
	int indice = 0;
	for(i = 0;i < total_indices;i++){
		if(i == 0 && total_indices != 1){
			strcpy(menor, jogos[i+1].time_a);
			indice = i+1;
		}
		if(total_indices == 1){
			strcpy(menor, jogos[0].time_a);
			indice = 0;
		}else{
			if( strcmp(jogos[i].time_a,menor) < 0 ){
				strcpy(menor, jogos[i].time_a);
			}
			if(menor == jogos[i].time_a){
				indice = i;
			}
		}
	}
	return indice;
}

int ordena_time_b(Jogo * jogos, int total_indices)
{
	int i;
	char menor[TAM_STR];
	int indice = 0;
	for(i = 0;i < total_indices;i++){
		if(i == 0 && total_indices != 1){
			strcpy(menor, jogos[i+1].time_b);
			indice = i+1;
		}
		if(total_indices == 1){
			strcpy(menor, jogos[0].time_b);
			indice = 0;
		}else{
			if( strcmp(jogos[i].time_b,menor) < 0 ){
				strcpy(menor, jogos[i].time_b);
			}
			if(menor == jogos[i].time_b){
				indice = i;
			}
		}
	}
	return indice;
}

int ordena_placar_a(Jogo * jogos, int total_indices)
{
	int i,menor;
	int indice = 0;
	for(i = 0;i < total_indices;i++){
		if(i == 0 && total_indices != 1){
			menor = jogos[i+1].placar_a;
			indice = i+1;
		}
		if(total_indices == 1){
			menor = jogos[0].placar_a;
			indice = 0;
		}else{
			menor = MIN(jogos[i].placar_a,menor);
			if(menor == jogos[i].placar_a){
				indice = i;
			}
		}
	}

	return indice;
}

int ordena_placar_b(Jogo * jogos, int total_indices)
{
	int i,menor;
	int indice = 0;
	for(i = 0;i < total_indices;i++){
		if(i == 0 && total_indices != 1){
			menor = jogos[i+1].placar_b;
			indice = i+1;
		}
		if(total_indices == 1){
			menor = jogos[0].placar_b;
			indice = 0;
		}else{
			menor = MIN(jogos[i].placar_b,menor);
			if(menor == jogos[i].placar_b){
				indice = i;
			}
		}
	}

	return indice;
}

int ordena_data(Jogo * jogos, int total_indices)
{
	int i,menor;
	int indice = 0;
	for(i = 0;i < total_indices;i++){
		if(i == 0 && total_indices != 1){
			menor = concatena_data(jogos[i+1].data_jogo.dia,jogos[i+1].data_jogo.mes,jogos[i+1].data_jogo.ano);
			indice = i+1;
		}
		if(total_indices == 1){
			menor = concatena_data(jogos[0].data_jogo.dia,jogos[0].data_jogo.mes,jogos[0].data_jogo.ano);
			indice = 0;
		}else{
			menor = MIN(concatena_data(jogos[i].data_jogo.dia,jogos[i].data_jogo.mes,jogos[i].data_jogo.ano),menor);
			if(menor == concatena_data(jogos[i].data_jogo.dia,jogos[i].data_jogo.mes,jogos[i].data_jogo.ano)){
				indice = i;
			}
		}
	}
	return indice;
}
