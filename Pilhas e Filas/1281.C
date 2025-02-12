#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[51];
    double price;
} Product;

typedef struct {
    char name[51];
    int quantity;
} ShoppingListItem;

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        int M;
        scanf("%d", &M);

        Product products[MAX_PRODUCTS];
        
        for (int i = 0; i < M; i++) {
            scanf("%s %lf", products[i].name, &products[i].price);
        }
        
        int P;
        scanf("%d", &P);

        double total = 0.0;
        
        for (int i = 0; i < P; i++) {
            ShoppingListItem item;
            scanf("%s %d", item.name, &item.quantity);

            for (int j = 0; j < M; j++) {
                if (strcmp(products[j].name, item.name) == 0) {
                    total += products[j].price * item.quantity;
                    break;
                }
            }
        }

        printf("R$ %.2f\n", total);
    }

    return 0;
}
