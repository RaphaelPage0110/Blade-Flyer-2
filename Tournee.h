#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Donnee.h"

/*! \file Tournee.h
	\brief Définie une tournée de points d'eau, c'est à dire la suite que le drône va pouvoir visiter en une seule fois sans avoir à aller vider son réservoir
*/

class Tournee
{

	private:
	// Attributs
	std::vector<int> m_pointsdeau; // les points d'eau visités dans la tournée
	std::vector<int> m_permutationMin; // ordre de visite des points d'eau offrant la plus petite distance à parcourir
	int m_distance; // plus petite distance à parcourir pour visites ces points

	public:
    Tournee(); //constructeur

	// Méthodes
	int size();//retourne le nombre de points d'eau visités pendant la tournee
	std::vector<int> getPointsdeau(); //retourne la liste non optimisée des points d'eau visités
	void setPermutationMin(Donnee d); // permet de mettre à jour la valeur de la permutation offrant la plus petite distance à parcourir

	std::vector<int> getPermutationMin(); //retourne la liste des points d'eau visités pendant la tournée, dans l'ordre offrant le plus court chemin
	int getDistance(); //retourne la plus petite distance necessaire afin de visiter tout les points d'eau pendant une tournée
	void setDistance(Donnee d); //permet de mettre à jour la plus petite distance à parcourir afin de visiter tout les points d'eau de la tournée
	void add(int i, Donnee d); //permet d'ajouter l'indice d'un nouveau point d'eau à visiter pendant la tournée
	std::vector<int> calculePlusPetiteDistancePerm( std::vector<int> tour, Donnee d);//calcule la permutation offrant la plus petite distance à parcourir
	int calculeDistanceTour( std::vector<int> tour, Donnee d);//calcule la distance d'une tournee

} ;

