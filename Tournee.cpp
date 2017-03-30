#include "Tournee.h"

/*! \file Tournee.cpp
	\brief Définie une tournée de points d'eau, c'est à dire la suite que le drône va pouvoir visiter en une seule fois sans avoir à aller vider son réservoir
*/

using namespace std;

/*! \brief Constructeur de Tournee
*/
Tournee::Tournee()
{}

/*! \brief Getter sur m_pointsdeau
 	\return m_pointsdeau
*/
vector<int> Tournee::getPointsdeau()
{
	return m_pointsdeau;
}

/*! \brief permet de mettre à jour la plus petite distance à parcourir afin de visiter tout les points d'eau de la tournée
	\param d données du problème
*/
void Tournee::setDistance(Donnee d)
{
	m_distance = calculeDistanceTour(m_permutationMin, d);
}

/*! \brief Getter sur m_distance
 	\return m_distance
*/
int Tournee::getDistance ()
{
	return m_distance;
}

/*! \brief Getter sur m_permutationMin
 	\return m_permutationMin
*/
vector<int> Tournee::getPermutationMin()
{
	return m_permutationMin;
}

/*! \brief Retourne le nombre de points d'eau visités
 	\return m_pointsdeau.size()
*/
int Tournee::size(){
	return m_pointsdeau.size();
}

/*! \brief calcule la distance parcourue pendant le tour fourni
	\param tour indices des points d'eau visités
	\param d données du problème
 	\return res la distance entre deux points
*/
int Tournee::calculeDistanceTour( vector<int> tour , Donnee d){
	int res = d.m_distancier[0][tour[0]]; //on calcule la distance pour aller au premier point de la tournée
	if (size() == 1 ) //si la taille du tour est de 1, on fait juste un aller-retour
	{
		res = res*2;
		return res;
	}
	else //sinon on additionne la distance entre tout les points
	{
		for(int i=1; i < size(); i++)
		{
			res += d.m_distancier[tour[i-1]][tour[i]];
		}
		res+=d.m_distancier[0][tour[size()-1]]; //et on oublie pas de retourner à la base
		return res;
	}
}

/*! \brief calcule la permutation offrant la plus petite distance à parcourir en brute force
	\param tour indices des points d'eau visités
	\param d données du problème
 	\return meilleur_tour permutation minimale
*/
vector<int> Tournee::calculePlusPetiteDistancePerm( vector<int> tour, Donnee d)
{
	int meilleur_distance = calculeDistanceTour(tour, d); 
	vector<int> meilleur_tour = tour; 

	while(next_permutation(tour.begin(), tour.end())) //on va simplement examiner toute les permutations possible, et mettre à jour la valeur de la distance  minimale
		  {
		      int distance = calculeDistanceTour(tour, d);
		      if ( distance < meilleur_distance )
			  {
				  meilleur_distance=distance;
				  meilleur_tour=tour;
			  }

	      }
	   return meilleur_tour;
}

/*! \brief permet de mettre à jour la valeur de la permutation offrant la plus petite distance à parcourir
	\param d donnees du problème
*/
void Tournee::setPermutationMin(Donnee d)
{
	m_permutationMin = calculePlusPetiteDistancePerm(m_pointsdeau,d);
}

/*! \brief permet d'ajouter l'indice d'un nouveau point d'eau à visiter pendant la tournée
	\param i indice du point d'eau à visiter pendant la tournée
	\param d données du problème
*/
void Tournee::add(int i, Donnee d)
{
	m_pointsdeau.push_back(i);
	setPermutationMin(d);
	setDistance(d);
}
