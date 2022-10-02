#include<stdio.h>
#include<stdlib.h>


// Creating NODE

struct node
{
    int data; 
    struct node *next;
};


// GLOBAL DECLERATION 

struct node *head,*newnode,*temp;

void in();
void prin();
void delete1();
void delete2();
void delete3();



void main()
{
    int count,c;
    char ch;
    head = NULL;

    while (count != 0)
    {
        in();
        printf("Do you want to contonue");
        scanf("%d",&count);
    }

    prin();

    printf("Enter the choice");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    {
        delete1();
        break;
    }

    case 2:
    {
        delete2();
        break;
    }

    case 3 :
    {
        delete3();
        break;
    }
    default:
    {
        printf("\n Invalid choice\n");
    }
    }

}

void in()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }

    else
    {
        temp->next = newnode;
        temp = newnode;
    }

        
    
}


void prin()
{
    temp=head;
    while(temp!= NULL)
    {
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}



void delete1()
{
    struct node *prenode,*temp1;
    int count=0,del;

    printf("Enter the data to delete:");
    scanf("%d",&del);
    temp = head;
    for(;;)
    {
        count++;
        if(temp->data == del)
        {
         if(count == 1)
         {
            temp1 = head;
            head = head->next;
            free(temp1);
            break;
         }
        }

        else{
            printf("\nThe element did not exist in the node \n");
            break;
        }

        temp=temp->next;
    }

    prin();

}


void delete2()
{
    struct node *current,*swap_1,*swap_2;
    int count = 0,data;
    printf("Enter the data want to delete");
    scanf("%d",&data);

    temp = head;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            printf("Element is found in the node");
            swap_1 = swap_2 = temp;
            current->next =swap_1->next;
            free(swap_2);
            break;
        }
        current = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("\n Element not found");
        return;
    }

    prin();

}


void delete3()
{
    struct node *prevoius;

    temp = head;

    while(temp->next != NULL)
    {
        prevoius = temp;
        temp = temp->next;
    }

    prevoius->next = NULL;

    free(temp); 
    prin();
}