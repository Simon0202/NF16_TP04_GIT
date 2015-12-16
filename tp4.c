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

/********************************
 ****FONCTIONS COMPLEMENTAIRES****
 *********************************/




//Fonction de calcul du max de deux entiers pour la fonction de calcul de la hauteur de l'ABR
int max(int a,int b)
{
    return (a>b)? a : b ;
}



//Retourne le minimum du sous ABR, utile dans la fonction supprimer
Noeud *minSousAbre(Noeud *noeud)
{
    while(noeud->gauche != NULL)
        noeud = noeud->gauche;
    
    return noeud;
}



//Retourne le pere d'un noeud, utilse dans la fonction supprimer
Noeud *pere(Noeud *fils, Noeud *root)
{
    Noeud *ptr = root, *ptr2 = root;
    while (ptr != NULL && ptr != fils)
    {
        if (fils->cle < ptr->cle)
        {
            ptr2 = ptr;
            ptr = ptr->gauche;
        }
        if (fils->cle > ptr->cle)
        {
            ptr2 = ptr;
            ptr = ptr->droit;
        }
    }
    return ptr2;
}

//Fonction de tri d'un tableau d'entier
void trierTableau(int *tab, int tailleTab)
{
    int changement,i;
    
    int tmp;
    
    do
    {
        changement=0;
        
        for (i=0; i<=tailleTab-2; i++)
        {
            if (tab[i]>tab[i+1])
            {
                tmp=tab[i+1];
                tab[i+1]=tab[i];
                tab[i]=tmp;
                changement=1;
            }
        }
        
    }while (changement==1);
}


/****************************************
 ****FIN DES FONCTIONS COMPLEMENTAIRES****
 ****************************************/








/****************************
 ****FONCTIONS PRINCIPALES****
 ****************************/




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
        {
            if(verifier(root->gauche)==0)
                return 0;
        }
        else
        {
            return 0;//sinon ce n'est pas un ABR
        }
    }
    
    if(root->droit)//si il y a un sous arbre droit on verifie que c'est un ABR
    {
        if(root->droit->cle>=root->cle)//si la clé du fils droit est supérieure ou égale à la clé du père on continue à partir du fils droit
        {
            if(verifier(root->droit)==0)
                return 0;
        }
        else
        {
            return 0;//sinon ce n'est pas un ABR
        }
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
    //est ce que la racine existe ?
    if (root != NULL)
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
    else
        printf("racine NULL");
}




//Fonction d'affichage de la structure
void afficherStructure(Noeud *root)
{
    //Condition d'arret de la fonction récursive
    if (root != NULL)
    {   //Condition d'affichage d'un fils gauche
        if (root->gauche!=NULL)
            printf("{ %d ,",root->gauche->cle);
        else
            printf("{ _ ,");
        
        //Affichage de la racine
        printf(" %d ,",root->cle);
        
        //Condition d'affichage d'un fils droit
        if (root->droit!=NULL)
            printf(" %d }\n\n",root->droit->cle);
        else
            printf(" _ }\n\n");
        
        //Appel récursif croissant
        afficherStructure(root->gauche);
        afficherStructure(root->droit);
    }
}




