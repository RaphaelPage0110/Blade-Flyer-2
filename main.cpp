#include <iostream>

using namespace std;

/*! \file main.cpp
	\brief Permet de résoudre le problème du projet
*/

#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <glpk.h>
#include <math.h>
#include "Donnee.h"
#include "Tournee.h"
#include "Enumeration.h"
#include "partitionEnsemble.h"
#include <iostream>
#include <ctime>

/*! \brief Lecture des données
	\param *file Le chemin du fichier de données
	\param *d Les données à remplir
*/
void lecture_data(char *file, Donnee *d)
{
	int i,j;
	FILE *fin;

	int val;
	fin = fopen(file,"rt");

	/* Lecture du nombre de lieux */
	fscanf(fin,"%d",&val);
	d->m_nombre_lieux = val;



	/* Allocation mémoire pour la quantité d'eau disponible à chaque point d'eau, et le distancier */
	d->m_quantite_eau = (int *) malloc (val * sizeof(int));
	d->m_distancier = (int **) malloc (val * sizeof(int *));
	for(i = 0;i < val;i++) d->m_distancier[i] = (int *) malloc (val * sizeof(int));

	/* Lecture de la capacité */
	fscanf(fin,"%d",&val);
	d->m_capacite = val;

	/* Lecture des quantités d'eau disponible aux points d'eau */
	for(i = 1;i < d->m_nombre_lieux;i++)
	{
		fscanf(fin,"%d",&val);
		d->m_quantite_eau[i] = val;
	}
	/* Lecture du distancier */
	for(i = 0; i < d->m_nombre_lieux; i++)
    {
		for(j = 0; j < d->m_nombre_lieux; j++)
		{
			fscanf(fin,"%d",&val);
			d->m_distancier[i][j] = val;
		}
    }

	fclose(fin);
}



int main(int argc, char* argv[])
{
	
	clock_t temps1, temps2, temps3; //temps d'execution total
	Donnee d; //les données du problème
	lecture_data(argv[1] , &d ); 
	Enumeration e1 = Enumeration(d);
	e1.powerset(d.m_nombre_lieux-1); //permet de lister les différentes tournées possible, et calcule la permutation offrant la plus courte distance pour chacune d'entre elle
	temps1=clock();
	partitionEnsemble(e1,d.m_nombre_lieux); //permet de résoudre le problème avec GLPK
	temps2=clock();
	temps3=clock();
	printf("Le powerset a mis %f secondes a se creer.\n", (double) temps1/CLOCKS_PER_SEC);
	printf("GLPK a mis %f secondes a resoudre le probleme.\n", (double) (temps2 - temps1) /CLOCKS_PER_SEC);
	printf("Le code a mis %f secondes au total à s'executer.\n", (double) temps3/CLOCKS_PER_SEC);
	return 0;
}


