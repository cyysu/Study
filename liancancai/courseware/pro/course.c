#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
    struct node_t *next;
    struct node_t *prev;
};

struct stu_t {
    int id;
    char name[128];
    char sex;
    struct node_t sel;
    struct node_t c_head;
};

struct class_t {
    char name[128];
    struct node_t sel;
    struct node_t s_head;
};

struct item_t {
    struct class_t *c;
    struct stu_t *s;
    struct node_t s_sel;
    struct node_t c_sel;
};

#define container_of(ptr, type, member)   ((type *)(((char *)(ptr)) - \
                ((unsigned long)(&(((type *)0)->member)))))

#define GETLINES(string, buf)       do                  \
                {                                       \
                    printf(string);                     \
                    fgets(buf, sizeof(buf), stdin);     \
                    if (buf[strlen(buf) - 1] == '\n')   \
                        buf[strlen(buf) - 1] = '\0';    \
                    else                                \
                    {                                   \
                        while (getchar() != '\n')       \
                            continue;                   \
                    }                                   \
                } while (0)

#define GETS(string, ret, cmd, ...)      do             \
            {                                           \
                int r;                                  \
                printf(string);                         \
                r = scanf(cmd, __VA_ARGS__);            \
                while (getchar() != '\n')               \
                    continue;                           \
                if (r == 0)                             \
                    ret;                                \
            } while (0)

void add_node(struct node_t *new, struct node_t *head)
{
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

int add_class(struct node_t *head)
{
    char name[128];
    struct class_t *c = NULL;

    while (1)
    {
        GETLINES("请输入课程名称(END为结束) : ", name);
        if (!strcasecmp(name, "end"))
            break;

        c = (struct class_t *)malloc(sizeof(struct class_t));
        c->s_head.next = &c->s_head;
        c->s_head.prev = &c->s_head;

        strcpy(c->name, name);

        add_node(&c->sel, head);
    }
}

void show_class(struct node_t *head)
{
    struct node_t *tail = NULL, *val = NULL;
    struct class_t *c = NULL;
    struct item_t *ip = NULL;

    for (tail = head->next; tail != head; tail = tail->next)
    {
        c = container_of(tail, struct class_t, sel);
        printf("\tname = %s, student : ", c->name);

        for (val = c->s_head.next; val != &c->s_head; val = val->next)
        {
            ip = container_of(val, struct item_t, c_sel);
            printf("%s ", ip->s->name); 
        }
        printf("\n");
    }
}

void destroy_cls(struct node_t *head)
{
    struct node_t *tail = head->next, *save = NULL; 
    struct class_t *c = NULL;

    while (tail != head)
    {
        save = tail->next;
        c = container_of(tail, struct class_t, sel);
        free(c);
        tail = save;
    }
}

int add_stu(struct node_t *head, struct node_t *cls_head)
{
    struct stu_t *s = NULL;
    struct class_t *c = NULL;
    struct node_t *tail = NULL;
    struct item_t *ip = NULL;
    char ch;

    s = (struct stu_t *)malloc(sizeof(struct stu_t));

    GETLINES("请输入学生姓名: ", s->name);
    s->id = rand() % 100;
    s->sex = rand() % 2 + 'A';
    s->c_head.next = &s->c_head;
    s->c_head.prev = &s->c_head;

    add_node(&s->sel, head);

    for (tail = cls_head->next; tail != cls_head; tail = tail->next)
    {
        c = container_of(tail, struct class_t, sel);
        printf("%s(Y/N): ", c->name);
        ch = getchar();
        while (getchar() != '\n')
            ;
        if (ch == 'Y' || ch == 'y')
        {
            ip = (struct item_t *)malloc(sizeof(struct item_t));
            ip->s = s;
            ip->c = c;

            add_node(&ip->s_sel, &s->c_head);
            add_node(&ip->c_sel, &c->s_head);
        }
    }

    return 0;
}

void show_stu(struct node_t *head)
{
    struct node_t *tail = NULL, *val = NULL;
    struct stu_t *s = NULL;
    struct item_t *ip = NULL;

    for (tail = head->next; tail != head; tail = tail->next)
    {
        s = container_of(tail, struct stu_t, sel);
        printf("\tid = %d, name = %s, sex = %c class: ",
                    s->id, s->name, s->sex);

        for (val = s->c_head.next; val != &s->c_head; val = val->next)
        {
            ip = container_of(val, struct item_t, s_sel);
            printf("%s ", ip->c->name); 
        }
        printf("\n");
    }
}

void destroy_stu(struct node_t *head)
{
    struct node_t *tail = NULL, *val = NULL, *save_tail = NULL, *save_val = NULL;
    struct stu_t *s = NULL;
    struct item_t *ip = NULL;

    for (tail = head->next; tail != head; tail = save_tail)
    {
        save_tail = tail->next;
        s = container_of(tail, struct stu_t, sel);

        for (val = s->c_head.next; val != &s->c_head; val = save_val)
        {
            save_val = val->next;
            ip = container_of(val, struct item_t, s_sel);
            free(ip);
        }
        free(s);
    }
}

int main(void)
{
    int n, quit = 0;
    struct node_t stu_head = {.next = &stu_head, .prev = &stu_head};
    struct node_t cls_head = {.next = &cls_head, .prev = &cls_head};

    srand(time(NULL));

    add_class(&cls_head);

    while (!quit)
    {
START:
        printf("====== 1. 添加学生 =======!\n");
        printf("====== 2. 遍历学生 =======!\n");
        printf("====== 3. 遍历课程 =======!\n");
        printf("====== 4. 退出系统 =======!\n");
        GETS("请输入 [ 1 - 4 ] : ", goto START, "%d", &n);

        switch (n)
        {
            case 1:
                add_stu(&stu_head, &cls_head);
                break;
            case 2:
                show_stu(&stu_head);
                break;
            case 3:
                show_class(&cls_head);
                break;
            case 4:
                quit = 1;
                break;
            default:
                break;
        }
    }

    destroy_cls(&cls_head);
    destroy_stu(&stu_head);

    return 0;
}
