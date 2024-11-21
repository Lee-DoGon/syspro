#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL) {
        perror("malloc failed");
        exit(1);
    }

    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

int pop(struct node **top) {
    if (*top == NULL) {
        return -1;
    }

    struct node *temp = *top;
    int popped_data = temp->data;

    *top = (*top)->next;

    free(temp);

    return popped_data;
}

void print_stack(struct node *top) {
    if (top == NULL) {
        return;
    }

    struct node *p = top;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct node *top = NULL;
    int num;


    while (scanf("%d", &num) == 1 && num != -1) {
        push(&top, num);
    }

    printf("\nPrint stack:\n");
    print_stack(top);

    return 0;
}
