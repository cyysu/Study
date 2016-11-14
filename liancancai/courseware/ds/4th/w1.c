#include "llist.h"

struct word_t{
	char *en;
	char *cn;
};

void ls(void *data)
{
	struct word_t *word = (struct word_t *)data;

	printf("English : %s || chiness : %s\n", word->en, word->cn);
}

int cmp_en(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct word_t *)d2)->en);
}

void destory(LLIST *handle)
{
	struct node_t *tail = NULL, *save = NULL;

	for (tail = handle->head.next; tail != &handle->head; tail = save)
	{
		save = tail->next;
		free(((struct word_t *)(tail->data))->en);
		free(((struct word_t *)tail->data)->cn);
		free(tail->data);
		free(tail);
	}
	free(handle);
}
LLIST *load_wrod(const char *path)
{
	char buf[1024]; 
	LLIST *handle = NULL;
	FILE *fp = NULL;
	int count = 0;
	int flag = 1;
	//1 -> en -1 cn
	struct word_t word;//临时接受数据

	fp = fopen(path, "r");
	ERRP(fp == NULL, fopen, goto ERR1);

	handle = llist_create(sizeof(struct word_t));
	ERRP(handle == NULL, llist_create, goto ERR2);

	while(fgets(buf, sizeof(buf), fp) != NULL)
	{
		buf[strlen(buf) - 1] = '\0';
		count++;
		if (flag == 1)
		{
			//en:
			word.en = (char *)malloc(strlen(buf) + 1);
			strcpy(word.en, buf);
		}
		else
		{
			//cn:
			word.cn = (char *)malloc(strlen(buf) + 1);
			strcpy(word.cn, buf);
			llist_append(&word, handle);
		}
		flag = -flag;
	}

	/*printf("count = %d\n", count);*/
	fclose(fp);
	return handle;
ERR2:
	fclose(fp);
ERR1:
	return NULL;
}
int main(void)
{
	LLIST *handle = NULL;
	char buf[128];
	struct word_t *ind = NULL;

	handle = load_wrod("./ciku.dict");

	while(1)
	{
		GETLINES("please input find en : ", buf);
		if (strncmp(buf, "end", 3) == 0)
		{
			break;
		}
		ind = llist_ind(buf, cmp_en, handle);
		if (ind == NULL)
		{
			printf("no find!\n");
		}
		else
		{
			printf("%s\n", ind->cn);
		}
	}
	/*llist_travel(handle, ls, 0);*/
	destory(handle);

	return 0;
}
