#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    int Node *next;
};

void insertatbegining(int value)
{
    struct newNode *newNode;
    newNode = (struct Node *)malloc(sizeof *(struct Node));
    if (Head == NULL)
    {
        newNode = Head;
        Head = newNode;
    }
    else
    {
        newNode->d1 = value;
        newNode->n1 = newNode;
    }
    printf("New node inserted./n");
}
int main()
{
    printf("Enter data\n");
    scanf(% d, value);
    insertatbegining(value);
    return 0;
}