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

//Fonction de calcul du max de deux entiers pour la fonction de calcul de la hauteur de l'ABR

int max(int a,int b)
{
    return (a>b)? a : b ;
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
    }
    else if(root->cle<n)
    {
        if(root->droit)
            return insererNoeud_rec(n, root->droit);//on insere dans le sous arbre droit
    }
    else// si le noeud existe déjà on ne l'insere pas
        return NULL;
    
    //si on arrive ici c'est que l'on doit insérer le noeud
    Noeud* newNoeud = malloc(sizeof(Noeud)); //on initialise le noeud
    newNoeud->cle=n;
    newNoeud->gauche=NULL;
    newNoeud->droit=NULL;
    
    
    if(root->cle>n && !root->gauche)//insertion à gauche
    {
        root->gauche = newNoeud;
    }
    else if(root->cle<n && !root->droit)//insertion à droite
    {
        root->droit = newNoeud;
    }
    
    return newNoeud;//si on atteint ce point le noeud a été ajouté et on le renvoie
    
}


//Fonction qui renvoie 1 si l'arbre est un ABR, 0 sinon
int verifier(Noeud* root)
{
    if(root->gauche)//si il y a un fils gauche on l'analyse
    {
        if(root->gauche->cle<=root->cle)//si la clé du fils gauche est inférieure ou égale à la clé du père on continue à partir du fils gauche
            verifier(root->gauche);
        else
            return 0;//sinon ce n'est pas un ABR
    }
    
    if(root->droit)//si il y a un sous arbre droit on verifie que c'est un ABR
    {
        if(root->droit->cle>=root->cle)//si la clé du fils droit est supérieure ou égale à la clé du père on continue à partir du fils droit
            verifier(root->droit);
        else
            return 0;//sinon ce n'est pas un ABR
    }
    
    return 1;//si on atteint ce point, l'arbre est un ABR
}


//Fonction récursive de recherche d'un noeud dans l'ABR
Noeud* recherche_rec(int n, Noeud* root)
{
    if(root->cle<n && root->droit)//si la clé du noeud est inférieure à n et qu'il y a un fils droit on le compare au fils droit
    {
        return recherche_rec(n,root->droit);
    }
    else if(root->cle>n && root->gauche)//si la clé du noeud est supérieure à n et qu'il y a un fils gauche on le compare au fils gauche
    {
        return recherche_rec(n,root->gauche);
    }
    else if(root->cle==n)//si la clé du noeud est égale à n on a trouvé le noeud et on le renvoie
    {
        return root;
    }
    
    return NULL;//si on atteint ce point c'est qu'on a pas trouvé le noeud donc on renvoie NULL
}



//Fonction intérative de recherche d'un noeud dans l'ABR
Noeud* recherche(int n, Noeud* root)
{
    Noeud* ptrNoeud = root; //initialisation d'un pointeur de noeud
    
    while (ptrNoeud)//on continue tant que le noeud n'est pas NULL
    {
        if (ptrNoeud->cle==n)//si la clé du noeud est égale à n on a trouvé le noeud et on le renvoie
        {
            return ptrNoeud;
        }
        else if (ptrNoeud->cle<n)//si la clé du noeud est inférieure à n et qu'il y a un fils droit on le compare au fils droit
        {
            ptrNoeud = ptrNoeud->droit;
        }
        else//si la clé du noeud est supérieure à n et qu'il y a un fils gauche on le compare au fils gauche
            ptrNoeud = ptrNoeud->gauche;
    }
    
    return NULL;//si on a pas trouvé le noeud on renvoie NULL
}


//Fonction de calcul de la hauteur de l'ABR
int hauteur(Noeud* root)
{
    if (root->gauche && !root->droit)//s'il n'y a que un sous arbre gauche on retourne 1 + la hauteur de celui-ci
    {
        return 1+hauteur(root->gauche);
    }
    else if(root->droit && !root->gauche)//s'il n'y a que un sous arbre droit on retourne 1 + la hauteur de celui-ci
    {
        return 1+hauteur(root->droit);
    }
    else if (root->droit && root->gauche)//s'il y a un sous arbre droit et un sous arbre gauche on retourne 1 + le max de la hauteur de ceux-ci
    {
        return 1+max(hauteur(root->gauche), hauteur(root->droit));
    }
    else//s'il n'y a pas de sous arbres gauche ou droit on renvoie 0
        return 0;
}


//Fonction de calcul de la somme des clés des noeuds de l'ABR
int somme(Noeud* root)
{
    if (root->gauche && !root->droit)//s'il n'y a que un sous arbre gauche on retourne la valeur de la clé du noeud + la somme des clés des noeuds du sous arbre gauche
    {
        return root->cle+somme(root->gauche);
    }
    else if(root->droit && !root->gauche)//s'il n'y a que un sous arbre droit on retourne la valeur de la clé du noeud + la somme des clés des noeuds du sous arbre droit
    {
        return root->cle+somme(root->droit);
    }
    else if (root->droit && root->gauche)//s'il y a  un sous arbre droit et gauche on retourne la valeur de la clé du noeud + la somme des clés des noeuds du sous arbre droit + la somme des clés des noeuds du sous arbre gauche
    {
        return root->cle+somme(root->gauche)+somme(root->droit);
    }
    else//s'il n'y a pas de sous arbres gauche ou droit on renvoie la valeur de la clé du noeud
        return root->cle;
}



//Fontion d'affichage des valeurs de l'ABR par ordre décroissant
void afficherDecroissant(Noeud *root)
{
    //Test s'il existe un sous ABR droit
    if (root->droit != NULL)
        //On rappelle la fonction sous ce sous ABR
        afficherDecroissant(root->droit);
    
    //Il n'y a plus de sous ABR droit, il faut donc afficher la cle
    printf("%d \t", root->cle);
    
    //Test s'il existe un ABR gauche à la cle qui vient d'être affichée
    if (root->gauche != NULL)
        //Si tel est le cas on appelle la fonction sur ce sous ABR gauche
        afficherDecroissant(root->gauche);
    
    
}
