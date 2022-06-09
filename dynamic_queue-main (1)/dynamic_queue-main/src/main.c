#include "fila.h"

int main()
{
	Fila f;
	Item aux;

	FFVazia(&f);

	aux.val = 30;
	Enfileira(&f, aux);
	aux.val = 25;
	Enfileira(&f, aux);
	aux.val =10;
	Enfileira(&f, aux);

	FImprime(&f);

	printf("Desenfileira\n");

	FImprime(&f);

	OrdenaBubble(&f);
	FImprime(&f);


	return 0;
}
