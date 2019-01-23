#include "hash_table.h"

/* Chaining hash table */

hash_table * hash_table_new(size_t capacity, size_t (*hash_fun)(const void *, size_t), int (*compare)(const void *, const void *)) {
    hash_table * table = malloc(sizeof(hash_table));
    table->array[0] = malloc(sizeof(hash_node *) * capacity);
    memset(table->array[0], 0, sizeof(hash_node *) * capacity);
    table->array[1] = NULL;
    table->slots[0] = capacity;
    table->nodes = 0;
    table->hash_fun = hash_fun;
    table->compare = compare;

    return table;
}

/**
 * @brief Allocate a new hash_node
 * @param key Pointer to key
 * @param key_len Length in bytes of key
 * @param val Pointer to value
 * @param val_len Length in bytes of value
 * @return Pointer to new node
 */
static hash_node * hash_node_new(const hash_table *table, const any * key, const any * value) {
	hash_node * node = malloc(sizeof(hash_node));
	node->hash = table->hash_fun(any_get_ref(key), any_size(key));
	node->count = 1;
    node->next = NULL;
	node->key = *key;
    node->value = *value;

	return node;
}

static void hash_node_free(hash_node * node) {
    free(node);
}

void hash_table_free(hash_table * table) {
	hash_node *cur, *next;
	int arrs = table->array[1] ? 2 : 1;

	for(int i = 0; i < arrs; i++) {
		for(size_t j = 0; j < table->slots[i]; j++) {
			cur = table->array[i][j];
			while (cur) {
				next = cur->next;
				hash_node_free(cur);
				cur = next;
			}
		}
        free(table->array[i]);
	}

    free(table);
}

/**
 * @brief Expand hash table size
 * @param table Pointer to hash table
 */
static void hash_table_expand(hash_table * table) {
    table->slots[1] = table->slots[0] * 2;
	table->array[1] = malloc(sizeof(hash_node *) * table->slots[1]);
    memset(table->array[1], 0, sizeof(hash_node *) * table->slots[1]);
}

/**
 * @brief Find the address for inserting, deleting and searching key
 * @param table Pointer to hash table
 * @param key Pointer to key
 * @param key_len Length in bytes of key
 */
static hash_node ** hash_table_find_place(const hash_table * table, const any * key) {
	size_t hash = table->hash_fun(any_get_ref(key), any_size(key));
	int arrs = table->array[1] ? 2 : 1;
	hash_node **p = NULL;

	for (int i = 0; i < arrs; i++) {
		size_t index = hash % table->slots[i];
		p = &table->array[i][index];

        while (*p) {
            if ((*p)->hash == hash && table->compare(any_get_ref(key), any_get_ref(&(*p)->key)) == 0) {
                return p;
            }
            else {
                p = &(*p)->next;
            }
        }
	}

	return p;
}

/**
 * @brief Move a node from old list to new expanded list
 * @param table Pointer to hash table
 */
static void hash_table_move(hash_table * table) {
	hash_node *node = NULL;

	for(size_t i = 0; i < table->slots[0]; i++) {
		node = table->array[0][i];
		if (node) {
			table->array[0][i] = node->next;
			node->next = NULL;
			break;
		}
	}

	if (node) {
		hash_node **p = hash_table_find_place(table, &node->key);
		*p = node;
	}
	else {
		free(table->array[0]);
		table->array[0] = table->array[1];
		table->array[1] = NULL;
		table->slots[0] *= 2;
	}
}

hash_node * hash_table_insert(hash_table *table, const any key, const any value) {
	hash_node ** p = hash_table_find_place(table, &key);
	hash_node * node = NULL;

	if (*p) {
		(*p)->count++;
        (*p)->value = value;
		node = *p;
	}
	else {
		*p = hash_node_new(table, &key, &value);
		table->nodes++;
	}

	if (table->nodes >= table->slots[0] && !table->array[1]) {
        hash_table_expand(table);
    }

	if (table->array[1]) {
        hash_table_move(table);
    }

	return node;
}

void hash_table_delete(hash_table * table, const any key) {
	hash_node ** p = hash_table_find_place(table, &key);

	if (*p) {
		hash_node *del = *p;
		*p = (*p)->next;
		hash_node_free(del);
		table->nodes--;
	}
}

hash_node * hash_table_find(const hash_table * table, const any key) {
	return *hash_table_find_place(table, &key);
}

any * hash_table_get_val(const hash_table * table, const any key) {
	hash_node ** node = hash_table_find_place(table, &key);

	if (*node) {
        return &(*node)->value;
    }
	else {
        return NULL;
    }
}
