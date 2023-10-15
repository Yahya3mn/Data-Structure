#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* addfront(struct node* head, int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    return temp;
}

struct node* addlast(struct node* head, int x) {
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

struct node* deleteNode(struct node* head, int x) {
    if (head == NULL) {
        return head;
    }

    struct node* temp = head;

    if (head->data == x) {
        head = head->next;
        free(temp);
        return head;
    }

    while (temp->next != NULL && temp->next->data != x) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return head;
    }

    struct node* deleted = temp->next;
    temp->next = deleted->next;
    free(deleted);

    return head;
};

struct node* destroy(struct node* head) {
    struct node* current = head;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return NULL;
}

void listinfo(struct node* head) {
    int i = 1;
    while (head != NULL) {
        printf("%d. Dugumun adresi = %p\n", i, head);
        printf("%d. Dugumun verisi = %d\n", i, head->data);
        printf("%d. Dugumun Bagli Oldugu Dugumun adresi = %p\n\n", i, head->next);
        head = head->next;
        i++;
    }
}

void printlist(struct node* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int count(struct node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int choice, data;
    struct node* head = NULL;

    while (1) {
        printf("1-Listenin Basina Eleman Ekle\n");
        printf("2-Listenin Sonuna Eleman Ekle\n");
        printf("3-Listeyi Gorme\n");
        printf("4-Listeden verilen bir degere sahip dugumu sil\n");
        printf("5-Listeyi sil\n");
        printf("6-Listedeki eleman sayisi\n");
        printf("7-Listenin tum eleman bilgileri\n");
        printf("8-Programdan Cikma\n");
        printf("Seciminiz....?");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklemek istediginiz degeri giriniz : ");
                scanf("%d", &data);
                head = addfront(head, data);
                break;

            case 2:
                printf("Eklemek istediginiz degeri giriniz : ");
                scanf("%d", &data);
                head = addlast(head, data);
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
                head = destroy(head);
                break;

            case 6:
                printf("Listede %d eleman vardir\n", count(head));
                break;

            case 7:
                listinfo(head);
                break;

            case 8:
                exit(0);
                break;

            default:
                printf("Yanlis secim\n");
                break;
        }
    }

    return 0;
}

