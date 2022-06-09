#include "fila.h"

int main()
{
	Fila f;
	Item aux;
	int menu;

	FFVazia(&f);
	printf("Escolha uma opção:\n1-Enfileira Fila.\n2-Desenfileira Fila.\n3-Imprime Lista.");
	scanf("%d", &menu);
	while(menu != 0){
		switch(menu){
			case 1: 
		}
	}
	aux.val = 30;
	Enfileira(&f, aux);
	aux.val = 25;
	Enfileira(&f, aux);
	aux.val =10;
	Enfileira(&f, aux);

	FImprime(&f);

	OrdenaBubble(&f);
	FImprime(&f);


	return 0;
}
