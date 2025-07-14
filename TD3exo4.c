/*
	Exercice 4 :
	Soient deux tableaux d’entiers T1 (maximum 100) et T2 (max 50). 
	Ecrire un programme C qui permet de vérifier que T2 existe dans T1. 
	Si T2 existe dans T1, alors supprimer les éléments de T2 dans T1. 
	Ex : 
		T1 1 4 6 7 3 2 9 
		T2 6 7 3 

		T1 → 1 4 2 9
*/
#include<stdio.h>
#include<stdlib.h>
#define TAILLE_MAX 50

void presentation();
int recupTaille(char nomtab[2]);
void recupTousLesValeus(int taille , char nomtab[2],int *premierElement);
int differeT1deT2(int tailleDeT1 , int *tableauDeT1 , int tailleDeT2 , int *tableauT2);
int trouveT2dansT1(int tailleDeT1 , int *tableauT1 , int tailleDeT2 , int *tableauT2);
void afficheResultat(int taille ,int *premierElement);

int main()
{
	int T1[(2*TAILLE_MAX)];
	int T2[TAILLE_MAX];
	int n , m ;

	presentation();
	n=recupTaille("T1");
	recupTousLesValeus(n,"T1",T1);
	m=recupTaille("T2");
	recupTousLesValeus(m,"T2",T2);
	n=trouveT2dansT1(n,T1,m,T2);
	afficheResultat(n,T1);
	
	return(0);
}
void presentation()
{
	//Presentaton du programme
	printf("\tEnlevement des elements de T1 qui est present T2\n\n");
}
int recupTaille(char nomtab[2])
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
		printf("Entrer la taille du tableau %s (max50): ",nomtab);
		scanf("%d",&n);	
	}
	while( n>TAILLE_MAX || n<0 );
	return (n);
}
void recupTousLesValeus(int taille , char nomtab[2] ,int *premierElement)
{
	//Recuperation des valeurs et calcule de leur somme
	printf("\n\tRecuperation des valeurs des elements du tableau %s :\n",nomtab);
	int i;
	int *T;
	T=premierElement;
	for(i=0;i<taille;i++)
	{
		printf("\t%s[%d] = ",nomtab,i);
		scanf("%d",T);
		T=T+1;
	}
}
int trouveT2dansT1(int tailleDeT1 , int *tableauT1 , int tailleDeT2 , int *tableauT2)
{
	int compteur,positionDuPremier,i;
	int *T1,*T2;
	T1=tableauT1;
	T2=tableauT2;
	/*
		initialisons celle-ci avec une valeur qui n'est pas une position 
	*/
	positionDuPremier=-1;
	for(i=0;i<tailleDeT1;i++)
	{
		if(T2[0]==T1[i])
		{
			positionDuPremier=i;
			compteur=0;
			while(T1[i]==T2[compteur])
			{
				compteur++;
				i++;
			}
		}
	}
	if (positionDuPremier!=-1 && compteur==tailleDeT2)
	{
		printf("--> T2 sont presents dans T1.\n");
		tailleDeT1=differeT1deT2(tailleDeT1,T1,tailleDeT2,T2);	
	}
	return (tailleDeT1);
}
int differeT1deT2(int tailleDeT1 , int *tableauT1 , int tailleDeT2 , int *tableauT2)
{
	int *T1,*T2;
	int compteur,indiceEchange,j,i;
	T1=tableauT1;
	T2=tableauT2;
	for(i=0;i<tailleDeT1;i++)
	{
		for(j=0;j<tailleDeT2;j++)
		{
			if(T1[i]==T2[j])
			{
				for(indiceEchange=i;indiceEchange<(tailleDeT1-1);indiceEchange++)
				{
					T1[indiceEchange]=T1[(indiceEchange+1)];
				}
				tailleDeT1--;
			}
		}
	}
	return (tailleDeT1);
}
void afficheResultat(int taille,int *premierElement)
{
	int i;
	int *T;
	T=premierElement;
	printf("Voici les elements du tableau T1 :\n");
	for(i=0;i<taille;i++)
	{
		printf("%d\t",T[i]);
	}
	printf("\n");

}