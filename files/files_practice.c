#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* I/O Lectura de archivos:


*/
int main()
{

  /* Abre el archivo ventas.txt */
  /* Lee linea por linea los consumos por dia:


    dia 5 ventas $100.50 articulos 15
    dia 6 ventas $210.99 articulos 21
    ..

  */
  FILE *fptr;    //PATH

  fptr = fopen("./ventas.txt", "r");

  int day;
  float sales;
  int obj;
  char ret;
  int count = 0;

  while((ret = fscanf (fptr, "dia %d ventas $%f articulos %d\n", 
                &day, &sales, &obj))  !=  EOF)
  {
    count++;
    printf("%d=%f=%d\n", day, sales, obj);
  };
  printf("Total of %d day found\n", count);
  fclose(fptr);

  /* Calcula el costo promedio por articulo por dia y escribelo
    en OTRO ARCHIVO (ventas_promedio.txt), 
    cada linea debera quedar asi:

    PROMEDIOS DEL MES
    dia 5 promedio $6.7
    dia 6 promedio $10.04
    ..
  */
  fptr = fopen("./ventas.txt", "r");
  FILE *fptr2 = fopen("./ventas_promedio.txt", "w");
  fprintf(fptr2, "PROMEDIOS DEL MES\n");

  while((ret = fscanf(fptr, "dia %d ventas $%f articulos %d\n", 
                &day, &sales, &obj))  !=  EOF) 
  {
      float promedio = sales / obj;
      fprintf(fptr2, "dia %d promedio $%.2f\n", day, promedio);
  }

  fclose(fptr);
  fclose(fptr2);

  
  /* Al terminar de escribir en ventas_promedio.txt, vuelve
    a ventas.txt y escribe en una linea nueva la leyenda:
    PROMEDIOS ESCRITOS EN ventas_promedio.txt
    el archivo debera de quedar asi...

    ...
    dia 9 ventas $1200 articulos 150
    dia 19 ventas $200 articulos 50
    PROMEDIOS ESCRITOS EN ventas_promedio.txt
  */
  fptr = fopen("./ventas.txt", "a");
  fprintf(fptr, "\nPROMEDIOS ESCRITOS EN ventas_promedio.txt\n");
  fclose(fptr);

  return 0;
}
