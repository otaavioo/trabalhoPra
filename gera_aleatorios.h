char* gera_nome_time_aleatorio()
{
	int i;
	static char palavra[TAM_STR];
	for(i = 0;i < TAM_STR-1;i++){
		palavra[i] = rand() % 26 + 'a';
	}
	palavra[TAM_STR] = '\0';
	return palavra;
}

int gera_mes()
{
	int mes=0;
	mes = rand() % 12 + 1;
	return mes;
}

int gera_ano()
{
	int ano=0;
	ano = rand() % (2014 - 1991) + 1991;
	return ano;
}

int gera_dia(int mes_param, int ano_param)
{
	int dia=0,bissexto=0;

	if (ano_param%4==0 && (ano_param%100!=0 || ano_param%400==0)){ /* Verificação Bissexto */
		bissexto=1;
	}
	if (mes_param == 1 || mes_param == 3 || mes_param == 5 || mes_param == 7 || mes_param == 8 || mes_param == 10 || mes_param == 12){
		dia = rand() % 31 + 1;
	}
	else if (mes_param == 4 || mes_param == 6 || mes_param == 9 || mes_param == 11){
		dia = rand() % 30 + 1;
	}
	else if (mes_param == 2 && bissexto == 1){
		dia = rand() % 29 + 1;
	}
	else if (mes_param == 2 && bissexto == 0){
		dia = rand() % 28 + 1;
	}
	return dia;
}

int gera_jogo(Jogo *pJogo, int quantidade)
{
	static int codigo = 1;
	int count = 0;

	if( !pJogo ) { return(1); }

	for( ; count < quantidade; count++){
		pJogo[count].codigo = codigo;
		pJogo[count].quantidade_publico = rand() % 30000 + 1;
		strcpy(pJogo[count].local,gera_nome_time_aleatorio());
		strcpy(pJogo[count].time_a,gera_nome_time_aleatorio());
		strcpy(pJogo[count].time_b,gera_nome_time_aleatorio());
		pJogo[count].placar_a = rand() % 20 + 1;
		pJogo[count].placar_b = rand() % 20 + 1;
		pJogo[count].data_jogo.mes = gera_mes();
		pJogo[count].data_jogo.ano = gera_ano();
		pJogo[count].data_jogo.dia = gera_dia(pJogo[count].data_jogo.mes,pJogo[count].data_jogo.ano);
		codigo++;
	}
	return(0);
}
