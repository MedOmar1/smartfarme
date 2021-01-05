#include <gtk/gtk.h>

typedef struct 

{
 
 char Nom[20];
 char Prenom[20];
 char Sexe[20];
 char Email[20];
 char Telephone[20] ;
 char ID[20];
 char Type[20];

} client;

typedef struct
{
    char id[30];
    int jour;
    int mois;
    int annee;
    float valeur;
} def ;


typedef  struct
{
    char ref[30];
    char type[30];
    char marque[30];
} capteur ;

void ajouter_client(client c);
void modifier_client(client C,char ID[20]);
void supprimer_client(client c,char ID[20]);
void afficher_client(GtkWidget *liste);
void chercher_client(GtkWidget *liste,char ID[20]);
int verif(char ID[20]);




/*void ajouter_capteur(def v);*/
void defectueux (char ch[30]);

