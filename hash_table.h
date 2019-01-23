#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "any.h"

typedef struct hash_node hash_node;
typedef struct hash_table hash_table;

/**
 * @struct hash_node
 * @brief Define the node structure of hash table
 */
struct hash_node {
    size_t hash;       //!< Hash value
    size_t count;      //!< Occurences
    any key;           //!< key
    any value;         //!< value
    hash_node * next;   //!< Pointer to next node
};

/**
 * @struct hash_table
 * @brief Define the structure of hash table
 */
struct hash_table {
    size_t slots[2];         //!< Number of slots
    size_t nodes;            //!< Number of nodes
    size_t (*hash_fun)(const void *, size_t);  //!< Pointer to a hash function
    int (*compare)(const void *, const void *);
    hash_node **array[2];    //!< [0] Currently used array of node pointers [1] Expanded array of node pointers
};

/**
 * @brief Allocate a new hash table
 * @param slots Number of slots
 * @param fun Pointer to hash function
 * @return Pointer to hash table
 */
extern hash_table * hash_table_new(size_t capacity, size_t (*hash_fun)(const void *, size_t), int (*compare)(const void *, const void *));

/**
 * @brief Deconstruct a hash table as well as all nodes
 * @param table Pointer to hash table
 */
extern void hash_table_free(hash_table * table);

/**
 * @brief Insert a new key to hash table
 * @param table Pointer to hash table
 * @param key Pointer to key
 * @param key_len Length in bytes of key
 * @param val Pointer to value
 * @param val_len Length in bytes of value
 * @return Pointer to the node where the key was inserted
 */
extern hash_node * hash_table_insert(hash_table * table, const any key, const any value);

/**
 * @brief Delete a key from hash table
 * @param table Pointer to hash table
 * @param key Pointer to key
 * @param key_len Length in bytes of key
 */
extern void hash_table_delete(hash_table * table, const any key);

/**
 * @brief Search key in hash table
 * @param table Pointer to hash table
 * @param key Pointer to key
 * @param key_len Length in bytes of key
 * @return Pointer to the node if given key exists, otherwise null pointer
 */
extern hash_node * hash_table_find(const hash_table * table, const any key);

/**
 * @brief Find the pointer to value by given key
 * @param table Pointer to hash table
 * @param key Pointer to key
 * @param key_len Length in bytes of key
 * @return Pointer to value
 */
extern any * hash_table_get_val(const hash_table * table, const any key);

#endif // HASH_TABLE_H
