#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "troupeaux.h"
#include <gtk/gtk.h>

enum
{
	EID,
	ETYPE,
	ESEXE,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS,
};

void number(int *pb,int *pv)
{
FILE *f ;
troupeaux t ;
int b=0;
int v=0 ;
f=fopen("troupeaux.txt","r");

if(f!=NULL)
{
while(fscanf(f,"%20s%20s%20s\t%d/%d/%d \n",t.id,t.type,t.sexe,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee)!=EOF)
{
if(strcmp(t.type,"Brebi")==0)
{
	b++;
	*pb=b ; 
}
else if(strcmp(t.type,"Veau")==0)
{
	v++;
	*pv=v;
}
}
fclose(f);
}
}

void ajouter(troupeaux t)
{
FILE *f ;
f=fopen("troupeaux.txt","a+");
if(f!=NULL){
fprintf(f,"%20s%20s%20s\t%d/%d/%d \n",t.id,t.type,t.sexe,t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee);
}
fclose(f);
}

void modifier(troupeaux T,char id[10])
{
FILE *f1;
FILE *f2;
troupeaux t;
f1=fopen("troupeaux.txt","r");
f2=fopen("tmp.txt","a+");
if((f1!=NULL)&&(f2!=NULL))
{while(fscanf(f1,"%20s%20s%20s\t%d/%d/%d \n",t.id,t.type,t.sexe,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee)!=EOF){
if(strcmp(t.id,id)!=0)
{fprintf(f2,"%20s%20s%20s\t%d/%d/%d \n",t.id,t.type,t.sexe,t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee);}
else 
{
//supprimer(t,id);
//ajouter(t);
fprintf(f2,"%20s%20s%20s\t%d/%d/%d \n",T.id,T.type,T.sexe,T.date_de_naissance.jour,T.date_de_naissance.mois,T.date_de_naissance.annee);
}
}
fclose(f1);
fclose(f2);
remove("troupeaux.txt");
rename("tmp.txt","troupeaux.txt");
}
}

/*void chercher(troupeaux t , char id[10] )
{FILE *f;
 FILE *f1;
f=fopen("troupeaux.txt","r");
f1=fopen("tmp.txt","a+");

if((f!=NULL)&&(f1!=NULL))
{while(fscanf(f,"%20s%20s%20s%d%d%d\n",t.id,t.type,t.sexe,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee)!=EOF){
if(!strcmp(t.id,id)){
fprintf(f1,"%20s%20s%20s\t%d/%d/%d \n",t.id,t.type,t.sexe,t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee);}
}
fclose(f);
fclose(f1);
remove("tmp.txt");
}
}*/

void supprimer(troupeaux t, char id[10] )
{
FILE *f1;
FILE *f2;

f1=fopen("troupeaux.txt","r");
f2=fopen("tmp.txt","a+");

if((f1!=NULL)&&(f2!=NULL))
{while(fscanf(f1,"%20s%20s%20s\t%d/%d/%d\n",t.id,t.type,t.sexe,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee)!=EOF){
if(strcmp(t.id,id)!=0)
{fprintf(f2,"%20s%20s%20s\t%d/%d/%d \n",t.id,t.type,t.sexe,t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee);}
}

fclose(f1);
fclose(f2);
remove("troupeaux.txt");
rename("tmp.txt","troupeaux.txt");
}
}

int verif(char id[10])
{
troupeaux t;
FILE *f;
f=fopen("troupeaux.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%20s%20s%20s%d%d%d\n",t.id,t.type,t.sexe,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee)!=EOF)
{
if (!strcmp(t.id,id))
{
return (1);
}
}
}
}
void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

char type[10];
char id[10];
char sexe[10];
int jour ;
int mois ;
int annee ;
store=NULL ;

FILE *f ;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f=fopen("troupeaux.txt","r");
if(f==NULL)
{return ;}
else 
{
f=fopen("troupeaux.txt","a+");
while(fscanf(f,"%20s%20s%20s\t%d/%d/%d\n",id,type,sexe,&jour,&mois,&annee)!=EOF)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store, &iter,EID,id,ETYPE,type,ESEXE,sexe,EJOUR,jour,EMOIS,mois,EANNEE,annee, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);
}
}


void chercher(GtkWidget *liste,char id[10])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
troupeaux t;

store=NULL;
FILE *f;

store= gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT );
f=fopen("troupeaux.txt","r");
if(f==NULL)
{return;}
else
{
f=fopen("troupeaux.txt","a+");
while(fscanf(f,"%20s%20s%20s\t%d/%d/%d\n",t.id,t.type,t.sexe,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee)!=EOF)
{
if (strcmp(t.id,id)==0)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter,EID,t.id,ETYPE,t.type,ESEXE,t.sexe,EJOUR,t.date_de_naissance.jour,EMOIS,t.date_de_naissance.mois,EANNEE,t.date_de_naissance.annee, -1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

}
}

