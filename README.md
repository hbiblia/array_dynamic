# array_dynamic
Creamos un método para guardar datos en un array dinámico.


    struct array *tmp = array_new();
    array_append(tmp, "Hola Mundo");
    array_append(tmp, "Pokemon!!");
    array_append(tmp, "Dragon Super");
    
    for(int i = 0; i<array_length(tmp); i++){
        printf("Out: %s\n",array_get(tmp,i));
    }

    array_free(tmp);
    
Resultado

Out: Hola Mundo                                                                                                                          
Out: Jhonson Ozuna                                                                                                                       
Out: Dragon Super 
