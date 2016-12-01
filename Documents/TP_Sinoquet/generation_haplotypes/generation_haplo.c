//gcc -o gene_haplo generation_haplo.c -lm
//TODO
/* 
#Ajouter une étoile après chaque génotype lors de la génération
#Associer chaque haplotype à une fréquence.
#Boucler pour que se soit fait pour plusieurs génotypes.
#Ajouter un test pour l'ouverture des fichiers.
*/
#include <stdio.h>
#include <math.h>
#define taille_max 20
int main(){
int i,Nbre_Haplo,x,j,k;
int Cptr2=0;
int compteur2;
int taille_geno=0;
char str[20];
FILE* FichierGenotypes = NULL;
FichierGenotypes=fopen("geno.txt", "r+");
FILE* FichierHaplotypes = NULL;
FichierHaplotypes=fopen("haplo_possibles.txt", "w+");

while(fgets(str,taille_max,FichierGenotypes)!=NULL){

Cptr2=0;
i=6;
do{ 
	i++;
	if(str[i]=='2'){Cptr2++;}
}while (str[i] != '*');
taille_geno=i-7;

Nbre_Haplo = pow(2,Cptr2);//calcul du nombre d'haplotypes
//Affichage des caractéristiques :
printf("Nombre de 2 : %d\n",Cptr2);
printf("Nombre d'haplotypes possibles : %d\n", Nbre_Haplo);
printf("Taille du genotype : %d\n",taille_geno);



int pos=0;//curseur pour se déplacer dans haplo.txt
int Matrice_haplo[Nbre_Haplo][taille_geno];
//Generation de tous les Haplotypes possibles dans la matrice, génération sous forme de plaindrome : le premier haplotype est en paire avec le dernier etc...
compteur2=0;
for (i=7;i<(7+taille_geno);i++){
//	fseek(FichierGenotypes, i, SEEK_SET);
	x=str[i];
	if(x=='0'){ //Si le genotype a un 0 à la position x
		for (j=0;j<Nbre_Haplo;j++){ //Tous les haplotypes ont un 0 à cette position
			Matrice_haplo[j][pos]='0';
		}
	}
	else if(x=='1'){ //Même mécanisme si x = 1 
		for (j=0;j<Nbre_Haplo;j++){
			Matrice_haplo[j][pos]='1';
		}
	}	
	else{ //Si le caractère est ambigue : 2
		compteur2++; //C'est le n.ième 2 rencontré par la fonction
		int positionement=0; //Pour se déplacer dans la matrice
		for(j=0;j<pow(2,compteur2-1);j++){ //Ecriture des haplotypes ambigues en fonction du nombre de 2 déjà rencontrés. Ecriture en palindrome.
			for(k=0;k<Nbre_Haplo/(pow(2,compteur2));k++){
				//ecrire 1
				Matrice_haplo[k+positionement][pos]='1';
			}
			for(k=Nbre_Haplo/(pow(2,compteur2));k<2*(Nbre_Haplo/(pow(2,compteur2)));k++){
				//ecrire 0
				Matrice_haplo[k+positionement][pos]='0';
			}
		positionement+=2*Nbre_Haplo/(pow(2,compteur2));
		}
	}
	pos++;
}

//Affichage des haplotypes possibles :	
printf("haplotypes possibles :\n");
for(i=0;i<Nbre_Haplo;i++){
	for(j=0;j<taille_geno;j++){
		printf("%c",Matrice_haplo[i][j]); //Affichage de chaque valeur de la matrice
	}printf("\n");
}

for(i=0;i<Nbre_Haplo;i++){ //Chaque valeur est lue dans la matrice et écrite dans un fichier.
	for(j=0;j<taille_geno;j++){
		fputc(Matrice_haplo[i][j],FichierHaplotypes);
	}fputc('\n',FichierHaplotypes);
}

}//fin du premier while

//Fermeture des fichiers avant la fin du script.
fclose(FichierGenotypes);
fclose(FichierHaplotypes);
return 0;
} //Fin du main
