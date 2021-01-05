#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include <string.h>
#include <gtk/gtk.h>

enum
 {
NOM,
PRENOM,
SEXE,
EMAIL,
TELEPHONE,
TYPE,
id,
COLUMNS
};

void ajouter_client(client c)
{
FILE *f;
f=fopen("client.txt","a+");
if(f!=NULL)
{
fprintf(f,"%20s%20s%20s%20s%20s%20s%20s\n",c.Nom,c.Prenom,c.Sexe,c.Email,c.Telephone,c.Type,c.ID); 
}
fclose(f);
}



void modifier_client(client C,char ID[20])
{
FILE *f1;
FILE *f2;
client c;

f1=fopen("client.txt","r");
f2=fopen("client1.txt","a+");

if ((f1!=NULL) && (f2!=NULL))
{
while(fscanf(f1,"%20s%20s%20s%20s%20s%20s%20s\n",c.Nom,c.Prenom,c.Sexe,c.Email,c.Telephone,c.Type,c.ID)!=EOF) 
{
if( strcmp(c.ID,ID)!=0)
{
fprintf(f2,"%20s%20s%20s%20s%20s%20s%20s\n",c.Nom,c.Prenom,c.Sexe,c.Email,c.Telephone,c.Type,c.ID); 
}

else
{

fprintf(f2,"%20s%20s%20s%20s%20s%20s%20s\n",C.Nom,C.Prenom,C.Sexe,C.Email,C.Telephone,C.Type,C.ID); 
}

}
fclose(f1);
fclose(f2);
remove("client.txt");
rename("client1.txt","client.txt");
}
}

void supprimer_client(client c,char ID[20])
{
FILE *f1;
FILE *f2;

f1=fopen("client.txt","r");
f2=fopen("client1.txt","a+");
if ((f1!=NULL) && (f2!=NULL))
{
while(fscanf(f1,"%20s%20s%20s%20s%20s%20s%20s\n",c.Nom,c.Prenom,c.Sexe,c.Email,c.Telephone,c.Type,c.ID)!=EOF) 
{
if ( strcmp(c.ID,ID)!=0)


{
fprintf(f2,"%20s%20s%20s%20s%20s%20s%20s\n",c.Nom,c.Prenom,c.Sexe,c.Email,c.Telephone,c.Type,c.ID);
}
}
fclose(f1);
fclose(f2);
remove("client.txt");
rename("client1.txt","client.txt");
}
else 
{return;}
}


void afficher_client(GtkWidget *liste)
{
GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter     iter;


GtkListStore *store;

char Nom[20];
char Prenom[20];
char Sexe[20];
char Email[20];
char Telephone[20];
char Type[20];
char ID[20]; 
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Nom", renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Sexe" ,renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	  
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Email",renderer, "text",EMAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Telephone", renderer,"text",TELEPHONE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("ID", renderer,"text",id,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("client.txt","r");

if(f==NULL)
{  

return;
}

else
{f =fopen("client.txt","a+");
	while(fscanf(f,"%20s %20s %20s %20s %20s %20s %20s \n",Nom,Prenom,Sexe,Email,Telephone,Type,ID)!=EOF)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter , NOM, Nom, PRENOM, Prenom ,SEXE, Sexe, EMAIL, Email, TELEPHONE, Telephone, TYPE, Type, id, ID, -1);
}
	fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}


void chercher_client (GtkWidget *liste,char ID[20])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
client c;
 
  store=NULL;

FILE *f;
store= gtk_tree_view_get_model(liste);


if (store==NULL)
{
        renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Nom", renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Sexe" ,renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	  
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Email",renderer, "text",EMAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Telephone", renderer,"text",TELEPHONE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("ID", renderer,"text",id,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("client.txt","r");

if(f==NULL)
{  

return;
}

else
{f =fopen("client.txt","a+");
	while(fscanf(f,"%20s %20s %20s %20s %20s %20s %20s \n",c.Nom,c.Prenom,c.Sexe,c.Email,c.Telephone,c.Type,c.ID)!=EOF)
{
if (strcmp(c.ID,ID)==0)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter , NOM, c.Nom, PRENOM, c.Prenom ,SEXE, c.Sexe, EMAIL, c.Email, TELEPHONE, c.Telephone, TYPE, c.Type, id, c.ID, -1);

}
}
	fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}


int verif(char ID[20])
{
client c;
FILE *f;
f=fopen("client.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%20s %20s %20s %20s %20s %20s %20s \n",c.Nom,c.Prenom,c.Sexe,c.Email,c.Telephone,c.Type,c.ID)!=EOF)

{
if (strcmp(c.ID,ID)==0)
{
return (1);
}
}
}
}

void ajouter_capteur(def v)
{
FILE *f2;

f2=fopen("valeur.txt","a+");
if(f2!=NULL)
{
fprintf(f2,"%s %d %d %d %f",v.id,v.jour,v.mois,v.annee,v.valeur); 
}
fclose(f2);
}






void defectueux (char ch[30])
{
    FILE *f;
    FILE *f1;
    capteur c;

    int n=0,b=0,c1=0,i=0,a=0;
    def v;
    char tabid[200][10];
    char tabm[200][10];

    f=fopen("valeur.txt","r+");
    if(f!=NULL)
    {

          while( fscanf(f,"%s %d %d %d %f",v.id,&v.jour,&v.mois,&v.annee,&v.valeur)!=EOF)
            if (v.valeur>100.00)
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

f1=fopen("capteur.txt","r+");

if(f!=NULL)
    {

          while( fscanf(f1,"%s %s %s \n",c.ref,c.type,c.marque)!=EOF)
            for(i=0;i<n;i++)
             if(strcmp(tabid[i],c.ref)==0)
          {
               strcpy(tabm[i],c.marque);
          }
}
fclose(f1);
for(i=0; i<n; i++)
    {
        printf("%s \t",tabm[i]);

    }
    printf("\n");

for(i=0; i<n; i++)
{
    if(strcmp(tabm[i],"OMEGA")==0)
        a++;
    else if (strcmp(tabm[i],"THERMIBEL")==0)
        b++;
    else c1++;
}
printf("%d",a);
printf("%d",b);
printf("%d \n",c1);

if(a>=b && a>=c1)
    strcpy(ch,"OMEGA");
    //printf("la marque est :OMEGA \n");
if(b>=a && b>=c1)
    strcpy(ch,"THERMIBEL");
    //printf("la marque est :THERMIBEL \n");
if (c1>=a && c1>=b)
    strcpy(ch,"DIMELCO");
    //printf("la marque est :DIMELCO \n");
    //return(ch);
if (a==b)
    strcpy(ch,"OMEGA et THERMIBEL");
if (a==c1)
    strcpy(ch,"OMEGA  et DIMELCO");
if (b==c1)
    strcpy(ch,"THERMIBEL et DIMELCO");

}
	
