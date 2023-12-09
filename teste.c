
#include <stdio.h>
#include <stdlib.h>
#include "array_dynamic.h"

int main()
{
    PtrArray *array = ad_array_new();
    ad_array_append(array, "Hola Mundo");
    ad_array_append(array, "Pokemon!!");
    ad_array_append(array, "Dragon Super");

    void* data = ad_array_remove(array, 2);
    
    for (int i = 0; i < array->length; i++) {
        printf("%s\n", (char*)ad_array_get(array, i));
    }
    printf("Eliminado: %s\n", (char*)data);
    ad_array_free(array);

    return 0;
}




