/*
	Exercice 3 :
	Ecrire un programme C qui permet de supprimer un élément X donné dans un tableau T de N entiers donné.
*/
#include<stdio.h>
#include<stdlib.h>
#define TAILLE_MAX 50

void presentation();
int recupTaille();
void recupTousLesValeus(int taille , int *premierElement);
int delete(int taille,int *premierElement);
void afficheResultat(int taille,int *premierElement);

int main ()
{
	int  n ;
	int T[TAILLE_MAX] ;

	presentation();
	n=recupTaille();
	recupTousLesValeus(n,T);
	n=delete(n,T);
	afficheResultat(n,T);

	return(0);
}
void presentation()
{
	//Presentaton du programme
	printf("\tSupprimer un élément X donnee dans un tableau T de N entiers donnees.\n");
}
int recupTaille()
{
	int n;
	int nombreEssai;
	nombreEssai=0;
	do
	{
		nombreEssai++;
		//limite que quelqu'un fasse n'importe quoi
		if(nombreEssai>3)
		{
			exit (0);
		}
		printf("Entrer la taille du tableau (max50): ");
		scanf("%d",&n);	
	}
	while( n>TAILLE_MAX || n<0 );
	return (n);
}
void recupTousLesValeus(int taille , int *premierElement)
{
	//Recuperation des valeurs et calcule de leur somme
	printf("\n\tRecuperation des valeurs des elements du tableau T :\n");
	int i;
	int *T;
	T=premierElement;
	for(i=0;i<taille;i++)
	{
		printf("\tT[%d] = ",i);
		scanf("%d",T);
		T=T+1;
	}
}
int delete(int taille,int *premierElement)
{
	int i,indiceSuppr;
	int *T;
	T=premierElement;

	printf("Quelle element du tableau voulez-vous supprimer ?\n");
	printf("-->veuillez entrez son indice : ");
	scanf("%d",&indiceSuppr);
	for(i=indiceSuppr;i<taille;i=i+1)
	{
		T[i]=T[i+1];
	}
	taille--;
	return (taille);
}
void afficheResultat(int taille,int *premierElement)
{
	int i;
	int *T;
	T=premierElement;
	printf("Voici les elements apres l'enlevement de l'element selectionnee :\n");
	for(i=0;i<taille;i++)
	{
		printf("%d\t",T[i]);
	}
	printf("\n");

}