#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node * node_ptr;

node_ptr createList();

void freeList(node_ptr list);

void printList(node_ptr list);

node_ptr addElement(node_ptr list, int element);

int get(node_ptr list, int elem);

node_ptr removeFromList(node_ptr list, int index);

int last(node_ptr list);

int main() {

    node_ptr list;

    list = createList();

    char input[6];
    char exitCheck[] = "exit";
    char putCheck[] = "put";
    char getCheck[] = "get";
    char firstCheck[] = "first";
    char lastCheck[] = "last";
    char removeCheck[] = "remove";
    char listCheck[] = "list";
    char clearCheck[] = "clear";
    int sizeList = 0;

    do {
        scanf("%s", input);
        
        if(strcmp(putCheck, input) == 0) {
            int new_el;
            scanf("%d", &new_el);
            list = addElement(list, new_el);
            printList(list);
            sizeList++;
        } else if (strcmp(getCheck, input) == 0) {
            int index;
            scanf("%d", &index);
            if(index < 1 || index > sizeList) {
                printf("Invalid search index. Please continue.\n");
            } else {
                printf("%d\n", get(list, index));
            }
        } else if (strcmp(firstCheck, input) == 0) {
            if (list != NULL) {
                printf("%d\n", list->data);
            } else {
                printf("List is currently empty.\n");
            }
        } else if (strcmp(lastCheck, input) == 0) {
            if (list != NULL) {
                printf("%d\n", last(list));
            } else {
                printf("List is currently empty.\n");
            }
        } else if (strcmp(removeCheck, input) == 0) {
            int index;
            scanf("%d", &index);
            if(index < 1 || index > sizeList) {
                printf("Invalid search index. Please continue.\n");
            } else {
                list = removeFromList(list, index);
                printList(list);
                sizeList--;
            }
        } else if (strcmp(listCheck, input) == 0) {
            printList(list);
        } else if (strcmp(clearCheck, input) == 0) {
            freeList(list);
            list = NULL;
        } else {
            printf("invalid command. Please try again.\n");
        }
    

    } while (strcmp(exitCheck, input) != 0);

    freeList(list);

    return 0;
}


node_ptr createList() {
    return NULL;
}

void freeList(node_ptr list) {
    if(list != NULL) {
        freeList(list->next);
        free(list);
    }
}

void printList(node_ptr list) {
    node_ptr ptr;

    for (ptr = list; ptr != NULL; ptr = ptr->next) {
        printf("%d ", ptr->data);
    }
    printf("\n");
}

node_ptr addElement(node_ptr list, int element) {
    node_ptr newPtr;
    node_ptr aux;

    newPtr = malloc(sizeof(node));
    if (newPtr == NULL) {
        printf("There are not enough memory!");
        freeList(list);
        exit(1);
    }
    newPtr->next = NULL;
    newPtr->data = element;
    aux = list;

    if (list == NULL) {
        list = newPtr;
    } else {
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = newPtr;
    }

    return list;
}

int get(node_ptr list, int index) {

    while(index != 1) {
        list = list->next;
        index--;
    }

    return list->data;
}

node_ptr removeFromList(node_ptr list, int index) {

    node_ptr before, current;
    before = list;
    current = list->next;

    if (index == 1) {
        printf("%d\n", list->data);
        free(list);
        list = current;
    } else {
        index--;
        while(index != 1) {
            current = current->next;
            before = before->next;
            index--;
        }
        before->next = current->next;
        printf("%d\n", current->data);
        free(current);
    }

    return list;
}

int last(node_ptr list) {
    node_ptr aux;
    aux = list;

    while(aux->next != NULL) {
        aux = aux->next;
    }
    return aux->data;
}
