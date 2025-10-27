#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static shash_node_t *shash_node_create(const char *key, const char *value);
static void sorted_insert(shash_table_t *ht, shash_node_t *node);

/**
 * shash_table_create - Create a sorted hash table
 * @size: array size
 *
 * Return: pointer to new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(*ht));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(*ht->array) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * shash_table_set - Add or update a key/value in a sorted hash table
 * @ht: sorted hash table
 * @key: key (non-empty)
 * @value: associated value (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *curr, *node;
	char *dup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	for (curr = ht->array[idx]; curr; curr = curr->next)
	{
		if (strcmp(curr->key, key) == 0)
		{
			dup = strdup(value);
			if (dup == NULL)
				return (0);
			free(curr->value);
			curr->value = dup;
			return (1);
		}
	}
	node = shash_node_create(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[idx];
	ht->array[idx] = node;
	sorted_insert(ht, node);

	return (1);
}

/**
 * shash_table_get - Retrieve a value by key
 * @ht: sorted hash table
 * @key: key to look up
 *
 * Return: value string, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *curr;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);

	for (curr = ht->array[idx]; curr; curr = curr->next)
	{
		if (strcmp(curr->key, key) == 0)
			return (curr->value);
	}
	return (NULL);
}

/**
 * shash_table_print - Print the table in ascending key order
 * @ht: sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *n;
	int comma = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (n = ht->shead; n; n = n->snext)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", n->key, n->value);
		comma = 1;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Print the table in reverse key order
 * @ht: sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *n;
	int comma = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (n = ht->stail; n; n = n->sprev)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", n->key, n->value);
		comma = 1;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Free the entire sorted hash table
 * @ht: sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *n, *next;

	if (ht == NULL)
		return;

	for (n = ht->shead; n; n = next)
	{
		next = n->snext;
		free(n->key);
		free(n->value);
		free(n);
	}
	free(ht->array);
	free(ht);
}

/**
 * shash_node_create - Allocate and fill a new sorted hash node
 * @key: key to duplicate
 * @value: value to duplicate
 *
 * Return: pointer to node or NULL
 */
static shash_node_t *shash_node_create(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;
	return (node);
}

/**
 * sorted_insert - Insert a node into the global sorted DLL (by key, ASCII)
 * @ht: sorted hash table
 * @node: node to insert (unique key guaranteed by caller)
 *
 * Description: Maintains shead/stail and fixes neighbors' links.
 */
static void sorted_insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *p;

	/* empty list */
	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	/* at head */
	if (strcmp(node->key, ht->shead->key) < 0)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
		return;
	}

	/* walk until we find first key >= node->key */
	for (p = ht->shead; p->snext && strcmp(p->snext->key, node->key) < 0; p = p->snext)
		;

	/* at tail */
	if (p->snext == NULL)
	{
		node->sprev = p;
		p->snext = node;
		ht->stail = node;
		return;
	}

	/* between p and p->snext */
	node->snext = p->snext;
	node->sprev = p;
	p->snext->sprev = node;
	p->snext = node;
}
