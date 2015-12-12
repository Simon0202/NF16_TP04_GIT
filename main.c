//
//  main.c
//  TP4
//
//  Created by Alex Ballet on 03/12/2015.
//  Copyright © 2015 Alex Ballet. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main()
{

    
/*****************************
****TEST SUR LES FONCTIONS****
******************************

 Noeud* suivant = insererNoeud_rec(60,root);
 Noeud* suivant2 = insererNoeud_rec(10,root);
 Noeud* suivant3 = insererNoeud_rec(5,root);
 Noeud* suivant4 = insererNoeud_rec(20,root);
 Noeud* suivant5 = insererNoeud_rec(35,root);
 Noeud* suivant6 = insererNoeud_rec(65,root);
 Noeud* suivant7 = insererNoeud_rec(15,root);
<<<<<<< HEAD
    Noeud* suivant8 = insererNoeud_rec(45,root);
    
=======
    Noeud* suivant8 = insererNoeud_rec(45,root);

 
>>>>>>> e4f89f9a5bdb42ab84756e6465fb733103e60c83
    printf("La racine de l'arbre est : %d\n",root->cle);
    printf("La le fils droit de la racine de l'arbre est : %d\n",root->droit->cle);
    
    if(verifier(root)==1)
        printf("L'arbre de racine %d est un ABR\n", root->cle);
    else
        printf("L'arbre de racine %d n'est pas un ABR\n", root->cle);
    
    Noeud* trouve = recherche_rec(60, root);
    
    if(trouve)
        printf("Le noeud de clé %d a été trouvé\n", trouve->cle);
    else
        printf("Noeud introuvable\n");
    
    printf("La hauteur de l'arbre de racine %d est %d\n", root->cle, hauteur(root));
    printf("La somme des cles des noeuds de l'arbre de racine %d est %d\n", root->cle, somme(root));
    
    printf("\n\n**DECROISSANT**\n\n");
    afficherDecroissant(root);
    
    printf("\n\n**ABR**\n\n");
    afficherStructure(root);
    
    afficherStructure(minSousAbre(root));
    
    //test sur la fonction supprimer
    //supprimer(65, root);
    //afficherDecroissant(root);
    
    //detruire(root);

****************
FIN DES TEST****
***************/
    
    
    
/***********************************
****Creation du menu utilisateur****
***********************************/
    
    //D'apres le sujet il semble que nous choisissons la racine
    Noeud* root = insererNoeud_rec(25,NULL);
    
    Noeud* trouve = malloc(sizeof(Noeud));
    Noeud* root2 = malloc(sizeof(Noeud));
    
    int Tab[MAX];
    
    int choix, arret = 1, valeur, i;
    printf("\t\t****BONJOUR****\n\n");
    while (arret == 1)
    {
        printf("VEUILLEZ CHOISIR L ACTION A EFFECTUER :\n\n");
        printf("\t1] Pour inserer un noeud\n");
        printf("\t2] Pour inserer un noeud recursivement\n");
        printf("\t3] Pour verifier que nous avons un abre binaire de recherche\n");
        printf("\t4] Pour rechercher un noeud\n");
        printf("\t5] Pour rechercher un noeud recursivement\n");
        printf("\t6] Pour obtenir la hauteur de l'abre\n");
        printf("\t7] Pour obtenir la somme des valeurs de noeuds\n");
        printf("\t8] Pour afficher les noeud de façon décroissant\n");
        printf("\t9] Pour afficher la structure de l'arbre\n");
        printf("\t10] Pour supprimer un noeud\n");
        printf("\t11] Pour detruire l'arbre\n");
        printf("\t12] BONUS : Pour construire un ABR équilibré\n");
        printf("\t13] Pour quitter\n");
        printf("\nSAISIR L ACTION \n");
        //On suppose que l'utilisateur entre un choix ci dessus
        scanf("%d",&choix);
        switch (choix)
        {
            case 1:
                printf("Veuillez entrer la valeur à choisir : \n");
                scanf("%d",&valeur);
                insererNoeud(valeur,root);
                break;
            
            case 2:
                printf("Veuillez entrer la valeur à choisir : \n");
                scanf("%d",&valeur);
                insererNoeud_rec(valeur,root);
                break;
            
            case 3:
                if(verifier(root)==1)
                    printf("L'arbre de racine %d est un ABR\n", root->cle);
                else
                    printf("L'arbre de racine %d n'est pas un ABR\n", root->cle);
                break;
            
            case 4:
                printf("Veuillez entrer la valeur à rechercher : \n");
                scanf("%d",&valeur);
                
                trouve = recherche(valeur, root);
                
                if(trouve)
                    printf("Le noeud de clé %d a été trouvé\n", trouve->cle);
                else
                    printf("Noeud introuvable\n");
                
                break;

            
            case 5:
                printf("Veuillez entrer la valeur à rechercher recursivement : \n");
                scanf("%d",&valeur);
                
                trouve = recherche_rec(valeur, root);
                
                if(trouve)
                    printf("Le noeud de clé %d a été trouvé\n", trouve->cle);
                else
                    printf("Noeud introuvable\n");

                break;
            
            case 6:
                printf("La hauteur de l'arbre de racine %d est %d\n", root->cle, hauteur(root));
                break;
            
            case 7:
                printf("La somme des cles des noeuds de l'arbre de racine %d est %d\n", root->cle, somme(root));
                break;
            
            case 8:
                afficherDecroissant(root);
                break;
            
            case 9:
                afficherStructure(root);
                break;
            
            case 10:
                printf("Veuillez entrer la valeur à supprimer : \n");
                scanf("%d",&valeur);
                supprimer(valeur,root);
                
                //si le noeud à supprimer était la racine, on change la racine
//                if(root->cle==valeur)
//                    if(root->droit)
//                        root=root->droit;
////                    else
////                        root=root->gauche;
                
                break;
            
            case 11:
                detruire(root);
                arret = 0;
                break;
                
            case 12:
                printf("Veuillez entrer le nombre de valeurs de l'arbre à créer : ");
                scanf("%d", &valeur);
                
                for (i=0; i<valeur; i++)
                {
                    printf("Entrer la valeur %d : \n", i);
                    scanf("%d", &Tab[i]);
                }
                
                trierTableau(Tab, valeur);
                
                root2 = insererNoeud_rec(Tab[(valeur/2)], NULL);
                
                construire(Tab, 0, valeur-1, root2);
                
                afficherStructure(root2);
                
                break;
                
            case 13:
                arret = 0;
                break;
            
            default:
                arret = 0;
                break;
        }
    }

    return 0;
}
