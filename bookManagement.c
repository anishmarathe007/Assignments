#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct node{
    char bookName[100];
    char author[100];
    float price;
    struct node *next;
}*head=NULL,*temp=NULL;

int search(char* bname){
    struct node *temp = head;
    int pos=1;
    int flag = 0;
    if(temp != NULL){
        while(temp != NULL){
            if(strcmp(temp->bookName,bname) == 0)
            {
                //printf("%s found at %d position\n",temp->bookName,pos);
                flag=1;
                return pos;
            }
            temp=temp->next;
            pos++;
        }
        if(flag==0){
            //printf("%s not present in the shelf!\n",bname);
            return 1;
        }
    }
    else{
        //printf("Book Shelf is empty! Cannot Search in here.\n");
        return 1;
    }
}

void insertLast(char* bname, char* auth, float p){
    struct node *newnode,*temp;

    if(search(bname)==1){

        newnode = (struct node *)malloc(sizeof(struct node));

        strcpy(newnode->bookName,bname);
        strcpy(newnode->author,auth);
        newnode->price=p;
        newnode->next=NULL;

        if(head==NULL)
            head=newnode;
        else
        {
            //struct node *temp;
            temp = head;
            while(temp->next != NULL)
                temp=temp->next;
            temp->next = newnode;
        }
    }
    else{
        printf("%s already present in the shelf!\n", bname);
    }
}

void insert(char* bname, char* auth, float p,int pos){

    int count=0,flag=0;
    struct node *temp,*prev,*newnode;

    if(search(bname)==1){
        newnode = (struct node *)malloc(sizeof(struct node));

        strcpy(newnode->bookName,bname);
        strcpy(newnode->author,auth);
        newnode->price=p;
        newnode->next=NULL;

        if(head==NULL)
            head = newnode;
        else
        {
            temp = head;
            prev = temp;
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
                count++;
                if(count==pos){
                    flag=1;
                    break;
                }
            }

            if(flag==0){
                printf("Enter the correct position\n");
                return;
            }
            else
            {
                prev->next = newnode;
                newnode->next = temp;
            }
        }
    }
    else{
        printf("%s already present in the shelf!\n", bname);
    }
}

void insertFirst(char* bname, char* auth, float p){
    struct node *temp,*newnode;

    if(search(bname)==1){

        newnode = (struct node *)malloc(sizeof(struct node));

        strcpy(newnode->bookName,bname);
        strcpy(newnode->author,auth);
        newnode->price=p;
        newnode->next=NULL;

        if(head==NULL)
            head = newnode;
        else{
            temp = head;
            head = newnode;
            newnode->next = temp;
        }
    }
    else{
        printf("%s already present in the shelf!\n", bname);
    }
}

void removeFirst(){
    struct node *temp = head;
    struct node *prev = head;
    char d[50];

    if(temp == NULL){
        printf("There is no book in the shelf\nAdd some books first\n");
        return;
    }
    else{
        if(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
            head = temp;
            free(prev);
        }
        else{
            strcpy(d,temp->bookName);
            head=NULL;
            printf("Book Shelf is now empty\nThe only book %s removed from the list\n",d);
        }
    }

}

