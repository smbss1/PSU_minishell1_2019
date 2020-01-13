/*
** EPITECH PROJECT, 2019
** dictionary_sort
** File description:
** Sort the dictionary
*/

#include <stdlib.h>
#include "my.h"

dictionary *merge_sort(dictionary *a, dictionary *b, int (*cmp)(void *, void *))
{
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (cmp(a, b) <= 0) {
        a->next = merge_sort(a->next, b, cmp);
        a->next->prev = a;
        a->prev = NULL;
        return (a);
    } else {
        b->next = merge_sort(a, b->next, cmp);
        b->next->prev = b;
        b->prev = NULL;
        return (b);
    }
}

dictionary *front_back_split(dictionary *source)
{
    dictionary *slow = source;
    dictionary *fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    dictionary *tmp = slow->next;
    slow->next = NULL;
    return (tmp);
}

void dictionary_sort(dictionary **dict, int (*compare)(void *, void *))
{
    dictionary *head = *dict;

    if (head == NULL || head->next == NULL)
        return;

    dictionary *b = front_back_split(head);
    dictionary_sort(&head, compare);
    dictionary_sort(&b, compare);
    *dict = merge_sort(head, b, compare);
}

int my_strcmp_key(void *a, void *b)
{
    return my_strcmp(((dictionary *) a)->key, ((dictionary *) b)->key);
}

void dictionary_sort_by_key(dictionary **dict)
{
    dictionary_sort(dict, my_strcmp_key);
}