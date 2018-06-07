#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int             data;
    struct node_    *next;
}node_t;

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;

    return tmp;
}

node_t *
create_list(int count)
{
    node_t *curr,*head = NULL;
    int value = 10;

    while(count)
    {
        if(head == NULL)
        {
            head = curr = get_node(value);
        }
        else
        {
            curr->next = get_node(value);
            curr = curr->next;
        }
        count--;
        value += 10;
    }

    return head;
}


void
print(node_t *list)
{
    while(list != NULL)
    {
        printf("[%d]-->", list->data);
        list = list->next;
    }
    printf("[NULL]\n");
}


node_t *
middle_node(node_t *list)
{
    node_t *fast = list, *slow = list;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}




int
main()
{
    node_t *head = get_node(10);
    head->next = get_node(20);
    head->next->next = get_node(30);
    head->next->next->next = get_node(40);
    head->next->next->next->next = get_node(50);
    head->next->next->next->next->next = get_node(60);
    head->next->next->next->next->next->next = get_node(70);

    print(head);
    node_t *mid = middle_node(head);
    printf("Middle Node = [%d]\n", mid->data);

    head = create_list(8);
    print(head);
    mid = middle_node(head);
    printf("Middle Node = [%d]\n", mid->data);
    
    return 0;
}
