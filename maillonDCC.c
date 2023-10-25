#include "maillonDCC.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SEGMENT_SIZE 100000

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

maillon_dcc* stringToList(const char* number) {
    int len = strlen(number);
    maillon_dcc* plist = NULL;

    for (int i = len; i > 0; i -= 5) {
        int startPos = i - 5 < 0 ? 0 : i - 5;
        char temp[6];
        strncpy(temp, number + startPos, i - startPos);
        temp[i - startPos] = '\0';
        plist = addToHistory(plist, atoi(temp));
    }

    return plist;
}

// Additionne deux grands nombres représentés par des listes chaînées
maillon_dcc* addLargeNumbers(maillon_dcc* a, maillon_dcc* b, maillon_dcc* list1, maillon_dcc* list2){
    maillon_dcc* result = NULL;
    int carry = 0;

    while (a != NULL || b != NULL || carry) {
        int valA = (a != NULL) ? a->value : 0;
        int valB = (b != NULL) ? b->value : 0;

        int sum = valA + valB + carry;
        carry = sum / SEGMENT_SIZE;
        sum %= SEGMENT_SIZE;

        result = addToHistory(result, sum);

        if (a != NULL) a = (a->next == list1) ? NULL : a->next;
        if (b != NULL) b = (b->next == list2) ? NULL : b->next;
    }

    return result;
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
