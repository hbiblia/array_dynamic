# array_dynamic
Creamos un método para guardar datos en un array dinámico.


    struct array *tmp = array_new();
    tmp = array_append(tmp, "Hola Mundo"); // espero eliminar esa salida pronto.
    tmp = array_append(tmp, "Pokemon!!");
    tmp = array_append(tmp, "Dragon Super");
    
    for(int i = 0; i<array_length(tmp); i++){
        printf("Out: %s\n",array_get(tmp,i));
    }

    array_free(tmp);
    
Resultado

Out: Hola Mundo                                                                                                                          
Out: Pokemon!!                                                                                                                       
Out: Dragon Super 