//Suppression d'un noeud dans un ABR
void supprimer(int n, Noeud *root)
{
    
    //On récupère le noeud à supprimer à l'aide de la fonction recherche
    Noeud *fils = recherche(n, root);
    
    if (fils != root)
    {
        
        /*****
         
         On peut tester si le noeud à supprimer n'est pas la racine
         Mais on suppose que l'utilisateur ne le fait pas
         
         ****/
        
        
        
        //On récupère le père de ce noeud pour la gestion du cas à deux fils
        Noeud *precedent = pere(fils, root);
        
        
        
        //Si le noeud est dans l'ABR
        if (fils != NULL)
        {
            //Cas ou le noeud à supprimer n'a aucun fils
            if (fils->droit == NULL && fils->gauche == NULL)
                if (fils->cle > precedent->cle)
                {
                    precedent->droit = NULL;
                    free(fils);
                }
                else
                {
                    precedent->gauche = NULL;
                    free(fils);
                }
            
            
            //Cas ou il a deux fils, détail de la procédure
            /*
             1)On cherche le minimum dans le sous arbre droit ou le maximum dans le sous arbre gauche
             2)On attache ce min au pere
             3)On relie min->gauche et min->droit
             4)On free la mémoire
             */
                else if (fils->droit != NULL && fils->gauche != NULL)
                {
                    
                    //On se prepare à recupere le min du sous ABR droit et son pere
                    Noeud *min, *dad2;
                    
                    //Recuperation du minimum du sous abre droit
                    min = minSousAbre(fils->droit);
                    
                    //récupération du nouveau pere du min du sous ABR droit
                    dad2 = pere(min, root);
                    
                    //Est ce que le noeud a supprimer est dans le sous arbre droit ou gauche?
                    //Permet de relier correctement le pere
                    if (fils->cle < precedent->cle)
                    {
                        //Jonction avec le pere
                        precedent->gauche=min;
                        
                        //Jonction avec ses fils
                        min->droit = fils->droit;
                        min->gauche = fils->gauche;
                        
                        //Gestion des cas limites :
                        
                        /*************************
                         ****DEBUT DE LA NOTICE****
                         **************************
                         
                         
                         1) verifier que le pere du min du sous ABR droit ne soit pas le fils à supprimer
                         --> Si tel est le cas cela signifie que le min->droit devra être mis à nul, sinon il pointera sur lui même
                         exemple avec 60 !
                         2) ensuite, verifier si le min admet un pere,
                         --> Si tel est le cas il faudra mettre le pere->d ou g à NULL pour qu'il ne pointe pas sur lui même
                         3) normalement les cas limites sont gérer. ATTENTION, si on choisit de prendre le max du sous ABR gauche, l'algorithme est à changer !!!!
                         
                         
                         ************************
                         ****FIN DE LA NOTICE****
                         ***********************/
                        
                        if (dad2 != fils)
                        {
                            if (dad2->cle > min->cle)
                                dad2->gauche = NULL;
                            else if (dad2->cle < min->cle)
                                dad2->droit = NULL;
                        }
                        else
                            min->droit = NULL;
                        
                        //Libération de la mémoire
                        free(fils);
                        
                    }
                    else
                    {
                        precedent->droit=min;
                        
                        min->droit = fils->droit;
                        min->gauche = fils->gauche;
                        if (dad2 != fils)
                        {
                            if (dad2->cle > min->cle)
                                dad2->gauche = NULL;
                            else if (dad2->cle < min->cle)
                                dad2->droit = NULL;
                        }
                        else
                            min->droit = NULL;
                        
                        free(fils);
                    }
                }
            
            //Le cas restant est celui où il n'y a qu'un fils
                else
                {
                    //Si le fils est dans le sous arbre droit et qu'il à un fils droit
                    if (fils->cle > precedent->cle && fils->droit != NULL)
                    {
                        precedent->droit = fils->droit;
                        free(fils);
                    }
                    //Si le fils est dans le sous arbre droit et qu'il à un fils gauche
                    else if (fils->cle > precedent->cle && fils->gauche != NULL)
                    {
                        precedent->droit = fils->gauche;
                        free(fils);
                    }
                    //Si le fils est dans le sous arbre gauche et qu'il à un fils droit
                    else if (fils->cle < precedent->cle && fils->gauche != NULL)
                    {
                        precedent->gauche = fils->gauche;
                        free(fils);
                    }
                    //Si le fils est dans le sous arbre gauche et qu'il à un fils gauche
                    else
                    {
                        precedent->gauche = fils->droit;
                        free(fils);
                    }
                }
        }
        //Affichage du message d'erreur si le noeud à supprimer n'existe pas ou qu'une erreur arrive
        else
            printf("Le noeud n'existe pas");
    }
    else
        printf("\n***************************************\nVOUS NE POUVEZ PAS SUPPRIMER LA RACINE!\n***************************************\n\n");
    
}


//Destruction de l'ABR en iteratif
void detruire (Noeud *root)
{
    Noeud *ptr = root;
    int cle;
    while (ptr->droit != NULL)
    {
        cle = ptr->droit->cle;
        supprimer(cle, root);
    }
    while (ptr->gauche != NULL)
    {
        cle = ptr->gauche->cle;
        supprimer(cle, root);
    }
    free(root);
    root=NULL;
    
}

//Construction d'un ABR équilibré
Noeud* construire (int Tab[MAX], int indiceDebut, int indiceFin, Noeud* root)
{
    int l = indiceFin-indiceDebut+1;
    
    if ((indiceDebut+l/2)!=indiceFin)
    {
        insererNoeud_rec(Tab[indiceDebut + l/2], root);
        construire(Tab, indiceDebut, indiceDebut-1 + l/2, root);
        construire(Tab, indiceDebut+1 + l/2, indiceFin, root);
    }
    else
    {
        insererNoeud_rec(Tab[indiceDebut], root);
        insererNoeud_rec(Tab[indiceFin], root);
    }
    
    return root;
}

