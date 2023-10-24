#include "maillonDCC.h"
#include <stdlib.h>
#include <stdio.h>

maillon_dcc* addToHistory(maillon_dcc* plist, int val) {
    maillon_dcc* tmpMaillon;
    tmpMaillon = malloc(sizeof(maillon_dcc));
    tmpMaillon->value = val;

    if (plist == NULL) {
        tmpMaillon->next = tmpMaillon;
        tmpMaillon->previous = tmpMaillon;
        return tmpMaillon;
    }

    else {
        maillon_dcc* last = plist->previous;

        last->next = tmpMaillon;
        tmpMaillon->previous = last;
        tmpMaillon->next = plist;
        plist->previous = tmpMaillon;

        return plist;
    }
}

maillon_dcc* removeFromHistory(maillon_dcc* plist, int* pval) {
    if (plist == NULL) {
        return NULL;
    }

    if(plist->next == plist) {
        *pval = plist->value;
        free(plist);
        return NULL;
    }

    maillon_dcc* last = plist->previous;
    *pval = last->value;

    last->previous->next = plist;
    plist->previous = last->previous;

    free(last);

    return plist;
}

void printList(maillon_dcc* pliste) {
    if (pliste == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    printf("Affichage de la liste chainee :\n");
    maillon_dcc *debut = pliste;

    do {
        printf("%d\n", pliste->value);
        pliste = pliste->next;
    } while (pliste != debut);
}
