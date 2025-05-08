#ifndef COMMON_LIST_H
#define COMMON_LIST_H

#include <SDL3/SDL.h>


typedef struct common_linked_list {
    struct common_linked_list *next;
    union { ;
        void *data;
        char *str;
    };
} common_linked_list;

common_linked_list *common_linked_list_append(common_linked_list **list, void *data) {
    while ((*list) != NULL) {
        list = &(*list)->next;
    }
    common_linked_list *new_item = (common_linked_list *) SDL_malloc(sizeof(common_linked_list));
    new_item->next = NULL;
    new_item->data = data;
    *list = new_item;
    return new_item;
}

#endif // COMMON_LIST_H
