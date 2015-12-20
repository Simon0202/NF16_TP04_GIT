//
//  tp4.h
//  TP4
//
//  Created by Alex Ballet on 03/12/2015.
//  Copyright © 2015 Alex Ballet. All rights reserved.
//

#ifndef tp4_h
#define tp4_h

//constantes
#define MAX 50

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
Noeud* recherche_rec(int n, Noeud* root);
Noeud* recherche(int n, Noeud* root);
int hauteur(Noeud* root);
int max(int a, int b);
int somme(Noeud* root);
void afficherDecroissant(Noeud *root);
void afficherStructure(Noeud *root);
void supprimer(int n, Noeud *root);
Noeud *minSousAbre(Noeud *root);
Noeud *maxSousAbre(Noeud *noeud);
Noeud *pere(Noeud *fils, Noeud *root);
void detruire (Noeud *root);
void trierTableau(int *tab, int tailleTab);
Noeud* construire (int Tab[MAX], int indiceDebut, int indiceFin, Noeud* root);

#endif /* tp4_h */
