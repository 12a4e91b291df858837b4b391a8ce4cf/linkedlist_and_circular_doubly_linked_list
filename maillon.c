#include "maillon.h"
#include <stdlib.h>
#include <stdio.h>

maillon_t* ajouter_début(maillon_t* pliste, int val) {
	maillon_t* tmpMaillon;
	tmpMaillon = malloc(sizeof(maillon_t));
	tmpMaillon->valeur = val;

	if (pliste == NULL) {
		tmpMaillon->suivant = NULL;
		return tmpMaillon;
	}

	tmpMaillon->suivant = pliste;

	return tmpMaillon;
}

maillon_t* ajouter_fin(maillon_t* pliste, int val) {
	maillon_t* premierMaillon = pliste;

	maillon_t* current = premierMaillon;

	maillon_t* tmpMaillon;
	tmpMaillon = malloc(sizeof(maillon_t));
	tmpMaillon->valeur = val;
	tmpMaillon->suivant = NULL;

	if (premierMaillon == NULL) {
		return tmpMaillon;
	}

	while ((current->suivant) != NULL)
	{
		current = current->suivant;
	}

	current->suivant = tmpMaillon;

	return premierMaillon;
}

maillon_t* rechecher(maillon_t* pliste, int val) {
	maillon_t* current = pliste;


	while (current != NULL) {
		if (current->valeur == val) {
			return current;
		}

		current = current->suivant;
	}

	return NULL;
}

maillon_t* supprimer_debut(maillon_t* pliste, int* pval) {
    if (!pliste) return NULL;

    maillon_t* tmp = pliste->suivant;

	// Insère dans le pointeur la valeur du premier maillon supprimé
	*pval = pliste->valeur;

	free(pliste);

	return tmp;
}

maillon_t* supprimer_fin(maillon_t* pliste, int* pval) {

	if (pliste == NULL) {
		return NULL;
	}

	if (pliste->suivant == NULL) {
		*pval = pliste->valeur;
		free(pliste);
		return NULL;
	}

	maillon_t* current = pliste->suivant;
	maillon_t* previous = pliste;

	while (current->suivant != NULL) {
		previous = current;
		current = current->suivant;
	}

	*pval = previous->valeur;

	previous->suivant = NULL;
	free(current);

	return pliste;
}

maillon_t* supprimer_val(maillon_t* pliste, int val) {
	maillon_t* current = pliste;
	maillon_t* previous = NULL;

	while (current != NULL && current->valeur != val) {
		previous = current;
		current = current->suivant;
	}

	if (current != NULL && current->valeur == val) {
		if (previous != NULL) {
			previous->suivant = current->suivant;
		}
		else {
			pliste = current->suivant;
		}

		free(current);
	}

	return pliste;
}

void afficher(maillon_t* pliste) {
	printf("Affichage de la liste chainee :\n");
	while (pliste != NULL) {
		printf("%d\n", pliste->valeur);
		pliste = pliste->suivant;
	}
}