#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "troupeaux.h"


void
on_button4_supprimer_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupprimer ;
GtkWidget *principal ;
windowsupprimer=create_supprimer();
gtk_widget_show (windowsupprimer);
principal=lookup_widget(button,"gestion_des_troupeaux");
gtk_widget_destroy(principal);
}


void
on_button3_chercher_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowchercher ;
GtkWidget *principal ;
windowchercher=create_chercher();
gtk_widget_show (windowchercher);
principal=lookup_widget(button,"gestion_des_troupeaux");
gtk_widget_destroy(principal);
}


void
on_button2_modifier_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier ;
GtkWidget *principal ;
windowmodifier=create_modifier();
gtk_widget_show (windowmodifier);
principal=lookup_widget(button,"gestion_des_troupeaux");
gtk_widget_destroy(principal);
}


void
on_button1_ajouter_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter,*principal ;
windowajouter=create_ajouter();
gtk_widget_show (windowajouter);
principal=lookup_widget(button,"gestion_des_troupeaux");
gtk_widget_destroy(principal);

}


void
on_button5_add_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{	
	troupeaux t ;
	GtkWidget *id , *combobox1_type , *combobox2_sexe ;
	GtkWidget *jour , *mois , *annee ;
	GtkWidget *ajout ;

	ajout=lookup_widget(button,"ajouter");
	
	id=lookup_widget(button,"entry2_id");
	jour=lookup_widget(button,"spinbutton1");
	mois=lookup_widget(button,"spinbutton2");
	annee=lookup_widget(button,"spinbutton3");
	combobox1_type=lookup_widget(button,"combobox1_type");
	combobox2_sexe=lookup_widget(button,"combobox2_sexe");

	strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(id)));
	t.date_de_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	t.date_de_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	t.date_de_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	strcpy(t.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_type)));
	strcpy(t.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2_sexe)));

	ajouter(t);



}


void
on_button6_cherche_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input, *output;
GtkWidget *Chercher;
GtkWidget *Affichage;
GtkWidget *treeview2;
char id[10];
int test;
char commentaire[30];

Chercher=lookup_widget(button,"chercher");
input=lookup_widget(button,"entry4_chercher");
output=lookup_widget(button,"commantaire2");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
test=verif(id);
if(test==1)
{
gtk_widget_destroy(Chercher);
Affichage=lookup_widget(button,"chercher_aff");
Affichage=create_chercher_aff();
gtk_widget_show(Affichage);
treeview2=lookup_widget(Affichage,"treeview2");
chercher(treeview2,id);
}
else
{
strcpy(commentaire,"Ce identifiant n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_button8_supprimer_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
troupeaux t ;
GtkWidget *input, *output, *Supprimer;
char id[10];
int test;
char commentaire[30];

Supprimer=lookup_widget(button,"supprimer");
input=lookup_widget(button,"entry5_supprimer");
output=lookup_widget(button,"commentaire1");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
test=verif(id);
if(test==1)
{
supprimer(t,id);
}
else
{
strcpy(commentaire,"Ce identifiant n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_button1_modifier_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdonnees;
GtkWidget *input, *output, *Modifier;
char id[10];
int test;
char commentaire[30];
Modifier=lookup_widget(button,"modifier");
input=lookup_widget(button,"entry1_modifier");
output=lookup_widget(button,"commentaire");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));

test=verif(id);
if(test==1)
{
gtk_widget_destroy(Modifier);
windowdonnees=create_formulaire();
gtk_widget_show(windowdonnees);
}
else
{
strcpy(commentaire,"Ce identifiant n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_button10_annuler_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier,*gestion ;
modifier=lookup_widget(button,"modifier");
gtk_widget_destroy(modifier);
gestion=create_gestion_des_troupeaux() ;
gtk_widget_show(gestion);
}


void
on_button1_annuler_ajout_clicked       (GtkWidget       *button,
                                        gpointer         user_data)

{
GtkWidget *ajout ;
GtkWidget *gestion ;
ajout=lookup_widget(button,"ajouter");
gtk_widget_destroy(ajout);

gestion=create_gestion_des_troupeaux() ;
gtk_widget_show(gestion);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
/*GtkTreeIter iter ;
gchar* id ;
gchar* type ;
gchar* sexe ;
int* jour ;
int* mois ;
int* annee ;
troupeaux t ;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&type,2,&sexe,3,&jour,4,&mois,5,&annee, -1);
strcpy(t.id,id);
strcpy(t.type,type);
strcpy(t.sexe,sexe);
jour=t.date_de_naissance.jour;
mois=t.date_de_naissance.mois;
annee=t.date_de_naissance.annee;
supprimer(t,id);
afficher(treeview);
}
*/
}


void
on_button_annuler_chercher_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *chercher,*gestion ;
chercher=lookup_widget(button,"chercher");
gtk_widget_destroy(chercher);
gestion=create_gestion_des_troupeaux() ;
gtk_widget_show(gestion);
}


void
on_button_annuler_supprimer_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer,*gestion ;
supprimer=lookup_widget(button,"supprimer");
gtk_widget_destroy(supprimer);
gestion=create_gestion_des_troupeaux() ;
gtk_widget_show(gestion);
}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *affich ;
GtkWidget *treeview1 ;

affich=lookup_widget(objet,"ajouter");


principal=lookup_widget(objet,"gestion_des_troupeaux");
principal=create_gestion_des_troupeaux();
gtk_widget_show(principal);
treeview1=lookup_widget(principal,"treeview1");
afficher(treeview1);*/
}



