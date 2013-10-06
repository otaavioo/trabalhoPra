#ifndef FUTEBOL

#define QUANTIDADE_ALEATORIOS 10000000
#define TAM_STR 50
#define ARQUIVO "jogos.dat"
#define ARQUIVO_TEMP "jogos_ordenados_parte_um.dat"
#define TAM_MAX 256
#define MIN(x,y) x<y ? x : y

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct {
	int codigo;
	int quantidade_publico;
	char local[TAM_STR];
	char time_a[TAM_STR];
	char time_b[TAM_STR];
	int placar_a;
	int placar_b;
	Data data_jogo;
} Jogo;

char * gera_nome_time_aleatorio();
int gera_mes();
int gera_ano();
int gera_dia(int mes_param, int ano_param);
int gera_jogo(Jogo* pJogo, int quantidade);

Jogo * gera_jogos_aleatorios(Jogo *pJogo, int quantidade);
void grava_jogo(Jogo *jogo,char *arquivo_str);
void grava_jogos(Jogo * jogos, int quantidade,char *arquivo_str);
Jogo * le_jogos(Jogo * jogos, int quantidade,int posicao,char *arquivo_str, int * tam);
Jogo * le_um_jogo(long posicao, char *arquivo_str);

void imprime_jogos(Jogo * jogos,int quantidade);

void ordenar(int opcao);
int * ordenar_arquivo_parte_um(int opcao, int * total_indices);
Jogo * ordena_fragmento(int opcao, int * tam,int * posicao);
void ordenar_arquivo_parte_dois(int opcao,int * posicoes_tamanho);
int peenche_vetores(Jogo ** jogos, long ** posicoes,int ** posicoes_posicoes, int vez, int indice);

int ordena_vetor(Jogo * jogos, int total_indices, int opcao);
int ordena_quantidade_publico(Jogo * jogos, int total_indices);
int ordena_placar_a(Jogo * jogos, int total_indices);
int ordena_local(Jogo * jogos, int total_indices);
int ordena_time_a(Jogo * jogos, int total_indices);
int ordena_time_b(Jogo * jogos, int total_indices);
int ordena_placar_b(Jogo * jogos, int total_indices);
int ordena_data(Jogo * jogos, int total_indices);

void aloca_jogos(Jogo **jogos);
void add_jogos(Jogo **jogos, int tam);
void aloca_posicoes(long ** posicoes);
void add_posicoes(long **posicoes, int tam);
void aloca_posicoes_posicoes(int **posicoes_posicoes);
void add_posicoes_posicoes(int **posicoes_posicoes, int tam);
void aloca_posicoes_tamanho(int ** posicoes_tamanho);
void add_posicoes_tamanho(int **posicoes_tamanho, int tam);

void sub_menu_ordenar();
void quick(Jogo * jogos, int p, int r, int opcao);
void quick_quantidade_publico(Jogo * jogos, int p, int r);
void quick_local(Jogo * jogos, int p, int r);
void quick_time_a(Jogo * jogos, int p, int r);
void quick_time_b(Jogo * jogos, int p, int r);
void quick_placar_a(Jogo * jogos, int p, int r);
void quick_placar_b(Jogo * jogos, int p, int r);
void quick_data(Jogo * jogos, int p, int r);
int concatena_data(int dia, int mes, int ano);

int existe_arquivo();

#endif
