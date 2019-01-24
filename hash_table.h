#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include "any.h"

typedef struct hash_node hash_node;
typedef struct hash_table hash_table;

struct hash_node {
    size_t hash;       //!< Hash value
    size_t count;      //!< Occurences
    any key;           //!< key
    any value;         //!< value
    hash_node * next;   //!< Pointer to next node
};

struct hash_table {
    size_t slots[2];         //!< Number of slots
    size_t nodes;            //!< Number of nodes
    size_t (*hash_fun)(const void *, size_t);  //!< Pointer to a hash function
    int (*compare)(const void *, const void *);
    hash_node ** array[2];    //!< [0] Currently used array of node pointers [1] Expanded array of node pointers
};

extern hash_table * hash_table_new(size_t capacity, size_t (*hash_fun)(const void *, size_t), int (*compare)(const void *, const void *));
extern void hash_table_free(hash_table * table);
extern hash_node * hash_table_insert(hash_table * table, const any key, const any value);
extern void hash_table_delete(hash_table * table, const any key);
extern hash_node * hash_table_find(const hash_table * table, const any key);
extern any * hash_table_get_val(const hash_table * table, const any key);

#endif // HASH_TABLE_H
