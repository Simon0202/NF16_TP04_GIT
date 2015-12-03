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

Noeud* insererNoeud(int n, Noeud *root)
{
    Noeud* newNoeud = malloc(sizeof(Noeud));
    Noeud* ptrNoeud = root;
    
    newNoeud->cle=n;
    newNoeud->gauche=NULL;
    newNoeud->droit=NULL;
    
    if(!root)
    {
        root=newNoeud;
        return root;
    }
    
    while (1)
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

Noeud* insererNoeud_rec(int n, Noeud *root)
{
    
    if(root->cle<n)
    {
        if(root->droit)
            return insererNoeud_rec(n, root->droit);
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
    else if(root->cle>n)
    {
        if(root->gauche)
            return insererNoeud_rec(n, root->gauche);
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
    else
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
