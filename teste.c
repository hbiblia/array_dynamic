
#include <stdio.h>
#include <stdlib.h>
#include "array_dynamic.h"

int main()
{
    PtrArray *array = ad_array_new();

    ad_array_append(array, "hola");
    ad_array_append(array, "mundo");
    ad_array_append(array, "cruel");
    ad_array_append(array, "!");
    ad_array_append(array, "aaaaah");

    void* data = ad_array_remove(array, 4);

    for (int i = 0; i < array->length; i++)
    {
        printf("%s\n", (char*)ad_array_get(array, i));
    }

    ad_array_free(array);

    return 0;
}




