/*
	Exercice 8 :
	On appelle bigramme une suite de 2 lettres.
	Ecrire un programme C qui calcule le nombre d’occurrences d’un bigramme donné dans une chaine de caractères.
*/
#include<stdio.h>
#include<string.h>
#define TAILLE 100

void presentation();
void saisir(int taillelimite,char *nomChaine);
void lireBigramme(char *nomBgr);
int compteurDeBigramme(char *nomChaine,char *nomBgr);
void afficheResultat(int nbrApparition,char *nomBgr);

int main ()
{
	char texte[TAILLE];
	char bigramme[3];
	int occurence;

	presentation();
	saisir(TAILLE,texte);
	lireBigramme(bigramme);
	occurence=compteurDeBigramme(texte,bigramme);
	afficheResultat(occurence,bigramme);

	return(0);
}
void presentation ()
{
	//presentation du programme
	printf("\t\tLE NOMBRE DE BIGRAMME DANS LE TEXTE\n");	
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
void lireBigramme(char *nomBgr)
{
	int longueur;
	do
	{
		//recuperation du bigramme a chercher
		printf("Veuillez entrer le bigramme a chercher dans le texte : ");
		scanf("%s",nomBgr);
		longueur=strlen(nomBgr);
	}
	while(longueur!=2);
}
int compteurDeBigramme(char *nomChaine,char *nomBgr)
{
	int longueur,nbDEbgr,i;

	//recuperation de la taille du texte pour pouvoir l'exploiter
	longueur=strlen(nomChaine);
	//initialisons le nombre de bigramme dans le texte par 0
	nbDEbgr=0;
	//recherche de bigramme
	for(i=0;i<longueur;i++)
	{
		if( (nomChaine[i]==nomBgr[0]) && (nomChaine[i+1]==nomBgr[1]) )
		{
			nbDEbgr++;
		}
	}
	return (nbDEbgr);	
}
void afficheResultat(int nbrApparition,char *nomBgr)
{
	printf("--> Il y a %d '%s' dans la chaine de caractere que vous avez donnee.\n",nbrApparition,nomBgr);
}