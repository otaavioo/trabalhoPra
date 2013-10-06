void quick(Jogo * jogos, int p, int r, int opcao)
{
	switch(opcao){
		case 1://quantidade_publico
			quick_quantidade_publico(jogos,p,r);
		break;

		case 2://local
			quick_local(jogos,p,r);
		break;

		case 3://time_a
			quick_time_a(jogos,p,r);
		break;

		case 4://time_b
			quick_time_b(jogos,p,r);
		break;

		case 5://placar_a
			quick_placar_a(jogos,p,r);
		break;

		case 6://placar_b
			quick_placar_b(jogos,p,r);
		break;

		case 7://data_jogo
			quick_data(jogos,p,r);
		break;
	}
}

void quick_quantidade_publico(Jogo * jogos, int p, int r)
{
	int i, j,c;
	Jogo t;
	if (p < r) {
		c = jogos[(p+r)/2].quantidade_publico;
		i = p, j = r;
		while (i <= j) {
			while (jogos[i].quantidade_publico < c) {
				++i;
			}
			while (c < jogos[j].quantidade_publico) {
				--j;
			}
			if (i <= j) {
				t = jogos[i],
				jogos[i] = jogos[j],
				jogos[j] = t;
				++i, --j;
			}
		}
		quick_quantidade_publico(jogos, p, j);
		quick_quantidade_publico(jogos, i, r);
	}
}

void quick_local(Jogo * jogos, int p, int r)
{
	int i, j;
	Jogo t;
	char local[TAM_STR];
	if (p < r) {
		strcpy(local, jogos[(p+r)/2].local);
		i = p, j = r;
		while (i <= j) {
			while( (strcmp(jogos[i].local,local) < 0) ){
				i++;
			}
			while( (strcmp(local, jogos[j].local) < 0) ){
				j--;
			}
			if (i <= j) {
				t = jogos[i],
				jogos[i] = jogos[j],
				jogos[j] = t;
				i++, j--;
			}
		}
		quick_local(jogos, p, j);
		quick_local(jogos, i, r);
	}
}

void quick_time_a(Jogo * jogos, int p, int r)
{
	int i, j;
	Jogo t;
	char time_a[TAM_STR];
	if (p < r) {
		strcpy(time_a, jogos[(p+r)/2].time_a);
		i = p, j = r;
		while (i <= j) {
			while( (strcmp(jogos[i].time_a,time_a) < 0) ){
				i++;
			}
			while( (strcmp(time_a, jogos[j].time_a) < 0) ){
				j--;
			}
			if (i <= j) {
				t = jogos[i],
				jogos[i] = jogos[j],
				jogos[j] = t;
				i++, j--;
			}
		}
		quick_time_a(jogos, p, j);
		quick_time_a(jogos, i, r);
	}
}

void quick_time_b(Jogo * jogos, int p, int r)
{
	int i, j;
	Jogo t;
	char time_b[TAM_STR];
	if (p < r) {
		strcpy(time_b, jogos[(p+r)/2].time_b);
		i = p, j = r;
		while (i <= j) {
			while( (strcmp(jogos[i].time_b,time_b) < 0) ){
				i++;
			}
			while( (strcmp(time_b, jogos[j].time_b) < 0) ){
				j--;
			}
			if (i <= j) {
				t = jogos[i],
				jogos[i] = jogos[j],
				jogos[j] = t;
				i++, j--;
			}
		}
		quick_time_b(jogos, p, j);
		quick_time_b(jogos, i, r);
	}
}

void quick_placar_a(Jogo * jogos, int p, int r)
{
	int i, j,c;
	Jogo t;
	if (p < r) {
		c = jogos[(p+r)/2].placar_a;
		i = p, j = r;
		while (i <= j) {
			while (jogos[i].placar_a < c) {
				++i;
			}
			while (c < jogos[j].placar_a) {
				--j;
			}
			if (i <= j) {
				t = jogos[i],
				jogos[i] = jogos[j],
				jogos[j] = t;
				++i, --j;
			}
		}
		quick_placar_a(jogos, p, j);
		quick_placar_a(jogos, i, r);
	}
}

void quick_placar_b(Jogo * jogos, int p, int r)
{
	int i, j,c;
	Jogo t;
	if (p < r) {
		c = jogos[(p+r)/2].placar_b;
		i = p, j = r;
		while (i <= j) {
			while (jogos[i].placar_b < c) {
				++i;
			}
			while (c < jogos[j].placar_b) {
				--j;
			}
			if (i <= j) {
				t = jogos[i],
				jogos[i] = jogos[j],
				jogos[j] = t;
				++i, --j;
			}
		}
		quick_placar_b(jogos, p, j);
		quick_placar_b(jogos, i, r);
	}
}

void quick_data(Jogo * jogos, int p, int r)
{
	int i, j,c;
	Jogo t;
	if (p < r) {
		c = concatena_data(jogos[(p+r)/2].data_jogo.dia,jogos[(p+r)/2].data_jogo.mes,jogos[(p+r)/2].data_jogo.ano);
		i = p, j = r;
		while (i <= j) {
			while (concatena_data(jogos[i].data_jogo.dia,jogos[i].data_jogo.mes,jogos[i].data_jogo.ano) < c) {
				++i;
			}
			while (c < concatena_data(jogos[j].data_jogo.dia,jogos[j].data_jogo.mes,jogos[j].data_jogo.ano)) {
				--j;
			}
			if (i <= j) {
				t = jogos[i],
				jogos[i] = jogos[j],
				jogos[j] = t;
				++i, --j;
			}
		}
		quick_data(jogos, p, j);
		quick_data(jogos, i, r);
	}
}
