#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    
    if (new_node == NULL) {
        perror("malloc failed");
        exit(1);
    }
    
    new_node->data = data;
    new_node->next = NULL;

    if (*tail == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

void delet(struct node **head, struct node **tail) {
    if (*head == NULL) {
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;

    if (*head == NULL) {
        *tail = NULL;
    }

    free(temp);
}

void print_queue(struct node *head) {
    if (head == NULL) {
        return;
    }

    struct node *p = head;
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL, *tail = NULL;
    int num;

    while (scanf("%d", &num) == 1 && num != -1) {
        addq(&head, &tail, num);
    }

    printf("Print queue\n");
    print_queue(head);

    // delet(&head, &tail);

    // printf("\n");
    // print_queue(head);

    return 0;
}
