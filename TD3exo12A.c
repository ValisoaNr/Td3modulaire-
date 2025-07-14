/*
	Exercice 12 :
	On appelle carré un tableau de n lignes et de n colonnes contenant des entiers naturels.
	Le carré est magique si, en effectuant la somme de tous les nombre d’une ligne ou d’une colonne, 
	le résultat est le même quelle que soit la ligne ou la colonne.

	Exemple : 
		8	6	1 = 15 
		4	2	9 = 15
		3	7	5 = 15 
		=	=	=
		15	15	15 
	Ecrire un programme C qui permet de remplir et déterminer si un carré est magique ou non.
*/
#include<stdio.h>
#define TAILLE_MAX 100

void presentation();
int recupTaille();
void recupElement(int taille, int tableau2D[][taille]);
int testMagique(int taille, int tableau2D[][taille]);
void afficheResultat(int verite);

int main ()
{
	int carree[TAILLE_MAX][TAILLE_MAX];
	int taille,magique;

	presentation();
	taille=recupTaille();
	recupElement(taille,carree);
	magique=testMagique(taille,carree);//return 1 si c'est un carree magique
	afficheResultat(magique);

	return(0);
}
void presentation()
{
	//Presentaton du programme
	printf("\tTester si un carree est un carree magique\n");
}
int recupTaille()
{
	int taille;
	do
	{
		printf("Entrez taille du carree a tester (max 100):");
		scanf("%d",&taille);
	}
	while(taille<0 || taille>TAILLE_MAX);
	return (taille);
}
void recupElement(int taille, int tableau2D[][taille])
{
	int ligne , colonne ;
	printf("\n\tEntrez les elements du carree a tester :\n");
	for(ligne=0 ; ligne<taille ;ligne++)
	{
		for(colonne=0 ; colonne<taille ;colonne++)
		{
			printf("--> carre[%d][%d] = ",ligne,colonne);
			scanf("%d",&tableau2D[ligne][colonne]);
		}
	}
}
int testMagique(int taille,int tableau2D[][taille])
{
	//stocker les sommes des colonnes et aussi des lignes separement pour les  comparer apres
	int somme[(TAILLE_MAX*2)]={};
	int ligne , colonne , i , iTabSomme , verite ;
	
	iTabSomme=0;
	for(ligne=0 ; ligne<taille ;ligne++)
	{
		for(colonne=0 ; colonne<taille ;colonne++)
		{
			somme[iTabSomme]=somme[iTabSomme]+tableau2D[ligne][colonne];
		}
		iTabSomme++;
	}
	for(colonne=0 ; colonne<taille ;colonne++)
	{
		for(ligne=0 ; ligne<taille ;ligne++)
		{
			somme[iTabSomme]=somme[iTabSomme]+tableau2D[ligne][colonne];
		}
		iTabSomme++;
	}

	//supposons en premier temps que c'est un carre magique
	verite=1;
	//testons s'il est vraiment un
	for(i=0 ; i<(iTabSomme-1) ;i++)
	{
		//s'il y a une difference entre chaque element du tableau somme
		//le carre n'est plus magique ; arretons le teste
		if(somme[i]!=somme[i+1])
		{
			verite=0;
			break ;
		}
	}
	return (verite);
}
void afficheResultat(int verite)
{
	//le carre est magique si verite vaut encore 1
	if(verite==1)
	{
		printf("\n\tOui , c'est un carre magique .\n");
	}
		else
		{
			printf("\n\tNon , ce n'est pas un carre magique .\n");
		}
}