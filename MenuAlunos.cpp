#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <locale.h>

#define maxTurma 100

struct alunos {
	int matricula;
	char nome[100];
	float nota1, nota2, media;
};

struct alunos turma[maxTurma];
struct alunos turmaOrdenada[maxTurma];
int totalDeAlunos = 0;

void gotoxy(int coluna, int linha){       
		COORD point;
        point.X = coluna; point.Y = linha;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

char ponta_lado_esquerdo  = 218;
char ponta_lado_direito   = 191;
char centro_superior	  = 196;
char lado		  = 179;
char espaco		  = 32;
char ponta_baixo_esquerdo = 195;
char ponta_baixo_direito  = 180;
char baixo_esquerdo 	  = 192;
char baixo_direito        = 217;
int espacamento = 0;

void incluir();
void excluir();
void listar(int num, int contaAluno);
void lancar();
void ordenar(int tamanho);
void topo();
void base();
void meio();
void caixa();
void texto();
void menuPrincipal();
void menuTabela();
void menuIncluir();


main(){
	menuPrincipal();		
} 

void topo() {
	int  tracos = 50;
	gotoxy(10,5);
	printf("%c",ponta_lado_esquerdo);
	while( tracos > 1 ) {
		printf("%c",centro_superior);
		tracos--;
	}
	gotoxy(60,5);
	printf("%c",ponta_lado_direito);
	
}
void meio() {
	int linha = 6;
	
	while (linha <= 14) {
		if(linha == 7) {
			gotoxy(10,linha);
			printf("%c",ponta_baixo_esquerdo);
						
			int tracos = 1;
			while(tracos <= 50 ) {
				printf("%c",centro_superior);
				tracos++;
			}
			gotoxy(60,linha);
			printf("%c",ponta_baixo_direito);
		}
		else {		
			gotoxy(10,linha);
			printf("%c",lado);
			gotoxy(60,linha);
			printf("%c",lado);
		}
		
		linha++;		
	}	
}
void base() {
	int  tracos = 50;
	gotoxy(10,15);
	printf("%c",ponta_baixo_esquerdo);
	while( tracos > 1 ) {
		printf("%c",centro_superior);
		tracos--;
	}
	
	gotoxy(60,15);
	printf("%c",ponta_baixo_direito);
	
	gotoxy(10,15);
	printf("%c",lado);
	gotoxy(60,15);
	printf("%c",lado);
	gotoxy(10,16);
	printf("%c",lado);
	gotoxy(60,16);
	printf("%c",lado);
	
	gotoxy(10,17);
	printf("%c",baixo_esquerdo);
	tracos = 50;
	while( tracos > 1 ) {
	    printf("%c",centro_superior);
		tracos--;
	}
	gotoxy(60,17);
	printf("%c\n",baixo_direito);
}
void texto() {
	
	int numero, expoente, resultado;
	int opcao;
	
	gotoxy(27,6);
	printf("Total de Alunos: %d", totalDeAlunos);
	gotoxy(27,9);
	printf("1. Incluir aluno");
	gotoxy(27,10);
	printf("2. Excluir aluno");
	gotoxy(27,11);
	printf("3. Listar alunos");
	gotoxy(27,12);
	printf("4. Lancar notas");
	gotoxy(27,13);
	printf("5. Sair");
	gotoxy(27, 16);
	printf("Digite a opcao: ");
	gotoxy(43, 16);
	scanf("%d", &opcao);
	
	if (opcao == 1){
		incluir();
	}
	
	if (opcao == 2){
		excluir();
	}
	
	if (opcao == 3){
		listar(5,0);
	}
	
	if (opcao == 4){
		lancar();
	}
		
}


void menuPrincipal(){
	system("cls");
	topo();
	meio();
	base();
	texto();
}
void menuTabela(){
	system("cls");
	topo();
 	base();
	meio();
}
void menuIncluir(){
	
		int voltar;
		menuTabela();
		gotoxy(20,6);
		printf("Incluir Aluno");
		gotoxy(14,10);
		printf("1. Incluir outro aluno");
		gotoxy(14,11);
		printf("2. Voltar ao menu");
		gotoxy(14, 16);
		printf("Digite a opcao: ");
}

void incluir(){
	
		alunos aluno;	
		char continuar;
		int cont = 0;
		int voltar;
		int alunoExiste = 0;
		
		menuTabela();
			 
		gotoxy(28,6);
		printf("Incluir Aluno");
		gotoxy(15,10);
		printf("Matricula: ");
		gotoxy(15,11);
		printf("Nome.....: ");
		
		gotoxy(27,10);
		scanf("%d", &aluno.matricula);
		
		gotoxy(27,11);
		scanf("%s", aluno.nome);
		//fgets(aluno.nome, 100, stdin);
		gotoxy(15,16);
		printf("Confirma aluno? (s/n) ");
		scanf("%s", &continuar);
		if(continuar == 's'){
			cont= 0;
			while(cont <= maxTurma){
				if(turma[cont].matricula == aluno.matricula){
					alunoExiste++;
					menuIncluir();
					gotoxy(26,13);
					printf("Matricula ja existe!");
					gotoxy(30, 16);
					scanf("%d", &voltar);
		
					if(voltar == 1){
						incluir();
					}
					else if(voltar == 2){
						menuPrincipal();
					}					
				}
				cont++;
			}
			
			if(alunoExiste == 0){
				
				turma[totalDeAlunos] = aluno;
				turma[totalDeAlunos].nota1 = 0;
				turma[totalDeAlunos].nota2 = 0;
				turma[totalDeAlunos].media = 0;
				
				totalDeAlunos++;
				menuIncluir();
				gotoxy(26,13);
				printf("Aluno cadastrado!");
				
				gotoxy(30, 16);
				scanf("%d", &voltar);
	
				if(voltar == 1){
					incluir();
				}
				else if(voltar == 2){
					menuPrincipal();
				}
			}	
		}
		else if(continuar == 'n'){
			menuIncluir();
			gotoxy(26,13);
			printf("Cadastro cancelado!");			
			gotoxy(30, 16);
			scanf("%d", &voltar);

			if(voltar == 1){
				incluir();
			}
			else if(voltar == 2){
				menuPrincipal();
			}					
		}		 
}

void excluir(){
	alunos aluno;
	int numeroMatricula; 
	int conti = 0;
	int alunoExcluido = 0;
	char continuar;
		
	menuTabela();
	gotoxy(27,6);
	printf("Excluir Aluno");
	
	gotoxy(15,10);
	printf("Digite a matricula: ");
	gotoxy(36,10);
	scanf("%d", &numeroMatricula);
	
	while(conti <= maxTurma) {
	
		if(turma[conti].matricula == numeroMatricula){
			
			gotoxy(14,12);
			printf("%s", turma[conti].nome);

			gotoxy(14,16);
			printf("Deseja excluir (s/n)");
			scanf("%s", &continuar);
			
			if(continuar == 's'){
				turma[conti].matricula = 0;
				
				gotoxy(26,14);
				printf("Aluno excluido!\n");
				alunoExcluido++;
				totalDeAlunos--;
				
				gotoxy(13,16);
				system("pause");
				menuPrincipal();				
			}
			else if(continuar == 'n'){
				menuPrincipal();
			}			
		}
		conti++;
	}
	if(alunoExcluido == 0){
		gotoxy(26,15);
		printf("Matricula nao encontrada!");	
	}
	
	gotoxy(15,16);
	printf("Excluir mais um aluno? (s/n)");
	gotoxy(38, 16);
	scanf("%s", &continuar);
	
	if(continuar == 's'){
		excluir();
	}
	else if(continuar == 'n'){
		menuPrincipal();
	}
}

void listar(int num, int contaAluno){
	char continuar;
	int linha = 9;
	int existeAluno = 0;
	ordenar(contaAluno);
	
	menuTabela();
	
	gotoxy(27,6);
	printf("Lista de alunos");
	
	while(contaAluno < num && contaAluno <= maxTurma){
		if(turma[contaAluno].matricula > 0){
			gotoxy(14,linha++);
			printf("%d  %s \t %.2f \t %.2f \t %.2f", turma[contaAluno].matricula, turma[contaAluno].nome, turma[contaAluno].nota1, turma[contaAluno].nota2, turma[contaAluno].media);
			existeAluno++;
		} 
		contaAluno++;
	}
	
	if(existeAluno == 0){
		gotoxy(26,11);
		printf("Nao ha mais alunos");
	}
	
	gotoxy(15,16);
	printf("Proximos alunos? (s/n)");
	gotoxy(38, 16);
	scanf("%s", &continuar);
	
	if(continuar == 's'){
		num = num + 5;
		listar(num, contaAluno);
	}
	else if(continuar == 'n'){
		menuPrincipal();
	}
	
}

void lancar(){
	int numeroMatricula, cont = 0, existeMatricula = 0; 
	float n1, n2;
		
	menuTabela();
	gotoxy(27,6);
	printf("Lancar Nota");
	
	gotoxy(15,10);
	printf("Digite a matricula: ");
	gotoxy(36,10);
	scanf("%d", &numeroMatricula);
	
	while(cont <= maxTurma) {
	
		if(turma[cont].matricula == numeroMatricula){
			
			gotoxy(15,11);
			printf("%s", turma[cont].nome);
			gotoxy(15,12);
			printf("Digite a nota1: ");
			gotoxy(32,12);
			scanf("%f", &n1);
			
			
			gotoxy(15,13);
			printf("Digite a nota2: ");
			gotoxy(32,13);
			scanf("%f", &n2);
			
			turma[cont].nota1 = n1;
			turma[cont].nota2 = n2;
			turma[cont].media = (n1+n2)/2;
						
			existeMatricula++;	
			menuPrincipal();
			
		}
		cont++;
	}
	
	if(existeMatricula == 0){
		gotoxy(26,10);
		printf("Matricula nao encontrada!");
	}
	
}
	
void ordenar(int tamanho){
	int i;
	alunos aux;

	for(i=0; i<maxTurma; i++){
		if(turma[i].matricula > 0 && turma[i+1].matricula > 0 ){
			if(turma[i].media > turma[i+1].media){
				turmaOrdenada[i] = turma[i]; 
				turma[i] = turma[i+1]; 
	            turma[i+1] = turmaOrdenada[i]; 
    		}
		}

    }
    
}


 									
