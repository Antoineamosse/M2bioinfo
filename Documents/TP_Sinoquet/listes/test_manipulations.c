#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

//Déclaration des structures et fonctions :
//Structure + liste :
    typedef struct TypeHaplotype TypeHaplotype;
    struct TypeHaplotype{
		TypeHaplotype* suivant;
		int num;
		int nombreGenotypes;
	};
	
	typedef struct ListeHaplotype{
		int nombreHaplotypes;
		TypeHaplotype* tete;
	}ListeHaplotype;
    
    

    
//Fonctions
	ListeHaplotype *initialisation(){
		ListeHaplotype *liste = malloc(sizeof(*liste));
		TypeHaplotype *element = malloc(sizeof(*element));
		if (liste == NULL || element == NULL){
			exit(EXIT_FAILURE);
		}
		element->num = 2;
		element->nombreGenotypes = 20;
		element->suivant = NULL;
		liste->tete = element;
		return liste;
	}
	
	void insertion(ListeHaplotype *liste, int num, int nombreGenotypes){
	/* Création du nouvel élément */
		TypeHaplotype *Haplotype = malloc(sizeof(*Haplotype));
		if (liste == NULL || Haplotype == NULL){
			exit(EXIT_FAILURE);
		}
		Haplotype->num = num;
		Haplotype->nombreGenotypes = nombreGenotypes;
		/* Insertion de l'élément au début de la liste */
		Haplotype->suivant = liste->tete;
		liste->tete = Haplotype;
	}


void afficherListe(ListeHaplotype *liste){
	if (liste == NULL){
		exit(EXIT_FAILURE);
	}
	TypeHaplotype *Haplotype = liste->tete;
	while (Haplotype != NULL){
		printf("Num %d -> ", Haplotype->num);
		printf("Nombre de Géntoypes %d -> ", Haplotype->nombreGenotypes);
		printf("Fin de la structure Haplotype\n");
		Haplotype = Haplotype->suivant;
	}
	printf("NULL\n");
}


//Tests manipulations
	ListeHaplotype *maliste =initialisation();
	insertion(maliste, 5,6);
	insertion(maliste, 7,8);
	afficherListe(maliste);


return 0;
} //Fin du main()
