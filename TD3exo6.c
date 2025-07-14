/*
	Exercice 6 :
	Ecrire un programme C qui lit une chaîne de caractères et vérifie si elle est palindrome ou non. 
	On rappelle qu’une chaîne de caractères est dite palindrome
	, si elle se lit de la même manière dans les deux sens. 
	Exemple: 
	non, touot et 1234321 sont toutes des chaînes de caractères palindromes.
*/
#include<stdio.h>
#include<string.h>
#define TAILLE 50

void presentation();
void saisir(char *nomChaine);
int testPalindrome(char *nomChaine);
void afficheResultat(int verite);

int main ()
{
	char chaine[TAILLE];
	int palindrome;

	presentation();
	saisir(chaine);
	palindrome=testPalindrome(chaine);//retourne 1 si chaine est palindrome
	afficheResultat(palindrome);

	return (0);
}
void presentation()
{
	//Presentaton du programme
	printf("\t\tIDENTIFIER SI UNE CHAINE DE CARACTERE  EST PALINDROME\n");
}
void saisir(char *nomChaine)
{
	printf("\tVeuillez entrer la chaine a tester : ");
	scanf("%s",nomChaine);
}
int testPalindrome(char *nomChaine)
{
	int nbcaractere,verite,i,j;
	
	//initialisons que la chaine est palindrome
	verite=1;
	//voyons le nombre de caractere de la chaine entree
	nbcaractere=strlen(nomChaine);
	//testons si la chaine est symetrique
	j=(nbcaractere-1);
	for(i=0;i<(nbcaractere/2);i++)
	{	
		if(nomChaine[j]!=nomChaine[i])
		{
			//s'il y a une difference , il n'est plus palindrome ; arretons la boucle
			verite=0;
			break;
		}
		j--;
	}
	//symetrique si verite vaut encore 1
	return (verite);
}
void afficheResultat(int verite)
{
	if(verite==1)
	{
		printf("\n-->C'est une chaine palindrome.\n");
	}
		else
		{
			printf("\n-->Non,ce n'est pas une chaine palindrome\n");	
		}

}