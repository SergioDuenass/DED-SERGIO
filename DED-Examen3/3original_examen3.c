// INICIA RESPUESTA
// Para que agregues tus Librerías para los ejercicios prácticos.

// TERMINA RESPUESTA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

char alumno[100] = "Sergio Daniel Dueñas Godinez";

/*  

    Fecha : 29 de Noviembre 2024
    Diseno de Estructura de Datos - Grupo B
    Tercera Evaluación Síncrona

  Teoría 1:     6 preguntas de 5 puntos       /30 pts
  Teoría 2:     4 preguntas de 10 puntos      /40 pts
  Ejercicio 1:  Map                           /20 pts
  Ejercicio 2:  Priority Queue                /20 pts               
       
                                            ________
  Calificación Final:                         /110 puntos
*/

/*
******************************************************** Teoría 1: 6 preguntas de 5 puntos       /30 pts **************************************************************

1)	Explica cuál es la diferencia entre una función pública y una función privada?

  R= La principal diferencia es en el acceso a la función, ya que en una pública se puede acceder desde cuakquier lado, mientras que en la función orivada
  unicacaente se puede acceder desde el mismo archivo donde se hizo.

2)  Menciona una diferencia entre una cola (ordinaria) y una cola de prioridad, desde el punto de vista de su comportamiento, no de su implementación:

  R= El único elemento accesible es aquel que tenga prioridad mayor, mientras que una ordinaria es con FIFO.

3)  Explica a detalle la importancia de la función "hash" al implementar un Mapa / Tabla Hash, y por qué se le aplica la operación de módulo.

  R= Como su nombre lo indica, para poder hashear la key y pueda ser más fácil de buscar, y el módulo es para que no se salga del rango válido de la tabla.

4)	¿Por qué implementamos un conjunto mediante un árbol binario de búsqueda en lugar de utilizar una lista enlazada o un arreglo? Justifica bien tu respuesta.	

  R= Para que sea mucho más eficiente ya que siempre que esté balanceado se elimina la mitad de las posiilidades de búsqueda, por lo que es mucho más rápido.

5)	Al crear un TDA / Librería ¿Por qué utilizamos void pointers en lugar de datos de un tipo específico?

  R= Para que pueda ser más "universal" y pueda ser utilizado por cualquier tipo de dato.

6) Menciona una diferencia entre un conjunto y un mapa, desde el punto de vista de su comportamiento, no de su implementación:

  R= Un conjunto es una colección de elementos únicos, mientras que un mapa es una colección de pares de elementos únicos.

******************************************************** Teoría 2: 4 preguntas de 10 puntos       /40 pts **************************************************************

7)  Dibuja cómo queda el siguiente árbol binario de búsqueda después de insertar 14, 5 y 13 (en este orden). 

             10
          /      \
        3         16
      /   \      /   \
    1      8   11     18 
   /     /              \
  0     6                20

  R=
             10
          /      \
        3         16
      /   \      /   \
    1      8   11     18 
   /     /      \       \
  0     6        14      20
      /         /
     5         13

8) Asume que se crea un montículo binario "máximo" a partir del siguiente arreglo.:
    4, 7, 10, 5, 12, 15, 22, 8, 17, 1
    a) ¿Cómo queda el montículo binario (MaxHeap) inicialmente?  Puedes mostrar la respuesta como montículo binario (dibujo) o como arreglo.
 
      R= [22, 17, 15, 8, 12, 4, 10, 7, 5, 1]

    b) ¿Cómo queda el montículo binario (MaxHeap) de arriba después de ejecutar offer(18)?  Puedes mostrar la respuesta como montículo binario (dibujo) o como arreglo.
 
      R= [22, 17, 15, 8, 18, 10, 4, 5, 7, 1, 12]

    b) ¿Cómo queda el montículo binario (MaxHeap) de arriba después de ejecutar poll()? Puedes mostrar la respuesta como montículo binario (dibujo) o como arreglo.

      R= [17, 18, 15, 8, 7, 10, 4, 5, 12, 1, 22]

9)	Asume que existe una Tabla Hash que almacena fechas, y se encuentra en el siguiente estado:

HashIndex
    0   -> |31/10/1987| -> NULL
    1   -> |02/06/2012| -> |19/01/1123| -> NULL
    2   -> |01/01/2024| -> |28/05/1546| -> NULL
    3   -> NULL
    4   -> |03/11/1990| -> NULL
    5   -> |31/12/1987| -> |15/03/2025| -> |19/07/1999| -> NULL
    6   -> |31/08/2005| -> NULL

Asume que el hashing se hace de la siguiente manera:
  
  int DateHash(int dia, int mes, int anyo){
    int hash;
    
    if(anyo >= 2000)
      hash = (dia * mes) + anyo;
    else
      hash = dia + (mes * anyo);

    return hash % 7;
  }

  Dibuja la Tabla Hash resultante después de ejecutar map_put("02/02/2000") y map_put("11/11/1111");
  
  R=
    0   -> |31/10/1987| -> NULL
    1   -> |02/06/2012| -> |19/01/1123| -> NULL
    2   -> |02/02/2000| -> |01/01/2024| -> |28/05/1546| -> NULL
    3   -> |11/11/1111| -> NULL
    4   -> |03/11/1990| -> NULL
    5   -> |31/12/1987| -> |15/03/2025| -> |19/07/1999| -> NULL
    6   -> |31/08/2005| -> NULL



10)	Acabas de instalar la siguiente librería para el uso de colas simples:
//Entiéndela bien antes de continuar.

      #ifndef QUEUE_H
      #define QUEUE_H
      // Tamaño máximo de la cola
      #define MAX 5

      // Estructura de la cola
      typedef struct Queue {
          int items[MAX];
          int front, rear;
      } Queue;

      // Declaración de funciones
      void initQueue(Queue *q);
      void enqueue(Queue *q, int value);
      int dequeue(Queue *q);
      void displayQueue(Queue *q);

      #endif // QUEUE_H


  Imagina que en tu "main" tienes el siguiente código:

      Queue q, z;
      initQueue(&q);
      initQueue(&z);

      enqueue(&q, "Jesus");
      enqueue(&z, "Zyanya");
      enqueue(&q, "Jorge");
      dequeue(&z);
      enqueue(&q, "Sofia"");
      enqueue(&q, "Erick");
      enqueue(&q, "Diego");
      enqueue(&q, "Chava");
      dequeue(&q);
      dequeue(&z);
      enqueue(&q, "Nicole");

      displayQueue(&q);
      return 0;

  Escribe o dibuja el estado final de la cola "q".

  R= front[Jorge, Sofia, Erick, Diego, Nicole]rear


******************************************************** Ejercicio 1: Mapa                 /20 pts **************************************************************

/* 
   
   Guarda en un mapa, la relacion de cuantas repeticiones por cada numero existen
   en siguiente arreglo:

   {1,1,1,2,3,0,1,2,5,5,1}

  numero | veces
    1    |   5
    2    |   2
    3    |   1
    5    |   2

  Puedes agregar cualquier librería que hayas hecho en clase o en tu proyecto.

*/
/* INICIA RESPUESTA */
// El mapa necesita 2 funciones y tal vez una estructura, declaralas aqui:
// hash
int int_hash(void * key) {
    return *((int *) key);
}
//equals
boolean int_equals(void * key1, void * key2) {
    return *((int *) key1) == *((int *) key2); 
}

