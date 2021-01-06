#include <stdio.h>
#include <stdlib.h>
#include "ouvrier.h"
#include <string.h>
#include <gtk/gtk.h>

enum
{NOM,PRENOM,CIN,SEXE,JOUR1,MOIS1,ANNEE1,JOUR2,MOIS2,ANNEE2,Num_de_telephone,ADRESSE,COLUMNS};


void ajouter(ouvrier o)
{
FILE *f;
f=fopen("ouvriers.txt","a+");
if(f!=NULL)
{
fprintf(f,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",o.nom,o.prenom,o.cin,o.sexe,o.date_de_recrutement.jour,o.date_de_recrutement.mois,o.date_de_recrutement.annee,o.date_de_naissance.jour,o.date_de_naissance.mois,o.date_de_naissance.annee,o.num_de_telephone,o.adresse);
}
fclose(f);
}

void modifier(ouvrier O,char cin[30])
{
FILE *f1;
FILE *f2;
ouvrier o;

f1=fopen("ouvriers.txt","r");
f2=fopen("ouvriers1.txt","a+");
if ((f1!=NULL) && (f2!=NULL))
{
while(fscanf(f1,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",o.nom,o.prenom,o.cin,o.sexe,&o.date_de_recrutement.jour,&o.date_de_recrutement.mois,&o.date_de_recrutement.annee,&o.date_de_naissance.jour,&o.date_de_naissance.mois,&o.date_de_naissance.annee,o.num_de_telephone,o.adresse)!=EOF)
{
if(strcmp (o.cin , cin )!=0)
{
fprintf(f2,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",o.nom,o.prenom,o.cin,o.sexe,o.date_de_recrutement.jour,o.date_de_recrutement.mois,o.date_de_recrutement.annee,o.date_de_naissance.jour,o.date_de_naissance.mois,o.date_de_naissance.annee,o.num_de_telephone,o.adresse);
}
else
{
//ajouter(o);
fprintf(f2,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",O.nom,O.prenom,O.cin,O.sexe,O.date_de_recrutement.jour,O.date_de_recrutement.mois,O.date_de_recrutement.annee,O.date_de_naissance.jour,O.date_de_naissance.mois,O.date_de_naissance.annee,O.num_de_telephone,O.adresse);
}
}
fclose(f1);
fclose(f2);
remove("ouvriers.txt");
rename("ouvriers1.txt","ouvriers.txt");
}
}

void supprimer(ouvrier o,char cin[30])
{
FILE *f1;
FILE *f2;

f1=fopen("ouvriers.txt","r");
f2=fopen("ouvriers1.txt","a+");
if ((f1!=NULL) && (f2!=NULL))
{
while(fscanf(f1,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",o.nom,o.prenom,o.cin,o.sexe,&o.date_de_recrutement.jour,&o.date_de_recrutement.mois,&o.date_de_recrutement.annee,&o.date_de_naissance.jour,&o.date_de_naissance.mois,&o.date_de_naissance.annee,o.num_de_telephone,o.adresse)!=EOF)
{
if (strcmp (o.cin , cin )!=0)
{
fprintf(f2,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",o.nom,o.prenom,o.cin,o.sexe,o.date_de_recrutement.jour,o.date_de_recrutement.mois,o.date_de_recrutement.annee,o.date_de_naissance.jour,o.date_de_naissance.mois,o.date_de_naissance.annee,o.num_de_telephone,o.adresse);
}
}
fclose(f1);
fclose(f2);
remove("ouvriers.txt");
rename("ouvriers1.txt","ouvriers.txt");
}
}
void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[30];
char prenom[30];
int jour1;
int mois1;
int annee1;
int jour2;
int mois2;
int annee2;
char adresse[30];
char cin[30];
char num_de_telephone[30]; 
char sexe[30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour1",renderer,"text",JOUR1, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois1",renderer,"text",MOIS1, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee1",renderer,"text",ANNEE1, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour2",renderer,"text",JOUR2, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois2",renderer,"text",MOIS2, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee2",renderer,"text",ANNEE2, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("num_de_telephone",renderer,"text",Num_de_telephone, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
f= fopen("ouvriers.txt","r");
if(f==NULL)
{
return;
}
else
{f=fopen("ouvriers.txt","a+");
	while(fscanf(f,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",nom,prenom,cin,sexe,&jour1,&mois1,&annee1,&jour2,&mois2,&annee2,num_de_telephone,adresse)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set (store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,SEXE,sexe,JOUR1,jour1,MOIS1,mois1,ANNEE1,annee1,JOUR2,jour2,MOIS2,mois2,ANNEE2,annee2,Num_de_telephone,num_de_telephone,ADRESSE,adresse, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
void chercher(GtkWidget *liste,char cin[30])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
ouvrier o;
 
  store=NULL;

FILE *f;
store= gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour1",renderer,"text",JOUR1, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois1",renderer,"text",MOIS1, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee1",renderer,"text",ANNEE1, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour2",renderer,"text",JOUR2, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois2",renderer,"text",MOIS2, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee2",renderer,"text",ANNEE2, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);



renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("num_de_telephone",renderer,"text",Num_de_telephone, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);


}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
f= fopen("ouvriers.txt","r");
if(f==NULL)
{
return;
}
else
{f=fopen("ouvriers.txt","a+");
	while(fscanf(f,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",o.nom,o.prenom,o.cin,o.sexe,&o.date_de_recrutement.jour,&o.date_de_recrutement.mois,&o.date_de_recrutement.annee,&o.date_de_naissance.jour,&o.date_de_naissance.mois,&o.date_de_naissance.annee,o.num_de_telephone,o.adresse)!=EOF)
{
if (strcmp(o.cin,cin)==0)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set (store,&iter,NOM,o.nom,PRENOM,o.prenom,CIN,o.cin,SEXE,o.sexe,JOUR1,o.date_de_recrutement.jour,MOIS1,o.date_de_recrutement.mois,ANNEE1,o.date_de_recrutement.annee,JOUR2,o.date_de_naissance.jour,MOIS2,o.date_de_naissance.mois,ANNEE2,o.date_de_naissance.annee,Num_de_telephone,o.num_de_telephone,ADRESSE,o.adresse, -1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

int verif(char cin[30])
{
ouvrier o;
FILE *f;
f=fopen("ouvriers.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",o.nom,o.prenom,o.cin,o.sexe,&o.date_de_recrutement.jour,&o.date_de_recrutement.mois,&o.date_de_recrutement.annee,&o.date_de_naissance.jour,&o.date_de_naissance.mois,&o.date_de_naissance.annee,o.num_de_telephone,o.adresse)!=EOF)
{
if (strcmp(o.cin,cin)==0)
{
return (1);
}
}
}
}
void meilleur_ouvrier (int annee,char ch[30])
{
    FILE *f;
    FILE *f1;
    ouvrier o;
    meill v;

    int n=0,i=0,frequence=1,j,compteur;/*b=0,c1=0,i=0,a=0*/
    char tabid[200][10];
    char tabm[200][10];
    
    f=fopen("absenteisme.txt","r+");
    if(f!=NULL)
    {

        while( fscanf(f,"%s %d %d %d %d",v.id,&v.jour1,&v.mois1,&v.annee1,&v.valeur)!=EOF)
         if (v.annee1==annee)
            if (v.valeur==1)
            {
                strcpy(tabid[i],v.id);
                n++;
                i++;
            }

        fclose(f);
    }
    for(i=0; i<n; i++)
    {
        printf("%s \t",tabid[i]);

    }
    printf("%d \n",n);

    f1=fopen("ouvriers.txt","r+");

    if(f!=NULL)
    {

        while( fscanf(f1,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",o.nom,o.prenom,o.cin,o.sexe,&o.date_de_recrutement.jour,
                      &o.date_de_recrutement.mois,&o.date_de_recrutement.annee,&o.date_de_naissance.jour,&o.date_de_naissance.mois,&o.date_de_naissance.annee,o.num_de_telephone,o.adresse)!=EOF)
            for(i=0; i<n; i++)
                if(strcmp(tabid[i],o.cin)==0)
                {
                    strcpy(tabm[i],o.nom);
                }
    }
    fclose(f1);
    for(i=0; i<n; i++)
    {
        printf("%s \t",tabm[i]);

    }
    printf("\n");

    for (i=0; i < n; i++)
    {
        compteur = 0 ;
        for (j = 0 ; j < n; j++)
        {
            if ( strcmp(tabm [i] , tabm [j])==0)
            {
                compteur ++ ;
            }
        }
        if  (compteur >frequence)
        {
            frequence = compteur ;
            strcpy(ch,tabm[i]);
        }
      
    }
    
}
void ajouter_ouvrier(meill v)
{
FILE *f;
f=fopen("absenteisme.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %d %d %d %d \n",v.id,v.jour1,v.mois1,v.annee1,v.valeur);}
fclose(f);
}
int nombre_ouvrier()
{
ouvrier o;
int nombre=0;
FILE* f1 ;
f1 = fopen("ouvriers.txt", "r");
   if (f1 != NULL)
{while (fscanf(f1,"%20s%20s%20s%20s %d/%d/%d %d/%d/%d %20s%20s \n",o.nom,o.prenom,o.cin,o.sexe,&o.date_de_recrutement.jour,
                      &o.date_de_recrutement.mois,&o.date_de_recrutement.annee,&o.date_de_naissance.jour,&o.date_de_naissance.mois,&o.date_de_naissance.annee,o.num_de_telephone,o.adresse)!=EOF)


 nombre++;
fclose(f1);
}
return(nombre);

}




float taux_absentisme(int mois,int annee)
{

float taux;
meill v;
int a=0,total;
FILE* f;
f = fopen("absenteisme.txt", "r");
if (f != NULL)
{

while (fscanf(f,"%s %d %d  %d %d \n",v.id,&v.jour1,&v.mois1,&v.annee1,&v.valeur)!=EOF)


if ((v.mois1==mois)&&(v.annee1==annee)&&(v.valeur==0))


a++;
total=nombre_ouvrier();

taux=(float)(a*100)/(total*30);

fclose(f);
}
printf("%d",a);
printf("%d",total);
return(taux) ;

}

