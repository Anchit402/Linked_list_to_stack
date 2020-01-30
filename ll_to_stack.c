#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int *link;
} *top = NULL;//starting with top being empty as in Stack.
main()
{
    while(1))//using infinite loop as we dont know what and how many times the user wants the do which operation.
    {
        printf("\nEnter 1 for Inserting node: ");
        printf("\nEnter 2 for Deleting node: ");
        printf("\nEnter 3 for Finding a node");
        printf("\nEnter 4 for displaying the stack: ");
        printf("\nEnter 5 for exiting: \n");
        int n;
        scanf("%d",&n);
        if(n == 1)
            push();//calling insert function.
        else if(n == 2)
            pop();//calling delete function
        else if(n == 3)
            find();//calling find function
        else if(n == 4)
            display();//calling display function
        else if(n == 5)
            break;//breaking the loop as soon as the user wants
    }
}
void push()
{
    printf("Enter no you want to insert: ");
    int n;
    scanf("%d",&n);
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));//dynamically allocation memory for temp
    temp->data = n;
    temp->link = top;
    top = temp;
}
void pop()
{
    if(top == NULL)
        printf("Stack underflow");
    else
    {
        struct node *temp = top;
        top = temp->link;
        free(temp);//freeing up the memory created by the element.
    }
}
void find()
{
    printf("\nEnter node to be found: ");
    int n;
    int count = 0;
    int c = 0;
    scanf("%d",&n);
    struct node *temp = top;
    while(temp->link!=NULL)//checking till last node,excluding last node
    {
        if(temp->data == n)
        {
            printf("%d found. It is in %d node",n,count);
            c = 1;
            break;
        }
        count++;
        temp = temp->link;
    }
    if(temp->link == NULL)//checking in last node
    {
        if(n == temp->data)
            c = 2;
        else
            c = 0;
    }
    if(c == 2)
        printf("%d found. It is in %d node",n,count);
    else if(c == 0)
        printf("Not found");
}
void display()
{
    if(top == NULL)
        printf("Stack is empty");
    else
    {
        struct node *temp = top;
        while(temp->link!=NULL)//print till last node,excluding last node.
        {
            printf("\n%d",temp->data);
            temp = temp->link;
        }
        printf("\n%d",temp->data);//printing in last node
    }
}
