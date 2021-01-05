#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"
#include <string.h>

void
on_ajouter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter;
GtkWidget *gestion;
gestion=lookup_widget(button,"client");
gtk_widget_destroy(gestion);
windowajouter=create_ajouter();
gtk_widget_show(windowajouter);
}


void
on_modifier_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier;
GtkWidget *gestion;
gestion=lookup_widget(button,"client");
gtk_widget_destroy(gestion);
windowmodifier=create_modifier();
gtk_widget_show(windowmodifier);
}

void
on_chercher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowChercher;
GtkWidget *gestion;
gestion=lookup_widget(button,"client");
gtk_widget_destroy(gestion);
windowChercher=create_chercher();
gtk_widget_show (windowChercher);

}


void
on_supprimer_clicked                   (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupprimer;
GtkWidget *gestion;
gestion=lookup_widget(button,"client");
gtk_widget_destroy(gestion);
windowsupprimer=create_supprimer();
gtk_widget_show(windowsupprimer);

}



void
on_enregistrer0_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
client c;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7;
/*GtkWidget *ajouter;*/


 /*ajouter=lookup_widget(button,"enregitrer0");*/

input1=lookup_widget(button,"Nomajout");
input2=lookup_widget(button,"Prenomajout");
input3=lookup_widget(button,"combobox1");
input4=lookup_widget(button,"Emailajout");
input5=lookup_widget(button,"Telephoneajout");
input6=lookup_widget(button,"combobox2");
input7=lookup_widget(button,"IDajout");

strcpy(c.Nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.Prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.Sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(c.Email,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.Telephone,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
strcpy(c.ID,gtk_entry_get_text(GTK_ENTRY(input7)));

ajouter_client (c);
}

void 
on_afficher_clicked                    (GtkWidget     *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview;

fenetre_ajout=lookup_widget(button,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(button,"fenetre_afficher");
fenetre_afficher=create_afficher();

gtk_widget_show(fenetre_afficher);

treeview=lookup_widget(fenetre_afficher,"treeviewafficher");

afficher_client(treeview);

}

void
on_annuler0_clicked                    (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget *ajout ;
GtkWidget *gestion;
ajout=lookup_widget(button,"ajouter");
gtk_widget_destroy(ajout);
gestion=create_client();
gtk_widget_show(gestion);
}


void
on_enregistrer1_clicked                (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget  *windowdonnees;
GtkWidget *input, *output, *Modifier;
char ID[30];
int test;
char commentaire[30];
Modifier=lookup_widget(button,"modifier");
input=lookup_widget(button,"ID1");
output=lookup_widget(button,"commentaire");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input)));

test=verif(ID);
if(test==1)
{
gtk_widget_destroy(Modifier);
windowdonnees=create_formulaire();
gtk_widget_show (windowdonnees);
}
else
{
strcpy(commentaire,"cet identifiant n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_annuler1_clicked                    (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget *MODIFIER ;
GtkWidget *gestion;
MODIFIER=lookup_widget(button,"modifier");
gtk_widget_destroy(MODIFIER);
gestion=create_client();
gtk_widget_show(gestion);
}


void
on_enregistrer2_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input, *output;
GtkWidget *Chercher;
GtkWidget *Affichage;
GtkWidget *treeview2;
char ID[20];
int test;
char commentaire[30];

Chercher=lookup_widget(button,"chercher");
input=lookup_widget(button,"ID2");
output=lookup_widget(button,"commentaire2");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input)));
test=verif(ID);
if(test==1)
{
gtk_widget_destroy(Chercher);
Affichage=lookup_widget(button,"Affichage");
Affichage=create_Affichage();
gtk_widget_show(Affichage);
treeview2=lookup_widget(Affichage,"treeview2");
chercher_client(treeview2,ID);
}
else
{
strcpy(commentaire,"cet identifiant n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_annuler2_clicked                    (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget *CHERCHER ;
GtkWidget *gestion;
CHERCHER=lookup_widget(button,"chercher");
gtk_widget_destroy(CHERCHER);
gestion=create_client();
gtk_widget_show(gestion);
}


void
on_enregistrer3_clicked                (GtkWidget        *button,
                                        gpointer         user_data)
{
client c;
GtkWidget *input, *output, *Supprimer;
char ID[20];
int test;
char commentaire[30];

Supprimer=lookup_widget(button,"supprimer");
input=lookup_widget(button,"ID3");
output=lookup_widget(button,"commentaire1");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input)));
test=verif(ID);
if(test==1)
{
supprimer_client(c, ID);
}
else
{
strcpy(commentaire,"Cet identifiant n'existe pas");
gtk_label_set_text(GTK_LABEL(output),commentaire);
return;
}
}


void
on_annuler3_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *SUPPRIMER ;
GtkWidget *gestion;
SUPPRIMER=lookup_widget(button,"supprimer");
gtk_widget_destroy(SUPPRIMER);
gestion=create_client();
gtk_widget_show(gestion);
}


void
on_enregitrer4_clicked                 (GtkWidget        *button,
                                        gpointer         user_data)
{
client C;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7 ,*input8;
/*GtkWidget *ajouter;*/
char ID[20];

 /*ajouter=lookup_widget(button,"enregitrer4");*/

input1=lookup_widget(button,"Nomformulaire");
input2=lookup_widget(button,"Prenomformulaire");
input3=lookup_widget(button,"combobox3");
input4=lookup_widget(button,"Emailformulaire");
input5=lookup_widget(button,"Telephoneformulaire");
input6=lookup_widget(button,"combobox4");
input7=lookup_widget(button,"IDformulaire");
input8=lookup_widget(button,"nouveau_id_formulaire");


strcpy(C.Nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(C.Prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(C.Sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(C.Email,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(C.Telephone,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(C.Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
strcpy(C.ID,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input7)));
//strcpy(ID,C.ID);
modifier_client (C,ID);
}



void
on_annuler4_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *FORMULAIRE ;
GtkWidget *gestion;
FORMULAIRE=lookup_widget(button,"formulaire");
gtk_widget_destroy(FORMULAIRE);
gestion=create_client();
gtk_widget_show(gestion);
}

 

void
on_retour2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
GtkWidget *Chercher;
Affichage=lookup_widget(button,"Affichage");
gtk_widget_destroy(Affichage);
Chercher=create_chercher();
gtk_widget_show(Chercher);
}




void
on_retour_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Afficher ;
GtkWidget *gestion;
Afficher=lookup_widget(button,"afficher");
gtk_widget_destroy(Afficher);
gestion=create_client();
gtk_widget_show(gestion);
}


void
on_ajouter_capteur_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
def v;

GtkWidget *input1, *input2, *input3, *input4, *input5;
GtkWidget *ajouter;

ajouter=lookup_widget(button,"ajouter");

input1=lookup_widget(button,"id_capteur");
input2=lookup_widget(button,"capteur_jour");
input3=lookup_widget(button,"capteur_mois");
input4=lookup_widget(button,"capteur_annee");
input5=lookup_widget(button,"spin_valeur");

strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(input1)));
v.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
v.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
v.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
v.valeur=gtk_spin_button_get_value(GTK_SPIN_BUTTON(input5));


ajouter_capteur(v);

}

void
on_supprimer_capteur_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *capteur ;
GtkWidget *gestion;
capteur=lookup_widget(button,"capteur_defetueux");
gtk_widget_destroy(capteur);
gestion=create_client();
gtk_widget_show(gestion);
}


void
on_marque_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output;

char chaine[30];
defectueux(chaine);
output=lookup_widget(button,"resultat");

gtk_label_set_text(GTK_LABEL(output),chaine);

}

