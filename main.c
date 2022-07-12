#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct almirante //Perfil e dados dos jogadores
{
    char nome[100];
    int placar;
};

struct almirante jogador;

void introducao ()
{

    printf("Bem-vindo ao Batalha Naval");
    printf("\n");
    printf("Você é o agente que tem a missão de derrubar todas as embarcações \ninimigaspara ganhar o jogo");
    printf("\n");
    printf("Qual seu nome?");
    fflush(stdin);
    gets(jogador.nome);
}

void batalha_naval () //Jogo
{

    char campo[14][14]; //Campo
    int hidro_cont, porta_cont, des_cont;
    int l, c;
    int c1 = 0, l1 = 0;
    int vida = 36;

    jogador.placar = 0; //Placar
    hidro_cont = 0;
    porta_cont = 0;
    des_cont = 0;

    char inimigo[14][14] =
    {
        //Arena do jogo
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {4, 4, 4, 0, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {0, 3, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0},
        {0, 3, 3, 3, 3, 3, 2, 0, 2, 0, 0, 1, 0, 2}
    };

    //Desenha a arena
    for(l = 0; l < 14; l = l + 1)
    {
        for(c = 0; c < 14; c = c + 1)
        {
            campo[l][c] = '~';
            printf(" \t%c" , campo[l][c]);
        }
        printf("\n");
    }

    //Condição para continuar jogando
    while (vida != 0)
    {


	//Tentativa
    printf("Agente %s\n", jogador.nome);
    printf("Vida: %i\n\n", vida);
    printf("Informe a linha: ");
    scanf("%i", &l);
    if(l < 0){
        vida == 0;
    }
    printf("Informe a coluna: ");
    scanf("%i", &c);
    printf("\n");

 	if(l < 14 && l >=0 &&
	   c < 14 && c >=0 && campo[l][c] == '~'){
		switch(inimigo[l][c]){
			case 0: campo[l][c] = 'A';
				  printf("Atingiu AGUA\n");
				  break;

			case 1: campo[l][c] = 'S';
				  vida--;
			  	  printf("Acertou!\n");
				  break;

			case 2: campo[l][c] = 'H';
				  vida--;
				  hidro_cont = (hidro_cont == 3 ? 0 : hidro_cont+1);
				  printf("Acertou!\n");
				  break;

			case 3: campo[l][c] = 'P';
				    vida--;
				    porta_cont = (porta_cont == 4 ? 0 : porta_cont+1);
				    printf("Acertou\n");
				    break;

			case 4: campo[l][c] = 'D';
                    vida--;
                    des_cont = (des_cont == 3 ? 0 : des_cont+1);
                    printf("Acertou!\n");
                    break;

			default:
			printf("ErrROU!\n");
		}
	}
    //desenha
    for(l = 0; l < 14; l = l + 1) {
       	for (c = 0; c < 14; c = c + 1){
        	printf(" \t%c", campo[l][c]);
        }
        printf("\n");
    }

   	if(vida == 0){
    	system("cls");
        puts("FIM DO JOGO");
        jogador.placar = jogador.placar + 1;
        printf("Jogador: %s\nPlacar: %i", jogador.nome, jogador.placar);
    }
	}
}

int main ()
{
    setlocale(LC_ALL,"portuguese");

    introducao();
    system("cls");
    batalha_naval ();
    system("pause");
    return 0;
}
