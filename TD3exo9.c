/*
	Exercice 9 : 
	Une chaîne de caractères W est un carré s’il existe une chaîne U telle que W = UU
	( par exemple "chercher" et "bonbon" sont des carrés).
	Ecrire un programme C qui dit si une chaîne est carrée ou non
*/
#include<stdio.h>
#include<string.h>
#define TAILLE 50

void presentation();
void saisir(int taillelimite,char *nomChaine);
int testCarre(char *nomChaine);
void afficheResultat(int verite);

int main ()
{
	char chaine[TAILLE];
	int carree;

	presentation();
	saisir(TAILLE,chaine);
	carree=testCarre(chaine);//return 1 si le chaine est carree
	afficheResultat (carree);

	return(0);
}
void presentation()
{
	//Presentaton du programme
	printf("\t\tIDENTIFIER SI UNE CHAINE DE CARACTERE  EST UN CARRE\n");
}
void saisir(int taillelimite,char *nomChaine)
{
	int longueur;
	do
	{
		printf("Veuillez entrer votre texte :\n--> ");
		gets(nomChaine);
		longueur=strlen(nomChaine);
	}
	while(longueur>taillelimite);
}
int testCarre(char *nomChaine)	
{
	int nbcaractere,verite,i,j;

	//initialisons que la chaine est carre
	verite=1;
	nbcaractere=strlen(nomChaine);
	//testons si la chaine est une composee de deux autre chaines tout identique
	j=(nbcaractere/2);
	for(i=0;i<(nbcaractere/2);i++)
	{	
		if(nomChaine[j]!=nomChaine[i])
		{
			//s'il y a une difference entre ses deux moitiees, il n'est plus carre ; arretons la boucle
			verite=0;
			break;
		}
		j++;
	}
	return (verite);
}
void afficheResultat(int verite)
{
		//carre si b vaut encore 1
 	if(verite==1)
	{
		printf("\n-->C'est une chaine carre .\n");
	}
		else
		{
			printf("\n-->Non,ce n'est pas une chaine carre .\n");	
		}
}