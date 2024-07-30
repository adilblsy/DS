#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *link;
};

struct node *head;

void display() {
   struct node *ptr;
   if(head==NULL)
      printf("\nThe list is empty");
   else {
      ptr=head;
      printf("Linked List:");
      while(ptr!=NULL) {
         printf("%d\t", ptr->data);
         ptr=ptr->link;
      }
   }
}

void insertFront(int x) {
   struct node *new;
   new=(struct node *)malloc(sizeof(struct node ));
   new->data=x;
   new->link=head;
   head=new;

   display();
}

void insertEnd(int x) {
   struct node *ptr, *new;
   new=(struct node *)malloc(sizeof(struct node ));
   new->data=x;
   new->link=NULL;
   if(head==NULL)
      head=new;
   else {
      ptr=head;
      while(ptr->link!=NULL)
         ptr=ptr->link;
      ptr->link=new;
   }
   display();
}

void insertAt(int x,int key) {
   struct node *ptr, *new;
   new=(struct node *)malloc(sizeof(struct node ));
   new->data=x;
   if(head==NULL)
      printf("Search key not found");
   else {
      ptr=head;
      while(ptr->data!=key && ptr->link!=NULL)
         ptr=ptr->link;
      if(ptr->data!=key)
         printf("Search key not found");
      else {
         new->link=ptr->link;
         ptr->link=new;
      }
   }
   display();
}

void deleteFront() {
   struct node *temp;
   if(head==NULL)
      printf("The list is empty");
   else {
      temp=head;
      head=head->link;
      free(temp);
   }
   display();
}

void deleteEnd() {
   struct node *prev, *curr, *temp;
   if(head==NULL)
      printf("The list is empty");
   else if(head->link==NULL) {
      head=temp;
      head=NULL;
      free(temp);
   }
   else {
      prev=head;
      curr=head->link;
      while(curr->link!=NULL) {
         prev=curr;
         curr=curr->link;
      }
      prev->link=NULL;
      free(curr);
   }
   display();
}

void deleteAt(int key) {
   struct node *curr, *prev, *temp;

   if(head==NULL)
      printf("The list is empty");
   else if(head->data==key) {
      temp=head;
      head=head->link;
      free(temp);
   }
   else {
      curr=head->link;
      prev=head;
      while(curr->data!=key && curr->link!=NULL) {
         prev=curr;
         curr=curr->link;
      }
      if(curr->data!=key)
         printf("Search key not found");
      else {
         prev->link=curr->link;
         free(curr);
      }
   }
   display();
}

void main() {
   int key, choice, opt, x;

   while(choice!=8) {
      printf("Linked List Operations:\n1:Insert at front\n2:Insert at end\n3:Insert at position\n4:delete from front\n5:Delete from end\n6:Delete from position\n7:Display\n8:Exit\nEnter your choice: ");
      scanf("%d", &opt);

      switch(opt) {
         case 1: printf("Enter the element to be inserted: ");
                 scanf("%d", &x);
                 insertFront(x);
                 break;
         case 2: printf("Enter the element to be inserted: ");
                 scanf("%d", &x);
		 insertEnd(x);
                 break;
         case 3: printf("Enter the element to be inserted: ");
                 scanf("%d", &x);
		 printf("Enter the search key: ");
                 scanf("%d", &key);
		 insertAt(x, key);
                 break;
         case 4: deleteFront();
                 break;
         case 5: deleteEnd();
                 break;
         case 6: printf("Enter the search key: ");
                 scanf("%d", &key);
		 deleteAt(key);
                 break;
         case 7: display();
                 break;
         case 8: break;
         default: printf("Invalid choice");
      }
   }
}