# include "formule.h"
float Mensualite(int arg_1, int arg_2, float arg_3)
{
   m_Borrowed_capital = arg_1;
   m_Nbr_years = arg_2;
   m_Nbr_months = arg_2*12;
   m_Annual_rate = arg_3;
   m_Monthly_rate = arg_3/12/100;
   /* [US] Calculating the monthly payment according to the amount borrowed
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
   */
   int I;
   float Power = 1 + m_Monthly_rate;
   for ( I = 1; I < m_Nbr_months; I++)
   {
      Power *= (1 + m_Monthly_rate );
   }
   Power = 1 / Power;
   m_Monthly = ( m_Borrowed_capital * m_Monthly_rate ) / ( 1 - Power );
}

float Interet()
{
   return (( m_Monthly * m_Nbr_months ) - m_Borrowed_capital );
}

float Mensualite_max( int Pay_1, int Pay_2)
{
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
   float Max_monthly = ( ( Pay_1 + Pay_2 ) * 0.33 );
   float Power = 1 + m_Monthly_rate;
   for ( I = 1; I < m_Nbr_months; I++)
   {
      Power *= (1 + m_Monthly_rate );
   }
   Power = 1 / Power;
   return ( Max_monthly * ( 1 - Power ) / ( m_Monthly_rate ) );
}

float Amortissement(int No_Monthly )
{
   /* [FR] calcule l'amortissement de la première mensualité 
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
    */
   float first_maturity_amortization, I;
   float Power_2 = 1 + m_Monthly_rate;
   for ( I = 1; I < m_Nbr_months; I++)
   {
      Power_2 *= 1 + m_Monthly_rate;
   }
   first_maturity_amortization = ( m_Borrowed_capital * m_Monthly_rate ) 
   / ( Power_2 - 1 );
   if ( No_Monthly == 1 )
   {
      return (first_maturity_amortization);
   }
   else
   {
      /* [US] calculating amortization of the nth monthly p 
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
      */                              
      Power_2 = 1 + m_Monthly_rate;
      for ( I = 1; I < No_Monthly; I++)
      {
         Power_2 *=(1 + m_Monthly_rate );
      }
      return ( Power_2  * first_maturity_amortization );
   }
}

float Capital_rembourser(int No_Monthly)
{
   /* [FR] calcule le capital remboursé après la p nième mensualité 
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
   */
   int I;
   float Power = (1 + m_Monthly_rate);
   float Power_2 = Power;
   for ( I = 1; I < No_Monthly; I++)
   {
      Power *= 1 + m_Monthly_rate;
   }
   for ( I = 1; I < m_Nbr_months; I++)
   {
      Power_2 *= 1 + m_Monthly_rate;
   }
   return ( m_Borrowed_capital * (( Power - 1) / ( Power_2 - 1 )) );
}
