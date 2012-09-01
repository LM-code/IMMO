#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include "fenetre_principale.h"
#include "formule.h"
#include "list.h"

void fenetre_principale( ELEMENT *Element )
{
// Variables
   gint i = 0;

// Widget
   // Widgets des boites
      GtkWidget *p_Hboite[1] = {NULL};
   // Widgets des cadres 
      GtkWidget *p_Cadre[3] = {NULL};
   // Widgets des tableaux pour cadre
      GtkWidget *p_Tableau[3] = {NULL};
   // Widgets des boites à bouton
      GtkWidget *p_Bouton_boite[1] = {NULL};

// création 
   // Création des boites
   	Element -> p_Vboite[0] = gtk_vbox_new ( FALSE,5);
		Element -> p_Vboite[1] = gtk_vbox_new ( FALSE,5);
		Element -> p_Vboite[2] = gtk_vbox_new ( FALSE,5);
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
      Element -> p_Selecteur[0] = gtk_spin_button_new_with_range (10,99999,10);
      gtk_spin_button_set_value
         (GTK_SPIN_BUTTON(Element -> p_Selecteur[0]),1000);
      Element -> p_Selecteur[1] = gtk_spin_button_new_with_range (10,99999,10);
      gtk_spin_button_set_value
         (GTK_SPIN_BUTTON(Element -> p_Selecteur[1]),1000);
      Element -> p_Selecteur[2] = gtk_spin_button_new_with_range (0.00,99.99,0.01);
      gtk_spin_button_set_value
         (GTK_SPIN_BUTTON(Element -> p_Selecteur[2]),5.0);
      Element -> p_Selecteur[3] = gtk_spin_button_new_with_range (1,30,1);
      gtk_spin_button_set_value
         (GTK_SPIN_BUTTON(Element -> p_Selecteur[3]),15);
      Element -> p_Selecteur[4] = gtk_spin_button_new_with_range (1,9999999,100);
      gtk_spin_button_set_value
         (GTK_SPIN_BUTTON(Element -> p_Selecteur[4]),100000);
   // création des étiquettes
      Element -> p_Etiq[0] = gtk_label_new("Salaire net emprunteur n°1 : ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[0]),1.0,0.5);
      Element -> p_Etiq[1] = gtk_label_new("Salaire net emprunteur n°2 : ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[1]),1.0,0.5);
      Element -> p_Etiq[2] = gtk_label_new("   €   ");
      Element -> p_Etiq[3] = gtk_label_new("   €   ");
      Element -> p_Etiq[4] = gtk_label_new("Taux d'intérêt annuel : ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[4]),1.0,0.5);
      Element -> p_Etiq[5] = gtk_label_new("Durée de l'emprunt : ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[5]),1.0,0.5);
      Element -> p_Etiq[6] = gtk_label_new("Somme empruntée : ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[6]),1.0,0.5);
      Element -> p_Etiq[7] = gtk_label_new(" % ");
      Element -> p_Etiq[8] = gtk_label_new(" ans ");
      Element -> p_Etiq[9] = gtk_label_new("   €   ");
      Element -> p_Etiq[10] = gtk_label_new(" Votre mensualité est de ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[10]),1.0,0.5);
      Element -> p_Etiq[11] = gtk_label_new(" Votre mensualité maxi est de ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[11]),1.0,0.5);
      Element -> p_Etiq[12] = gtk_label_new(" Votre endettement est de ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[12]),1.0,0.5);
      Element -> p_Etiq[13] = gtk_label_new(" Votre capacité d'emprunt est de ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[13]),1.0,0.5);
      Element -> p_Etiq[14] = gtk_label_new(" Le montant des intérêts ");
      gtk_misc_set_alignment(GTK_MISC(Element -> p_Etiq[14]),1.0,0.5);
      Element -> p_Etiq[15] = gtk_label_new(" 0000 € ");
      Element -> p_Etiq[16] = gtk_label_new(" 0000 € ");
      Element -> p_Etiq[17] = gtk_label_new(" 00 % ");
      Element -> p_Etiq[18] = gtk_label_new("   €   ");
      Element -> p_Etiq[19] = gtk_label_new("   €   ");
   // création des boites à bouton
      p_Bouton_boite[0] = gtk_hbutton_box_new();
   // création des boutons
      Element -> p_Bouton[0] = gtk_button_new_with_label("CALCULER");  
      Element -> p_Bouton[1] = gtk_button_new_with_label("QUITTER");  

// construction de la fenêtre principale
   Element -> p_Fenetre[0] = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_position(GTK_WINDOW(Element -> p_Fenetre[0]),
      GTK_WIN_POS_CENTER);
   gtk_window_set_default_size(GTK_WINDOW(Element -> p_Fenetre[0]), 
     LARGEUR_FENETRE, HAUTEUR_FENETRE);
   gtk_window_set_title(GTK_WINDOW(Element -> p_Fenetre[0]),TITRE_FENETRE);

// Assemblage des boites 
	gtk_container_add(GTK_CONTAINER(Element -> p_Fenetre[0]), Element -> p_Vboite[0]);
	gtk_box_pack_start(GTK_BOX(Element -> p_Vboite[0]), p_Hboite[0], FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(p_Hboite[0]), Element -> p_Vboite[1], TRUE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(p_Hboite[0]), Element -> p_Vboite[2], TRUE,TRUE,5);
	gtk_box_pack_end(GTK_BOX(Element -> p_Vboite[0]), p_Bouton_boite[0], FALSE,FALSE,5);

// Cadre pour les revenus 
	gtk_box_pack_start(GTK_BOX(Element -> p_Vboite[1]), p_Cadre[0], TRUE,TRUE,5);
	gtk_container_add(GTK_CONTAINER(p_Cadre[0]), p_Tableau[0]);
// premier tableau 
   for (i = 0; i < 2 ; i++ )
   {
     gtk_table_attach(GTK_TABLE(p_Tableau[0]), Element -> p_Etiq[i],
        0, 1, i, i+1,GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
     gtk_table_attach(GTK_TABLE(p_Tableau[0]), Element -> p_Selecteur[i],
        1, 2, i, i+1,GTK_FILL, GTK_EXPAND,
        0, 0);
     gtk_table_attach(GTK_TABLE(p_Tableau[0]), Element -> p_Etiq[i+2],
        2, 3, i, i+1,GTK_FILL, GTK_EXPAND,
        0, 0);
   }
// Cadre pour le prêt 
	gtk_box_pack_start(GTK_BOX(Element -> p_Vboite[1]), p_Cadre[1], TRUE,TRUE,5);
	gtk_container_add(GTK_CONTAINER(p_Cadre[1]), p_Tableau[1]);
// deuxième tableau 
   for (i = 2; i < 5 ; i++ )
   {
     gtk_table_attach(GTK_TABLE(p_Tableau[1]), Element -> p_Etiq[i+2],
        0, 1, i-2, i-1,GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
     gtk_table_attach(GTK_TABLE(p_Tableau[1]), Element -> p_Selecteur[i],
        1, 2, i-2, i-1,GTK_FILL, GTK_EXPAND,
        0, 0);
     gtk_table_attach(GTK_TABLE(p_Tableau[1]), Element -> p_Etiq[i+5],
        2, 3, i-2, i-1,GTK_FILL, GTK_EXPAND,
        0, 0);
   }
// Cadre pour les résultats
	gtk_box_pack_start(GTK_BOX(Element -> p_Vboite[2]), p_Cadre[2], TRUE,TRUE,5);
	gtk_container_add(GTK_CONTAINER(p_Cadre[2]), p_Tableau[2]);
// troisième tableau 
   for (i = 10; i < 15 ; i++ )
   {
     gtk_table_attach(GTK_TABLE(p_Tableau[2]), Element -> p_Etiq[i],
        0, 1, i-10, i-9,GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
     gtk_table_attach(GTK_TABLE(p_Tableau[2]), Element -> p_Etiq[i+5],
        1, 3, i-10, i-9,GTK_EXPAND | GTK_FILL ,GTK_EXPAND,
        5, 5);
   }
// Ajoute des boutons dans la boite spécifique
	gtk_button_box_set_layout
      (GTK_BUTTON_BOX(p_Bouton_boite[0]),GTK_BUTTONBOX_CENTER);
	gtk_box_pack_start(GTK_BOX(p_Bouton_boite[0]), Element -> p_Bouton[0], FALSE,FALSE,5);
	gtk_box_pack_end(GTK_BOX(p_Bouton_boite[0]), Element -> p_Bouton[1], FALSE,FALSE,5);
// Définition des callbacks
     g_signal_connect (
        G_OBJECT (Element -> p_Bouton[1]), 
        "clicked",G_CALLBACK(gtk_main_quit),NULL
        );
     g_signal_connect (
        G_OBJECT (Element -> p_Bouton[0]), 
        "clicked",G_CALLBACK(Calcul_pret),Element
        );
}
void Calcul_pret ( GtkWidget *p_Widget, gpointer data )
{
   // Conversion des datas dans une structure ELEMENT
   ELEMENT *Recup = data;
   // Variables récupération des données
   gint i = 0;
   gint Paie_1 = 0;
   gint Paie_2 = 0;
   gfloat Taux_interet = 0;
   gint Duree_emprunt = 0;
   gint Somme_emprunt = 0;
   float Montant_mensualite = 0;
   float Montant = 0;
   float Mensualite_amortis = 0;
   float Mensualite_interet = 0;
   float Restant = 0;
   gchar *p_text_1 = NULL;

   // Récupération des informations
   Paie_1 = gtk_spin_button_get_value_as_int 
      (GTK_SPIN_BUTTON (Recup -> p_Selecteur[0]));
   Paie_2 = gtk_spin_button_get_value_as_int 
      (GTK_SPIN_BUTTON (Recup -> p_Selecteur[1]));
   Taux_interet = gtk_spin_button_get_value_as_float 
      (GTK_SPIN_BUTTON (Recup -> p_Selecteur[2]));
   Duree_emprunt = gtk_spin_button_get_value_as_int 
      (GTK_SPIN_BUTTON (Recup -> p_Selecteur[3]));
   Somme_emprunt = gtk_spin_button_get_value_as_int 
      (GTK_SPIN_BUTTON (Recup -> p_Selecteur[4]));
 
   // Calcule et affichae la mensualité
   Montant_mensualite = Mensualite(Somme_emprunt, Duree_emprunt,Taux_interet);
	p_text_1 = g_strdup_printf("%.2f €",Montant_mensualite);
	gtk_label_set_text(GTK_LABEL (Recup->p_Etiq[15]),p_text_1);
   // Calcule et affiche le montant maximal de la mensualité
   Montant = Mensualite_max(Paie_1, Paie_2, Duree_emprunt,
      Taux_interet);
	p_text_1 = g_strdup_printf("%.2f €",Montant);
	gtk_label_set_text(GTK_LABEL (Recup->p_Etiq[16]),p_text_1);
   // Calcule et affiche le pourcentage d'endettement
   Montant = Endettement(Paie_1, Paie_2, Somme_emprunt, 
      Duree_emprunt, Taux_interet);
	p_text_1 = g_strdup_printf("%.2f %%",Montant);
	gtk_label_set_text(GTK_LABEL (Recup->p_Etiq[17]),p_text_1);
   // Calcule et affiche la capacité d'emprunt
   Montant = Emprunt_max(Paie_1, Paie_2, Duree_emprunt,
      Taux_interet);
	p_text_1 = g_strdup_printf("%.0f €",Montant);
	gtk_label_set_text(GTK_LABEL (Recup->p_Etiq[18]),p_text_1);
   // Calcule et affiche Le montant des intérêts
   Montant = Interet(Somme_emprunt, Duree_emprunt,Taux_interet);
	p_text_1 = g_strdup_printf("%.0f €",Montant);
	gtk_label_set_text(GTK_LABEL (Recup->p_Etiq[19]),p_text_1);
   // Efface le tableau
	if (GTK_IS_LIST_STORE(Recup->p_Modele)) 
   {
      gtk_list_store_clear(GTK_LIST_STORE(Recup->p_Modele));
	}
// Remplit le tableau
   for( i = 1; i < ( Duree_emprunt * 12 ) + 1; i++ ) 
   {
   // Calcule l'amortissement
   Mensualite_amortis = Amortissement(Somme_emprunt, Duree_emprunt,
      Taux_interet,i);
   Mensualite_interet = Montant_mensualite - Mensualite_amortis;
   Restant = Capital_rembourser(Somme_emprunt, Duree_emprunt,
      Taux_interet,i);
      Ajout_list(
         Recup -> p_Modele,
			i,
			Montant_mensualite,
			Mensualite_interet,
         Mensualite_amortis,
         Somme_emprunt - Restant
      );
   }
   // Libére la mémoire
}
