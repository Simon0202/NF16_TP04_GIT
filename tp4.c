//
//  tp4.c
//  TP4
//
//  Created by Alex Ballet on 03/12/2015.
//  Copyright © 2015 Alex Ballet. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

//fonctions complémentaires
int max(int a, int b)
{
    if (a<b)
        return b;
    
    return a;
}

//fonctions principales

//Fonction itérative d'insertion d'un noeud dans l'ABR
Noeud* insererNoeud(int n, Noeud *root)
{
    Noeud* newNoeud = malloc(sizeof(Noeud)); //on initialise le noeud
    Noeud* ptrNoeud = root;
    
    newNoeud->cle=n;
    newNoeud->gauche=NULL;
    newNoeud->droit=NULL;
    
    if(!root)//s'il n'y a pas de noeud dans l'ABR, on ajoute le noeud à la racine
    {
        root=newNoeud;
        return root;
    }
    
    while (1)//on continue tant qu'on a pas ajouté le noeud
    {
        if(ptrNoeud->cle<n)
            if(ptrNoeud->droit)
                ptrNoeud = ptrNoeud->droit;
            else
            {
                ptrNoeud->droit = newNoeud;
                return newNoeud;
            }
            else if(ptrNoeud->cle>n)
                if(ptrNoeud->gauche)
                    ptrNoeud = ptrNoeud->gauche;
                else
                {
                    ptrNoeud->gauche = newNoeud;
                    return newNoeud;
                }
                else
                    return NULL;
    }
}

//Fonction récursive d'insertion d'un noeud dans l'ABR
Noeud* insererNoeud_rec(int n, Noeud *root)
{
    
    if(!root)//s'il n'y a pas de noeuds dans l'arbre on l'ajoute à la racine
    {
        Noeud* newNoeud = malloc(sizeof(Noeud));
        newNoeud->cle=n;
        newNoeud->gauche=NULL;
        newNoeud->droit=NULL;
        root = newNoeud;
        return root;
    }
    else if(root->cle>n)
    {
        if(root->gauche)
            return insererNoeud_rec(n, root->gauche);//on insère dans le sous arbre gauche
        else
        {
            Noeud* newNoeud = malloc(sizeof(Noeud));
            newNoeud->cle=n;
            newNoeud->gauche=NULL;
            newNoeud->droit=NULL;
            root->gauche = newNoeud;
            return newNoeud;
        }
    }
    else if(root->cle<n)
    {
        if(root->droit)
            return insererNoeud_rec(n, root->droit);//on insere dans le sous arbre droit
        else
        {
            Noeud* newNoeud = malloc(sizeof(Noeud));
            newNoeud->cle=n;
            newNoeud->gauche=NULL;
            newNoeud->droit=NULL;
            root->droit = newNoeud;
            return newNoeud;
        }
    }
    else// si le noeud existe déjà on ne l'insere pas
        return NULL;
}

int verifier(Noeud* root)
{
    if(root->gauche)
    {
        if(root->gauche->cle<=root->cle)
            verifier(root->gauche);
        else
            return 0;
    }
    
    if(root->droit)
    {
        if(root->droit->cle>=root->cle)
            verifier(root->droit);
        else
            return 0;
    }
    
    return 1;
}

Noeud* recherche_rec(int n, Noeud* root)
{
    if(root->cle<n)
    {
        if(root->droit)
            recherche(n,root->droit);
        else
            return NULL;
    }
    else if(root->cle>n)
    {
        if(root->gauche)
            recherche(n,root->gauche);
        else
            return NULL;
    }
    else
    {
        return root;
    }
    
    return NULL;
}

Noeud* recherche(int n, Noeud* root)
{
    Noeud* ptrNoeud = root;
    
    while (ptrNoeud)
    {
        if (ptrNoeud->cle==n)
        {
            return ptrNoeud;
        }
        else if (ptrNoeud->cle<n)
        {
            ptrNoeud = ptrNoeud->droit;
        }
        else
            ptrNoeud = ptrNoeud->gauche;
    }
    
    return NULL;
}

int hauteur(Noeud* root)
{
    Noeud* ptrNoeud = root;
    
    if (ptrNoeud->gauche && !ptrNoeud->droit)
    {
        return 1+hauteur(ptrNoeud->gauche);
    }
    else if(ptrNoeud->droit && !ptrNoeud->gauche)
    {
        return 1+hauteur(ptrNoeud->droit);
    }
    else if (ptrNoeud->droit && ptrNoeud->gauche)
    {
        return 1+max(hauteur(ptrNoeud->gauche), hauteur(ptrNoeud->droit));
    }
    else
        return 0;
}

int somme(Noeud* root)
{
    Noeud* ptrNoeud = root;
    
    if (ptrNoeud->gauche && !ptrNoeud->droit)
    {
        return ptrNoeud->cle+somme(ptrNoeud->gauche);
    }
    else if(ptrNoeud->droit && !ptrNoeud->gauche)
    {
        return ptrNoeud->cle+somme(ptrNoeud->droit);
    }
    else if (ptrNoeud->droit && ptrNoeud->gauche)
    {
        return ptrNoeud->cle+somme(ptrNoeud->gauche)+somme(ptrNoeud->droit);
    }
    else
        return ptrNoeud->cle;
}
