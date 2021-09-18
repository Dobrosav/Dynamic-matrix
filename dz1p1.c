#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COLUMN 5
typedef struct Node {
	int row, col,value;
	struct Node *down, *right;
}node;
typedef struct Matrix {
	node *r[ROW], *c[COLUMN];
}matrix;
void creatematrix(matrix *m) {
	int i;
 	for (i = 0; i < ROW; i++) {
		m->r[i] = (node *) malloc(sizeof(node));
 		m->r[i]->down = NULL;
 		m->r[i]->right = NULL;
 		m->r[i]->col = -1;
 		m->r[i]->row = -1;
 	}
 	for (i = 0; i < COLUMN; i++) {
		m->c[i] = (node *) malloc(sizeof(node));
 		m->c[i]->down = NULL;
 		m->c[i]->right = NULL;
		while (auxrow->right!=NULL && auxrow->right->col < col)
		{
			auxrow = auxrow->right;
		}
		while (auxcol->down!=NULL&& auxcol->down->row < r)
		{
			auxcol = auxcol->down;
		}
		node *novi = (node *) malloc(sizeof(node));
		novi->value = val;
		novi->col = col;
		novi->row = r;
		novi->down = auxcol->down;
		auxcol->down = novi;
		novi->right = auxrow->right;
		auxrow->right = novi;
}
void print(matrix *m, int def) {
	node *aux;
	int i, j;
	for (i = 0; i < ROW; i++) {
		if (m->r[i]->right != NULL)
			aux = m->r[i]->right;
		else 
			aux = m->r[i];
		for (j = 0; j < COLUMN; j++) {
			if (aux && aux->col == j) {
				printf("%d ", aux->value);
				aux = aux->right;
			}
			else 
				printf("%d ", def);
		}
		printf("\n");
	}
}
void createD(matrix *m, matrix *mG, matrix *mD, int def) {
	creatematrix(mG);
	creatematrix(mD);
	node *aux;
	int i, j;
	for (i = 0; i < ROW; i++){
		
		if (m->r[i]->right == NULL) 
			continue;
	aux = m->r[i]->right;
		while (aux != NULL) {
			if (aux->col >= i) 
				insert(mG, aux->value, i, aux->col);
			else
				insert(mD, aux->value, i, aux->col);
			aux = aux->right;
		}
	}
	printf("Gornje trougaona matrica\n");
	print(mG, def);
	printf("\nDonje trougaona matrica\n");
	print(mD, def);
}

void prazni(matrix *m){
	int i;
	for(i=0;i<ROW;i++){
		node *p=m->r[i];
		while(p!=NULL){
			node *brisi = p;
  			p = p->right;
  			free(brisi);
		}
	}
	free(m->r);
	free(m->c);
	free(m);
	m=NULL;
}
int main() {
	int def, r, c, v,meni;
	int n=0;
    matrix *m = (matrix *) malloc(sizeof(matrix));
    matrix *mG = (matrix *) malloc(sizeof(matrix));
	matrix *mD = (matrix *) malloc(sizeof(matrix));
	creatematrix(m);
	printf("1. stvaranje matrice zadatih dimenzija uz inicijalizaciju ne podrazumevanih vrednosti \n2.postavljanje podrazumevanih vrednosti \n3.dohvatanje zadatog elementa \n 4.postavljanje vrednosti zadatom elementu \n5. dohvatanje broja nepodrazumevanih elemenata \n6. ispis matrice\n7. brisanje matrice \n 8. kreiranje gornjo i donje trougaone matrice  \n 9. izlaz");
	printf("\nunesi te broj u zavisnosti sta zelite da radite\n");
	scanf("%d", &meni);
	while(1){
		if(meni==1){
			creatematrix(m);
			printf("\nmatrica generisana\n");
			printf("\n1. stvaranje matrice zadatih dimenzija uz inicijalizaciju ne podrazumevanih vrednosti \n2.postavljanje podrazumevanih vrednosti \n3.dohvatanje zadatog elementa \n 4.postavljanje vrednosti zadatom elementu \n5. dohvatanje broja nepodrazumevanih elemenata \n6. ispis matrice\n7. brisanje matrice \n 8. kreiranje gornjo i donje trougaone matrice  \n 9. izlaz");
			printf("\nunesi te broj u zavisnosti sta zelite da radite\n");
			scanf("%d", &meni);
		}
		if(meni==2){
			printf("\nunesi podrazumevani element\n");
			scanf("%d",&def);
			printf("\n1. stvaranje matrice zadatih dimenzija uz inicijalizaciju ne podrazumevanih vrednosti \n2.postavljanje podrazumevanih vrednosti \n3.dohvatanje zadatog elementa \n 4.postavljanje vrednosti zadatom elementu \n5. dohvatanje broja nepodrazumevanih elemenata \n6. ispis matrice\n7. brisanje matrice \n 8. kreiranje gornjo i donje trougaone matrice  \n 9. izlaz");
			printf("\nunesi te broj u zavisnosti sta zelite da radite\n");
			scanf("%d", &meni);
		}
		if(meni==3){
			printf("\nunesi te red i kolonu elementa kojem zelite da pristupite \n");
			scanf("%d%d",&r,&c);
			if((r>4||(r<0)||(c>4||(c<0)))){
				printf("prekoracili ste opseg");
				break;
			}
			printf("\n1. stvaranje matrice zadatih dimenzija uz inicijalizaciju ne podrazumevanih vrednosti \n2.postavljanje podrazumevanih vrednosti \n3.dohvatanje zadatog elementa \n 4.postavljanje vrednosti zadatom elementu \n5. dohvatanje broja nepodrazumevanih elemenata \n6. ispis matrice\n7. brisanje matrice \n 8. kreiranje gornjo i donje trougaone matrice  \n 9. izlaz");
			printf("\nunesi te broj u zavisnosti sta zelite da radite\n");
			scanf("%d", &meni);
		}
		if(meni==4){
			printf("\nunesi te vrednost elementa na toj poziciji \n");
			scanf("%d",&v);
			insert(m,v,r,c);
			n++;
			printf("\n1. stvaranje matrice zadatih dimenzija uz inicijalizaciju ne podrazumevanih vrednosti \n2.postavljanje podrazumevanih vrednosti \n3.dohvatanje zadatog elementa \n 4.postavljanje vrednosti zadatom elementu \n5. dohvatanje broja nepodrazumevanih elemenata \n6. ispis matrice\n7. brisanje matrice \n 8. kreiranje gornjo i donje trougaone matrice  \n 9. izlaz");
			printf("\nunesi te broj u zavisnosti sta zelite da radite\n");
			scanf("%d", &meni);
		}
		if(meni==5){
			printf("\nbroj nepodrazumenih elemenata je %d\n",n);
			printf("\n1. stvaranje matrice zadatih dimenzija uz inicijalizaciju ne podrazumevanih vrednosti \n2.postavljanje podrazumevanih vrednosti \n3.dohvatanje zadatog elementa \n 4.postavljanje vrednosti zadatom elementu \n5. dohvatanje broja nepodrazumevanih elemenata \n6. ispis matrice\n7. brisanje matrice \n 8. kreiranje gornjo i donje trougaone matrice  \n 9. izlaz");
			printf("\nunesi te broj u zavisnosti sta zelite da radite\n");
			scanf("%d", &meni);
		}
		if(meni==6){
			print(m,def);
			printf("\n");
			printf("\n1. stvaranje matrice zadatih dimenzija uz inicijalizaciju ne podrazumevanih vrednosti \n2.postavljanje podrazumevanih vrednosti \n3.dohvatanje zadatog elementa \n 4.postavljanje vrednosti zadatom elementu \n5. dohvatanje broja nepodrazumevanih elemenata \n6. ispis matrice\n7. brisanje matrice \n 8. kreiranje gornjo i donje trougaone matrice  \n 9. izlaz");
			printf("\nunesi te broj u zavisnosti sta zelite da radite\n");
			scanf("%d", &meni);
		}
		if(meni==7){
			prazni(m);
			printf("\nmatrica obrisana\n");
			printf("\n1. stvaranje matrice zadatih dimenzija uz inicijalizaciju ne podrazumevanih vrednosti \n2.postavljanje podrazumevanih vrednosti \n3.dohvatanje zadatog elementa \n 4.postavljanje vrednosti zadatom elementu \n5. dohvatanje broja nepodrazumevanih elemenata \n6. ispis matrice\n7. brisanje matrice \n 8. kreiranje gornjo i donje trougaone matrice  \n 9. izlaz");
			printf("\nunesi te broj u zavisnosti sta zelite da radite\n");
			scanf("%d", &meni);
		}
		if(meni==8){
			createD(m, mG, mD, def);
			printf("\n1. stvaranje matrice zadatih dimenzija uz inicijalizaciju ne podrazumevanih vrednosti \n2.postavljanje podrazumevanih vrednosti \n3.dohvatanje zadatog elementa \n 4.postavljanje vrednosti zadatom elementu \n5. dohvatanje broja nepodrazumevanih elemenata \n6. ispis matrice\n7. brisanje matrice \n 8. kreiranje gornjo i donje trougaone matrice  \n 9. izlaz");
			printf("\nunesi te broj u zavisnosti sta zelite da radite\n");
			scanf("%d", &meni);
		}
		if(meni==9){
			printf("kraj rada");
			break;
		}
	}
	getchar();
	return 0;
}
