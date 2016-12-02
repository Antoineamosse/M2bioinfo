#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAILLEGENOTYPE 10


void generationGenotype (char*);
int locusAleatoire(int tauxAmbiguite);

//D�finition des structures

    typedef struct TypeGenotypeExplique TypeGenotypeExplique;
    typedef struct TypeHaplotype TypeHaplotype;

    struct TypeGenotypeExplique{
    char nom[TAILLEGENOTYPE+1];
    int num;
    TypeGenotypeExplique* suivant;
    TypeHaplotype* haplotypeComplementaire;
    };


	struct TypeHaplotype{
	TypeHaplotype* suivant;
	char nom[TAILLEGENOTYPE+1];
	int num;
	TypeGenotypeExplique* tete;
	int nombreGenotypes;
	};

	typedef struct ListeHaplotype{
		int nombreHaplotypes;
		TypeHaplotype* tete;
	}ListeHaplotype;

	typedef struct TypePaireHaplotypes TypePaireHaplotypes;
	typedef struct TypeGenotype TypeGenotype;

	struct TypePaireHaplotypes{
	    char brin1[TAILLEGENOTYPE+1];
	    char brin2[TAILLEGENOTYPE+1];
	    TypePaireHaplotypes* suivant;
	    int num;
	};

	struct TypeGenotype{
        int num;
        TypeGenotype* suivant;
        TypePaireHaplotypes* tete;
        char nom[TAILLEGENOTYPE+1];
        int nombrePairesHaplotypes;
	};

	typedef struct ListeGenotype{
        TypeGenotype* tete;
        int nombre;
    }ListeGenotype;

// D�finition des structures fin

int main()
{

    //D�clarations des variables globales
    FILE* FichierGenotypes = NULL;
    int i;
    char genotype[TAILLEGENOTYPE];
    //on initialise l'al�atoire
    srand(time(NULL));

    //Test d'existence du fichier contenant les g�ntoypes

    //Cr�ation du fichier contenant les g�notypes
    FichierGenotypes=fopen("Liste des g�notypes.txt", "w+");
    if (FichierGenotypes != NULL){
            for (i=0; i<10; i++){
                generationGenotype(genotype);
                fprintf(FichierGenotypes, "/ind %d %s\n", i, genotype);
            }
    }
    fclose(FichierGenotypes);
    return 0;
}

//G�n�ration d'un genotype au hasard
void generationGenotype (char* genotype)
{
    //D�claration des variables locales
        int i;
        char locus[2];
        strcpy(genotype, "");
        for (i=0; i<TAILLEGENOTYPE; i++){
            sprintf(locus,"%d", locusAleatoire(50)); // Met un entier al�atoire entre 0 et 2 dans la chaine locus
            strcat(genotype, locus); // Ajoute un nouveau locus au g�notype
        }
}

int locusAleatoire(int tauxAmbiguite)
{
    int ambiguite, locus;
    ambiguite = rand()%101;
    if (ambiguite < tauxAmbiguite){
        locus=2;
    }else{
        locus=rand()%2;
    }
    return locus;
}
