#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char isim[16];
	struct node *sonraki;
} dugum;

int main(){
	int n=16;
	dugum *bagliListe = malloc(n*sizeof(dugum));
	if(bagliListe==NULL){
		printf("Memory Allocation Failed.\n");
		exit(1);
	}
	strcpy(bagliListe[0].isim, "Baslangic");
	bagliListe[0].sonraki = &bagliListe[1];
	int i=1;
	while (1){
		char ad[16];
		printf("Isim giriniz: ");
		scanf("%s", ad);
		if (strcmp(ad, "Cik") == 0 || strcmp(ad, "cik")==0){
			bagliListe[i-1].sonraki=NULL;
			break;
		}
		strcpy(bagliListe[i].isim, ad);
		bagliListe[i].sonraki=&bagliListe[i+1];
		i++;
		if (i==n){
			n*=2;
			dugum *temp = realloc(bagliListe, n * sizeof(dugum));
			if (temp==NULL) {
				printf("Reallocation Failed.\n");
				free(bagliListe);
				bagliListe=NULL;
				exit(1);
			}
			bagliListe = temp;
			for (int j=0; j<i; j++){
				bagliListe[j].sonraki=&bagliListe[j+1];
			}
		}
	}
	n=i;
	for (i=1; i<n; i++){
		printf("%d. Kisinin Adi: %s. \n", i, bagliListe[i].isim);
		printf("Bir sonraki kisinin adresi: %p. \n", bagliListe[i].sonraki);
	}
	free(bagliListe);
	bagliListe=NULL;
	return 0;
}
