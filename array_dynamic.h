/**
 * @file array_dynamic.h
 * @brief This file contains the MIT License for the array_dynamic library.
 * @author Jhonson Ozuna - hbiblia@gmail.com
 *
 * The array_dynamic library provides functions for working with dynamically allocated arrays.
 * It allows users to create, resize, access, and modify arrays of any data type.
 *
 * @license MIT License
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ARRAY_DYNAMIC_H
#define ARRAY_DYNAMIC_H

#include <stdio.h>
#include <stdlib.h>

// estructura del array
typedef struct PtrArray {
    void** data; // Use double pointer to store array of pointers
    int length;
}PtrArray;

/**
 * @brief Crea un nuevo arreglo dinámico.
 * 
 * @return Puntero al nuevo arreglo dinámico.
 */
PtrArray* ad_array_new(void)
{
    PtrArray* tmp = (PtrArray*)malloc(sizeof(PtrArray));
    tmp->length = 0;
    tmp->data = NULL;
    return tmp;
}

/**
 * @brief Libera la memoria asignada a un arreglo dinámico.
 *
 * @param array El puntero al arreglo dinámico.
 */
void ad_array_free(PtrArray* array)
{
    if (array == NULL) return;
    free(array->data);
    free(array);
}

/**
 * Añade un elemento al final del arreglo dinámico.
 *
 * @param array El arreglo dinámico al que se desea añadir el elemento.
 * @param data El dato que se desea añadir al arreglo.
 */
void ad_array_append(PtrArray* array, void* data)
{
    if (array == NULL) return;
    array->data = (void**)realloc(array->data, sizeof(void*) * (array->length + 1));
    array->data[array->length] = data;
    array->length++;
}

/**
 * @brief Obtiene el elemento en la posición especificada del arreglo dinámico.
 *
 * @param array El arreglo dinámico.
 * @param index El índice del elemento a obtener.
 * @return Un puntero al elemento en la posición especificada, o NULL si el índice está fuera de rango.
 */
void* ad_array_get(PtrArray* array, int index)
{
    if (array == NULL || index < 0 || index >= array->length) return NULL;
    return array->data[index];
}

/**
 * @brief Remueve un elemento del arreglo dinámico en la posición especificada.
 *
 * @param array El arreglo dinámico del cual se removerá el elemento.
 * @param index La posición del elemento a remover.
 * @return Un puntero al elemento removido, o NULL si no se encontró el elemento o el arreglo está vacío.
 */
void* ad_array_remove(PtrArray* array, int index)
{
    if (array == NULL || index < 0 || index >= array->length) return NULL;
    void* tmp = array->data[index];
    array->data[index] = array->data[array->length - 1];
    array->length--;
    return tmp;
}

#endif
