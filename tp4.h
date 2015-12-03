//
//  tp4.h
//  TP4
//
//  Created by Alex Ballet on 03/12/2015.
//  Copyright © 2015 Alex Ballet. All rights reserved.
//

#ifndef tp4_h
#define tp4_h

//structures
typedef struct Noeud
{
    int cle;
    struct Noeud* gauche;
    struct Noeud* droit;
} Noeud;


//prototypes

Noeud* insererNoeud(int n, Noeud *root);
Noeud* insererNoeud_rec(int n, Noeud *root);
int verifier(Noeud* root);
Noeud* recherche(int n, Noeud* root);



#endif /* tp4_h */
