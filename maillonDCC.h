typedef struct maillondcc {
    int value;
    struct maillondcc* next;
    struct maillondcc* previous;
} maillon_dcc;

maillon_dcc* addToHistory(maillon_dcc* plist, int val);

maillon_dcc* removeFromHistory(maillon_dcc* plist, int* pval);

void printList(maillon_dcc* plist);

maillon_dcc* stringToList(const char* number);

maillon_dcc* addLargeNumbers(maillon_dcc* a, maillon_dcc* b, maillon_dcc* list1, maillon_dcc* list2);


//S'assurer que next du dernier maillon pointe vers le premier et que previous du premier maillon pointe vers le dernire