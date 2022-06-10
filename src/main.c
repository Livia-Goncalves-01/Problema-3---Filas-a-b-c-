#include "fila.h"

int main()
{
	Fila f, l;
	Item aux;
	int menu, n, count =0;

	FFVazia(&f);
	FFVazia(&l);
	printf("Escolha uma opção:\n1-Cria listas e enfileira valores randômicos.\n2-Desenfileira um valor nas Filas.\n3-Imprime Lista\n4-Troca metadade das listas.\n5-Ordena através do cálculo.\n0-Sair do programa.");
	scanf("%d", &menu);
	printf("\nDigite o tamanho das listas: ");
	scanf("%d", &n);
	
	while(menu != 0){
		switch(menu){
			case 1: 
				Crialista(&f, &l, n);
				count++;
				break;

			case 2: 
				Desenfileira(&f, &aux);
				Desenfileira(&l, &aux);
				break;

			case 3: 
				FImprime(&f);
				FImprime(&l);
				break;

			case 4:
				n = n * count;
				TrocaFila(&f, &l, n);
				break;
			case 5: 
				OrdenaBubble(&f);
				break;

			default: printf("Valor inválido,");
		}
		printf("Escolha uma opção:\n1-Cria listas e enfileira valores randômicos.\n2-Desenfileira um valor nas Filas.\n3-Imprime Listas\n4-Troca metadade das listas.\n5-Ordena através do cálculo.\n0-Sair do programa.");
		scanf("%d", &menu);
	}
	


	return 0;
}
