#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct nlist {					/* table entry */
	struct nlist *next;			/* next entry in chain */
	char *name;					/* defined name */
	char *defn;					/* replacement text */
};

#define HASHSIZE	101

static struct nlist *hashtab[HASHSIZE];		/* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; ++s)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;	/* found */

	return NULL;		/* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free((void *) np->defn);

	if ((np->defn = strdup(defn)) == NULL)
		return NULL;

	return np;
}

void undefn(char *s)
{
	struct nlist *q, *p;

	for (q = NULL, p = hashtab[hash(s)];
			p != NULL;
			q = p, p = p->next)
		if (strcmp(s, p->name) == 0)
			break;

	if (p != NULL) {
		if (q == NULL)
			hashtab[hash(s)] = p->next;
		else
			q->next = p->next;
		free(p);
	}
}

int
main()
{
	install("name", "value");
	printf("%s\n", lookup("name")->defn);
	assert(lookup("name") != NULL);
	undefn("name");
	assert(lookup("name") == NULL);
	return 0;
}
