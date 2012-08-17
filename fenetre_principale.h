#ifndef DEF_FENETRE_PRINCIPALE
#define DEF_FENETRE_PRINCIPALE

#define TITRE_FENETRE "-- Calcul de votre prêt immobilier --"
#define LARGEUR_FENETRE 700
#define HAUTEUR_FENETRE 500

// Définition de la structure de la fenêtre principale
struct ELEMENT
{
	GtkWidget *p_Fenetre[1];
	GtkWidget *p_Cadre[1];
};
typedef struct ELEMENT ELEMENT;

// Prototype des fonctions
void fenetre_principale( ELEMENT *p_Element );

#endif
