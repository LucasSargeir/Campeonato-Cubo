#include<stdio.h>
#include<string.h>
#define LIMITE 1000

float maior,menor,temp[5],tottemp,aux,auxm;
int i,j,n,l,dnf,pessoas;
char auxn[50],mod[50];
FILE *arquivo;
char fim;
struct reg{
	char nome[50];
	float media,menort;
};
struct reg pessoa[LIMITE];

int main(){

	printf("No final do nome da modalidade use um ponto final.\nEntre com o nome da modalidade:\n");
	
	for(j=0;j<50;j++){
		scanf("%c",&mod[j]);
		if(mod[j]=='.')
			j=50;
	}
	
	printf("Digite o numero de participantes: ");
	
	scanf("%d",&pessoas);
	printf("__________________________________________________________________________________________\n");
	printf("   ____________ \t  _____  _____  ____  _____  _______\t __ _______\n");
	printf("  /___/___/___/|\t |      |      |     |          |\t/_//   ____\\ \n");
	printf(" /___/___/___/||\t |      |      |     |          |\t  /   / ___ \n");
	printf("/___/___/___/|||\t |      |___   |___  |___       |\t /   //___/ \n");
	printf("|   |   |   ||/|\t |      |      |     |          |\t/   /____ \n");
	printf("|___|___|___|/||\t |      |      |     |          |\t\\__//___/ \n");
	printf("|   |   |   ||/|\t |_____ |_____ |     |_____     |\t\t\n");
	printf("|___|___|___|/|/ \t                                     (EXPOTEC 2015)\n");
	printf("|   |   |   ||/\n",179,179,179,179,179);
	printf("|___|___|___|/\n\n",179,179,179,179);
	printf("______________________________ ATENCAO PARA O MODO DE USAR _______________________________\n");
	printf("|                                                                                         |\n");
	printf("| Ao escrever o nome do participante deve ser colocado um ponto final depois do nome, nao |\n");
	printf("|esqueca isso para facilitar a vizualizacao do placar. Caso mesmo assim voce esqueca basta|\n");
	printf("|  depois do enter escrever um ponto e apertar enter de novo. Ao digitar os tempos nao os |\n");
	printf("|  escreva em minutos, escreva o total de segundos(no placar os tempos estao em segundos  |\n");
	printf("|_________________________________________________________________________________________|\n");
	for(i=0;i<pessoas;i++){

		printf("\nNo final de cada nome use um ponto final.\nEntre com o nome:\n");
		int jaPonto = 0;
		for(j=0;j<50;j++){
			if(jaPonto == 0)
				scanf("%c",&pessoa[i].nome[j]);
			else
				pessoa[i].nome[j] = ' ';
			if(pessoa[i].nome[j]=='.')
				jaPonto=1;
		}
		
		tottemp=0;
		printf("DNF ou DNS ?\n(0)NADA\n(1)DNF\n(2)DNS\n");
		scanf("%d",&dnf);
		while(dnf!=0 && dnf!=1 && dnf!=2){
			printf("OP%c%cO INV%cLIDA ENTRE COM OUTRO N%cMERO: ",128,199,181,233);
			scanf("%d",&dnf);
		}
		if(dnf==0){	
			for(n=0;n<5;n++){
			    printf("\nEntre com %d %c tempo:",n+1,167);
				scanf("%f",&temp[n]);
					if(n==0){
						maior=temp[n];
						menor=temp[n];
					}	
					else{
						if(temp[n]>maior)
							maior=temp[n];
						if(temp[n]<menor)
							menor=temp[n];
					}
					tottemp+=temp[n];
			}
			tottemp-=(maior+menor);
			pessoa[i].media=tottemp/3;
		}
		if(dnf==2){
			pessoa[i].media=10101010;
			printf("Media DNS.\n");
		}
		if(dnf==1){
			for(n=0;n<4;n++){
			   		printf("\nEntre com %d %c tempo:",n+1,167);
					scanf("%f",&temp[n]);
					if(n==0){
						menor=temp[n];
					}	
					else{
						if(temp[n]<menor)
							menor=temp[n];
					}
					tottemp+=temp[n];
			}
			tottemp-=menor;
			pessoa[i].media=tottemp/3;
		}
		pessoa[i].menort=menor;
		printf("__________________________________________________________________________________________\n");
	}
	for(i=0;i<pessoas-1;i++){
		for(j=i+1;j<pessoas;j++){
			if(pessoa[i].media>pessoa[j].media){
				aux=pessoa[i].media;
				pessoa[i].media=pessoa[j].media;
				pessoa[j].media=aux;
				auxm=pessoa[i].menort;
				pessoa[i].menort=pessoa[j].menort;
				pessoa[j].menort=auxm;
				strcpy(auxn,pessoa[i].nome);
				strcpy(pessoa[i].nome,pessoa[j].nome);
				strcpy(pessoa[j].nome,auxn);
			}
		}
	}
	printf("________________________________________________________________________________________________________________________\n");
	printf("__________________________________________________RESULTADO_____________________________________________________________\n");
	printf("Nomes                                             Media\t\tMelhor Tempo\t    Colocacao       \n\n");
	for(i=0;i<pessoas;i++){
		for(j=0;j<50;j++){
			printf("%c",pessoa[i].nome[j]);
		}
		if(pessoa[i].media!=10101010)
			printf(" %.2f\t\t%.2f\t\t\t%d\t\n",pessoa[i].media,pessoa[i].menort,i+1);
		if(pessoa[i].media==10101010)
			printf(" DNS\t\t-\t\t\t%d\t\t\n",i+1);
	}
	printf("_________________________________________________________________________________________________________________________");
	printf("\n                                                                                                Made by Lucas Sargeiro%c\n",169);

	arquivo=fopen(strcat(mod, "txt"),"wt");
	
	fprintf(arquivo,"%s\n",mod);
	fprintf(arquivo,"________________________________________________________________________________________________________________________\n__________________________________________________RESULTADO_____________________________________________________________\n");
	fprintf(arquivo,"Nomes                                             Media\t\tMelhor Tempo\t\t    Colocacao       \n\n");
	
	for(i=0;i<pessoas;i++){
		for(j=0;j<50;j++){
			fprintf(arquivo,"%c",pessoa[i].nome[j]);
		}
		if(pessoa[i].media!=10101010)
			fprintf(arquivo," %.2f\t\t%.2f\t\t\t\t%d\t\n",pessoa[i].media,pessoa[i].menort,i+1);
		if(pessoa[i].media==10101010)
			fprintf(arquivo," DNS\t\t-\t\t\t\t%d\t\t\n",i+1);
	}
	fclose(arquivo);
	scanf("%c",&fim);

	return 0;
}
