#include <stdio.h>
#include <stdlib.h>
#include "equipements.h"
#include <string.h>
#include<gtk/gtk.h>

enum
{
NUMERO,
NOM,
MARQUE,
COUT,
JOUR,
MOIS,
ANNEE,
DUREE,
COLUMNS
};

void ajouter(Equipements E)
{
FILE *f;
f=fopen("equipements.txt","a+");
if(f!=NULL)
{
fprintf(f," %s %s %s %s %d %d %d %d \n",E.Numero,E.Nom,E.Marque,E.cout,E.date.jour,E.date.mois,E.date.annee,E.duree);
}
fclose(f);
}

void supprimer(Equipements E, char num[30])
{
FILE *f1;
FILE *f2;

f1=fopen("equipements.txt","r");
f2=fopen("equipements1.txt","a+");
if ((f1!=NULL) && (f2!=NULL))
{
while(fscanf(f1," %s %s %s %s %d %d %d %d \n",E.Numero,E.Nom,E.Marque,E.cout,&E.date.jour,&E.date.mois,&E.date.annee,&E.duree)!=EOF)
{
if (strcmp(E.Numero, num)!=0)
{
fprintf(f2,"%s %s %s %s %d %d %d %d \n",E.Numero,E.Nom,E.Marque,E.cout,E.date.jour,E.date.mois,E.date.annee,E.duree);
}
}
fclose(f1);
fclose(f2);
remove("equipements.txt");
rename("equipements1.txt","equipements.txt");
}
else
{return;}
}

void modifier( Equipements e, char num[30])
{
FILE *f1;
FILE *f2;
Equipements E;
f1=fopen("equipements.txt","r");
f2=fopen("equipements1.txt","a+");
if ((f1!=NULL) && (f2!=NULL))
{
while(fscanf(f1," %s %s %s %s %d %d %d %d \n",E.Numero,E.Nom,E.Marque,E.cout,&E.date.jour,&E.date.mois,&E.date.annee,&E.duree)!=EOF)
{
if (strcmp(E.Numero,num)!=0)
{
fprintf(f2," %s %s %s %s %d %d %d %d \n",E.Numero,E.Nom,E.Marque,E.cout,E.date.jour,E.date.mois,E.date.annee,E.duree);
}
else
{
/*supprimer(E,num);
ajouter(E);*/
fprintf(f2," %s %s %s %s %d %d %d %d \n",e.Numero,e.Nom,e.Marque,e.cout,e.date.jour,e.date.mois,e.date.annee,e.duree);
}
}

fclose(f1);
fclose(f2);
remove("equipements.txt");
rename("equipements1.txt","equipements.txt");
}
}

void afficher( GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

  /*char Nom[30];
  char Numero[30];
  char Marque[30];
  char cout[30];
  int jour;
  int mois;
  int annee;
  int duree;*/
Equipements E;
 
  store=NULL;

FILE *f;
store= gtk_tree_view_get_model(liste); 


if (store==NULL)
{


renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Numero",renderer,"text",NUMERO,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Cout",renderer,"text",COUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("duree",renderer,"text",DUREE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT );
f=fopen("equipements.txt","r");
if(f==NULL)
{return;}
else
{
f=fopen("equipements.txt","a+");
while(fscanf(f," %s %s %s %s %d %d %d %d \n",E.Numero, E.Nom, E.Marque, E.cout,
&E.date.jour,&E.date.mois,&E.date.annee,&E.duree)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NUMERO,E.Numero,NOM,E.Nom,MARQUE,E.Marque,COUT,E.cout,JOUR,E.date.jour,MOIS,E.date.mois,ANNEE,E.date.annee,DUREE,E.duree,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

void chercher(GtkWidget *liste,char num[30])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
Equipements E;
 
  store=NULL;

FILE *f;
store= gtk_tree_view_get_model(liste); 


if (store==NULL)
{


renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Numero",renderer,"text",NUMERO,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Cout",renderer,"text",COUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("duree",renderer,"text",DUREE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT );
f=fopen("equipements.txt","r");
if(f==NULL)
{return;}
else
{
f=fopen("equipements.txt","a+");
while(fscanf(f," %s %s %s %s %d %d %d %d \n",E.Numero, E.Nom, E.Marque, E.cout,
&E.date.jour,&E.date.mois,&E.date.annee,&E.duree)!=EOF)
{
if (strcmp(E.Numero,num)==0)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NUMERO,E.Numero,NOM,E.Nom,MARQUE,E.Marque,COUT,E.cout,JOUR,E.date.jour,MOIS,E.date.mois,ANNEE,E.date.annee,DUREE,E.duree,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

}
}

int verif(char num[30])
{
Equipements E;
FILE *f;
f=fopen("equipements.txt","r");
if (f!=NULL)
{
while(fscanf(f," %s %s %s %s %d %d %d %d \n",E.Numero,E.Nom,E.Marque,E.cout,&E.date.jour,&E.date.mois,&E.date.annee,&E.duree)!=EOF)
{
if (strcmp(E.Numero,num)==0)
{
return (1);
}
}
}
}








