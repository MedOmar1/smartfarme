#include<gtk/gtk.h>

typedef struct
{
  int jour;
  int mois;
  int annee;
} Date;

typedef struct 
{
  char Nom[30];
  char Numero[30];
  char Marque[30];
  char cout[30];
  Date date;
  int duree;
} Equipements;

int verif(char num[30]);
void ajouter( Equipements E);
void modifier( Equipements e, char num[30]);
void chercher( GtkWidget *liste,char num[30]);
void supprimer( Equipements E, char num[30]);
void afficher( GtkWidget *liste);
