#include <vector>
#include "Enumeration.h"

/*! \file Enumeration.cpp
	\brief Définie une énumeration des différentes tournées que le drône peut réaliser sans vider son réservoir
*/

using namespace std;

/*! \brief Constructeur
    \param data données du problème
*/
Enumeration::Enumeration(Donnee data)
{
    m_d = data;
}

/*! \brief permet d'acceder aux données du problème
    \return m_d données du problème
*/
Donnee Enumeration::get_m_d()
{
    return m_d;
}

/*! \brief permet d'ajouter une tournee à l'ensemble de tournées à visiter
    \param Tournee tournée à ajouter à l'énumeration
*/
void Enumeration::set_m_ListeTournees(Tournee tour)
{
    vector <int> res;
    res = tour.getPermutationMin();
    m_ListeTournees.push_back(tour);
}

/*! \brief permet d'accéder à la liste des tournées
    \return m_ListeTournees vecteur des tournées
*/
vector<Tournee> Enumeration::get_m_ListeTournees()
{
    return m_ListeTournees;
}

/*! \brief permet de créer une tournée et de l'ajouter à l'énumeration
    \param array[] tableau contenant des indices de points d'eau
    \param size intervalle sur lequel on doit considérer le tableau
*/
void Enumeration::addToEnum(int array[],int size)
{
    int i;
    Tournee tour;

    for (i=1;i<=size;i++)
    {
        tour.add(array[i], get_m_d()); //add va automatiquement mettre à jour tout les attributs de la tournée (incluant la permutation optimale)
    }

    set_m_ListeTournees(tour);

    return;
}

/*! \brief permet de determiner si le reservoir du drone à une contenance suffisante pour visiter tout les points de la tournée
    \param array[] tableau contenant des indices de points d'eau
    \param size intervalle sur lequel on doit considérer le tableau
    \return bool  retourne oui si le drone à une capacite suffisante pour visiter tout les points d'eau dont l'indice est donné dans le tableau
*/
bool Enumeration::capaciteSuffisante(int array[], int size)
{
    int quantiteEau = 0;
    int i;
    Donnee data=get_m_d();

    for (i=1;i<=size;i++)
    {
        quantiteEau+=data.m_quantite_eau[array[i]]; //on additionne les différentes quantités d'eau disponible aux points d'eau visités par le drone 
    }
    return(data.m_capacite >= quantiteEau ); //et on compare cette valeur à la capacité de son réservoir
}

/*! \brief permet de determiner l'ensemble des différentes tournées que le drône peut réaliser sans vider son réservoir
    \param n taille de l'ensemble à traiter
*/
void Enumeration::powerset (int n){
    int stack[n+1];
    int position;

    stack[0]=0; //0 represente la base et 0 ne fait pas parti du set
    position = 0;

    bool done = false;
    while(!done) //on va utiliser un tableau qui va aggrandir et retrecir le set 
    {

            if (stack[position]<n) //si l'on a pas dépassé la borne du set
            {
                stack[position+1] = stack[position] + 1; //on fait grandir le tableau
                position++;
            }

            else //on revient en arrière et on recommence
            {
                stack[position-1]++;
                position--;
            }

            if (position==0) // quand position arrive à 0, on a exploré toute les options
                done = true;

            if (capaciteSuffisante(stack,position)) //si le reservoir du drone permet de visiter le point d'eau
                addToEnum(stack,position); //alors on ajoute la tournée à l'énumeration de l'ensemble des tournées possible

    }
    return;
}

/*! \brief permet d'accéder au nombre nombre de tournée qu'il est possible de faire
    \return m_ListeTournees.size()
*/
int Enumeration::size()
{
    return  m_ListeTournees.size();
}

