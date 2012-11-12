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
   GtkTreeViewColumn *p_Colonne = NULL;
	GtkCellRenderer *p_Cellule = NULL;

// création de la barre de défilement
   p_Defilement = gtk_scrolled_window_new(NULL, NULL);
// création des colonnes
   Element -> p_Modele = gtk_list_store_new
      (5 ,G_TYPE_INT ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING,
         G_TYPE_STRING);
// création de la vue 
   p_Vue = gtk_tree_view_new_with_model(GTK_TREE_MODEL(Element -> p_Modele));
// création des colonnes 
	// 1 ère colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      gtk_cell_renderer_set_alignment (p_Cellule,0.5,0.5);
      p_Colonne = gtk_tree_view_column_new_with_attributes
         (" Echéance ", p_Cellule, "text", 0, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
		gtk_tree_view_column_set_min_width
         (GTK_TREE_VIEW_COLUMN(p_Colonne),LARGEUR_COLONNE_1 );
      gtk_tree_view_column_set_alignment
         (GTK_TREE_VIEW_COLUMN(p_Colonne),0.5 );
	// 2 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      gtk_cell_renderer_set_alignment (p_Cellule,0.5,0.5);
      p_Colonne = gtk_tree_view_column_new_with_attributes
         (" Mensualité ", p_Cellule, "text", 1, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
		gtk_tree_view_column_set_min_width
         (GTK_TREE_VIEW_COLUMN(p_Colonne),LARGEUR_COLONNE_2 );
      gtk_tree_view_column_set_alignment
         (GTK_TREE_VIEW_COLUMN(p_Colonne),0.5 );
	// 3 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      gtk_cell_renderer_set_alignment (p_Cellule,0.5,0.5);
      p_Colonne = gtk_tree_view_column_new_with_attributes
         ("Intérêt", p_Cellule, "text", 2, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
		gtk_tree_view_column_set_min_width
         (GTK_TREE_VIEW_COLUMN(p_Colonne),LARGEUR_COLONNE_3 );
      gtk_tree_view_column_set_alignment
         (GTK_TREE_VIEW_COLUMN(p_Colonne),0.5 );
	// 4 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      gtk_cell_renderer_set_alignment (p_Cellule,0.5,0.5);
      p_Colonne = gtk_tree_view_column_new_with_attributes
         ("Amortissement", p_Cellule, "text", 3, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
		gtk_tree_view_column_set_min_width
         (GTK_TREE_VIEW_COLUMN(p_Colonne),LARGEUR_COLONNE_4 );
      gtk_tree_view_column_set_alignment
         (GTK_TREE_VIEW_COLUMN(p_Colonne),0.5 );
	// 5 ème colonne du tableau
      p_Cellule = gtk_cell_renderer_text_new();
      gtk_cell_renderer_set_alignment (p_Cellule,0.5,0.5);
      p_Colonne = gtk_tree_view_column_new_with_attributes
         (" Capital restant ", p_Cellule, "text", 4, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(p_Vue), p_Colonne);
		gtk_tree_view_column_set_min_width
         (GTK_TREE_VIEW_COLUMN(p_Colonne),LARGEUR_COLONNE_5 );
      gtk_tree_view_column_set_alignment
         (GTK_TREE_VIEW_COLUMN(p_Colonne),0.5 );
// active l'aternance des couleurs 
      gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(p_Vue),TRUE);
// assemblage 
   gtk_container_add (GTK_CONTAINER(p_Defilement),p_Vue);
   gtk_box_pack_start (GTK_BOX(Element -> p_Vboite[0]),
      Element -> p_Etiq[22],FALSE,FALSE,0);
   gtk_box_pack_start (GTK_BOX(Element -> p_Vboite[0]),p_Defilement,TRUE,TRUE,0);
}
void Ajout_list(GtkListStore *p_Modele, int Mois, float Mensualite, 
   float Interet, float Amortissement, float Restant)
{
GtkTreeIter iter;
// Ajout des données dans le tableau
   gtk_list_store_append(p_Modele, &iter);
   gtk_list_store_set (p_Modele, &iter,
       0, Mois,
       1, g_strdup_printf("%.2f",Mensualite),
       2, g_strdup_printf("%.2f",Interet),
       3, g_strdup_printf("%.2f",Amortissement),
       4, g_strdup_printf("%.2f",Restant),
   -1);
}
