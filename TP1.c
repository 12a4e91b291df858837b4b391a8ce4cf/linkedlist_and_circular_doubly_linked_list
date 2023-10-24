#include <stdlib.h>
#include "maillon.h"
#include "maillonDCC.h"
#include <stdio.h>

void firstTest();

void secondTest();

void thirdTest();

int main() {
    firstTest();
    secondTest();
    thirdTest();
}

void firstTest() {
    maillon_t* maillon;
    maillon = malloc(sizeof(maillon_t));
    maillon->valeur = 4;
    maillon->suivant = NULL;

    maillon_t* maillon2;
    maillon2 = malloc(sizeof(maillon_t));
    maillon2->valeur = 10;
    maillon2->suivant = NULL;

    maillon->suivant = maillon2;

    printf("-----AJOUT AU DEBUT TEST-----\nAVANT :\n");
    afficher(maillon);
    printf("APRES :\n");
    maillon = ajouter_début(maillon, 50);
    afficher(maillon);

    printf("-----AJOUT A LA FIN TEST-----\n");
    maillon = ajouter_fin(maillon, 99);
    afficher(maillon);

    int valSupp = 0;
    printf("-----SUPPRESSION A LA FIN TEST-----\n");
    maillon = supprimer_fin(maillon, &valSupp);
    afficher(maillon);

    printf("-----SUPPRESSION AU DEBUT TEST-----\n");
    maillon = supprimer_debut(maillon, &valSupp);
    afficher(maillon);

    printf("-----SUPPRESSION DE VALEUR TEST-----\n");
    maillon = supprimer_val(maillon, 4);
    afficher(maillon);
}

void secondTest() {
    maillon_dcc* maillon;
    maillon = malloc(sizeof(maillon_dcc));
    maillon->value = 4;
    maillon->next = NULL;

    maillon_dcc* maillon2;
    maillon2 = malloc(sizeof(maillon_t));
    maillon2->value = 10;
    maillon2->next = NULL;

    maillon->next = maillon2;
    maillon->previous = maillon2;

    maillon2->next = maillon;
    maillon2->previous = maillon;

    printf("\n---------HISTORIQUE---------\n----AJOUT TEST-----\n");
    maillon = addToHistory( maillon, 50);
    printList(maillon);

    printf("-----NAVIGATION TEST-----\n");
    printf("Avant 4 il y'a : %d", maillon->previous->value);
    printf("\nAvant 50, il y'a : %d", maillon->next->next->previous->value);
    printf("\nApres 50, il y'a : %d\n", maillon->next->next->next->value);

    printf("-----SUPPRESSION TEST-----\n");
    int valSup = 0;
    maillon = removeFromHistory(maillon, &valSup);
    printList(maillon);
}

void thirdTest() {

}