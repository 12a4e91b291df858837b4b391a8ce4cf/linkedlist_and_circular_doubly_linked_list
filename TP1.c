#include <stdlib.h>
#include "maillon.h"
#include "maillonDCC.h"
#include <stdio.h>

void firstTest();

void secondTest();

void thirdTest();

int main() {
    //firstTest();
    //secondTest();
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
    char* number1 = "96789543216";
    char* number2 = "55555555555";
    maillon_dcc* list1 = stringToList(number1);
    maillon_dcc* list2 = stringToList(number2);
    printf("Liste 1 :\n");
    printList(list1);

    printf("Liste 2 :\n");
    printList(list2);
    maillon_dcc* sumList = addLargeNumbers(list1, list2, list1, list2);

    printf("Somme = ");
    maillon_dcc* start = sumList;
    do {
        printf("%05d", sumList->value);  // pour garder le format de 5 chiffres
        sumList = sumList->next;
    } while (sumList != start);
    printf("\n");

}