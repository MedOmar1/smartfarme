#include <gtk/gtk.h>
typedef struct {
int jour ;
int mois ;
int annee ;
}date;
typedef struct {
char type[10];
char id[10] ;
char sexe[10] ;
date date_de_naissance ;
}troupeaux;

void ajouter(troupeaux t );
void modifier(troupeaux T,char id[] );
void chercher(GtkWidget *liste,char id[] );
void supprimer(troupeaux t,char id[] );
void afficher(GtkWidget *liste);
int verif(char id[]);
void number(int *pv,int *pb);

