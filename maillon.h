typedef struct maillon {
	int valeur;
	struct maillon* suivant;
} maillon_t;

maillon_t* ajouter_début(maillon_t* pliste, int val);

maillon_t* ajouter_fin(maillon_t* pliste, int val);

maillon_t* rechecher(maillon_t* pliste, int val);

maillon_t* supprimer_debut(maillon_t* pliste, int* pval);

maillon_t* supprimer_fin(maillon_t* pliste, int* pval);

maillon_t* supprimer_val(maillon_t* pliste, int val);

void afficher(maillon_t* pliste);