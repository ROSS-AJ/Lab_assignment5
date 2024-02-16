//Aniya Ross
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    //declare and initialize variables
    int numNodes = 0;
    struct node* temp = head;
    //track the number of nodes traversed through while iterating through linked list
    if(head == NULL)
        return numNodes;

    while(temp!= NULL)
    {
        temp = temp->next;
        numNodes++;
    }
    //return number of nodes in linked list
    return numNodes;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    //declare and initialize variables
    int stringLength = length(head) + 1;
    char *list_string = (char*)malloc(stringLength*sizeof(char));

    struct node* temp = head;
    int index = 0;
    //traverse through linked list and copy each letter of the linked list into char array
    while(temp!=NULL)
    {
        list_string[index] = temp->letter;
        temp = temp -> next;
        index++;
    }
    //insert null character at end of string
    list_string[index] = '\0';

    //return finished string
    return list_string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    //declare & initialize variables
    struct node* temp = *pHead;
    struct node* newChar = (struct node*)malloc(sizeof(struct node*));
    newChar->letter = c;
    newChar->next = NULL;

    //check if head of linked list is null
    if(*pHead == NULL)
    {
        *pHead = newChar;
        return;
    }
    //traverse to the end of the linked list
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    //insert new character node into linked list
    temp->next = newChar;

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    *pHead = NULL;
}
int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;

    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}