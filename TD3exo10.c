/*
	Exercice 10 :
	Ecrire un programme C permettant de crypter une phrase en français, ne contenant que des lettres. 
	Il s'agit d'ajouter "IT" à chaque fois que l'on rencontre une consonne suivie d'une voyelle. 
	Les voyelles sont : 'a', 'e', 'i', 'o', 'u', 'y' 

	Exemple : 	Phrase en français : "Je travaille" 
				Phrase en cryptée : "JITe trITavITaillITe"
*/

#include<stdio.h>
#include<string.h>
#define TAILLE 100

void presentation();
void saisir(int taillelimite,char *nomChaine);
void crypter(char *texte);
void affiche(char *nomChaine);

int main ()
{
	char phrase[TAILLE];

	presentation();
	saisir(TAILLE,phrase);
	crypter(phrase);
	affiche(phrase);

	return(0);
}
void presentation()
{
	//Presentaton du programme
	printf("\tCRYPTAGE D'UNE PHRASE\n");
}
void saisir(int taillelimite,char *nomChaine)
{
	int longueur,tailleNonCryptee;
	//diviser par 2 pour garder du place a l'insertion de 'IT'
	tailleNonCryptee=taillelimite/2;
	do
	{
		printf("Veuillez entrez la phrase à crypter (max 50 caractere):\n--> ");
		gets(nomChaine);
		longueur=strlen(nomChaine);
	}
	while(longueur>tailleNonCryptee);
}
void crypter(char *texte)
{
	char voyelle[6]="aeyuio";
	char consonne[40]="zrtpqsdfghjklmwxcvbnZRTPQSDFGHJKLMWXCVBN";
	int longueur,i,j,k,l;

	//affectons la taille du texte pour faciliter l'ecriture d'une instruction
	longueur=strlen(texte);
	//Ajoutons IT apres chaque voyelle suivi d'une consonne
	for(i=0;i<longueur;i++)
	{
		for(k=0;k<40;k++ )
		{
			for(l=0;l<6;l++)
			{
				if( (texte[i]==consonne[k]) && (texte[i+1]==voyelle[l]) )
				{
					for(j=(longueur+1);j>(i+2);j--)
					{
						texte[j]=texte[j-2];
					}
					texte[i+1]='I';
					texte[i+2]='T';
					i+=3;
					longueur+=2;
				}
			}
		}
	}
	texte[longueur]='\0';
}
void affiche(char *nomChaine)
{
	printf("\tVoici la phrase cryptee :\n");
	puts(nomChaine);
}