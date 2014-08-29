/**
 	@file Game.h
	 @author Chammem Raed et Abdeljelil Skander.
	 @supervisor Mme Ben Amor Imene et Mr Khodjet El Khil Ghazi.
	 @version 1.1
	 @date 17/05/2012
	 @brief C'est un fichier qui contient les prototypes des fonctions implémentées dans Game.c.
*/

#include"Files.h"

void cpy_matrice(int M1[][24],int M[][24],int h,int l);
int cmp_matrice(int M1[][24],int M[][24],int h,int l);
void ajout_lampe(int M[][24],int h,int l);
void afficher_matrice(int M[][24],int h,int l);
void illuminer(int M[][24],int h,int l,int a,int b);
void supprimer_lampe(int M[][24],int h,int l);
