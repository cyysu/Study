#ifndef __KEN_LLIST_H__
#define __LEN_LLIST_H__

struct node_t {
    void *data;
    struct node_t *prev;
    struct node_t *next;
};

typedef struct llist_t {
    struct node_t head;
    int size;
    int num;
}LLIST;

#define ERR(con, ret)       do              \
                            {               \
                                if (con)    \
                                {           \
                                    ret;    \
                                }           \
                            } while (0)

#define MAGIC       "LLIST"

typedef void (llist_op_t)(const void *, void *);
typedef void (llist_destroy_t)(const void *);
typedef int (llist_cmp_t)(const void *, const void *);
typedef int (llist_file_t)(const void *, FILE *);


extern LLIST *llist_create(int size);
extern void llist_destroy(LLIST *handle, llist_destroy_t *op);
extern int llist_append(void *data, LLIST *handle);
extern int llist_sort_insert(void *data, llist_cmp_t *cmp, LLIST *handle);
extern void llist_sort(llist_cmp_t *cmp, LLIST *handle);
extern int llist_delete(void *key, llist_cmp_t *cmp, llist_destroy_t *op, LLIST *handle);
extern int llist_deleteall(void *key, llist_cmp_t *cmp, llist_destroy_t *op, LLIST *handle);
extern void *llist_find(void *key, llist_cmp_t *cmp, LLIST *handle);
extern LLIST *llist_findall(void *key, llist_cmp_t *cmp, LLIST *handle);
extern void llist_travel(llist_op_t *op, void *args, LLIST *handle);
extern int llist_store(const char *path, llist_file_t *op, LLIST *handle);
extern LLIST *llist_load(const char *path, llist_file_t *op);

#endif /* __LLIST_H__*/
