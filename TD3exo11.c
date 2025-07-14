/*
	Exercice 11 
	Ecrire un programme C permettant de décrypter une phrase de l’exercice précédente.
*/

#include<stdio.h>
#include<string.h>
#define TAILLE 100

void presentation();
void saisir(int taillelimite,char *nomChaine);
void decrypter(char *texte);
void affiche(char *nomChaine);

int main ()
{
	char phrase[TAILLE];

	presentation();
	saisir(TAILLE,phrase);
	decrypter(phrase);
	affiche(phrase);
	
	return(0);
}
void presentation()
{
	//Presentaton du programme
	printf("\tDECRYPTAGE D'UNE PHRASE\n");
}
void saisir(int taillelimite,char *nomChaine)
{
	int longueur;
	do
	{
		printf("Veuillez entrez la phrase à decrypter (max 100 caractere) :\n--> ");
		gets(nomChaine);
		longueur=strlen(nomChaine);
	}
	while(longueur>taillelimite);
}
void decrypter(char *texte)
{
	char voyelle[6]="aeyuio";
	char consonne[40]="zrtpqsdfghjklmwxcvbnZRTPQSDFGHJKLMWXCVBN";
	int longueur,i,j,k,l;
	//affectons la taille du texte pour faciliter l'ecriture d'une instruction
	longueur=strlen(texte);
	//supprimons tout les IT entre consonne et voyelle
	for(i=0;i<longueur;i++)
	{
		for(k=0;k<40;k++ )
		{
			for(l=0;l<6;l++)
			{
				if( (texte[i]==consonne[k]) && (texte[i+3]==voyelle[l]) )
				{
					if( (texte[i+1]=='I') && (texte[i+2]=='T') )
					{
						for(j=(i+1);j<longueur;j++)
						{
							texte[j]=texte[j+2];
						}
						i-=3;
						longueur-=2;
					}
				}
			}
		}
	}
	texte[longueur]='\0';
}
void affiche(char *nomChaine)
{
	printf("\tVoici la phrase decryptee :\n");
	puts(nomChaine);
}