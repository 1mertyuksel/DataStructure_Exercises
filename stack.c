#include <stdio.h>
#include <stdlib.h>

// Bağlı liste düğümü
struct Node {
    int data;
    struct Node* next;
};

// Yığıt yapısı
struct Stack {
    struct Node* top;
};

// Yeni bir düğüm oluşturur
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Hafıza tahsisi hatası");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Yığıtı başlatır
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Yığıta eleman ekler
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Yığıttan eleman çıkarır
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Yığıt boş, pop işlemi başarısız.\n");
        exit(EXIT_FAILURE);
    }

    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Yığıtın en üstündeki elemanı döndürür
int peek(const struct Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Yığıt boş, peek işlemi başarısız.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// Yığıt boş mu kontrol eder
int isEmpty(const struct Stack* stack) {
    return (stack->top == NULL);
}

// Yığıtı temizler
void clearStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Yığıtın en üstündeki eleman: %d\n", peek(&stack));

    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    clearStack(&stack);

    return 0;
}
