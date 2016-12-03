/*
procedure initialisation des frequences d'haplotypes
	dans l'ensemble de tous les haplotypes susceptibles d'entrer dans l'explication des genotypes observés, attribuer la frequence f à chaque haplotype.  
	f=1/nb_haplotypes //mettre dans f_prec
*/

// gcc -o ini_freq_haplo.ex ini_freq_haplo.c
//TODO Ceci ne fonctionne que si nous n'avons pas de doublons dans les haplotypes. A Vérifier.
#include <stdio.h>
int main(){
double nLignes=0; //utilisation d'un double pour le calcul de la fréquence plus bas.
int c;

FILE* FichierHaplotypes = NULL;
FichierHaplotypes=fopen("../generation_haplotypes/haplo_possibles.txt", "r+");

while ((c=getc(FichierHaplotypes))!=EOF){
	if (c=='\n'){
		nLignes++;
	}
}
fclose(FichierHaplotypes);

double freq_Haplo = 1/nLignes;
printf("Nombre de lignes (=nombre d'haplotypes) : %.f\n",nLignes); //%.f permet d'arrondir avant la virgule, comme si c'était un int.
printf("Fréquence de chaque haplotypes : %f\n",freq_Haplo);

return 0;
}//Fin du main()
