# include "formule.h"
float Mensualite(int Somme_emprunt, int Nbr_annee, float Taux_annuel)
{
   // Variables
   int Nbr_mois = Nbr_annee*12;
   float Taux_mensuel = Taux_annuel/12/100;
   // [US] Calculating the monthly payment according to the amount borrowed
   // [FR] Calcule de la mensualité en fonction du montant emprunté
   //
   // [US] L = Loan amount
   // [US] M = Monthly rate
   // [US] N = Number of months
   //                     
   //                L x M  
   // Monthly = -----------------
   //                        -N
   //           1 - ( 1 + M )
   //
   // [FR] C = Montant du prêt
   // [FR] T = Taux mensuel
   // [FR] N = Nombre de mois
   //                     
   //                   C x T  
   // Mensualité = -----------------
   //                            -N
   //              1 - ( 1 + T )
   //
   int I;
   float Puissance = 1 + Taux_mensuel;
   for ( I = 1; I < Nbr_mois; I++)
   {
      Puissance *= (1 + Taux_mensuel );
   }
   Puissance = 1 / Puissance;
   return( Somme_emprunt * Taux_mensuel ) / ( 1 - Puissance );
}

float Mensualite_max( int Paie_1, int Paie_2, int Nbr_annee, float Taux_annuel)
{
   return ( ( Paie_1 + Paie_2 ) * 0.33 );
}

float Endettement( int Paie_1, int Paie_2, int Somme_emprunt, int Nbr_annee, 
  float Taux_annuel)
{
   float Recup_mensualite = 0;
   float Endettement = 0;
   Recup_mensualite = Mensualite(Somme_emprunt, Nbr_annee, Taux_annuel);
   Endettement = Recup_mensualite / ( (Paie_1 + Paie_2) / 100);
   return(Endettement);
}

float Emprunt_max( int Paie_1, int Paie_2,int Nbr_annee, float Taux_annuel )
{
   // Variables
   int Nbr_mois = Nbr_annee*12;
   float Taux_mensuel = Taux_annuel/12/100;
   /* [US] Calculating the maximum borrowing capacity
   // [FR] Calcule la capacité d'emprunt maximale
   //
   // [US] MM = Maximum monthly
   // [US] MR = Monthly rate
   // [US] N  = Number of months
   //                                                -N
   //                           MM x  ( 1 - ( 1 + MR ) )
   // Max_borrowing_capacity = -------------------------
   //                                      MR  
   //
   // [FR] MM = Mensualité maximum
   // [FR] TM = Taux mensuel
   // [FR] N  = Nombre de mois
   //                                             -N
   //                        MM x  ( 1 - ( 1 + MM ) )
   // Max_capacite_emprunt = -------------------------
   //                                   MM  
   */
   int I;
   float Mensualite_max = ( ( Paie_1 + Paie_2 ) * 0.33 );
   float Puissance = 1 + Taux_mensuel;
   for ( I = 1; I < Nbr_mois; I++)
   {
      Puissance *= (1 + Taux_mensuel );
   }
   Puissance = 1 / Puissance;
   return ( Mensualite_max * ( 1 - Puissance ) / ( Taux_mensuel ) );
}
float Interet(int Somme_emprunt, int Nbr_annee, float Taux_annuel)
{
   // Variables
   int Nbr_mois = Nbr_annee*12;
   float Recup_mensualite = Mensualite( Somme_emprunt, Nbr_annee, Taux_annuel);
   return (( Recup_mensualite * Nbr_mois ) - Somme_emprunt );
}


float Amortissement(int Somme_emprunt, int Nbr_annee, float Taux_annuel, int Num_Mensualite )
{
   // Variables
   int Nbr_mois = Nbr_annee*12;
   float Taux_mensuel = Taux_annuel/12/100;
   // [FR] calcule l'amortissement de la première mensualité 
   // [US] calculating the amortization of the first monthly 
   //
   // [US] BC = Borrowed Capital
   // [US] MR = Monthly rate
   // [US] N  = Number of months
   //
   //                         BC x MR 
   // first amortization = ----------------
   //                               N
   //                      (1 + MR )  - 1
   //
   // [FR] CE = Capital emprunté
   // [FR] TM = Taux mensuel
   // [FR] N  = Nombre de mois
   //
   //                        CE x TM 
   // 1er amortissement = ----------------
   //                              N
   //                     (1 + TM )  - 1
   //
   float Premier_num_amortissement, I;
   float Puissance_2 = 1 + Taux_mensuel;
   for ( I = 1; I < Nbr_mois; I++)
   {
      Puissance_2 *= 1 + Taux_mensuel;
   }
   Premier_num_amortissement = ( Somme_emprunt * Taux_mensuel ) 
   / ( Puissance_2 - 1 );
   if ( Num_Mensualite == 1 )
   {
      return (Premier_num_amortissement);
   }
   else
   {
      // [US] calculating amortization of the nth monthly p 
      // [FR] calcule l'amortissement de la p enième mensualité 
      //
      // [US] BC = Borrowed Capital
      // [US] MR = Monthly rate
      // [US] N  = Nth Monthly
      // [US] A  = first amortization
      //
      // P nth amortization =( 1 + MR ) x A
      //
      // [FR] C  = Capital emprunté
      // [FR] TM = Taux mensuel
      // [FR] P  = Enième mensualité
      // [FR] A  = 1er amortissement
      //
      // P nième amortissement =( 1 + TM ) x A
      //
      //                              
      Puissance_2 = 1 + Taux_mensuel;
      for ( I = 1; I < Num_Mensualite; I++)
      {
         Puissance_2 *=(1 + Taux_mensuel );
      }
      return ( Puissance_2  * Premier_num_amortissement );
   }
}

float Capital_rembourser(int Somme_emprunt, int Nbr_annee, float Taux_annuel, int Num_Mensualite )
{
   // Variables
   int Nbr_mois = Nbr_annee*12;
   float Taux_mensuel = Taux_annuel/12/100;
   // [FR] calcule le capital remboursé après la p nième mensualité 
   // [US] calculating the capital repaid after the nth monthly p 
   //
   // [US] BC = Borrowed Capital
   // [US] MR = Monthly rate
   // [US] NM = Nth Monthly
   // [US] N  = Number of Months
   //
   //                            NM
   //                  ( 1 + MR ) - 1
   // Repayment = BC x ---------------
   //                            N
   //                  ( 1 + MR ) - 1
   //
   // [FR] C  = Capital emprunté
   // [FR] TM = Taux mensuel
   // [FR] P  = Enième écheance
   // [FR] N  = Nombre de mois
   //
   //                            P
   //                  ( 1 + TM ) - 1
   // Rembourser = C x ---------------
   //                            N
   //                  ( 1 + TM ) - 1
   //
   int I;
   float Puissance = (1 + Taux_mensuel);
   float Puissance_2 = Puissance;
   for ( I = 1; I < Num_Mensualite; I++)
   {
      Puissance *= 1 + Taux_mensuel;
   }
   for ( I = 1; I < Nbr_mois; I++)
   {
      Puissance_2 *= 1 + Taux_mensuel;
   }
   return ( Somme_emprunt * (( Puissance - 1) / ( Puissance_2 - 1 )) );
}
