#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node*next;
};
void swap(int* a, int* b);

void pairwiseswap(struct Node*head)
{
  if(head !=NULL && head->next !=NULL)
  {
     swap(&head->data, &head->next->data);
     pairwiseswap(head->next->next)
  }
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
void push(struct Node**head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printlist(struct Node* node)
{
   while(node != NULL)
   {
      printf("%d ", node->data);
      node = node->next;
   }
}

int main()
{
    struct Node* start = NULL;
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("Linked list before calling pairwiseswap()\n");
    printlist(start);
    pairwiseswap(start);

    printf("\nLinked list after calling pairwiseswap()\n");
    printlist(start);

return 0;
}
