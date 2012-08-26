#include <stdio.h>
#include <stdlib.h>
#include "gtk/gtk.h"
#include "fenetre_principale.h"
#include "list.h"

/******************************************************************************
 *  file : main.c                                                             *
 *                                                                            *
 *  Copyright  2012  Meurillon Laurent                                        *
 *  webmaster@super-annonce.fr                                                *
 ******************************************************************************
 *                                                                            *
 *  This program is free software; you can redistribute it and/or modify      *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation; either version 2 of the License, or         *
 *  any later version.                                                        *
 *                                                                            *
 *  This program is distributed in the hope that it will be useful,           *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with this program; if not, write to the Free Software               *
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.*
 ******************************************************************************/

int main (int argc, char *argv[])
{
   gtk_init(&argc, &argv);
   ELEMENT Element;

   // Création de la fenêtre principale
     fenetre_principale(&Element);
     create_list (&Element);

   // Construction du tableau de prêt
   // affichage de l'ensemble
   gtk_widget_show_all(Element.p_Fenetre[0]);
   gtk_main();
	return (EXIT_SUCCESS);
}
