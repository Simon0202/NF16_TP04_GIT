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
    Noeud* root = insererNoeud(25,NULL);
    Noeud* suivant = insererNoeud_rec(60,root);
    Noeud* suivant2 = insererNoeud_rec(10,root);
    Noeud* suivant3 = insererNoeud_rec(5,root);
    Noeud* suivant4 = insererNoeud_rec(20,root);
    Noeud* suivant5 = insererNoeud_rec(35,root);
    Noeud* suivant6 = insererNoeud_rec(65,root);
    Noeud* suivant7 = insererNoeud_rec(15,root);
    Noeud* suivant8 = insererNoeud_rec(45,root);
    
    
    printf("La racine de l'arbre est : %d\n",root->cle);
//    
//    if(suivant)
//        printf("Le fils droit de la racine est : %d\n",root->droit->cle);
//    else
//        printf("Erreur dans l'ajout de la clé 60\n");
//    
//    printf("Le fils gauche de la racine est : %d\n",root->gauche->cle);
    
    if(verifier(root)==1)
        printf("L'arbre de racine %d est un ABR\n", root->cle);
    else
        printf("L'arbre de racine %d n'est pas un ABR\n", root->cle);
    
    Noeud* trouve = recherche(25, root);
    
    if(trouve)
        printf("Le noeud de clé %d a été trouvé\n", trouve->cle);
    else
        printf("Noeud introuvable\n");
    
    
    
    return 0;
}
