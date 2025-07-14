/*
	Exercice 13 : 
	Ecrire un programme C qui permet d’afficher un triangle de Pascal de degré N.
*/
#include<stdio.h>
#define TAILLE_MAX 100

void presentation();
int recupTaille();
void affichePascal(int taille);

int main ()
{
	int degre;
	
	presentation();
	degre=recupTaille();
	affichePascal(degre);

	return(0);
}
void presentation()
{
	printf("\tAffichage  d'un TRIANGLE DE PASCAL de n degre\n");
}
int recupTaille()
{
	int taille;
	do
	{
		printf("\nEntrer la valeur de n (max 100): ");
		scanf("%d",&taille); 
	}
	while(taille<0 || taille>TAILLE_MAX);
	return (taille);
}
void affichePascal(int taille)
{
	int trianglePascal[TAILLE_MAX][TAILLE_MAX]={};
	int i,j;
	for(i=0;i<=taille;i++)
	{
		trianglePascal[i][i]=1;
		trianglePascal[i][0]=1;
	}
	for(i=2;i<=taille;i++)
	{
		for(j=1;j<=taille;j++)
		{
			trianglePascal[i][j]=trianglePascal[i-1][j-1]+trianglePascal[i-1][j];
		}
	}
	for(i=0;i<=taille;i++)
	{
		for(j=0;j<=taille;j++)
		{
			if(trianglePascal[i][j]!=0)
			{
				printf("%d\t",trianglePascal[i][j]);
			}
		}
		printf("\n\n");
	}
}