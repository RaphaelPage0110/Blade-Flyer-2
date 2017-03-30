
,------------------------------------------.
`-----------------------------------------. |
,-----. ,-----.  ,----. ,-.  ,-.,------.  | | ,-. ,-. ,----. ,-----.  ,----.
`----. |`----. |`----. |`--` | |`------'  `-' `-' | |'----. |`----. |'------`
,-.  | |,----' |,-.  | |,---.| |,------.  ,-. ,-. | |,----' |,----' |.-----.
| |  | || ,-. < | |  | || |\ ` || ,----'  | | | | | || ,--. || ,-. <  `---. |
| `--' || |  | || `--' || | \  || `----.  | `-' `-' || |  | || |  | |.----' |
`-----' `-'  `-' `----' `-'  | |`------'  `----^----'`-'  `-'`-'  `-' `----'
                             | `--------------------------------------------.
                              `---------------------------------------------'


Ce dossier contient le résultat du projet de Recherche Opérationnelle de l'université de Nantes pour l'année 2016/2017.
Il comporte 13 fichiers et 2 dossiers.

Dossiers:
A -> comporte les jeux de données de type A
B -> comporte les jeux de données de type B

Fichiers:
Rapport_Blade_Flyer_2.pdf -> Rapport du projet
Documentation_bladeFlyer.pdf -> Documentation de la structure du programme (description des classes, structures etc...)
Donne.h -> contient la structure Donnee
Enumeration.cpp -> contient la classe Enumeration
Enumeration.h -> header de la classe Enumeration
Licence -> Licence du projet
main.cpp -> main du programme
partitionEnsemble.cpp -> fonction permettant de résoudre une instance du problème de partition d'ensemble avec GLPK
partitionEnsemble.h -> header de la donction partitionEnsemble
projet2017.PDF -> sujet du projet
resultats.txt -> fichier contenant les resultats de l'execution du programme avec les fichiers présents dans les dossiers A et B
Tournee.cpp -> contient la classe Tournee
Tournee.h -> header de la classe Tournee

Instruction de compilation:
Nous avons compilé notre projet en utilisant gpp et lglpk -> 
gpp *.cpp -lglpk -o a
./a NOM_FICHIER_DONNEE
