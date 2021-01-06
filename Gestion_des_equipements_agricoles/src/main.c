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
  GtkWidget *Gestion_des_equipements_agricoles;
  GtkWidget *Ajouter;
  GtkWidget *Modifier;
  GtkWidget *Supprimer;
  GtkWidget *Chercher;
  GtkWidget *Formulaire;
  GtkWidget *Afficher;
  GtkWidget *Affichage;

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
  Gestion_des_equipements_agricoles = create_Gestion_des_equipements_agricoles ();
  gtk_widget_show (Gestion_des_equipements_agricoles);
  Ajouter = create_Ajouter ();
  gtk_widget_show (Ajouter);
  Modifier = create_Modifier ();
  gtk_widget_show (Modifier);
  Supprimer = create_Supprimer ();
  gtk_widget_show (Supprimer);
  Chercher = create_Chercher ();
  gtk_widget_show (Chercher);
  Formulaire = create_Formulaire ();
  gtk_widget_show (Formulaire);
  Afficher = create_Afficher ();
  gtk_widget_show (Afficher); 
  Affichage = create_Affichage ();
  gtk_widget_show (Affichage); 


  gtk_main ();
  return 0;
}
