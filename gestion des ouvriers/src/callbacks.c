#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ouvrier.h"
#include <string.h>


void
on_chercher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowchercher ;
GtkWidget *gestion;
gestion=lookup_widget(button,"gestion_des_ouvriers");
gtk_widget_destroy(gestion);
windowchercher=create_chercher();
gtk_widget_show (windowchercher);
}

void
on_ajouter_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter ;
GtkWidget *gestion;
gestion=lookup_widget(button,"gestion_des_ouvriers");
gtk_widget_destroy(gestion);
windowajouter=create_ajouter();
gtk_widget_show (windowajouter);

}


void
on_modifier_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier ;
GtkWidget *gestion;
gestion=lookup_widget(button,"gestion_des_ouvriers");
gtk_widget_destroy(gestion);
windowmodifier=create_modifier();
gtk_widget_show (windowmodifier);

}


void
on_afficher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *Afficher;
GtkWidget *treeview1;
GtkWidget *gestion;
gestion=lookup_widget(button,"gestion_des_ouvriers");
gtk_widget_destroy(gestion);
Afficher=lookup_widget(button,"afficher");
Afficher=create_afficher();

gtk_widget_show(Afficher);

treeview1=lookup_widget(Afficher,"treeview1");
afficher(treeview1);

}


void
on_supprimer_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupprimer ;
GtkWidget *gestion;
gestion=lookup_widget(button,"gestion_des_ouvriers");
gtk_widget_destroy(gestion);
windowsupprimer=create_supprimer();
gtk_widget_show (windowsupprimer);
}


void
on_annuler_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *ajout;
GtkWidget *gestion;
ajout=lookup_widget(button,"ajouter");
gtk_widget_destroy(ajout);
gestion=create_gestion_des_ouvriers();
gtk_widget_show(gestion);

}


void
on_valider_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)

{ ouvrier o;
GtkWidget *input1, *input2, *input3 ,*input4, *input5, *input6 , *input7, *input8, *input9, *input10 , *input11, *input12;
GtkWidget *Ajouter;

Ajouter=lookup_widget(button,"ajouter");

input1=lookup_widget(button,"entry1_nom");
input2=lookup_widget(button,"entry2_prenom");
input3=lookup_widget(button,"entry3_cin");
input4=lookup_widget(button,"spinbutton1_jour");
input5=lookup_widget(button,"spinbutton2_mois");
input6=lookup_widget(button,"spinbutton3_annee");
input7=lookup_widget(button,"spinbutton4_jour");
input8=lookup_widget(button,"spinbutton5_mois");
input9=lookup_widget(button,"spinbutton6_annee");
input10=lookup_widget(button,"combobox1");
input11=lookup_widget(button,"entry4_adresse");
input12=lookup_widget(button,"entry5_num");

strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
o.date_de_recrutement.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
o.date_de_recrutement.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
o.date_de_recrutement.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
o.date_de_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
o.date_de_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
o.date_de_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input10)));
strcpy(o.adresse,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(o.num_de_telephone,gtk_entry_get_text(GTK_ENTRY(input12)));

ajouter(o);
}


void
on_button9_annuler_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *modif;
GtkWidget *gestion;
modif=lookup_widget(button,"modifier");
gtk_widget_destroy(modif);
gestion=create_gestion_des_ouvriers();
gtk_widget_show(gestion);
}


void
on_annuler1_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{GtkWidget *info;
GtkWidget *gestion;
info=lookup_widget(button,"formulaire");
gtk_widget_destroy(info);
gestion=create_gestion_des_ouvriers();
gtk_widget_show(gestion);
}


void
on_chercher1_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input, *output;
GtkWidget *Chercher;
GtkWidget *Affichage;
GtkWidget *treeview2;
char cin[30];
int test;
char commentaire[30];

Chercher=lookup_widget(button,"chercher");
input=lookup_widget(button,"entry12_cin");
output=lookup_widget(button,"commentaire2");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
test=verif(cin);
if(test==1)
{
gtk_widget_destroy(Chercher);
Affichage=lookup_widget(button,"affichage");
Affichage=create_affichage();
gtk_widget_show(Affichage);
treeview2=lookup_widget(Affichage,"treeview2");
chercher(treeview2,cin);
}
else
{
strcpy(commentaire,"cin n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}

void
on_annuler_chercher_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cher;
GtkWidget *gestion;
cher=lookup_widget(button,"chercher");
gtk_widget_destroy(cher);
gestion=create_gestion_des_ouvriers();
gtk_widget_show(gestion);
}


void
on_annuler_afficher_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *affich;
GtkWidget *gestion;
affich=lookup_widget(button,"afficher");
gtk_widget_destroy(affich);
gestion=create_gestion_des_ouvriers();
gtk_widget_show(gestion);
}


