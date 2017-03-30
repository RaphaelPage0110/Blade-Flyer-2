#pragma once

#include <vector>
#include "Donnee.h"
#include "Tournee.h"

/*! \file Enumeration.h
	\brief Définie une énumeration des différentes tournées que le drône peut réaliser sans vider son réservoir
*/

class Enumeration {

	private:
	//Attributs
	std::vector<Tournee> m_ListeTournees; // vecteur des tournées
	Donnee m_d; // données du problème

	public:
	Enumeration(Donnee data);	// Constructeur

	//Méthodes
	Donnee get_m_d(); //permet d'acceder aux données du problème
	void set_m_ListeTournees(Tournee tour); //permet d'ajouter une tournee à l'ensemble de tournée à visiter
	void addToEnum(int array[],int size);//permet de créer une tournée et de l'ajouter à l'énumeration
	std::vector<Tournee> get_m_ListeTournees();//permet d'accéder à la liste des tournées
	bool capaciteSuffisante(int array[], int size); //retourne oui si le drone à une capacite suffisante pour visiter tout les points d'eau dont l'indice est donné dans le tableau
	void powerset (int n); //permet de determiner l'ensemble des différentes tournées que le drône peut réaliser sans vider son réservoir
	int size(); //retourne le nombre de tournée qu'il est possible de faire

};
