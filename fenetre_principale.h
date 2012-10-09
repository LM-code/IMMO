#ifndef DEF_FENETRE_PRINCIPALE
#define DEF_FENETRE_PRINCIPALE

#define TITRE_FENETRE "-- Calcul de votre prêt immobilier --"
#define LARGEUR_FENETRE 700
#define HAUTEUR_FENETRE 700
#define ICONE "images/immo.png"

// Définition de la structure de la fenêtre principale
struct ELEMENT
{
	GtkWidget *p_Fenetre[1];
	GtkWidget *p_Vboite[3];
	GtkWidget *p_Selecteur[6];
	GtkWidget *p_Bouton[2];
   GtkWidget *p_Etiq[23];
   GtkListStore *p_Modele;
};
typedef struct ELEMENT ELEMENT;

// Prototype des fonctions
void fenetre_principale( ELEMENT *p_Element );
void Calcul_pret ( GtkWidget *p_Widget, gpointer data );

#endif
