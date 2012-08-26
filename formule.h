#ifndef DEV_FORMULE
#define DEV_FORMULE

// Déclaration des prototypes
float Mensualite(int Somme_emprunt, int Nbr_annee, float Taux_annuel);
float Mensualite_max( int Paie_1, int Paie_2, int Nbr_annee, float Taux_annuel);
float Endettement( int Paie_1, int Paie_2, int Somme_emprunt, int Nbr_annee, float Taux_annuel);
float Emprunt_max( int Paie_1, int Paie_2,int Nbr_annee, float Taux_annuel );
float Interet(int Somme_emprunt,int Nbr_annee,float Taux_annuel);
float Amortissement(int No_Monthly );
float Capital_rembourser(int No_Monthly);

#endif
