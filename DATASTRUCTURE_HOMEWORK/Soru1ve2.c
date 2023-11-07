#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* next;
};

struct node* AddFront(struct node* head, int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    return temp;
}

struct node* AddLast(struct node* head, int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        return temp;
    }

    struct node* temp2 = head;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    temp2->next = temp;
    return head;
}



struct node* deleteNode(struct node* head, int key) {
    if (head == NULL) {
        return head;
    }

    struct node* temp = head;
    if (head->data == key) {
        head = head->next;
        free(temp);
        return head;
    }

    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return head;
    }

    struct node* deleted = temp->next;
    temp->next = deleted->next;
    free(deleted);

    return head;
}

void printlist(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


struct node* TekCiftSayilar(struct node* head) {
    head = NULL;
    int num;

    printf("Tek sayilari basa, cift sayilari sona ekleyin. Cikmak icin -1 girin.\n");

    while (1) {
        printf("Sayi giriniz: ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        } else {
            if (num % 2 == 1) {
                head = AddFront(head, num); // Tek sayilari listenin başına ekler
            } else {
                head = AddLast(head, num); // Çift sayıları listenin sonuna ekler
            }
            printf("Guncel liste: ");
            printlist(head);
        }
    }
    printf("Son liste: ");
    printlist(head);
    return head;
}



void BubbleSort(struct node* head) {
    struct node* i, *j;
    int swap;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                swap = i->data;
                i->data = j->data;
                j->data = swap;
            }
        }
    }
}




struct node* GenerateNumber(struct node* head) {
    head = NULL;
    srand(time(NULL));

    int i;
    for (i = 0; i < 100; i++) {
        head = AddFront(head, rand() % 1000 + 1);
    }

    printf("Liste siralanmadan once:\n");
    printlist(head);

    BubbleSort(head);

    printf("Liste siralandiktan sonra:\n");
    printlist(head);

    return head;
}

int main() {
    int choice, data;
    struct node* head = NULL;

    while (1) {
        printf("1-Listenin Basina Eleman Ekle\n");
        printf("2-Listenin Sonuna Eleman Ekle\n");
        printf("3-Listeyi Gorme\n");
        printf("4-Listeden verilen bir degere sahip dugumu sil\n");
        printf("5-Tek sayilar ve Cift sayilar islemi\n");
        printf("6-Sirali Rasgele Sayi olustur listeye\n");
        printf("7-Programdan Cikma\n");
        printf("Seciminiz....?");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklemek istediginiz degeri giriniz : ");
                scanf("%d", &data);
                head = AddFront(head, data);
                break;

            case 2:
                printf("Eklemek istediginiz degeri giriniz : ");
                scanf("%d", &data);
                head = AddLast(head, data);
                break;

            case 3:
                printlist(head);
                break;

            case 4:
                printf("Silmek istediginiz degeri giriniz : ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;

            case 5:
                head = TekCiftSayilar(head);
                break;

            case 6:
                head = GenerateNumber(head);
                break;

            case 7:
                exit(0);
                break;

            default:
                printf("Yanlis secim\n");
                break;
        }
    }

    return 0;
}
