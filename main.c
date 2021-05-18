#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputInt();
void borrar(int);
void buscar(char);
void abrirArchivo();

int main (void)
{
    int opc, trabajNum; 
    
    //Obtención de la fecha y hora actual
    time_t fecha;
    char *fechaActual;
    fecha = time(NULL);
    if (fecha == (time_t)-1)
    {
        printf("Error");
    }
    else
    {
        fechaActual = ctime(&fecha);
        if (fechaActual == NULL)
        {
            printf("Error");
        }
        else
        {
            printf("Success");
        }
    }
    printf("Menú\n1: Añadir archivo\n2.Agregar trabajador\n3.Actualizar temperatura\n4.Eliminar Trabajador\n5.Salir\n");    
    opc = inputInt();
    do
    {
       
        switch (opc)
        {
        
        case 2:
            printf("Ingrese la cantidad de empleados: ");
            trabajNum = inputInt();
            char employee[trabajNum][20];
            int employeeTmp[trabajNum];
            for (int i = 0; i < trabajNum; i++)
            {
                printf("Ingrese el nombre del trabajador %d: ", i + 1);
                scanf("%s", employee[i]);
                printf("Ingrese la temperatura del trabajador %d: ", i + 1);
                scanf("%d", &employeeTmp[i]);
            }
            FILE *fpt;
            fpt = fopen("Registro.csv", "w+");
            fprintf(fpt, "ID, Name, Temperature, Date\n");
            for (int j = 0; j < trabajNum; j++)
            {
                fprintf(fpt, "%d, %s, %d, %s\n", j + 1, employee[j], employeeTmp[j], fechaActual);

            }
            fclose(fpt);
                       
        
        
        }

    }while(opc < 2 && opc>2);
    
   
return 0;  
}
int inputInt()
{
    //Se crea una variable para guardar temporalmente el valor a escanera
    int x;
    //Se imprime el mensaje hasta que el usuario ingrese un valor adecuado
    do{
        scanf("%d", &x);
        if (x < 0){
            printf("Ingrese un número válido: \n");
        }
    }while (x < 0);
    //Finalmente se devuelve el entero válido
    return x;
}