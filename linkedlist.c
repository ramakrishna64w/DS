#include <stdio.h>
#include <stdlib.h>  // for malloc, free

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

// Function declarations
struct queue *create_queue();
struct queue *insert(struct queue *, int);
struct queue *delete_element(struct queue *);
void display(struct queue*);
int peek(struct queue *);

int main() {
    int val, option;
    struct queue *q = create_queue();  // properly initialize the queue

    do {
        printf("\n***** MAIN MENU *****");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the number to insert in the queue: ");
                scanf("%d", &val);
                q = insert(q, val);
                break;

            case 2:
                q = delete_element(q);
                break;

            case 3:
                val = peek(q);
                if(val != -1)
                    printf("\nThe value at front of queue is: %d", val);
                break;

            case 4:
                display(q);
                break;

            case 5:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid option. Try again.");
        }

    } while(option != 5);

    return 0;
}

// Creates a new queue and returns a pointer to it
struct queue *create_queue() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Insert an element into the queue
struct queue *insert(struct queue *q, int val) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if(q->front == NULL) {
        q->front = q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }

    return q;
}

// Delete an element from the queue
struct queue *delete_element(struct queue *q) {
    struct node *ptr;

    if(q->front == NULL) {
        printf("\nUNDERFLOW: Queue is empty.");
    } else {
        ptr = q->front;
        printf("\nThe value being deleted is: %d", ptr->data);
        q->front = q->front->next;
        free(ptr);
        if(q->front == NULL) {
            q->rear = NULL;  // Reset rear if queue is now empty
        }
    }

    return q;
}

// Display the queue
void display(struct queue *q) {
    struct node *ptr = q->front;

    if(ptr == NULL) {
        printf("\nQUEUE IS EMPTY");
    } else {
        printf("\nQueue contents: ");
        while(ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

// Peek at the front element
int peek(struct queue *q) {
    if(q->front == NULL) {
        printf("\nQUEUE IS EMPTY");
        return -1;
    } else {
        return q->front->data;
    }
}

