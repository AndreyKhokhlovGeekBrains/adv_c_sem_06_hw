// Используя код задачи 1, написать программу поиска первого и последнего слова в строке.

// Пример №1
// Данные на входе: efg abcd zzz.
// Данные на выходе: efg zzz.

// Пример №2
// Данные на входе: fffff kkkkkk a.
// Данные на выходе: fffff a.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    char* word;
    struct node *next;
};

void print (struct node* list) {
    while (list != NULL) {
        printf("%s ", list->word);
        list = list->next;
    }
}

void printFirstLast (struct node* list) {
    if (list == NULL) return;
    char* last = list->word;
    char* first = NULL;
    
    while(1) {
        if (list->next == NULL) {
            first = list->word;
            break;
        }
        list = list->next;
    }

    printf("%s %s\n", first, last);
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

struct node* addNode(struct node* list, const char* value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->word = strdup(value); // allocates sufficient memory for the string and then copies the string to this newly allocated memory
    newNode->next = list;

    return newNode;
}

int main (void) {
    char word[100];
    struct node* list = NULL;

    printf("Enter a line of text (ending with a dot):\n");

    while (1) {
        scanf("%s", word);
        list = addNode(list, word);

        if (word[strlen(word) - 1] == '.') break;
    }

    printFirstLast(list);
    free_list(list);
    return 0;
}