void removeLast(){
    struct node *temp = head;
    struct node *prev;
    char d[50];

    if(temp==NULL){
        printf("Book Shelf is currently empty\nAdd some books first");
        return;
    }
    else{
        if (temp->next != NULL){
           while(temp->next!= NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            free(temp);
        }
        else{
            strcpy(d,temp->bookName);
            head=NULL;
            printf("Book shelf is now empty\nThe only book %s removed from the list\n",d);
        }
    }
}

void removeByElement(char* d){
    struct node *temp = head;
    struct node *prev = head;
    int flag=0;

    temp = temp->next;


    if(strcmp(head->bookName,d) == 0){
        printf("Removed %s\n",head->bookName);
        head = temp;
        flag = 1;
        return;
    }
    else{
         while(temp!= NULL){
            if (strcmp(temp->bookName,d) == 0){
                printf("Removed %s\n",temp->bookName);
                prev->next = temp->next;
                free(temp);
                flag = 1;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    if(flag==0){
        printf("Book not found\n");
        return;
    }
}

void removeByPos(int pos){
    struct node *temp = head;
    struct node *prev;
    int count=1,flag=0;

    while(temp!=NULL){
        if(count == pos){
            if(count==1){
                printf("Removed %s at position %d",head->bookName,count);
                head = temp->next;
                free(temp);
                flag = 1;
                return;
            }
            else{
                printf("Removed %s at position %d",head->bookName,count);
                prev->next = temp->next;
                free(temp);
                flag = 1;
                return;
            }
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    if(flag==0){
        printf("Entered position does not exist in Book Shelf\n");
        return;
    }
}

void printList(){
    struct node *temp;
    temp=head;
    if(temp == NULL)
        printf("The Book Shelf seems empty here..!!\n");
    else{
        printf("\nThe Book Shelf is : \n");
        printf("Book Name  Author  Price\n");
        while(temp!=NULL)
        {
            printf("%s\t %s\t%.2f",temp->bookName,temp->author,temp->price);
            temp = temp->next;
            printf("\n");
        }
    }
}

// void sort(){
//     struct node *temp = head;
//     int temp1;

//     while(temp->next!=NULL){
//             if(temp->data > temp->next->data){
//                 temp1 = temp->data;
//                 temp->data = temp->next->data;
//                 temp->next->data = temp1;
//             }
//         temp = temp->next;
//     }
// }



int main(int argc, char const *argv[])
{
    int ch,pos;
    char bname[100];
    char author[200];
    float price;

    while(1){
        printf("\n1.Insert element at last\n2.Insert at specific position\n3.Add at first\n4.Display List\n5.Remove first element from the list\n6.Remove last element from the list\n7.Remove any element (Input an element) \n8.Remove element by position (Input the position)\n9.Sort the list\n10.Search for a specific position\n11.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);

        switch(ch){
             case 1 : printf("Enter the book name\n");
                      scanf("%s",&bname);
                      printf("Enter the author for book\n");
                      scanf("%s",&author);
                      printf("Enter the price for book\n");
                      scanf("%f",&price);
                      insertLast(bname,author,price);
                      break;

            case 2 : printf("Enter the book name\n");
                      scanf("%s",&bname);
                      printf("Enter the author for book\n");
                      scanf("%s",&author);
                     printf("Enter the price for book\n");
                     scanf("%f",&price);
                     printf("Enter the position where you want to put this book!\n");
                     scanf("%d",&pos);
                     insert(bname,author,price,pos);
                     break;

            case 3 : printf("Enter the book name\n");
                      scanf("%s",&bname);
                      printf("Enter the author for book\n");
                      scanf("%s",&author);
                     printf("Enter the price for book : %s\n");
                     scanf("%f",&price);
                     insertFirst(bname,author,price);
                     break;

            case 4 : printList();
                      break;

            case 5 : removeFirst();
                     break;

            case 6 : removeLast();
                     break;

            case 7 : if(head == NULL)
                        printf("Book Shelf is empty\n");
                     else{
                         printf("Enter the element which you wish to delete\n");
                         scanf("%s",bname);
                         removeByElement(bname);
                        }
                        break;

            case 8 : if(head == NULL)
                        printf("Book Shelf is empty\n");
                     else{
                         printf("Enter the position from which you wish to delete the element\n");
                         scanf("%d",&pos);
                         removeByPos(pos);
                        }
                        break;

            case 9 : //sort();
                     break;

            case 10 : printf("Enter the book name\n");
                      scanf("%s",bname);
                      search(bname);
                      break;

            case 11 : exit(0);

            default : printf("Wrong choice..!!\n");
        }
    }
    return 0;
}
