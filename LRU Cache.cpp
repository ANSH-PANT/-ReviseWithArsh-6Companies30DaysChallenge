#define MOD 5023

typedef struct DNode {
    int key;
    int val;
    struct DNode* prev;
    struct DNode* next;
} DNode;

typedef struct {
    DNode** ht;
    DNode* pool;
    DNode* freep;
    DNode* deleted;
    DNode* sentinel;
    int size;
    int capacity;
} LRUCache;

int hash(int key) { 
  return key % MOD; 
}

int find(DNode** ht, int key) {
    DNode* n;
    int i, newIndex, index = hash(key);
    for (i = 0; i < MOD; ++i) {
        newIndex = (index + i * i) % MOD;
        n = ht[newIndex];
        if (n == NULL) {
            return -1;
        }
        if (n->key == key) {
            return newIndex;
        }
    }
    return -1;
}

LRUCache* lRUCacheCreate(int capacity) {
    int i;
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->ht = (DNode**)calloc(MOD, sizeof(DNode*));
    obj->sentinel = (DNode*)malloc(sizeof(DNode));
    obj->sentinel->prev = obj->sentinel;
    obj->sentinel->next = obj->sentinel;
    obj->pool = (DNode*)malloc((capacity + 1) * sizeof(DNode));
    obj->pool[capacity].next = NULL;
    for (i = capacity - 1; i >= 0; --i) {
        obj->pool[i].next = &obj->pool[i + 1];
    }
    obj->freep = &obj->pool[0];
    obj->deleted = malloc(sizeof(DNode));
    obj->deleted->key = INT_MAX;
    obj->size = 0;
    obj->capacity = capacity;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    int index, retVal;
    DNode *p, *q, *n;
    index = find(obj->ht, key);
    if (index < 0) {
        retVal = -1;
    } else {
        n = obj->ht[index];
        retVal = n->val;
        p = n->prev;
        q = n->next;
        p->next = q;
        q->prev = p;
        n->next = obj->sentinel->next;
        n->prev = obj->sentinel;
        obj->sentinel->next = n;
        n->next->prev = n;
    }
    return retVal;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    DNode *p, *q, *n;
    int i, newIndex, index = find(obj->ht, key);
    if (index > 0) {
        n = obj->ht[index];
        n->val = value;
        p = n->prev;
        q = n->next;
        p->next = q;
        q->prev = p;
    } else {
        n = obj->freep;
        obj->freep = obj->freep->next;
        n->key = key;
        n->val = value;
        index = hash(key);
        for (i = 0; i < MOD; ++i) {
            newIndex = (index + i * i) % MOD;
            if (obj->ht[newIndex] == NULL ||
                obj->ht[newIndex] == obj->deleted) {
                break;
            }
        }
        obj->ht[newIndex] = n;
        if (obj->size < obj->capacity) {
            ++obj->size;
        } else {
            p = obj->sentinel->prev;
            obj->sentinel->prev = p->prev;
            p->prev->next = obj->sentinel;
            index = find(obj->ht, p->key);
            obj->ht[index] = obj->deleted;
            p->next = obj->freep;
            obj->freep = p;
        }
    }
    n->prev = obj->sentinel;
    n->next = obj->sentinel->next;
    obj->sentinel->next = n;
    n->next->prev = n;
}

void lRUCacheFree(LRUCache* obj) {
    DNode *p, *q;
    p = obj->sentinel->next;
    free(obj->pool);
    free(obj->ht);
    free(obj->deleted);
    free(obj->sentinel);
    free(obj);
}
