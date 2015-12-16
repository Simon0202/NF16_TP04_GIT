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
    int arret = 1;
    
    while (arret == 1)
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
     Noeud* suivant8 = insererNoeud_rec(45,root);
     
     
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
    
    Noeud* trouve = malloc(sizeof(Noeud));
    Noeud* root2 = malloc(sizeof(Noeud));
    
    int Tab[MAX];
    
    int choix, continuer=1,valeur, i;
    printf("\t\t****BONJOUR****\nBienvenue dans notre programme de gestion d'ABR\nVeuillez entrer la racine de votre arbre : \n");
    scanf("%d", &valeur);
    
    Noeud* root = insererNoeud_rec(valeur,NULL);
    
    if(root)
        printf("Vous venez de créer un arbre de racine %d.\n", root->cle);
    else
        printf("Erreur dans l'ajout du noeud.\n");

    while(continuer)
    {
        printf("APPUYEZ SUR UNE TOUCHE POUR CONTINUER...");
        getchar();
        getchar();
        printf("\n\nVEUILLEZ CHOISIR L ACTION A EFFECTUER :\n\n");
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
        printf("\nCHOIX : ");
        //On suppose que l'utilisateur entre un choix ci dessus
        scanf("%d",&choix);
        switch (choix)
        {
            case 1:
                printf("Veuillez entrer la valeur à choisir : \n");
                scanf("%d",&valeur);
                trouve = insererNoeud(valeur,root);
                if(trouve)
                    printf("Vous venez d'ajouter le noeud de clé %d.\n", trouve->cle);
                else
                    printf("Erreur dans l'ajout du noeud.\n");
                
                break;
                
            case 2:
                printf("Veuillez entrer la valeur à choisir : \n");
                scanf("%d",&valeur);
                trouve = insererNoeud_rec(valeur,root);
                if(trouve)
                    printf("Vous venez d'ajouter le noeud de clé %d.\n", trouve->cle);
                else
                    printf("Erreur dans l'ajout du noeud.\n");
                
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
                break;
                
            case 11:
                valeur = root->cle;
                detruire(root);
                printf("Vous venez de détruire l'ABR de racine %d\n", valeur);
                printf("Vous allez être redirigé vers la saisie de la racine de l'arbre !\n");
                printf("APPUYEZ SUR UNE TOUCHE POUR CONTINUER...");
                getchar();
                getchar();
                continuer = 0;
                break;
                
            case 12:
                printf("Veuillez entrer le nombre de valeurs de l'arbre à créer : ");
                scanf("%d", &valeur);
                
                for (i=0; i<valeur; i++)//on remplie le tableau des valeurs de l'AVL
                {
                    printf("Entrer la valeur %d : \n", i);
                    scanf("%d", &Tab[i]);
                }
                
                trierTableau(Tab, valeur);//On trie le tableau dans l'ordre croissant
                
                root2 = insererNoeud_rec(Tab[(valeur/2)], NULL);
                
                construire(Tab, 0, valeur-1, root2);
                
                printf("\nVoici la structure de votre AVL de racine %d :\n", root2->cle);
                afficherStructure(root2);
                break;
                
            case 13:
                valeur = root->cle;
                detruire(root);
                printf("Vous venez de détruire l'ABR de racine %d\n", valeur);
                printf("APPUYEZ SUR UNE TOUCHE POUR QUITTER...");
                getchar();
                getchar();
                continuer = 0;
                arret = 0;
                break;
                
            default:
                printf("Choix inconnu\n");
                break;
        }
    }
    }
    return 0;
}