void
on_supprimer1_clicked                  (GtkWidget      *button,
                                        gpointer         user_data)
{
ouvrier o;
GtkWidget *input, *output, *Supprimer;
char cin[30];
int test;
char commentaire[30];

Supprimer=lookup_widget(button,"supprimer");
input=lookup_widget(button,"entry13_cin");
output=lookup_widget(button,"commentaire1");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
test=verif(cin);
if(test==1)
{
supprimer(o, cin);
}
else
{
strcpy(commentaire,"cin n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_annuler_supprimer_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *supp;
GtkWidget *gestion;
supp=lookup_widget(button,"supprimer");
gtk_widget_destroy(supp);
gestion=create_gestion_des_ouvriers();
gtk_widget_show(gestion);
}





void
on_annuler10_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cher;
GtkWidget *gestion;
cher=lookup_widget(button,"affichage");
gtk_widget_destroy(cher);
gestion=create_gestion_des_ouvriers();
gtk_widget_show(gestion);
}


void
on_valider10_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowdonnees;
GtkWidget *input, *output, *Modifier;
char cin[30];
int test;
char commentaire[30];
Modifier=lookup_widget(button,"modifier");
input=lookup_widget(button,"entry6_cin");
output=lookup_widget(button,"commentaire");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

test=verif(cin);
if(test==1)
{
gtk_widget_destroy(Modifier);
windowdonnees=create_formulaire();
gtk_widget_show (windowdonnees);
}
else
{
strcpy(commentaire,"cin n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_valider1_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
 ouvrier O;
GtkWidget *input1, *input2, *input3 ,*input4, *input5, *input6 , *input7, *input8, *input9, *input10 , *input11, *input12,*input13;
GtkWidget *Ajouter;
char cin [30];

Ajouter=lookup_widget(button,"valider1");

input1=lookup_widget(button,"entry7_nom");
input2=lookup_widget(button,"entry8_prenom");
input3=lookup_widget(button,"entry9_cin");
input13=lookup_widget(button,"entry_cin");
input4=lookup_widget(button,"spinbutton7");
input5=lookup_widget(button,"spinbutton9");
input6=lookup_widget(button,"spinbutton10");
input7=lookup_widget(button,"spinbutton11");
input8=lookup_widget(button,"spinbutton12");
input9=lookup_widget(button,"spinbutton13");
input10=lookup_widget(button,"combobox2");
input11=lookup_widget(button,"entry10_adresse");
input12=lookup_widget(button,"entry11_num");

strcpy(O.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(O.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(O.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input13)));
O.date_de_recrutement.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
O.date_de_recrutement.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
O.date_de_recrutement.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
O.date_de_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
O.date_de_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
O.date_de_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
strcpy(O.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input10)));
strcpy(O.adresse,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(O.num_de_telephone,gtk_entry_get_text(GTK_ENTRY(input12)));
//strcpy(cin,O.cin);
modifier(O,cin);

}


void
on_annuler_abs_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *abs;
GtkWidget *gestion;
abs=lookup_widget(button,"absenteisme");
gtk_widget_destroy(abs);
gestion=create_gestion_des_ouvriers();
gtk_widget_show(gestion);

}


void
on_valider_abs_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
meill v;

GtkWidget *input1, *input2, *input3, *input4, *input5;
GtkWidget *ajouter;

ajouter=lookup_widget(button,"ajouter");

input1=lookup_widget(button,"entrycinabs");
input2=lookup_widget(button,"spinbuttonjour");
input3=lookup_widget(button,"spinbuttonmois");
input4=lookup_widget(button,"spinbuttonannee");
input5=lookup_widget(button,"spinbuttonvaleur");

strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(input1)));
v.jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
v.mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
v.annee1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
v.valeur=gtk_spin_button_get_value(GTK_SPIN_BUTTON(input5));


ajouter_ouvrier(v);

}


void
on_valider_sur1_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *output,*input1;
int annee;
char chaine[30];
input1=lookup_widget(button,"spinbuttonannee1");
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
meilleur_ouvrier (annee,chaine);
output=lookup_widget(button,"labelmeilleur");
gtk_label_set_text(GTK_LABEL(output),chaine);



}


void
on_valider_taux_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output,*input1,*input2;
int annee,mois;
char chaine[30];
float taux;
input1=lookup_widget(button,"spinbuttonannee2");
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
input2=lookup_widget(button,"spinbuttonmois1");
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
taux=taux_absentisme(mois,annee);
sprintf(chaine,"%0.2f",taux);
output=lookup_widget(button,"labeltaux");
gtk_label_set_text(GTK_LABEL(output),chaine);

}


void
on_verification_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsurface ;
GtkWidget *gestion;
gestion=lookup_widget(button,"gestion_des_ouvriers");
gtk_widget_destroy(gestion);
windowsurface=create_surface_absenteisme();
gtk_widget_show (windowsurface);

}


void
on_presence_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowpresence ;
GtkWidget *gestion;
gestion=lookup_widget(button,"gestion_des_ouvriers");
gtk_widget_destroy(gestion);
windowpresence=create_absenteisme();
gtk_widget_show (windowpresence);
}


void
on_annulersur_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *surf;
GtkWidget *gestion;
surf=lookup_widget(button,"surface_absenteisme");
gtk_widget_destroy(surf);
gestion=create_gestion_des_ouvriers();
gtk_widget_show(gestion);
}

