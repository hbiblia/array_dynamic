
#ifndef ARRAY_DYNAMIC_H
#define ARRAY_DYNAMIC_H

#include <stdio.h>

struct array{
  void *data;
  int length;
};

/* iniciamos un nuevo array */
struct array *array_new(void)
{
    struct array *tmp = (struct array*)malloc(sizeof(struct array)+2);
    tmp[0].length = 0;
    return tmp;
}

/* creamos un nuevo valor */
void array_append(struct array *a, void *data)
{
    a[ a[0].length ].data = data;
    a[0].length++;
}

/* obtenemos un valor del array */
void *array_get(struct array *a, int index)
{
    return a[index].data;
}

/* borramos todo el array */
void array_free(struct array *a)
{
    free(a);
}

/* contamos la cantidad de datos que tienen el array */
int array_length(struct array *a)
{
    return a[0].length;
}

#endif
