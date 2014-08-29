/**
 	@file Files.c
	 @author Chammem Raed et Abdeljelil Skander.
	 @supervisor Mme Ben Amor Imene et Mr Khodjet El Khil Ghazi.
	 @version 1.1
	 @date 17/05/2012
	 @brief C'est le code qui assure la gestion des fichiers.
*/

#include"Files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
	 @fn Reprendre
	 @brief Une Fonction qui permet au joueur de reprendre une partie
             @param Une matrice d'entier M, un entier h qui caractérise la hauteur et un entier l qui caractérise la largeur
	 @return void
	*/

void reprendre(int M[][24],int *h,int *l)
{	int a,b,n;
    int i=0;
    int T[10];	
	int j;
	FILE* fichier = NULL;
    fichier = fopen("sauvgarde.txt", "r");
    printf("Loading...\n");
if(fichier!=NULL)
{
fscanf(fichier,"%d %d \n",h,l);

if((*h)==10 && (*l)==10)
{
while(fscanf(fichier,"%d %d %d %d %d %d %d %d %d %d",&T[0],&T[1],&T[2],&T[3],&T[4],&T[5],&T[6],&T[7],&T[8],&T[9])!=EOF)
       {
            M[i][0]=T[0];
            M[i][1]=T[1];
            M[i][2]=T[2];
            M[i][3]=T[3];
            M[i][4]=T[4];
            M[i][5]=T[5];
            M[i][6]=T[6];
            M[i][7]=T[7];
            M[i][8]=T[8];
            M[i][9]=T[9];
            i++;
	}
}else if((*h)==10 && (*l)==18)
{
while(fscanf(fichier,"%d %d %d %d %d %d %d %d %d %d",&T[0],&T[1],&T[2],&T[3],&T[4],&T[5],&T[6],&T[7],&T[8],&T[9])!=EOF)
       {
            M[i][0]=T[0];
            M[i][1]=T[1];
            M[i][2]=T[2];
            M[i][3]=T[3];
            M[i][4]=T[4];
            M[i][5]=T[5];
            M[i][6]=T[6];
            M[i][7]=T[7];
            M[i][8]=T[8];
            M[i][9]=T[9];
            i++;
	}} else if((*h)==14 && (*l)==24)
{

while(fscanf(fichier,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&T[0],&T[1],&T[2],&T[3],&T[4],&T[5],&T[6],&T[7],&T[8],&T[9],&T[10],&T[11],&T[12],&T[13],&T[14],&T[15],&T[16],&T[17],&T[18],&T[19],&T[20],&T[21],&T[22],&T[23])!=EOF)
        {
              M[i][0]=T[0];
              M[i][1]=T[1];
              M[i][2]=T[2];
              M[i][3]=T[3];
              M[i][4]=T[4];
              M[i][5]=T[5];
              M[i][6]=T[6];
              M[i][7]=T[7];
              M[i][8]=T[8];
              M[i][9]=T[9];
            M[i][10]=T[10];
            M[i][11]=T[11];
            M[i][12]=T[12];
            M[i][13]=T[13];
            M[i][14]=T[14];
            M[i][15]=T[15];
            M[i][16]=T[16];
            M[i][17]=T[17];
            M[i][18]=T[18];
            M[i][19]=T[19];
            M[i][20]=T[20];
            M[i][21]=T[21];
            M[i][22]=T[22];
            M[i][23]=T[23];
            i++;
        }
     }
}
else
        printf("\n\n\n*** IMPOSSIBLE D'OUVRIR LE FICHIER DE SAUVEGARDE ***\n\n\n");
        fclose(fichier);
}
////////////////////////////////////////////////////////////////////////////////////////////
/**
	 @fn Sauvegarder
	 @brief Une Fonction qui permet au joueur de sauvegarder une partie
             @param Une matrice d'entier M, un entier h qui caractérise la hauteur et un entier l qui caractérise la largeur
	 @return void
	*/

void sauvgarder(int M[][24], int h,int l)
{	int i,j;
	FILE* fichier = NULL;
    fichier = fopen("sauvgarde.txt", "w");
    printf("Saving...\n");
if(fichier!=NULL)
{
fprintf(fichier,"%d %d \n",h,l);
for(i=0;i<h;i++)
{ for(j=0;j<l;j++)
{
fprintf(fichier,"%d ",M[i][j]);
}
fprintf(fichier,"\n");
}

    printf("\n\nSaving Done...\n");
}
else
        printf("\n\n\n*** IMPOSSIBLE D'OUVRIR LE FICHIER DE SAUVEGARDE ***\n\n\n");
fclose(fichier);
}
//////////////////////////////////////////////////////////////////////////////////////////
/**
	 @fn ResumeGame_Facile
	 @brief Une Fonction qui permet au joueur de commencer une partie au niveau facile
             @param Une matrice d'entier M
	 @return void
	*/

