/*
procedure calculer les probabilités des genotypes
	pour chaque genotype g
		proba <- 0
		pour chaque paire explicative (h1,h2) de g  //g doit être une liste donc pas g mais identifiant de g. Il faut pointer sur les id d'haplo et geno pas les 0/1/2.
			f1 <- frequence de l'haplotype h1
			f2 <- frequence de l'haplotype h2
			si (h1==h2)
				p_part<-f1²
			sinon
				p_part<-2*f1f2
			fin si
			proba<-proba+p_part //dans proba_prec
		fin pour
	fin pour
*/


#include <stdio.h>
int main(){
/*Boucle qui circule dans la liste genotype
	Pour chacun 
		proba = 0
		Pour chaque Paire Explicative
		.. 
		*/
		
void calcul_proba_geno(ListeGenotype *liste){
	double f1,f2;
	if (liste == NULL){
		exit(EXIT_FAILURE);
	}
	TypeGenotype *Genotype = liste -> tete;
	while (Genotype != NULL){
		Genotype->proba=0;
		TypePaireHaplo * PaireHaplo = liste2 -> tete;
		while (PaireHaplo != NULL){
			if (PaireHaplo -> PaireHaplo_id == Genotype -> PaireHaplo_id){
				f1 = PaireHaplo -> freq1;
				f2 = PaireHaplo -> freq2;
			}
			PaireHaplo = PaireHaplo -> suivant;
		}
		if (f1==f2){
			p_part=f1*f1;
		}else{
			p_part=2*f1f2;
		}
		proba = proba + p_part;
		
		Genotype = Genotype -> suivant;
	}
}

return 0;
}//Fin du main
