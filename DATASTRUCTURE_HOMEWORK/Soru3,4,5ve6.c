#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[50];
    int Year;
    int number;
    struct node *next;
};

struct node *AddFront(struct node* head, char name[], int year, int number)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->name, name);
    temp->Year = year;
    temp->number = number;
    temp->next = head;
    return temp;
}

struct node *AddLast(struct node *head, char name[], int year, int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->name, name);
    temp->Year = year;
    temp->number = num;
    temp->next = NULL;

    if (head == NULL) {
        return temp;
    }

    struct node *temp2 = head;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    return head;
}

struct node *DeleteNode(struct node *head, char *keyword)
{
    if (head == NULL) {
        return head;
    }

    if (strcmp(head->name, keyword) == 0) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        if (strcmp(temp->next->name, keyword) == 0) {
            struct node *deleted = temp->next;
            temp->next = deleted->next;
            free(deleted);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

struct node *searchList(struct node *head, char *keyword)
{
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, keyword) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printLongestName(struct node *head)
{
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    int longestLength = strlen(temp->name);
    char *longestName = temp->name;

    while(temp != NULL){
        int currentLength = strlen(temp->name);
        if(currentLength > longestLength){
            longestLength = currentLength;
            longestName = temp->name;
        }
        temp = temp->next;
    }

    printf("The longest name in the list is : %s\n",longestName);
    printf("Length : %d\n",longestLength);
}

void printList(struct node *head){
    int counter = 1;
    while(head != NULL){
        printf("%d- %s %d %d\n", counter, head->name, head->Year, head->number);
        head = head->next;
        counter++;
    }
}

int main()
{
    int secim, yas, numara;
    char isim[50];
    struct node *head = NULL;

    while(1)
    {
        printf("1- Listenin basina Ogrenci bilgilerini ekle\n");
        printf("2- Listenin sonuna Ogrenci bilgilerini ekle\n");
        printf("3- Isme göre silme işlemi yap\n");
        printf("4- Listedeki öğrenciyi ara\n");        
        printf("5- Listedeki en uzun isme sahip olanı gör\n");  
        printf("6- Bilgileri ekrana yazdır\n");
        printf("7- Çıkış yap\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch(secim){
            case 1:
                printf("Lutfen listenin basina ogrencinin bilgilerini girin: ");
                scanf("%s %d %d", isim, &yas, &numara);
                head = AddFront(head, isim, yas, numara);
                break;
            case 2:
                printf("Lutfen listenin sonuna ogrenci bilgilerini girin: ");
                scanf("%s %d %d", isim, &yas, &numara);
                head = AddLast(head, isim, yas, numara);
                break;
            case 3:
                printf("Lutfen silinecek ogrencinin adini giriniz: ");
                scanf("%s", isim);
                head = DeleteNode(head, isim);
                break;
            case 4:
                printf("Lutfen aranacak ogrencinin adini giriniz: ");
                scanf("%s", isim);
                struct node *result = searchList(head, isim);
                if (result != NULL) {
                    printf("Bulundu: %s %d %d\n", result->name, result->Year, result->number);
                } else {
                    printf("Ogrenci bulunamadi.\n");
                }
                break;
            case 5:
                printLongestName(head);
                break;
            case 6:
                printList(head);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Hatali secim! Lutfen tekrar deneyin.\n");
        }
    }

    return 0;
}
