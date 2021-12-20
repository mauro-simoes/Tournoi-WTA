# Tournoi-WTA

Français:

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



English:

First of all, the objective of the application is to establish a ranking of female tennis players based on the rules set up by the Women's Tennis Association (WTA). To do this, the user must enter a text file containing the commands to be executed as well as the data to be recorded such as the players and the tournaments. The application will then read these commands and data to display the result of the commands on another text file called run.txt. Concerning the matches of a tournament, the winner appears first and then the loser. There are 7 possible commands in this application: définir_nombre_tournois, enregistrement_tournoi, affichage_matchs_tournoi, affichage_matchs_joueuse, affichage_joueuses_tournoi, afficher classement and exit.

definir_nombre_tournois : This command records the number of tournaments by checking first if the number entered by the user is between 1 and 10. example: definir_nombre_tournois 8
enregistrement_tournoi: The command record_tournament followed by the name and the date of a tournament allows to record this tournament, its matches and its players. It also assigns points to the players based on the WTA system. example: enregistrement_tournoi Paris 2021

affichage_matchs_tournoi : 
	This command followed by the name and date of a tournament displays all the matches of a tournament indicating its rounds. example: affichage_matchs_tournoi London 2020

affichage_matchs_joueuse : 
	This command followed by the name, date of a tournament and the name of a player displays all the matches played by the player during the tournament. ex: 			affichage_matchs_joueuse London 2020 Osaka

affichage_joueuses_tournoi  : 
	The command display_players_tournament followed by the name and date of a tournament displays the name and points of all the players of the tournament in alphabetical	  	  order. ex: affichage_joueuses_tournoi Melbourne 2019

afficher_classement : 
	The command alone displays the ranking of the players sorted in descending order by points and then sorted by alphabetical order when there is a tie in points.
	
exit:
	This command exits the program.
