#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
    double i;
    double g = 9.8;
    double Vo;
    double x;
    double xmax;
    double ymax;
    double Vxo;
    double Vyo;
    double tmax;
    double Vx;
    double y;
    double Vy;
    double t=0.00;
    double delta_t;  
    double a = 0.7853;
    FILE *salida;

    
    printf("Introduce el valor de la velocidad(m/s): ");
    scanf("%lf", &Vo);

    salida = fopen("Tiro parabolico.txt","w");

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

    for ( i=0; i<101; i++ )
    {
        x = Vx*t;
        Vx=Vo*cos(a);
        Vy=Vo*sin(a)-(g*t);
        y= Vo*sin(a)*t-((g/2)*(t*t));
        fprintf(salida, "%lf %lf %lf %lf %lf\n", t, x, Vx, y, Vy);
        t = t + delta_t;
    };
    fclose(salida);
    system("pause");
    return 0;
}
