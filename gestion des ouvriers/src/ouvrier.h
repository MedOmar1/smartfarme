#include <gtk/gtk.h>
typedef struct
{int jour;
int mois;
int annee;
}date;
typedef struct 
{char nom[30];
char prenom[30];
date date_de_recrutement;
date date_de_naissance;
char adresse[30];
char cin[30];
char num_de_telephone[30]; 
char sexe[30];
}ouvrier;
typedef struct
{
    char id[30];
    int jour1;
    int mois1;
    int annee1;
    int valeur;
} meill ;
void meilleur_ouvrier (int annee,char ch[30]);
void ajouter (ouvrier o);
void modifier (ouvrier O,char cin[30]);
void chercher (GtkWidget *liste,char cin[30]);
void supprimer (ouvrier o,char cin[30]);
void afficher (GtkWidget *liste);
int verif(char cin[30]);
void ajouter_ouvrier(meill v);
int nombre_ouvrier();
float taux_absentisme(int mois,int annee);
