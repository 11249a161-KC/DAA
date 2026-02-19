#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

struct Queue {
    int front, rear, size;
    struct Node* array;
};

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->array = (struct Node*)malloc(queue->size * sizeof(struct Node));
    return queue;
}

void enqueue(struct Queue* queue, struct Node item) {
    queue->array[++queue->rear] = item;
}

struct Node dequeue(struct Queue* queue) {
    return queue->array[++queue->front];
}

int isEmpty(struct Queue* queue) {
    return queue->front == queue->rear;
}

int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r1 < r2) - (r1 > r2);
}

float bound(struct Node u, int n, int W, struct Item arr[]) {
    if (u.weight >= W) return 0;
    float profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    if (j < n)
        profit_bound += (W - totweight) * (float)arr[j].value / arr[j].weight;
    return profit_bound;
}

int knapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), compare);
    struct Queue* q = createQueue(1000);
    struct Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    enqueue(q, u);

    int maxProfit = 0;
    while (!isEmpty(q)) {
        u = dequeue(q);
        if (u.level == n - 1) continue;

        v.level = u.level + 1;

        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            enqueue(q, v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            enqueue(q, v);
    }
    return maxProfit;
}

int main() {
    int W = 10;
    struct Item arr[] = {{2, 40}, {3, 50}, {5, 100}, {7, 120}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum Profit: %d\n", knapsack(W, arr, n));
    return 0;
}