/* FIN DE RESPUESTA */

void ejercicio1()
{
  int arreglo[] = {1,1,1,2,3,0,1,2,5,5,1};
  int size = 11;

  // INICIA RESPUESTA
  map * m = map_create(10, int_hash, int_equals);
    
    for (int i = 0; i < size; i++) {
        // Verificar si el número ya existe en el mapa
        int *key = &arreglo[i];
        int *value = (int *) map_get(m, key); 
        
        if (value == NULL) {
            // si valor no existe = 1
            int *new_value = (int *) malloc(sizeof(int));
            *new_value = 1;
            map_put(m, key, new_value);
        } else {
            // si valor existe =+ 1
            (*value)++;
        }
    }

    // print
    printf("Numero | Veces \n");
    for (int i = 1; i < 10; i++) {
        int *key = (int *) malloc(sizeof(int));
        *key = i;
        int *value = (int *) map_get(m, key);
        if (value != NULL) {
            printf("   %d   |    %d\n", i, *value);
        }
    }
  // TERMINA RESPUESTA
}

/*
******************************************************** Ejercicio 2: Priority Queue              /20 pts **************************************************************

   Este ejercicio tiene un TDA que guarda un color, utilizando sus valores en RGB de 0 a 255.
    *R = Red = Rojo
    *G = Green = Verde
    *B = Blue = Azul
   Referencia: https://www.rapidtables.com/web/color/RGB_Color.html

   Crea una Priority Queue (Cola de prioridad) para guardar 5 colores.
   Puedes agregar cualquier librería que hayas hecho en clase o en tu proyecto.

   Una vez guardados:
   Extrae todos los colores (uno por uno) y comprueba que salen en el orden deseado.
   Cuál es ese orden? Solo hay 2 reglas:
    * El color con más rojo (R) es el más importante.
    * En caso de empate en rojo (R), utliza Azul (B) para desempatar.
*/

typedef struct color
{
  char name[15];
  int r;
  int g;
  int b;
} color;

/* INCIA RESPUESTA */
// aqui va una función que el priority queue necesita para funcionar


/* TERMINA RESPUESTA */

void ejercicio2()
{
  //Inicialización de colores.
  color c1, c2, c3, c4, c5;
  snprintf(c1.name, sizeof(c1.name), "Negro");
  c1.r=0;c1.g=0;c1.b=0;
  snprintf(c2.name, sizeof(c2.name), "Blanco");
  c2.r=255;c2.g=255;c2.b=255;
  snprintf(c3.name, sizeof(c3.name), "Limon");
  c3.r=120;c3.g=200;c3.b=10;
  snprintf(c4.name, sizeof(c4.name), "Naranja");
  c4.r=255;c4.g=153;c4.b=51;
  snprintf(c5.name, sizeof(c5.name), "Aqua");
  c5.r=120;c5.g=180;c5.b=180;

  /* INCIA RESPUESTA */
  // Inserta los 5 colores de arriba, sin importar el orden, comprueba
  // que al extraerlos, siempre sale el de mayor prioridad.


  /* FIN DE RESPUESTA */
}

int main()
{
  printf("Examen Parcial 3 de : %s\n", alumno);
  printf("\n----- Ejercicio 1:-----\n\n");
  ejercicio1();
  printf("\n----- Ejercicio 2:-----\n\n");
  ejercicio2();
}
