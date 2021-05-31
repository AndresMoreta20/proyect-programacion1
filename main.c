#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define tam 20

int inputInt();
void borrar(int);
void abrirArchivo();

int buscar(int, char[][tam], float[], char[tam]);
void ingresoEmpleado(int, char[][tam], float[]);
void guardaEmpleado(int, char[][tam], float[], char[tam]);

int main(void)
{
    
    int op, cantEmp;
    char nombre[tam][tam], nombreBusca[tam];
    float temperatura[tam];

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

    
    do
    {
        printf("\n1.Ingreso temperatura\n2.Buscar por nombre\n3.Salir\n");
        printf("Escoja la opción:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Ingrese la cantidad de empleados que registrará: ");
            scanf("%d", &cantEmp);
            ingresoEmpleado(cantEmp, nombre, temperatura);
            guardaEmpleado(cantEmp, nombre, temperatura, fechaActual);
            break;
        
        case 2:
            printf("Ingrese el nombre del empleado: ");
            scanf(" %[^\n]s",nombreBusca);
            buscar(cantEmp, nombre, temperatura, nombreBusca);
        break;
        case 3:
            printf("Salir del programa\n");
            break;
        default:
            printf("Opción inválida.Intente nuevamente\n");
            break;
        }
    } while (op != 3);

    /*
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
   */
}
int inputInt()
{
    //Se crea una variable para guardar temporalmente el valor a escanera
    int x;
    //Se imprime el mensaje hasta que el usuario ingrese un valor adecuado
    do
    {
        scanf("%d", &x);
        if (x < 0)
        {
            printf("Ingrese un número válido: \n");
        }
    } while (x < 0);
    //Finalmente se devuelve el entero válido
    return x;
}

void ingresoEmpleado(int cantEmp, char nombre[][tam], float temperatura[])
{
    int cont;
    for (cont = 0; cont < cantEmp; cont++)
    {
        printf("Datos del Empleado N°%d\n", cont + 1);
        
        //getchar();
        
        printf("Ingrese el nombre del empleado: ");
        //fgets(nombre[cont], tam, stdin);
        scanf(" %[^\n]s",nombre[cont]);
        printf("Ingrese la temperatura: ");
        scanf("%f", &temperatura[cont]);
    }
}

void guardaEmpleado(int cantEmp, char nombre[][tam], float temperatura[], char fecha[tam])
{
    
        FILE *fpt;
        fpt = fopen("Registro2.csv", "w+");
        fprintf(fpt, "ID, Nombre, Temperatura, Fecha\n");
        for (int j = 0; j < cantEmp; j++)
        {
            fprintf(fpt, "%d, %s, %.2f, %s\n", j+ 1, nombre[j], temperatura[j], fecha);
        }
        fclose(fpt);
        /*      
       printf("Datos del Empleado N°%d\n",cont+1);
       printf("Nombre del empleado:%s\n",nombre[cont]);
       printf("Temperatura:%.1f\n",temperatura[cont]);
    */
    
}
int buscar(int cantEmp,char nombre[][tam],float temperatura[], char buscar[tam])

{
    int aviso = 0;
    for(int k =0; k<cantEmp;k++)
    {
        if(strcmp(buscar, nombre[k])==0)
        {
            printf("Datos del Empleado N°%d\t",k+1);
            printf("Nombre del empleado:%s\t",nombre[k]);
            printf("Temperatura:%.1f\n",temperatura[k]);
            return 0;
        }
        else if (aviso==0)
        {
            printf("No se encuentra ese nombre.\n");
            aviso = 1;
        }
        
    }
    return 1;

    
}