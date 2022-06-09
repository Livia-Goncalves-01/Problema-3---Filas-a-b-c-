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

	if(f == NULL || f->first->prox == NULL){
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
		printf("%.2f\t|", aux->data.calculo);

		aux = aux->prox;
	}
	printf("\n");

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

void Crialista(Fila *f, Fila *l, int n){
	Item aux;
	int i;
	for (i = 0; i < n; i++){
		aux.val = rand() % 100;
		Enfileira(f, aux);
	}
		
	for (i = 0; i < n; i++){
		aux.val = rand() % 100;
		Enfileira(l, aux);
	}


}

void TrocaFila(Fila *f, Fila *l, int n){
	Fila x, z;
	Item aux;
	int i;

	FFVazia(&x);
	FFVazia(&z);
	
	printf("%d", n);

	//Pega a primeira parte das filas e enfileira nas filas auxiliares
	for(i = 0; i < (n/2); i++ ){
		Desenfileira(f, &aux);
		Enfileira(&x, aux);
	}

	for(i = 0; i < (n/2); i++ ){
		Desenfileira(l, &aux);
		Enfileira(&z, aux);
	}

	//Desenfileira a segunda parte das listas e coloca nas listas auxiliares invertidas

	for(i = n/2; i < n; i++ ){
		Desenfileira(f, &aux);
		Enfileira(&z, aux);
	}

	for(i = n/2; i < n; i++ ){
		Desenfileira(l, &aux);
		Enfileira(&x, aux);
	}
	//Atribui as filas auxiliares nas filas iniciais
	f = &x;
	l = &z;

	FImprime(f);
	FImprime(l);
	

}

