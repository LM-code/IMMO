#include <stdio.h>
#include <stdlib.h>
#include "gtk/gtk.h"
#include "fenetre_principale.h"
#include "list.h"
void create_list( ELEMENT *Element )
{
// Widget
   // Widgets pour la barre de défilement
   GtkWidget *p_Defilement = NULL;
   GtkWidget *p_Vue = NULL;
   // Widgets pour le tableau de prêt
   GtkListStore *p_Modele = NULL;
   GtkTreeViewColumn *p_Colonne = NULL;
	GtkCellRenderer *p_Cellule = NULL;
	GtkTreeIter iter;

// création de la barre de défilement
   p_Defilement = gtk_scrolled_window_new(NULL, NULL);
// création des colonnes
   p_Modele = gtk_list_store_new
      (5 ,G_TYPE_INT ,G_TYPE_DOUBLE ,G_TYPE_DOUBLE ,G_TYPE_DOUBLE,
         G_TYPE_DOUBLE);
// création de la vue 
   p_Vue = gtk_tree_view_new_with_model(GTK_TREE_MODEL(p_Modele));
// création des colonnes 
	// 1 ère colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      p_Colonne = gtk_tree_view_column_new_with_attributes
         (" Echéance ", p_Cellule, "text", 0, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
	// 2 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      p_Colonne = gtk_tree_view_column_new_with_attributes
         (" Mensualité ", p_Cellule, "text", 1, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
	// 3 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      p_Colonne = gtk_tree_view_column_new_with_attributes
         (" Intérêt période ", p_Cellule, "text", 2, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
	// 4 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      p_Colonne = gtk_tree_view_column_new_with_attributes
         (" Amortissement période ", p_Cellule, "text", 3, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
	// 4 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      p_Colonne = gtk_tree_view_column_new_with_attributes
         (" Capital restant ", p_Cellule, "text", 4, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
// Ajout des données dans le tableau
   gtk_list_store_append(p_Modele, &iter);
      gtk_list_store_set
         (p_Modele, &iter, 0, 2, 1, 4.0, 2, 32.00, 3, 44.44, 4,55.55,-1);
// assemblage 
   gtk_container_add (GTK_CONTAINER(p_Defilement),p_Vue);
   gtk_box_pack_start (GTK_BOX(Element -> p_Vboite[0]),p_Defilement,TRUE,TRUE,5);
}
