#pragma once

/*! \file PartitionEnsemble.h
	\brief Résolution d'une instance de problème de partitionnement d'ensemble
*/

#include <vector>
#include <list>
#include "Tournee.h"
#include "Enumeration.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glpk.h>

void partitionEnsemble(Enumeration enume, int nbLieux); //fonction permettant de résoudre le problème posé et de déterminer les tournées que le drone doit choisir afin d'avoir un itinéraire optimal
