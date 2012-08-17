#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "fenetre_principale.h"

void fenetre_principale( ELEMENT *Element )
{
// Variables
   gint i = 0;

// Widget
   // Widgets des boites
      GtkWidget *p_Vboite[3] = {NULL};
      GtkWidget *p_Hboite[1] = {NULL};
   // Widgets des cadres 
      GtkWidget *p_Cadre[3] = {NULL};
   // Widgets des tableaux pour cadre
      GtkWidget *p_Tableau[3] = {NULL};
   // Widgets sélecteur numérique
      GtkWidget *p_Selecteur[6] = {NULL};
   // Widgets pour les étiquettes
      GtkWidget *p_Etiq[20] = {NULL};

// création 
   // Création des boites
   	p_Vboite[0] = gtk_vbox_new ( FALSE,5);
		p_Vboite[1] = gtk_vbox_new ( FALSE,5);
		p_Vboite[2] = gtk_vbox_new ( FALSE,5);
		p_Hboite[0] = gtk_hbox_new ( TRUE,5);
   // création des cadres
      p_Cadre[0] = gtk_frame_new ("Vos revenus");
      p_Cadre[1] = gtk_frame_new ("Votre prêt");
      p_Cadre[2] = gtk_frame_new ("Résultats");
   // création des tableaux
      p_Tableau[0] = gtk_table_new ( 3,2,FALSE );
      p_Tableau[1] = gtk_table_new ( 3,3,FALSE );
      p_Tableau[2] = gtk_table_new ( 3,5,FALSE );
   // création des sélecteurs numériques
      p_Selecteur[0] = gtk_spin_button_new_with_range (10,99999,10);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(p_Selecteur[0]),1000);
      p_Selecteur[1] = gtk_spin_button_new_with_range (10,99999,10);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(p_Selecteur[1]),1000);
      p_Selecteur[2] = gtk_spin_button_new_with_range (0.00,99.99,0.01);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(p_Selecteur[2]),5.0);
      p_Selecteur[3] = gtk_spin_button_new_with_range (1,30,1);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(p_Selecteur[3]),15);
      p_Selecteur[4] = gtk_spin_button_new_with_range (1,9999999,100);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(p_Selecteur[4]),100000);
   // création des étiquettes
      p_Etiq[0] = gtk_label_new("Paie du 1er emprunteur : ");
      gtk_misc_set_alignment(GTK_MISC(p_Etiq[0]),1.0,0.5);
      p_Etiq[1] = gtk_label_new("Paie du 2ème emprunteur : ");
      gtk_misc_set_alignment(GTK_MISC(p_Etiq[1]),1.0,0.5);
      p_Etiq[2] = gtk_label_new("   €   ");
      p_Etiq[3] = gtk_label_new("   €   ");
      p_Etiq[4] = gtk_label_new("Taux d'intérêt : ");
      gtk_misc_set_alignment(GTK_MISC(p_Etiq[4]),1.0,0.5);
      p_Etiq[5] = gtk_label_new("Somme empruntée : ");
      gtk_misc_set_alignment(GTK_MISC(p_Etiq[5]),1.0,0.5);
      p_Etiq[6] = gtk_label_new(" Votre mensualité est de ");
      gtk_misc_set_alignment(GTK_MISC(p_Etiq[6]),1.0,0.5);
      p_Etiq[7] = gtk_label_new(" % ");
      p_Etiq[8] = gtk_label_new(" ans ");
      p_Etiq[9] = gtk_label_new("   €   ");

// construction de la fenêtre principale
   Element -> p_Fenetre[0] = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_position(GTK_WINDOW(Element -> p_Fenetre[0]),
      GTK_WIN_POS_CENTER);
   gtk_window_set_default_size(GTK_WINDOW(Element -> p_Fenetre[0]), 
     LARGEUR_FENETRE, HAUTEUR_FENETRE);
   gtk_window_set_title(GTK_WINDOW(Element -> p_Fenetre[0]),TITRE_FENETRE);

// Assemblage des boites 
	gtk_container_add(GTK_CONTAINER(Element -> p_Fenetre[0]), p_Vboite[0]);
	gtk_box_pack_start(GTK_BOX(p_Vboite[0]), p_Hboite[0], FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(p_Hboite[0]), p_Vboite[1], TRUE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(p_Hboite[0]), p_Vboite[2], TRUE,TRUE,5);

// Cadre pour les revenus 
	gtk_box_pack_start(GTK_BOX(p_Vboite[1]), p_Cadre[0], TRUE,TRUE,5);
	gtk_container_add(GTK_CONTAINER(p_Cadre[0]), p_Tableau[0]);
// premier tableau 
   for (i = 0; i < 2 ; i++ )
   {
     gtk_table_attach(GTK_TABLE(p_Tableau[0]), p_Etiq[i],
        0, 1, i, i+1,GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
     gtk_table_attach(GTK_TABLE(p_Tableau[0]), p_Selecteur[i],
        1, 2, i, i+1,GTK_FILL, GTK_EXPAND,
        0, 0);
     gtk_table_attach(GTK_TABLE(p_Tableau[0]), p_Etiq[i+2],
        2, 3, i, i+1,GTK_FILL, GTK_EXPAND,
        0, 0);
   }
// Cadre pour le prêt 
	gtk_box_pack_start(GTK_BOX(p_Vboite[1]), p_Cadre[1], TRUE,TRUE,5);
	gtk_container_add(GTK_CONTAINER(p_Cadre[1]), p_Tableau[1]);
// deuxième tableau 
   for (i = 2; i < 5 ; i++ )
   {
     gtk_table_attach(GTK_TABLE(p_Tableau[1]), p_Etiq[i+2],
        0, 1, i-2, i-1,GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
     gtk_table_attach(GTK_TABLE(p_Tableau[1]), p_Selecteur[i],
        1, 2, i-2, i-1,GTK_FILL, GTK_EXPAND,
        0, 0);
     gtk_table_attach(GTK_TABLE(p_Tableau[1]), p_Etiq[i+5],
        2, 3, i-2, i-1,GTK_FILL, GTK_EXPAND,
        0, 0);
   }
// Cadre pour les résultats
	gtk_box_pack_start(GTK_BOX(p_Vboite[2]), p_Cadre[2], TRUE,TRUE,5);
	gtk_container_add(GTK_CONTAINER(p_Cadre[2]), p_Tableau[2]);
// troisième tableau 
   for (i = 6; i < 8 ; i++ )
   {
     gtk_table_attach(GTK_TABLE(p_Tableau[2]), p_Etiq[i+2],
        0, 1, i-2, i-1,GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
   }
// Cadre pour les revenus 
	gtk_box_pack_start(GTK_BOX(p_Vboite[1]), p_Cadre[0], TRUE,TRUE,5);
	gtk_container_add(GTK_CONTAINER(p_Cadre[0]), p_Tableau[0]);

   gtk_widget_show_all(Element -> p_Fenetre[0]);
}
