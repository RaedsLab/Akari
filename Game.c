/**
 	@file Game.c
	 @author Chammem Raed et Abdeljelil Skander.
	 @supervisor Mme Ben Amor Imene et Mr Khodjet El Khil Ghazi.
	 @version 1.1
	 @date 17/05/2012
	 @brief C'est le code dans lequel nous avons implémenté les fonctions qui commandent le jeu.
*/

#include"Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
	 @fn Cpy_Matrice.
	 @brief Une Fonction qui permet de copier une partie déjà résolue et remplacer les ampoules et les cases illuminées par une case vide.
         @param Deux matrices d'entier M1 et M,une, un entier h qui caractérise la hauteur et un entier l qui caractérise la largeur.
	 @return void.
	*/

void cpy_matrice(int M1[][24],int M[][24],int h,int l)
{
    int i,j;
    for(i=0; i<h; i++)
    {
        for(j=0; j<l; j++)
        {
            if((M1[i][j])==6 || M1[i][j]==5)
            {
                M[i][j]=-1;
            }
            else
            {
                M[i][j]=M1[i][j];
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
/**
	 @fn Cmp_Matrice
	 @brief Une Fonction qui permet comparer la partie jouée avec la celle déjà résolue
             @param Deux matrices d'entier M1 et M, un entier h qui caractérise la hauteur et un entier l qui caractérise la largeur
	 @return int
	*/

int cmp_matrice(int M1[][24],int M[][24],int h,int l)
{
    int i,j;
    for(i=0; i<h; i++)
    {
        for(j=0; j<l; j++)
        {
            if((M[i][j])!=(M1[i][j]))
            {
                return 0;
            }
        }
    }

    return 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////
/**
	 @fn Ajout_Lampe
	 @brief Une Fonction qui permet au joueur d'ajouter une ampoule
             @param La matrice d'entier M, un entier h qui caractérise la hauteur et un entier l qui caractérise la largeur
	 @return void
	*/

void ajout_lampe(int M[][24],int h,int l)
{
    int i,j;

    do
    {
        printf("M[i][j] \n");
        printf("M[i]: ");
        scanf("%d",&i);
        printf("M[j]: ");
        scanf("%d",&j);
    }
    while((i>=h||i<0||j>=l||j<0) || (M[i][j]>=0 && M[i][j]<=4));

    if(M[i][j]==6)
    {
        printf("\033[22;31m\n\n\nIl y'a un conflit de lamples ! \n    Changez quelque chose !!! \033[22;30m\n\n ");
    }
    M[i][j]=5;
    illuminer(M,h,l,i,j);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
	 @fn Afficher_Matrice
	 @brief Une Fonction qui permet d'afficher une grille au joueur
             @param Une matrice d'entier M, un entier h qui caractérise la hauteur et un entier l qui caractérise la largeur
	 @return void
	*/

void afficher_matrice(int M[][24],int h,int l)
{
    int i,j;

    printf("\n");
    for(i=0; i<h; i++)
    {
        for(j=0; j<l; j++)
        {
            if(M[i][j]==6)
            {
                printf("\033[22;32m[*]\033[22;30m");
            }
            else if(M[i][j]==-2)
            {
                printf("[X]");
            }
            else if(M[i][j]==5)
            {
                printf("\033[01;33m[O]\033[22;30m");
            }
            else if(M[i][j]==-1)
            {
                printf("[ ]");
            }
            else
                printf("[%d]",M[i][j]);
        }

        printf("\n");
    }

        printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
	 @fn Illuminer
	 @brief Une Fonction qui permet à l'ampoule d'illuminer toutes s
es cases voisines si elles ne sont pas des obstacles(case noire ou numérotée)
             @param Une matrice d'entier M, un entier h qui caractérise la hauteur un entier l qui caractérise la largeur et deux entiers a et  qui caractérisent la position de l'ampoule saisie par le joueur
	 @return void
	*/

void illuminer(int M[][24],int h,int l,int a,int b)
{
    int i,j;
    i=a;
    if (b>0 && b<(l-1))
    {
        for(j=(b+1); j<l; j++)
        {
            if((M[i][j]>=0 && M[i][j]<=4) || (M[i][j]==-2 || M[i][j]==5) )
            {
                break;
            }
            else
            {
                M[i][j]=6;
            }
        }
        for(j=b-1; j>=0; j--)
        {
            if((M[i][j]>=0 && M[i][j]<=4) || (M[i][j]==-2 || M[i][j]==5) )
            {
                break;
            }
            else
            {
                M[i][j]=6;
            }
        }
    }
    else if(b==0)
    {
        for(j=(b+1); j<l; j++)
        {
            if((M[i][j]>=0 && M[i][j]<=4) || (M[i][j]==-2 || M[i][j]==5) )
            {
                break;
            }
            else
            {
                M[i][j]=6;
            }
        }
    }
    else if(b==(l-1))
    {
        for(j=(b-1); j>0; j--)
        {
            if((M[i][j]>=0 && M[i][j]<=4) || (M[i][j]==-2 || M[i][j]==5) )
            {
                break;
            }
            else
            {
                M[i][j]=6;
            }
        }
    }
///////b///////
    j=b;


    if (a>0 && a<(h-1))
    {
        for(i=(a+1); i<h; i++)
        {
            if((M[i][j]>=0 && M[i][j]<=4) || (M[i][j]==-2 || M[i][j]==5) )
            {
                break;
            }
            else
            {
                M[i][j]=6;
            }
        }
        for(i=a-1; i>=0; i--)
        {
            if((M[i][j]>=0 && M[i][j]<=4) || (M[i][j]==-2 || M[i][j]==5) )
            {
                break;
            }
            else
            {
                M[i][j]=6;
            }
        }
    }
    else if(a==0)
    {
        for(i=(a+1); i<h; i++)
        {
            if((M[i][j]>=0 && M[i][j]<=4) || (M[i][j]==-2 || M[i][j]==5) )
            {
                break;
            }
            else
            {
                M[i][j]=6;
            }
        }
    }
    else if(a==(h-1))
    {
        for(i=(a-1); i>0; i--)
        {
            if((M[i][j]>=0 && M[i][j]<=4) || (M[i][j]==-2 || M[i][j]==5) )
            {
                break;
            }
            else
            {
                M[i][j]=6;
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
	 @fn Supprimer_Lampe
	 @brief Une Fonction qui permet au joueur d'enlever une ampoule de sa position après l'avoir mise 
             @param Une matrice d'entier M, un entier h qui caractérise la hauteur et un entier l qui caractérise la largeur
	 @return void
	*/

void supprimer_lampe(int M[][24],int h,int l)
{
int i,j;
do
{    printf("Lampe : ");
     printf("M[i][j] \n");
     printf("M[i]: ");
     scanf("%d",&i);
     printf("M[j]: ");
    
 scanf("%d",&j);
}while(M[i][j]!=5);
M[i][j]=-1;
for(i=0;i<h;i++)
{for(j=0;j<l;j++)
    {
        if(M[i][j]==6)
        {
            M[i][j]=-1;
        }
    }
}
for(i=0;i<h;i++)
{for(j=0;j<l;j++)
    {
        if(M[i][j]==5)
        {illuminer(M,h,l,i,j);
        }
    }
  }
}
