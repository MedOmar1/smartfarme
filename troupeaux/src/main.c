/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *gestion_des_troupeaux;
  GtkWidget *ajouter;
  GtkWidget *modifier;
  GtkWidget *chercher;
  GtkWidget *supprimer;
  GtkWidget *calcul ;
#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  gestion_des_troupeaux = create_gestion_des_troupeaux ();
  gtk_widget_show (gestion_des_troupeaux);
  /*ajouter = create_ajouter ();
  gtk_widget_show (ajouter);
  modifier = create_modifier ();
  gtk_widget_show (modifier);
  chercher = create_chercher ();
  gtk_widget_show (chercher);
  supprimer = create_supprimer ();
  gtk_widget_show (supprimer);
  calcul = create_calcul ();
  gtk_widget_show (calcul);*/

  gtk_main ();
  return 0;
}

