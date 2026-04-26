#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float val;
    struct Node* next;
} Node;

Node* insertSorted(Node* head, float x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = x;
    node->next = NULL;

    if (!head || x < head->val) {
        node->next = head;
        return node;
    }

    Node* curr = head;
    while (curr->next && curr->next->val <= x)
        curr = curr->next;

    node->next = curr->next;
    curr->next = node;

    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    float *arr = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    Node** buckets = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n);
        buckets[idx] = insertSorted(buckets[idx], arr[i]);
    }

    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr) {
            printf("%.6f ", curr->val);
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(arr);
    free(buckets);

    return 0;
}