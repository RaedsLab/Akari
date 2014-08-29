/**
 	@file Menu.c
	 @author Chammem Raed et Abdeljelil Skander.
	 @supervisor Mme Ben Amor Imene et Mr Khodjet El Khil Ghazi.
	 @version 1.1
	 @date 17/05/2012
	 @brief C'est le code dans lequel nous avons implémenté les fonctions qui assurent l'affichage des menus du jeu.
*/

#include"Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Menu_Princ();
int Menu_Jeu();
int Menu_Inst();
void Menu_Quit();

/**
	 @fn Main
	 @brief Une Fonction qui fait appel à toutes les fonctions déjà implémentées dans les codes précédents.
         @param Aucun paramètre.
	 @return int.
	*/

int main()
{ 	int i,j;
    int M[24][24];
    int M1[24][24];
    int niv,h,l,m;
int menu=-1;
int menu2=-1;
int inst=-1;
menu=Menu_Princ();
do
{


if(menu==1)
{
menu2=Menu_Jeu();
if(menu2==1)
{

printf("**********************************************************\n");
printf("***                  A  K  A  R  I                     ***\n");
printf("**                                                      **\n");
printf("*      [1] Facile                                        *\n");
printf("*      [2] Moyen                                         *\n");
printf("*      [3] Difficile                                     *\n");
printf("**                                                      **\n");
printf("***                                                    ***\n");
printf("**********************************************************\n");
printf("Saisir choix...\n");

    scanf("%d",&niv);
    switch (niv)
    {
    case 1:
        h=10;
        l=10;
        resumeGame_facile(M1);
        break;

    case 2:
        h=10;
        l=18;
        resumeGame_moy(M1);
        break;

    case 3:
        h=14;
        l=24;
        resumeGame_dif(M1);
        break;
    }
}
else if(menu2==2)
{
reprendre(M1,&h,&l);
printf(" h %d   l %d \n\n",h,l); 
}
if(menu2==2 || menu2==1)
{
if(menu2==1)
{
printf("Copy activated");
cpy_matrice(M1,M,h,l);
}
else if (menu2==2)
{
for(i=0;i<h;i++)
{
for(j=0;j<l;j++)
M[i][j]=M1[i][j];
}}    
        while(m!=3)
        {	
do
    {
            afficher_matrice(M,h,l);
printf(" ************************ \n");
printf("* [1] Ajouter ampoule    *\n");
printf("* [2] Supprimer ampoule  *\n");
printf("* [3] Quitter            *\n");
printf("*                        *\n");
printf("* [4] Enregistrer Partie *\n");
printf(" ************************ \n");
printf("Saisir choix...\n");

            scanf("%d",&m);
            if(m==1)
            {
                ajout_lampe(M,h,l);
            }
            else if(m==2)
            {
                supprimer_lampe(M,h,l);
            }
            else if (m==3)
            {
                break;
            }else if(m==4)
		{
		sauvgarder(M,h,l);		
		}
            else
                printf("Entree non valide! \n");
}while(m!=3);
if(cmp_matrice(M1,M,h,l)==0)
{
printf("\033[22;35mVous n'avez pas fini le niveau.. \n");
        printf("\033[22;31mVous voulez vraiment Quitter ?  (N/Y):[0/3]\033[22;30m");
        scanf("%d",&m);
}}
 if(cmp_matrice(M1,M,h,l)==1)
{
printf("\033[22;32m[*]\n\n\n*** BRAVO Vous Avez gagné !! ***\n\n\n\033[22;30m");
}    



}

else if(menu2==0)
Menu_Quit();
break;
}else if(menu==2)
{
inst=Menu_Inst();
if(inst==0)
{
menu=1;
}
}



}while (menu!=0 && menu2!=0);
if(menu==0)
Menu_Quit();

return 0;
}


///////////////////////////////////////////////////////////////////////
/**
	 @fn Menu_Principal.
	 @brief Une Fonction qui assure la navigation dans le menu principal et choisir de jouer, voir les instructions ou de quitter .
         @param Aucun paramètre.
	 @return int.
	*/

int Menu_Princ()
{
int menu=-1;
do{
printf("**********************************************************\n");
printf("***                  A  K  A  R  I                     ***\n");
printf("**                                                      **\n");
printf("*      [1] Jouer                                         *\n");
printf("*      [2] Instructions                                  *\n");
printf("*      [3] Meilleurs Scores                              *\n");
printf("*      [0] Quitter                                       *\n");
printf("**                                                      **\n");
printf("***                                                    ***\n");
printf("**********************************************************\n");
printf("Saisir choix...\n");
scanf("%d",&menu);
}
while(menu<0 || menu>3);
return(menu);
}
///////////////////////////////////////////////////////////////////////
/**
	 @fn Menu_Jeu.
	 @brief Une Fonction qui assure la navigation dans le menu du jeu et choisir entre une nouvelle partie ou reprendre une partie sauvegardée.
         @param Aucun paramètre.
	 @return int.
	*/

int Menu_Jeu()
{
int menu2=-1;
do
{
printf("**********************************************************\n");
printf("***                  A  K  A  R  I                     ***\n");
printf("**                                                      **\n");
printf("*      [1] Nouvelle Partie                               *\n");
printf("*      [2] Reprendre                                     *\n");
printf("*      [0] Quitter                                       *\n");
printf("**                                                      **\n");
printf("***                                                    ***\n");
printf("**********************************************************\n");
printf("Saisir choix...\n");
scanf("%d",&menu2);
}
while(menu2<0 || menu2>2);
return(menu2);
}
///////////////////////////////////////////////////////////////////////
/**
	 @fn Menu_Instruction.
	 @brief Un menu qui permet d'afficher les instructions du jeu.
         @param Aucun paramètre.
	 @return int.
	*/

int Menu_Inst()
{
int inst=-1;
printf("**********************************************************\n");
printf("***                  A  K  A  R  I                     ***\n");
printf("**                                                      **\n");
printf("*  Vous ne pouvez placer les ampoules que dans les cases *\n");
printf("*  vides. Un nombre [0..4] indique le nombre d'ampoules  *\n");
printf("*  qui doivent l'entourer,verticalement ou/et            *\n");
printf("*  horizentalement.                                      *\n");
printf("*                                                        *\n");
printf("*  Chaque ampoule illumine toute sa rangé et colonne,    *\n");
printf("*  sauf si un obstacle bloque le chemin.                 *\n");
printf("*                                                        *\n");
printf("*  Chacune des cases vides doit être illuminée.          *\n");
printf("*                                                        *\n");
printf("*  Une ampoule ne peut illuminer une autre.              *\n");
printf("**                                                      **\n");
printf("***                  [0]  Retour                       ***\n");
printf("**********************************************************\n");
printf("Saisir choix...\n");
scanf("%d",&inst);
inst=0;
return(inst);
}
///////////////////////////////////////////////////////////////////////
/**
	 @fn Menu_Quitter.
	 @brief C'est un text d'Au Revoir.
         @param Aucun paramètre.
	 @return void.
	*/

void Menu_Quit()
{
printf("**********************************************************\n");
printf("***                  A  K  A  R  I                     ***\n");
printf("**                                                      **\n");
printf("*                                                        *\n");
printf("*                      Au Revoir                         *\n");
printf("*                                                        *\n");
printf("**                                                      **\n");
printf("***                                                    ***\n");
printf("**********************************************************\n");
}