void resumeGame_facile(int M[][24])
{	int a,b,n;
    int i=0;
    int T[10];
    FILE* fichier = NULL;
    fichier = fopen("database1.txt", "r");
    printf("Resuming...\n");
	srandom(time (NULL));
do{n=random()%10;
}while(n>2 || n<=0);

printf("%d \n\n",n);
    if(fichier!= NULL)
    {
	for(a=-1;a<(n-1);a++)
{
        for(b=0;b<10;b++)
{
fscanf(fichier,"%d %d %d %d %d %d %d %d %d %d",&T[0],&T[1],&T[2],&T[3],&T[4],&T[5],&T[6],&T[7],&T[8],&T[9]);
       
            M[i][0]=T[0];
            M[i][1]=T[1];
            M[i][2]=T[2];
            M[i][3]=T[3];
            M[i][4]=T[4];
            M[i][5]=T[5];
            M[i][6]=T[6];
            M[i][7]=T[7];
            M[i][8]=T[8];
            M[i][9]=T[9];
            i++;
		
	 }
i=0;
}	
	
}
    else
        printf("\n\n\n*** IMPOSSIBLE D'OUVRIR LE FICHIER DE SAUVEGARDE ***\n\n\n");

    fclose(fichier);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
	 @fn ResumeGame_Moyen
	 @brief Une Fonction qui permet au joueur de commencer une partie au niveau moyen
             @param Une matrice d'entier M
	 @return void
	*/

void resumeGame_moy(int M[][24])
{	int a,b,n;
    int i=0;
    int T[18];
    FILE* fichier = NULL;
    fichier = fopen("database2.txt", "r");
    printf("Resuming...\n");
	srandom(time (NULL));
	do
	{
	n=random()%10;
	}while(n>1 || n<=0);
printf("%d \n",n);

    if(fichier!= NULL)
    {
for(a=-1;a<(n-1);a++)
{
        for(b=0;b<10;b++)
{
       fscanf(fichier,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&T[0],&T[1],&T[2],&T[3],&T[4],&T[5],&T[6],&T[7],&T[8],&T[9],&T[10],&T[11],&T[12],&T[13],&T[14],&T[15],&T[16],&T[17]);
        
            M[i][0]=T[0];
            M[i][1]=T[1];
            M[i][2]=T[2];
            M[i][3]=T[3];
            M[i][4]=T[4];
            M[i][5]=T[5];
            M[i][6]=T[6];
            M[i][7]=T[7];
            M[i][8]=T[8];
            M[i][9]=T[9];
            M[i][10]=T[10];
            M[i][11]=T[11];
            M[i][12]=T[12];
            M[i][13]=T[13];
            M[i][14]=T[14];
            M[i][15]=T[15];
            M[i][16]=T[16];
            M[i][17]=T[17];
            i++;
        }
i=0;    
}}

    else
        printf("\n\n\n*** IMPOSSIBLE D'OUVRIR LE FICHIER DE SAUVEGARDE ***\n\n\n");

    fclose(fichier);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
	 @fn ResumeGame_Difficile
	 @brief Une Fonction qui permet au joueur de commencer une partie au niveau difficile
             @param Une matrice d'entier M
	 @return void
	*/

void resumeGame_dif(int M[][24])
{
    int i=0;
    int T[24];
    FILE* fichier = NULL;
    fichier = fopen("database3.txt", "r");
    printf("Resuming...\n");

    if(fichier!= NULL)
    {
        while(fscanf(fichier,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&T[0],&T[1],&T[2],&T[3],&T[4],&T[5],&T[6],&T[7],&T[8],&T[9],&T[10],&T[11],&T[12],&T[13],&T[14],&T[15],&T[16],&T[17],&T[18],&T[19],&T[20],&T[21],&T[22],&T[23])!=EOF)
        {
              M[i][0]=T[0];
              M[i][1]=T[1];
              M[i][2]=T[2];
              M[i][3]=T[3];
              M[i][4]=T[4];
              M[i][5]=T[5];
              M[i][6]=T[6];
              M[i][7]=T[7];
              M[i][8]=T[8];
              M[i][9]=T[9];
            M[i][10]=T[10];
            M[i][11]=T[11];
            M[i][12]=T[12];
            M[i][13]=T[13];
            M[i][14]=T[14];
            M[i][15]=T[15];
            M[i][16]=T[16];
            M[i][17]=T[17];
            M[i][18]=T[18];
            M[i][19]=T[19];
            M[i][20]=T[20];
            M[i][21]=T[21];
            M[i][22]=T[22];
            M[i][23]=T[23];
            i++;
        }
    }

    else
        printf("\n\n\n*** IMPOSSIBLE D'OUVRIR LE FICHIER DE SAUVEGARDE ***\n\n\n");

    fclose(fichier);
}
