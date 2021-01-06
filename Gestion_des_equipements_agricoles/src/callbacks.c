#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gtk/gtkcalendar.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "equipements.h"
#include <string.h>




void
on_ajouter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAjouter;
GtkWidget *gestion;
gestion=lookup_widget(button,"Gestion_des_equipements_agricoles");
gtk_widget_destroy(gestion);
windowAjouter=create_Ajouter();
gtk_widget_show (windowAjouter);

}


void
on_chercher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowChercher;
GtkWidget *gestion;
gestion=lookup_widget(button,"Gestion_des_equipements_agricoles");
gtk_widget_destroy(gestion);
windowChercher=create_Chercher();
gtk_widget_show (windowChercher);

}


void
on_modifier_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowModifier;
GtkWidget *gestion;
gestion=lookup_widget(button,"Gestion_des_equipements_agricoles");
gtk_widget_destroy(gestion);
windowModifier=create_Modifier();
gtk_widget_show (windowModifier);
}


void
on_supprimer_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowSupprimer;
GtkWidget *gestion;
gestion=lookup_widget(button,"Gestion_des_equipements_agricoles");
gtk_widget_destroy(gestion);
windowSupprimer=create_Supprimer();
gtk_widget_show (windowSupprimer);
}


void
on_enregistrer1_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
Equipements E;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8;
GtkWidget *Ajouter;

Ajouter=lookup_widget(button,"Ajouter");

input1=lookup_widget(button,"entry2_numero");
input2=lookup_widget(button,"entry1_nom");
input3=lookup_widget(button,"entry3_marque");
input4=lookup_widget(button,"entry4_cout");
input5=lookup_widget(button,"jour");
input6=lookup_widget(button,"mois");
input7=lookup_widget(button,"annee");
input8=lookup_widget(button,"entry5_duree");

strcpy(E.Numero,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E.Nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(E.Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(E.cout,gtk_entry_get_text(GTK_ENTRY(input4)));
E.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
E.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
E.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
E.duree=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));

ajouter(E);
}


void
on_afficher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion;
GtkWidget *Afficher;
GtkWidget *treeview1;

gestion=lookup_widget(button,"Gestion_des_equipements_agricoles");
gtk_widget_destroy(gestion);
Afficher=lookup_widget(button,"Afficher");
Afficher=create_Afficher();
gtk_widget_show(Afficher);
treeview1=lookup_widget(Afficher,"treeview1");
afficher(treeview1);

/*Gestion_des_equipements_agricoles=lookup_widget(button,"Gestion_des_equipements_agricoles");
gtk_widget_destroy(Gestion_des_equipements_agricoles);
treeview1=lookup_widget(Afficher,"treeview1");
afficher(treeview1);*/


}


void
on_annuler1_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajouter;
GtkWidget *gestion;
Ajouter=lookup_widget(button,"Ajouter");
gtk_widget_destroy(Ajouter);
gestion=create_Gestion_des_equipements_agricoles();
gtk_widget_show(gestion);
}


void
on_annuler2_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier;
GtkWidget *gestion;
Modifier=lookup_widget(button,"Modifier");
gtk_widget_destroy(Modifier);
gestion=create_Gestion_des_equipements_agricoles();
gtk_widget_show(gestion);
}


void
on_annuler3_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer;
GtkWidget *gestion;
Supprimer=lookup_widget(button,"Supprimer");
gtk_widget_destroy(Supprimer);
gestion=create_Gestion_des_equipements_agricoles();
gtk_widget_show(gestion);
}


void
on_annuler4_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Chercher;
GtkWidget *gestion;
Chercher=lookup_widget(button,"Chercher");
gtk_widget_destroy(Chercher);
gestion=create_Gestion_des_equipements_agricoles();
gtk_widget_show(gestion);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{/*
GtkTreeIter iter;
gchar *Numero;
Equipements E;

GtkTreeModel *model= gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&Numero,-1);
strcpy(E.Numero,Numero);
supprimer(E,Numero);
afficher(treeview);
}
*/


}


void
on_enregistrer3_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
Equipements E;
GtkWidget *input, *output, *Supprimer;
char num[30];
int test;
char commentaire[30];

Supprimer=lookup_widget(button,"Supprimer");
input=lookup_widget(button,"suppression_num");
output=lookup_widget(button,"commentaire1");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
test=verif(num);
if(test==1)
{
supprimer(E, num);
}
else
{
strcpy(commentaire,"Ce numéro n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_enregistrer2_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowdonnees;
GtkWidget *input, *output, *Modifier;
GdkColor color;
char num[30];
int test;
char commentaire[30];
Modifier=lookup_widget(button,"Modifier");
input=lookup_widget(button,"modification_num");
output=lookup_widget(button,"commentaire");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
color.red=0xaaaa;
gtk_widget_modify_bg(output, GTK_STATE_NORMAL, &color);

test=verif(num);
if(test==1)
{
gtk_widget_destroy(Modifier);
windowdonnees=create_Formulaire();
gtk_widget_show (windowdonnees);
}
else
{
strcpy(commentaire,"Ce numéro n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}

void
on_enregistrer5_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9;
Equipements e;

GtkWidget *enregistrer;
char num[30];

enregistrer=lookup_widget(button,"enregistrer5");

input1=lookup_widget(button,"entry8_numero");
input2=lookup_widget(button,"entry7_nom");
input3=lookup_widget(button,"entry9_marque");
input4=lookup_widget(button,"entry10_cout");
input5=lookup_widget(button,"jour1");
input6=lookup_widget(button,"mois1");
input7=lookup_widget(button,"annee1");
input8=lookup_widget(button,"entry11_duree");
input9=lookup_widget(button,"entry11_numero");

strcpy(e.Numero,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.Nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(e.cout,gtk_entry_get_text(GTK_ENTRY(input4)));
e.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
e.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
e.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
e.duree=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input9)));
//strcpy(num,e.Numero);
modifier( e, num );

}


void
on_annuler5_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Les_donnees;
GtkWidget *Modifier;
Les_donnees=lookup_widget(button,"Formulaire");
gtk_widget_destroy(Les_donnees);
Modifier=create_Modifier();
gtk_widget_show(Modifier);
}


void
on_Annuler_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Afficher;
GtkWidget *gestion;
Afficher=lookup_widget(button,"Afficher");
gtk_widget_destroy(Afficher);
gestion=create_Gestion_des_equipements_agricoles();
gtk_widget_show(gestion);
}


void
on_enregistrer4_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input, *output;
GtkWidget *Chercher; 
GtkWidget *Affichage;
GtkWidget *treeview2;
char num[30];
int test;
char commentaire[30];

Chercher=lookup_widget(button,"Chercher");
input=lookup_widget(button,"recherche_num");
output=lookup_widget(button,"commentaire2");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
test=verif(num);
if(test==1)
{
gtk_widget_destroy(Chercher);
Affichage=lookup_widget(button,"Affichage");
Affichage=create_Affichage();
gtk_widget_show(Affichage);
treeview2=lookup_widget(Affichage,"treeview2");
chercher(treeview2,num);
}
else
{
strcpy(commentaire,"Ce numéro n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_annuler6_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
GtkWidget *Chercher;
Affichage=lookup_widget(button,"Affichage");
gtk_widget_destroy(Affichage);
Chercher=create_Chercher();
gtk_widget_show(Chercher);
}

