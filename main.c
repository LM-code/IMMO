#include <stdio.h>
#include <stdlib.h>
#include "gtk/gtk.h"
#include "fenetre_principale.h"

/******************************************************************************
 *            main.c                                                          *
 *                                                                            *
 *  Copyright  2012  Meurillon Laurent                                        *
 *  webmaster@super-annonce.fr                                                *
 ******************************************************************************
 *                                                                            *
 *  This program is free software; you can redistribute it and/or modify      *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation; either version 2 of the License, or         *
 *  any later version.                                                        *
 *                                                                            *
 *  This program is distributed in the hope that it will be useful,           *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with this program; if not, write to the Free Software               *
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.*
 ******************************************************************************/

int main (int argc, char *argv[])
{

   gtk_init(&argc, &argv);
   ELEMENT Element;

   // Création de la fenêtre principale
      fenetre_principale(&Element);

 /*  // Widgets fenêtre
   // Widgets pour la barre de défilement
      GtkWidget *p_Defilement = NULL;
   // Widgets pour la liste des colonnes
      GtkListStore *p_Colonne_pret = NULL;
      GtkTreeIter iter;
      GtkWidget *p_Arbre = NULL;
      GtkTreeViewColumn *p_Arbre_colonne = NULL;
      GtkCellRenderer *p_Cellule = NULL;
   
   // création des sélecteurs numériques
      p_Selecteur_num_mensualite = gtk_spin_button_new_with_range
     		(0,20000,1);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(p_Selecteur_num_mensualite),
         0);
   // création des étiquettes
      p_Etiq_euro_mensualite = gtk_label_new(" € ");
      p_Etiq_mensualite_max = gtk_label_new(" Votre mensualité maxi est de ");
      gtk_misc_set_alignment(GTK_MISC(p_Etiq_mensualite_max),1.0,0.5);
      p_Etiq_mensualite_max_somme = gtk_label_new(" 0000 € ");
      p_Etiq_endettement = gtk_label_new(" Votre endettement est de ");
      gtk_misc_set_alignment(GTK_MISC(p_Etiq_endettement),1.0,0.5);
      p_Etiq_endettement_pourcent = gtk_label_new(" 00 % ");
      p_Etiq_capacite_emprunt = 
         gtk_label_new(" Votre capacité d'emprunt est de ");
      gtk_misc_set_alignment(GTK_MISC(p_Etiq_capacite_emprunt),1.0,0.5);
      p_Etiq_capacite_emprunt_somme = gtk_label_new(" € ");
      p_Etiq_interet = gtk_label_new(" le montant des intérêts ");
      gtk_misc_set_alignment(GTK_MISC(p_Etiq_interet),1.0,0.5);
      p_Etiq_interet_montant = gtk_label_new(" € ");
   // création de la barre de défilement
      p_Defilement = gtk_scrolled_window_new(NULL, NULL);
   // création des colonnes
      p_Colonne_pret = gtk_list_store_new
         (5 ,G_TYPE_INT ,G_TYPE_DOUBLE ,G_TYPE_DOUBLE ,G_TYPE_DOUBLE,
         G_TYPE_DOUBLE);

   // Première ligne - mensualité
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat), p_Etiq_mensualite,
        0, 1, 0, 1,
        GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),
		  p_Selecteur_num_mensualite,1, 2, 0, 1,
        GTK_FILL ,GTK_EXPAND,
        5, 5);
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),p_Etiq_euro_mensualite,
		  2, 3, 0, 1,
        GTK_FILL ,GTK_EXPAND,
        5, 5);
   // seconde ligne - mensualité maximum autorisée
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),p_Etiq_mensualite_max,
        0, 1, 1, 2,
        GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),
		  p_Etiq_mensualite_max_somme,1, 2, 1, 2,
        GTK_FILL ,GTK_EXPAND,
        5, 5);
   // troisème ligne - endettement
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),p_Etiq_endettement,
        0, 1, 2, 3,
        GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),
        p_Etiq_endettement_pourcent,1, 2, 2, 3,
        GTK_FILL ,GTK_EXPAND,
        5, 5);
   // quatrième ligne - capacité d'emprunt
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),p_Etiq_capacite_emprunt,
        0, 1, 3, 4,
        GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),
        p_Etiq_capacite_emprunt_somme,1, 2, 3, 4,
        GTK_FILL ,GTK_EXPAND,
        5, 5);
   // cinquième ligne - capacité d'emprunt
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),p_Etiq_interet,
        0, 1, 4, 5,
        GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
      gtk_table_attach(GTK_TABLE(p_Tableau_resultat),p_Etiq_interet_montant,
        1, 2, 4, 5,
        GTK_EXPAND ,GTK_EXPAND,
        5, 5);
   // Construction du tableau de prêt
      gtk_box_pack_end(GTK_BOX(p_Vboite[0]), p_Defilement, TRUE,TRUE,5);
      p_Arbre = gtk_tree_view_new_with_model(GTK_TREE_MODEL(p_Colonne_pret));
      gtk_container_add (GTK_CONTAINER(p_Defilement),p_Arbre);
		// 1 ère colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      p_Arbre_colonne = gtk_tree_view_column_new_with_attributes
         (" Echéance ", p_Cellule, "text", 0, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Arbre), p_Arbre_colonne);
		// 2 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      p_Arbre_colonne = gtk_tree_view_column_new_with_attributes
         (" Mensualité ", p_Cellule, "text", 1, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Arbre), p_Arbre_colonne);
		// 3 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      p_Arbre_colonne = gtk_tree_view_column_new_with_attributes
         (" Intérêt période ", p_Cellule, "text", 2, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Arbre), p_Arbre_colonne);
		// Ajout des données dans le tableau
      gtk_list_store_append(p_Colonne_pret, &iter);
      gtk_list_store_set
         (p_Colonne_pret, &iter, 0, 2, 1, 4.0, 2, 32.00, 3, 44.44, 4,
5555,-1);
   */
   // affichage de l'ensemble
   gtk_main();
	return (EXIT_SUCCESS);
}
