// Напишите программу, которая удаляет из списка все элементы с нечетным порядковым номером.

// Пример №1
// Данные на входе: aa ss dd ff gg hh jj kk ll.
// Данные на выходе: aa dd gg jj ll

// Пример №2
// Данные на входе: aa ss dd ff gg hh jj kk ll tt.
// Данные на выходе: aa dd gg jj ll

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    char* word;
    int index;
    struct node *next;
};

struct node* addNode(struct node* list, const char* value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->word = strdup(value);
    int ind;
    if(list == NULL) {
        newNode->index = 0;
    } else {
        ind = list->index;
        newNode->index = ++ind;
    }
    newNode->next = list;

    return newNode;
}

void print (struct node* list) {
    if (list == NULL) return;
    print(list->next);
    printf("%s ", list->word);
    printf("%d ", list->index);
}

void removeOddElements(struct node **list) {
    struct node* current = *list;
    struct node* prev = NULL;

    while (current != NULL) {
        if (current->index % 2 == 1) {
            struct node* temp = current;
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                *list = current->next;
            }
            current = current->next;
            free(temp->word);
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void free_list(struct node* list) {
    struct node* temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp->word);
        free(temp);
    }
}

int main (void) {
    char input[100];
    struct node* list = NULL;

    printf("Enter a line of text (ending with a dot):\n");

    while (1) {
        scanf("%s", input);
        if (input[strlen(input) - 1] == '.') {
            input[strlen(input) - 1] = '\0';
            list = addNode(list, input);
            break;
        }
        list = addNode(list, input);
    }

    print(list);
    printf("\n");
    removeOddElements(&list);
    print(list);
    free_list(list);
    return 0;
}