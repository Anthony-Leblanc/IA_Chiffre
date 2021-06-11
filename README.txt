# IA_Chiffre

Rendu du 11/06/2021

Travail en binôme sur les fonctions save et load neural network. 
Corrections de fonctions set neurone (append to liste en même temps) avec allocation dynamique de mémoire.
Création de la fonction append to network.

REMARQUES :

Test des fonctions de retour chez nous, celle-ci fonctionne comme attendu mais pas sur les pc de l'université, on n'a pas compris pourquoi. 
Si vous voulez tester nos fonctions séparément il faut commenter/décommenter les lignes des fonctions testAlex soit testAntho dans le fichier iachiffre 
ou encore dans les fichiers mêmes pour voir toutes nos fonctions.


Fin du rendu du 11/06/2021

Rendu du 28/05/2021

Alex Rousseau :
  Fonction get Neurone+ set Neurone. Fonction Print couche. Les trois précedentes fonctionne comme souhaités.
  Construction de la fonction  save_neuralNetwork(NETWORK* network) pour sauvegarder un réseau de neurone sur un fichier csv.
  Quasi fonctionelle pour une simple couche(ne provoque pas d'erreur), beaucoup de correction seront à effectuer pour plusieurs couches.
  
Anthony Leblanc :
  Fin de la fonction load_dataBase qui fonctionne comme souhaité, on la modifiera dans l'avenir ou on s'en inspirera (pour un nom de fonction cohérent) pour entraîner l'IA.
Création de la fonction load_neuralNetwork qui permet de charger un réseau de neurone à partir d'un fichier csv. Rencontre d'un problème avec cette fonction
(décommenté la ligne test_load_neuralNetwork du fichier test_Antho.c si vous voulez voir, je ne comprend pas pourquoi j'ai une erreur avec la fonction strtod, enfin c'est ce que je crois comprendre).
  
  
Commentaire supplémentaire :

	Le fichier ia_chiffre.c contient les fonctions que nous avons effectués, pensé à commenter/décommenter les fonctions test_Antho/test_Alex 
si vous voulez voir leur fonctionnement séparément.
  
Fin du rendu du 28/05/2021


Rendu du 14/05/2021

Alex Rousseau :
  Définition des structures + fonctions get de la structure Neuronne avec test d'affichage.
  Les tests sont effectués sur le fichier debut_projet

Anthony Leblanc :
  Fonction getLine + fonction du traitement de la première ligne (qui met les paramètres des images à jour) + fonction de chargement d'une image (à compléter et tester)
  Les tests sont fait sur le fichier test_Antho, il faut décommenter la ligne "test_parametersImages(); // Fonctionne comme souhaité" puis "test_GetLine(); // Fonctionne comme 
  souhaité", l'une après l'autre pour bien voir le fonctionnement


  !! ATTENTION !! : Pour le bon fonctionnnement des tests, pensez à commenter le main du fichier debut_projet ou test_Antho pour éviter les conflits

Fin du rendu du 14/05/2021