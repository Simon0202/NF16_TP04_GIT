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

int main(int argc, const char * argv[])
{
    Noeud* root = insererNoeud_rec(25,NULL);
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
    
    printf("\n\n**ARB**\n\n");
    afficherStructure(root);
    
    return 0;
}
