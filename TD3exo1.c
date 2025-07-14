/*
	Exercice 1 :
	Ecrire un algorithme qui saisit un tableau d'entiers de taille N (constante) 
	et qui l'affiche de telle sorte que tous les entiers pairs se retrouvent avant les entiers impairs.
	Par exemple, le programme affichera pour un tableau contenant 7 4 7 8 4 6 3 9 6 
	ses valeurs de la manière suivante : 4 8 4 6 6 7 7 3 9.
*/
#include<stdio.h>
#include<stdlib.h>
#define TAILLE_MAX 50

void presentation();
int recupTaille();
void recupTousLesValeus(int taille , int *premierElement);
void triage(int taille,int *premierElement);
void afficheResultat(int taille,int *premierElement);


int main()
{
	int  n ;
	int T[TAILLE_MAX] ;

	presentation();
	n=recupTaille();
	recupTousLesValeus(n,T);
	triage(n,T);
	afficheResultat(n,T);

	return(0);
}
void presentation()
{
	//Presentaton du programme
	printf("\tTriage des elements Paire(s) et impaire(s) du tableau\n");
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
void triage(int taille,int *premierElement)
{
	int i,positionPair,indiceEchange,temp;
	int *T;
	T=premierElement;
	positionPair=0;
	for(i=0;i<taille;i++)
	{
		if((T[i]%2) == 0)
		{
			for(indiceEchange=i ; (indiceEchange > positionPair) ; indiceEchange--)
			{
				temp = T[indiceEchange] ;
				T[indiceEchange] = T[(indiceEchange - 1)] ;
				T[(indiceEchange - 1)] = temp ;
			}
			positionPair++;
		}
	}
}
void afficheResultat(int taille,int *premierElement)
{
	int i;
	int *T;
	T=premierElement;
	printf("Voici les elements apres triage :");
	for(i=0;i<taille;i++)
	{
		printf("%d\t",T[i]);
	}
	printf("\n");

}