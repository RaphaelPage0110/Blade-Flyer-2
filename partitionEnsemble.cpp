#include "partitionEnsemble.h"
using namespace std;
/*! \file partitionEnsemble.cpp
	\brief Résolution d'une instance de problème de partitionnement d'ensemble
*/

/*! \brief //fonction permettant de résoudre le problème posé en utilisant GLPK et de déterminer les tournées que le drone doit choisir afin d'avoir un itinéraire optimal
	\param enum Enumeration de l'ensemble des tournées possible
	\param nbLieux Le nombre de lieux du problème
*/
void partitionEnsemble(Enumeration enume, int nbLieux)
{
	//Déclaration du problème
	glp_prob *prob;

	//Données
	vector<Tournee> tournee = enume.get_m_ListeTournees(); //on recupère le vecteur contenant les différentes tournées

	int nbVar = tournee.size()-1; //le nombre de variables du problème
	int nbContr = nbLieux -1; //le nombre de contraite du problème

	//variables de la matrice creuse
	vector<int> ia; //ligne
	vector<int> ja; //colonne
	vector<double> ar; //valeur

	//Variables diverses
	int i; //itérateur
	int j; //itérateur
	double z; // résultat de la résolution du problème
	double x[nbVar]; //contient les variables solutions

	//Tableau des noms
	char nomVar[nbVar][10];
	char nomContr[nbContr][13];

	//Création du problème
	prob = glp_create_prob();
	glp_set_prob_name(prob, "Partionnement d'ensemble : choix des tournees");
	glp_set_obj_dir(prob, GLP_MIN);

	//Déclaration des contraintes
	glp_add_rows(prob, nbContr);

	for(i = 1; i <= nbContr; i++)
	{
		sprintf(nomContr[i], "Contrainte %d", i);

		glp_set_row_name(prob, i, nomContr[i]);

		glp_set_row_bnds(prob, i, GLP_FX, 1.0, 0.0);
	}

	//Déclaration des variables
	glp_add_cols(prob, nbVar); 

	for(i = 1; i <= nbVar; i++)
	{
		sprintf(nomVar[i],"x%d",i);

		glp_set_col_name(prob, i , nomVar[i]);
		glp_set_col_bnds(prob, i, GLP_DB, 0.0, 1.0); //Variables entre 0 et 1
		glp_set_col_kind(prob, i, GLP_BV); //Variables binaires
	}

	//Fonction objectif
	for(i = 1; i<= nbVar; i++)
		glp_set_obj_coef(prob,i,tournee[i-1].getDistance());

	//Matrice creuse
	//ia : le numero de la contrainte
	//ja : le numero de la variable
	//ar : le coefficient de la variable
	ia.push_back(0);
	ja.push_back(0);
	ar.push_back(0);

	//Pour chaque contrainte
	vector <int> pointsdeau; //contient les différents points d'eau visités pendant une tournée
	for(i=0; i<=nbVar; i++) //on va parcourir l'ensemble des tournées
	{
	    pointsdeau = tournee[i].getPermutationMin();
		
		for(int j = 0; j < pointsdeau.size(); j++)
		{
			ia.push_back(pointsdeau[j]); //Le numero de la contrainte
			ja.push_back(i+1); //Le numero de la variable
			ar.push_back(1.0); //sa valeur
		}	
	}

	glp_load_matrix(prob,ia.size()-1,ia.data(),ja.data(),ar.data());

	//Pour le debug
	glp_write_lp(prob,NULL,"Debug.lp");

	//Résolution
	glp_simplex(prob,NULL);
	glp_intopt(prob,NULL);

	z = glp_mip_obj_val(prob); // on récupère la solution de la fonction objectif

	//On récupère les variables solutions
	for(int i = 0; i <  nbVar; i++)
		x[i] = glp_mip_col_val(prob,i+1);

	//Affichage
	printf("\n\nz = %lf\n",z);

	for(int i = 0; i < nbVar; i++) //Affichage des x
	{
		if((int)(x[i] + 0.5) == 1)
		{
			printf("%s = %d  :  ",nomVar[i+1],(int)(x[i] + 0.5)); /* un cast est ajouté, x[i] pourrait être égal à 0.99999... */

			printf("[%d", tournee[i].getPermutationMin()[0]);
			for(int j = 1; j < tournee[i].getPermutationMin().size(); j++)
			{
				printf(", %d", tournee[i].getPermutationMin()[j]);
			}

			printf("] de longueur %d\n", tournee[i].getDistance());
		}
	}

	puts("");

	//Libération de la mémoire
	glp_delete_prob(prob);
}
