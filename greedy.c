#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float weight;
    float profit;
    float ratio;
} Item;

int compareItems(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    if (itemB->ratio > itemA->ratio) return 1;
    if (itemB->ratio < itemA->ratio) return -1;
    return 0;
}

void fractionalKnapsack(float capacity, Item items[], int n) {
    int i;
    float totalProfit = 0.0;
    float currentWeight = 0.0;

    for (i = 0; i < n; i++) {
        items[i].ratio = items[i].profit / items[i].weight;
    }

    qsort(items, n, sizeof(Item), compareItems);

    printf("Items considered (in order of ratio):\n");
    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("  * Added full item %d (Weight: %.2f, Profit: %.2f)\n", items[i].id, items[i].weight, items[i].profit);
        }
        else {
            float remainingCapacity = capacity - currentWeight;
            float fraction = remainingCapacity / items[i].weight;
            currentWeight += remainingCapacity;                     
            totalProfit += (items[i].profit * fraction);
            printf("  * Added %.2f fraction of item %d (Weight: %.2f, Profit: %.2f)\n", fraction, items[i].id, (items[i].profit * fraction));
            break;
        }
    }

    printf("\nMaximum total profit: %.2f\n", totalProfit);
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    if (scanf("%d", &n) != 1) return 1;

    Item* items = (Item*)malloc(sizeof(Item) * n);

    printf("Enter the weight and profit for each item:\n");
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Item %d Weight: ", i + 1);
        scanf("%f", &items[i].weight);
        printf("Item %d Profit: ", i + 1);
        scanf("%f", &items[i].profit);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    fractionalKnapsack(capacity, items, n);

    free(items);

    return 0;
}
