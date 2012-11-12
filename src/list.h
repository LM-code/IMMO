#ifndef DEF_LIST
#define DEF_LIST

#define LARGEUR_COLONNE_1 133
#define LARGEUR_COLONNE_2 133
#define LARGEUR_COLONNE_3 133
#define LARGEUR_COLONNE_4 150
#define LARGEUR_COLONNE_5 150

// Déclaration des prototypes
void create_list( ELEMENT *Element );
void Ajout_list(GtkListStore *p_Modele, int Mois, float Mensualite, 
   float Interet, float Amortissement, float Restant);
#endif
