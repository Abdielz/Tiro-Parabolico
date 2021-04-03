/*
Programa: Tiro Parabolico
Autores: Abdiel Andrade, Doribeth Andrade y Guadalupe
Clase: Programacion Cientifica
Fecha: 02/04/21
Descripcion: El programa resuelve las ecuaciones de tiro parabolico de posicion y velocidad dependientes del tiempo y
guarda en un archivo los valores de las variables t, x, Vx, y, Vy. Se usa un ciclo for para guardar en archivo las variables.
Cada vez que se use la función fprintf() el sistema guardará las variables al final del archivo.
*/ 

#include <stdio.h> //Se incluye la libreria de entrada y salida
#include <math.h> //Se incluye la libreria de operaciones matematicas
#include <stdlib.h> //Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras.

int main ()
{
    double i; //Se declaran las variables
    double g = 9.8; //Variable que representa la gravedad
    double Vo; //Representa la velocidad inicial (m/s)
    double x; //Representa la pocicion del movil en el eje x
    double xmax; //Representa la distancia maxima recorrida por el movil en el eje x
    double ymax; //Representa la altura maxima alcanzada por el movil en el eje y
    double Vxo; //Representa la velocidad inicial en el eje x (M.R.U.)
    double Vyo; //Representa la velicidad inicial en el eje y (M.R.U.A.)
    double tmax; //Representa el aumento en el tiempo para el cual se calcularan la posicion y velocidad nuevas (s)
    double Vx; //Representa la velocidad de el movil en el eje x (esta es constante)
    double y; //Representa la pocicion del movil en el eje y
    double Vy; //Representa la velicidad del movil en cada pocicion respecto al tiempo
    double t=0.00; //Valor del tiempo incial
    double delta_t; // Representa el aumento en el tiempo para el cual se calcularan la posicion y velocidad nuevas (s) 
    double a = 0.7853; //a es el valor del angulo de inclinacion (en este caso 45 grados) en radianes
    FILE *salida;

    
    printf("Introduce el valor de la velocidad(m/s): "); // Se pide al usuario la velocidad inicial
    scanf("%lf", &Vo); // Escanea el valor que el usuario asigana

    salida = fopen("Tiro parabolico.txt","w"); // Se abre el archivo en modo escritura

    tmax = 2*Vo*sin(a)/g;
    printf("Timpo de vuelo = %lf\n", tmax);
        
    ymax=((Vo*Vo)*(sin(a)*sin(a)))/(2*g);
    printf("Altura maxima = %lf\n", ymax);

    xmax=((Vo*Vo)*sin(2*a))/g;
    printf("Distancia maxima recorrida = %lf\n", xmax);

    Vx=Vo*cos(a);
    printf("Velocidad constante en x = %lf\n", Vx);

    Vxo=Vo*cos(a);
    printf("Velocidad inicial x = %lf\n", Vxo);

    Vyo=Vo*sin(a);
    printf("Velocidad inicial y = %lf\n", Vxo);

    delta_t =tmax/100;

    for ( i=0; i<101; i++ ) /* Ciclo que calculará las nuevas posiciones y velocidades aumentando cada vez el tiempo por un delta_t */
    {
        x = Vx*t; // formula para calcular la pocicion en el eje x en cada instante de tiempo
        Vx=Vo*cos(a); //formula para calcular la velocidad del movil en el eje x
        Vy=Vo*sin(a)-(g*t); //formula para calcular la velicidad del movil en el eje y
        y= Vo*sin(a)*t-((g/2)*(t*t)); //formula para calcular la pocicion en el eje y en cada instante de tiempo, La funcion pow(x,n) viene en la librería math.h y eleva una cantidad x a una potencia dada n
        fprintf(salida, "%lf %lf %lf %lf %lf\n", t, x, Vx, y, Vy); // Se abre el archivo en modo escritura
        t = t + delta_t; // Se actualiza el valor del tiempo para calcular v y h en la siguiente iteracion del ciclo
    };
    fclose(salida); // Se cierra el archivo
    system("pause"); //ejecutar un comando externo, en este caso pause, que funciona para que el cmd no se cierre y pida oprimir una tecla para finalizar.
    return 0;
}
