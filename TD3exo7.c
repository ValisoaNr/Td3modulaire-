/*
	Exercice 7 :
	Ecrire un programme C qui permet de lire un texte caractère par caractère 
	; le texte se termine par un point.
	Ce programme doit afficher le nombre de d’apparition du caractère ‘a’ 
	et le nombre de d’apparition de la suite "es".
*/
#include<stdio.h>

void presentation();
void compterAetES();

int main ()
{
	
	presentation();
	compterAetES();

	return(0);
}
void presentation()
{
	//presentation du programme
	printf("\t\tLE NOMBRE D'APPARITION DE 'a' ET DE LA SUITE 'es'\n");	
}
void compterAetES()
{
	char caractere;
	int nbDEa,nbDEes,flags;

	nbDEa=0;
	nbDEes=0;
	/*
		utilisons un variable pour indiquer 
		la presence ou pas d'un 'e' si on verra un 's' 
	*/
	flags=0;
	//La partie suivante permet de lire un texte caractère par caractère 
	printf("Entrez le texte (termine-le par un point) : ");
	do
	{
		scanf("%c",&caractere);
		if ( caractere=='a' )
		{
			nbDEa++;
			flags=0;
		}
			else if ( caractere=='e' )
			{
				flags=1;
			}
				else if ( ( caractere=='s' ) && ( flags==1 ) )
				{
					nbDEes++;
				}
					else
					{
						flags=0;
					}
	}
	while(caractere!='.');
	printf("--> Il y a %d 'a' et %d 'es' dans le texte \n",nbDEa,nbDEes);
}