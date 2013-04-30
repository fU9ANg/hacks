
/*
 * Written 2013 by fU9ANg
 * bb.newlife@gmail.com
 */

#ifndef _CHAT_LIST_H
#define _CHAT_LIST_H

/*
====================
 insert a node to list
====================
*/
#define INSERT_TO_LIST(list, item, prev, next) \
if (!list) \
{ \
    list = item; \
    list->prev = list->next = list; \
} \
else \
{ \
    item->prev = list->prev; \
    item->next = list; \
    list->prev = item; \
    item->prev->next = item; \
}

/*
====================
 remove a node from list
====================
*/
#define REMOVE_FROM_LIST(list, item, prev, next) \
if (item == list) \
{ \
    if (item == item->next) \
        list = NULL; \
    else \
        list = item->next; \
} \
if (list) \
{ \
    item->prev->next = item->next; \
    item->next->prev = item->prev; \
}

/*
====================
 list loop
====================
*/
#define LIST_WHILE(list, item, temp_d, next) \
if ((item == list)) \
{ \
    do { \
        temp_d = item->next;

/*
====================
 loop end of list
====================
*/
#define LIST_WHILEEND(list, item, temp_d) \
        item = temp_d; \
    } while (list && item && (item != list)); \
}

/*
====================
 do nothing for temp node of list
====================
*/
#define LIST_SKIP(item, temp_d) \
{ \
    item = temp_d; \
    continue; \
}

#endif  //_CHAT_LIST_H
