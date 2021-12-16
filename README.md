# Tournoi-WTA

Tout d’abord, l’objectif de l’application est d’établir un classement des joueuses de tennis à partir des règles mis en place par la Women’s Tennis Association (WTA). Pour cela, l’utilisateur doit entrer un fichier texte contenant les commandes à exécuter ainsi les données à enregistrer tels que les joueuses et les tournois. L’application va ensuite lire ces commandes et les données afin d’afficher le résultat des commandes sur un autre fichier texte appelé run.txt. Concernant les matchs d’un tournoi, la gagnante apparait en premier et la perdante ensuite.  Il existe en tout 7 commandes possibles dans cette application : définir_nombre_tournois, enregistrement_tournoi, affichage_matchs_tournoi, affichage_matchs_joueuse, affichage_joueuses_tournoi, afficher classement et exit.

definir_nombre_tournois :
	Cette commande enregistre le nombre de tournois en vérifiant d’abord si le nombre entré par l’utilisateur est entre 1 et 10.
  exemple: definir_nombre_tournois 8

enregistrement_tournoi :
	La commande enregistrement_tournoi suivie par le nom et la date d’un tournoi permet d’enregistrer ce tournoi, ses matchs et ses joueuses. Elle attribue aussi les points aux joueuses     en se basant sur le système de la WTA.
  ex: enregistrement_tournoi Paris 2021

affichage_matchs_tournoi :
	Cette commande suivie par le nom et la date d’un tournoi affiche tous les matchs d’un tournoi en indiquant les phases de ce dernier. 
  exemple: affichage_matchs_tournoi Londres 2020

affichage_matchs_joueuse :
	Cette commande suivie par le nom, date d’un tournoi et le nom d’une joueuse affiche tous les matchs joués par la joueuse lors du tournoi.
  ex: affichage_matchs_joueuse Londres 2020 Osaka

affichage_joueuses_tournoi :
	La commande affichage_joueuses_tournoi suivie par le nom et la date d’un tournoi affiche le nom et les points de toutes les joueuses du tournoi par ordre lexicographique.
  ex: affichage_joueuses_tournoi Melbourne 2019

afficher_classement :
	La commande à elle seule affiche le classement des joueuses triées par ordre décroissant en fonction des points puis triées par ordre lexicographique lorsqu’il y a égalité de points.

exit :
	La commande exit correspond à la sortie du programme.
