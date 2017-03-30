#pragma once

#include <vector>
#include <string>

/*! \file Donnee.h
	\brief Définie les données du problème à résoudre, c'est à dire le nombre de points d'eau, la capacité du réservoir du drone accompagné du distancier
*/

/*! \struct donnee
	\brief Structure définissant les données du problème
*/
struct  Donnee {
	int m_nombre_lieux; 	//!< Nombre de lieux (incluant la base)
	int m_capacite; 	//!< Capacité du reservoir du drone
	int *m_quantite_eau; 	//!< Quantité d'eau disponible à chaque point de pompage (la case 0 est inutilisée car la base ne possède pas de point d'eau)
	int **m_distancier; 	//!< Distancier (les lignes et colonnes 0 correspondent à la base)
};
