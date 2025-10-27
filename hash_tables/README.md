#  C - Hash Tables

This project focuses on implementing and understanding **hash tables** in the C programming language.  
A hash table is a powerful data structure that allows efficient **data storage and retrieval** using a key–value mapping system.

---

## 🧠 Learning Objectives

- What a **hash function** is and how it works  
- What **hash tables** are and how to use them  
- What **collision** means and how to handle it  
- What the **djb2** algorithm does  
- How to deal with **key/value pairs**  
- How to implement both **unsorted** and **sorted** hash tables  

---
## 📋 Requirements
- Allowed editors: **vi**, **vim**, **emacs**
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options **-Wall -Werror -Wextra -pedantic -std=gnu89**
- All your files should end with a new line
- A **README.md** file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using **betty-style.pl** and **betty-doc.pl**
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the C standard library
- The prototypes of all your functions should be included in your header file called **hash_tables.h**
- Don’t forget to push your header file
- All your header files should be include guarded

---

## ⚙️ Project Files

| File | Description |
|------|--------------|
| `hash_tables.h` | Header file containing all function prototypes and data structures |
| `0-hash_table_create.c` | Function that creates a new hash table |
| `1-djb2.c` | Implementation of the djb2 hashing algorithm |
| `2-key_index.c` | Function that maps a key to an index using the djb2 hash |
| `3-hash_table_set.c` | Adds or updates key/value pairs in the hash table |
| `4-hash_table_get.c` | Retrieves a value associated with a given key |
| `5-hash_table_print.c` | Prints the contents of a hash table |
| `6-hash_table_delete.c` | Deletes and frees all memory used by a hash table |
| `100-sorted_hash_table.c` | (Advanced) Implementation of a sorted hash table |

---

## 🧩 Data Structures

```
/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string (unique)
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the list
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

## 🧩 Compilation :
```
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hash
./hash
```

## 🧮 Example Output :
```
{'Betty': 'Cool', 'python': 'awesome', 'c': 'fun'}
```

## 💡 Author

- 👩‍💻 **Nada Al-Mutairi**
