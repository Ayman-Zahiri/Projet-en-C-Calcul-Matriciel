#include <stdio.h>
#include <stdlib.h>


typedef struct  Smat {
  int i ;// lignes
  int j ;// collones
  int coeff ; //elle contient la valeur reelle non nul
  struct Smat * next ;
}Smat;


 Smat * creeelement(int ligne , int colone , int value ) {
    Smat * newnode= (Smat*) malloc(sizeof(Smat));
    newnode->i=ligne;
    newnode->j=colone;
    newnode->coeff=value ;
    newnode->next=NULL;
    return newnode;
 }


 Smat * creematrice_identite (int taille ){
     if (taille<=0) return NULL;
     Smat * tete= NULL;
        Smat* courant = tete ;



      int i ;// pour parcourir la boucle
      for (i= 0;i<taille ; i++){
        Smat * nouveau =creeelement(i,i,1);
          if (tete ==NULL) {
            tete = nouveau;
            courant = tete ;
          }
          else {
        courant ->next=nouveau ;
        courant = nouveau ;}

      }
      return tete ;
 }
void affiche_matric(Smat*head , int n ){

    int c ;//copteur//
    int k , g ;

        for ( k = 0; k<n ; k++){
            for (g=0 ; g<n ; g++ ) {
                c = 0;
                Smat*courant = head ;//parcourir la liste chainee pour qu'on perde pas la tete
                while (courant!=NULL){
                    if ((courant->i==k) && (courant->j==g) ) {
                    printf("%d",courant->coeff);
                    c=1;
                    break ;
                }
                courant=courant->next;
            }

        if (!c){
            printf("0");
        }

        }
        printf("\n");
        }


    }










void affiche_matrice(Smat*head , int n ){

    int c ;//compteur//
    int k , g ;

        for ( k = 0; k<n ; k++){
            for (g=0 ; g<n ; g++ ) {
                c = 0;
                Smat*courant = head ;//parcourir la liste chainee pour qu'on perde pas la tete
                while (courant!=NULL){
                    if ((courant->i==k) && (courant->j==g) ) {
                    printf("%d      ",courant->coeff);
                    c=1;
                    break ;
                }
                courant=courant->next;
            }

        if (!c){
            printf("0");
        }

        }
        printf("\n");
        }


    }




void ajouter_element (Smat**tete , int ligne , int colonne , int value ){
 Smat * newnoud = creeelement(ligne , colonne , value );
  newnoud->next= *tete ;
  *tete = newnoud ;



}


Smat * additionner_matrice (Smat * A , Smat*B ){
    Smat* nouv_matriice=NULL;
    Smat*mat1= A ;
    Smat*mat2=B;
    int somme ;

  while (mat1!=NULL && mat2!=NULL){
    if (mat1->i == mat2->i && mat1->j == mat2->j){
        somme = mat1->coeff + mat2->coeff ;
        ajouter_element(&nouv_matriice,mat1->i,mat2->j,somme);
    }

    mat1=mat1->next;
    mat2=mat2->next;

  }
return nouv_matriice ;
}

Smat * transformer(float Mat[10][10],int taille){
    Smat * head = NULL;
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            if(Mat[i][j]!=0)
                ajouter_element(&head,i,j,Mat[i][j]);
        }
    }
    return head;
}
void afficher_creuse(Smat* head) {
    Smat* temp = head;
    while (temp != NULL) {
        printf("(%d, %d) = %d\n", temp->i, temp->j, temp->coeff);
        temp = temp->next;
    }
}








int main() {
    int choix;
    do {
        printf("===== MENU =====\n");
        printf("1. Creer matrice identite\n");
        printf("2. Additionner deux matrices creuses\n");
        printf("3. Transformer une matrice dense en creuse\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            int n;
            printf("Taille de la matrice identite : ");
            scanf("%d", &n);
            Smat* identite = creematrice_identite(n);
            printf("Matrice identite :\n");
            affiche_matric(identite, n);

        } else if (choix == 2) {
            int n, value;

            printf("Donner la taille des matrices carrees : ");
            scanf("%d", &n);

            Smat* matrice1 = NULL;
            Smat* matrice2 = NULL;

            printf("Saisie matrice 1 :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("Element [%d][%d] = ", i, j);
                    scanf("%d", &value);
                    if (value != 0)
                        ajouter_element(&matrice1, i, j, value);
                }
            }

            printf("Saisie matrice 2 :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("Element [%d][%d] = ", i, j);
                    scanf("%d", &value);
                    if (value != 0)
                        ajouter_element(&matrice2, i, j, value);
                }
            }

            printf("\nMatrice 1 :\n");
            affiche_matric(matrice1, n);

            printf("\nMatrice 2 :\n");
            affiche_matric(matrice2, n);

            Smat* somme = additionner_matrice(matrice1, matrice2);

            printf("\nSomme des matrices :\n");
            affiche_matric(somme, n);

        } else if (choix == 3) {
            int n;
            printf("Taille de la matrice (max 10) : ");
            scanf("%d", &n);

            float Mat[10][10];
            printf("Saisir les elements de la matrice :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("Mat[%d][%d] = ", i, j);
                    scanf("%f", &Mat[i][j]);
                }
            }

            Smat* creuse = transformer(Mat, n);
            printf("Matrice creuse (liste chainee) :\n");
            afficher_creuse(creuse);
        }

    } while (choix != 0);

    return 0;
}