void
on_afficher_treeview_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *affich;
GtkWidget *treeview1 ;

affich=lookup_widget(objet,"gestion_des_troupeaux");
treeview1=lookup_widget(affich,"treeview1");
afficher(treeview1);
}


void
on_confirmer_mod_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *type, *iden, *sexe, *jour, *mois, *annee, *oldid;
troupeaux T;

GtkWidget *enregistrer;
char id[10];

enregistrer=lookup_widget(button,"formulaire");

type=lookup_widget(button,"combobox_type_mod");
iden=lookup_widget(button,"entry_id_mod");
sexe=lookup_widget(button,"combobox_sexe_mod");
jour=lookup_widget(button,"spinbutton_jour_mod");
mois=lookup_widget(button,"spinbutton_mois_mod");
annee=lookup_widget(button,"spinbutton6");
oldid=lookup_widget(button,"entry_old_id");

strcpy(T.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(T.id,gtk_entry_get_text(GTK_ENTRY(iden)));
strcpy(T.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe)));
T.date_de_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
T.date_de_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
T.date_de_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(oldid)));
//strcpy(id,T.id);
modifier( T, id );
}


void
on_annuler_mod_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *formulaire,*gestion ;
formulaire=lookup_widget(button,"formulaire");
gtk_widget_destroy(formulaire);
gestion=create_gestion_des_troupeaux() ;
gtk_widget_show(gestion);
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_return_chercher_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
GtkWidget *Chercher;
Affichage=lookup_widget(button,"chercher_aff");
gtk_widget_destroy(Affichage);
Chercher=create_chercher();
gtk_widget_show(Chercher);
}


void
on_button_calculer_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Calculer ;
GtkWidget *label ;
int v=0 ;
int b=0 ;
char m[60];

Calculer=lookup_widget(button,"calcul");
label=lookup_widget(button,"resultat");
number(&b,&v);
sprintf(m,"le nombre de brebi est %d \n le nombre de veau est %d ",b,v);
gtk_label_set_text(GTK_LABEL(label),m);
}


void
on_calculer1_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcalcul ;
GtkWidget *principal ;
windowcalcul=create_calcul();
gtk_widget_show (windowcalcul);
principal=lookup_widget(button,"gestion_des_troupeaux");
gtk_widget_destroy(principal);

}


void
on_annuler_calcul_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcalculer,*gestion ;
windowcalculer=lookup_widget(button,"calcul");
gtk_widget_destroy(windowcalculer);
gestion=create_gestion_des_troupeaux() ;
gtk_widget_show(gestion);
}

