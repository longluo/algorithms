#include <iostream>
#include <cstring>

// 定义哈希桶的节点结构体
typedef struct Node
{
    char *key;
    int value;
    struct Node *next;
} Node;

// 定义哈希表结构体
typedef struct HashMap
{
    int size;
    Node **buckets;
} HashMap;

// 创建指定大小的哈希表
HashMap *createHashMap(int size)
{
    auto *map = (HashMap *)malloc(sizeof(HashMap));
    map->size = size;
    map->buckets = (Node **)calloc(size, sizeof(Node *));
    return map;
}

// 哈希函数
int hash(HashMap *map, char *key)
{
    int sum = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        sum += key[i];
    }

    return sum % map->size;
}

void put(HashMap *map, char *key, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = nullptr;

    int index = hash(map, key);
    Node *curr = map->buckets[index];

    if (curr == nullptr)
    {
        map->buckets[index] = newNode;
    }
    else
    {
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// 从哈希表中获取指定键的值
int get(HashMap *map, char *key)
{
    int index = hash(map, key);
    Node *curr = map->buckets[index];

    while (curr != nullptr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            return curr->value;
        }
        curr = curr->next;
    }

    return -1; // 如果没有找到，返回 -1
}

// 释放哈希表的内存
void freeHashMap(HashMap *map)
{
    for (int i = 0; i < map->size; i++)
    {
        Node *curr = map->buckets[i];
        while (curr != nullptr)
        {
            Node *temp = curr;
            curr = curr->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

int main()
{
    HashMap *map = createHashMap(10);

    char a[] = "apple", b[] = "banana", o[] = "orange", w[] = "watermelon";
    put(map, a, 1);
    put(map, b, 2);
    put(map, o, 3);

    printf("Value of 'apple': %d\n", get(map, a));
    printf("Value of 'banana': %d\n", get(map, b));
    printf("Value of 'orange': %d\n", get(map, o));
    printf("Value of 'watermelon': %d\n", get(map, w));

    freeHashMap(map);

    return 0;
}
