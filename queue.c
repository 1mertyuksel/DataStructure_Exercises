#include <stdio.h>
#include <stdlib.h>

// Queue elemanını temsil eden bir yapı (node)
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Queue'i temsil eden başlık yapısı
struct Queue {
    struct QueueNode* front; // Kuyruğun önündeki eleman
    struct QueueNode* rear;  // Kuyruğun sonundaki eleman
};

// Yeni bir boş kuyruk oluşturmak için bir yardımcı işlev
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Kuyruğun sonuna bir eleman eklemek için bir yardımcı işlev
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Kuyruğun önünden bir eleman çıkarmak için bir yardımcı işlev
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk boş.\n");
        return -1;
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Kuyruğu ekrana yazdıran bir yardımcı işlev
void displayQueue(struct Queue* queue) {
    struct QueueNode* current = queue->front;
    if (current == NULL) {
        printf("Kuyruk boş.\n");
        return;
    }

    printf("Kuyruk: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;

    while (1) {
        printf("1. Eleman Ekle\n");
        printf("2. Eleman Çıkar\n");
        printf("3. Kuyruğu Göster\n");
        printf("4. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklemek istediğiniz elemanı girin: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Çıkarılan eleman: %d\n", data);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Programdan çıkılıyor.\n");
                exit(0);
            default:
                printf("Geçersiz seçim. Tekrar deneyin.\n");
        }
    }

    return 0;
}
