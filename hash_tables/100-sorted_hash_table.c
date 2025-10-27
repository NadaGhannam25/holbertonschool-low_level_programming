#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * insert_sorted - Inserts a node into the sorted linked list
 * @ht: Pointer to the sorted hash table
 * @new_node: The new node to insert
 *
 * Description: Inserts node alphabetically by key into the
 * sorted doubly linked list (shead <-> stail).
 */
void insert_sorted(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		return;
	}

	tmp = ht->shead;
	while (tmp && strcmp(new_node->key, tmp->key) > 0)
		tmp = tmp->snext;

	if (tmp == ht->shead)
	{
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else if (tmp == NULL)
	{
		new_node->sprev = ht->stail;
		ht->stail->snext = new_node;
		ht->stail = new_node;
	}
	else
	{
		new_node->snext = tmp;
		new_node->sprev = tmp->sprev;
		tmp->sprev->snext = new_node;
		tmp->sprev = new_node;
	}
}

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: Pointer to the new sorted hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
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
 * shash_table_set - Adds or updates a key/value pair in a sorted hash table
 * @ht: The sorted hash table
 * @key: The key to add/update
 * @value: The value to associate with the key
 *
 * Return: 1 if success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node, *tmp;
	char *new_value;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (0);
	}

	node->next = ht->array[index];
	ht->array[index] = node;
	node->sprev = NULL;
	node->snext = NULL;
	insert_sorted(ht, node);

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The sorted hash table
 * @key: The key to look for
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table in ascending order
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int comma = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma = 1;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int comma = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma = 1;
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and frees memory
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(ht->array);
	free(ht);
}
