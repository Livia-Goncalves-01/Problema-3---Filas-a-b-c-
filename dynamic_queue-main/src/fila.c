#include "fila.h"

void FFVazia(Fila *f){
	f->first = (Block*) malloc (sizeof(Block));
	f->last  = f->first;
	f->first->prox = NULL;
}

void Enfileira(Fila *f, Item d){
	Block *novo = (Block*) malloc (sizeof(Block));
	Calcula( &d);
	novo->data = d;
	
	novo->prox = NULL;
	
	if (f->first == NULL) {
		f->first = novo;
	}
	else {
		f->last->prox = novo;
	}
	f->last = novo;
	


}

void Desenfileira(Fila *f, Item *d){
	Block *aux;

	if(f->first == f->last || f == NULL || f->first->prox == NULL){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first->prox;
	f->first->prox = aux->prox;
	if (f->first->prox == f->last)
		f->last = f->first;
	d->val   = aux->data.val;
	free(aux);
}


void FImprime(Fila *f){
	Block *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%d\t", aux->data.val);
		printf("%.2f\n", aux->data.calculo);

		aux = aux->prox;
	}

}

void Calcula( Item *d){
	d->calculo = sqrt((d->val * 2)+ d->val/(0.5*d->val));
}

void OrdenaBubble(Fila *f){
	bool mudou = false;
	Block *aux1, *aux2 = NULL;

	Item tmp;

	do{
		mudou = false;
		aux1 = f->first;
		while(aux1->prox != aux2){
			if(aux1->data.calculo > aux1->prox->data.calculo){
				tmp = aux1->data;
				aux1->data = aux1->prox->data;
				aux1->prox->data = tmp;
				mudou = true;
			}

			aux1 = aux1->prox;
		}

		aux2 = aux1;
	}while(mudou);
}
