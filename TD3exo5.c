/*
	Exercice 5 :
	Etant donné un tableau d’entiers trouver et afficher l’élément le plus proche de la moyenne.
*/
#include<stdio.h>
#include<stdlib.h>
#define TAILLE_MAX 50

void presentation();
int recupTaille();
void recupTousLesValeus(int taille , int *premierElement);
float calculeMoy(int taille, int *tableau);
void afficheTab(int taille,int *premierElement);
int trouveMax(int taille,int *premierElement);
int trouveMin(int taille,int *premierElement);
int trouveElementMoyenne(int taille,int *tableau,float moyenne);

int main ()
{
	int T[TAILLE_MAX] ;
	int  n ;
	float moyenne;

	presentation();
	n=recupTaille();
	recupTousLesValeus(n,T);
	moyenne=calculeMoy(n,T);
	afficheTab(n,T);
	trouveElementMoyenne(n,T,moyenne);

	return(0);
}
void presentation()
{
	//Presentaton du programme
	printf("\tAffichage de l'element le plus proche de la moyenne\n");
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
float calculeMoy(int taille, int *tableau)
{
	int i,somme;
	float moyenne;
	somme=0;
	for(i=0;i<taille;i++)
	{
		somme=somme+tableau[i];
	}
	moyenne=somme/taille;
	return (moyenne);
}
int trouveMin(int taille,int *premierElement)
{
	/*identification du minimum*/
	int *A;
	int i,min;
	A=premierElement;
	min=A[0];
	for(i=0;i<taille;i++)
	{
		if(A[i]<=min)
		{
			min=A[i];
		}
	}
	return(min);
}
int trouveMax(int taille,int *premierElement)
{
	/*identification du maximum*/
	int *A;
	int i,max;
	A=premierElement;
	max=A[0];
	
	for(i=0;i<taille;i++)
	{
		if(A[i]>=max)
		{
			max=A[i];
		}
	}
	return(max);
}
int trouveElementMoyenne(int taille,int *tableau,float moyenne)
{
	/*
		l'element le plus proche de la moyenne se trouve 
		entre la moyenne des elements ET le minimum ou maximum

		pdm : proche de la moyenne
	*/
	int i,pdm,pdm1,pdm2;
	int e1,e2,pdmDefinition;
	int *T;
	T=tableau;
	pdm1=trouveMin(taille,tableau);
	pdm2=trouveMax(taille,tableau);
	pdmDefinition=0;
	for(i=0;i<taille;i++)
	{
		if(T[i]>pdm1 && T[i]<moyenne)
		{
			pdm1=T[i];
		}
			else if (T[i]<pdm2 && T[i]>moyenne)
			{
				pdm2=T[i];
			}
				else if(T[i]==moyenne)
				{
					pdm=T[i];
					pdmDefinition=1;//c'est pour indiquer pdm qu'on ne doit plus le redefinir
					break;//puisque le moyenne est existant dans T
				}
	}
	if (pdmDefinition==0)
	{
		if(pdm1==pdm2)
		{
			pdm=pdm1;
		}
			else
			{
				e1=moyenne-pdm1;
				e2=pdm2-moyenne;
				if(e1<e2)
				{
					pdm=pdm1;
				}
					else if(e1>e2)
					{
						pdm=pdm2;
					}
			}

	}
	printf("\n-->L'element du tableau T le plus proche de la moyenne est %d ",pdm);
	printf("\n");
}
void afficheTab(int taille,int *premierElement)
{
	int i;
	int *T;
	T=premierElement;
	printf("Voici les elements du tableau :\n");
	for(i=0;i<taille;i++)
	{
		printf("%d\t",T[i]);
	}
	printf("\n");
}
