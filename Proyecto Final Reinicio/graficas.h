#include <stdio.h>
#include <stdlib.h>
#include <winbgim.h>

//Porcentaje de espacio para que quede un "margen" en la pantalla
#define PORC 5
//Cantidad de datos
#define CANTIDAD 8


typedef struct {
	char Nombre[50];
	char Apellidos[100];
	int Edad;
	char Direccion[100];
}Persona;

typedef struct{
	int clave;
	Persona DatosPersonales;
	char borrado;	
}Paciente;

typedef struct{
	int NumeroTrabajador;
	Persona DatosPersonales;
	char Especialidad[50];
	int Experiencia;
	char borrado;
}Doctor;

typedef struct{
	int NoConsulta;
	float costo;
	int clave;
	int NumeroTrabajador;
	char borrado;
}Consulta;

typedef struct{
	int NumeroTrabajador;
	Persona DatosPersonales;
	float ganancia;
}Gananciadoc;


void graficaBarras(Gananciadoc *datos, int nbarras){

    int Xf, Xi, Yf, Yi, EspacioX, EspacioY, AnchoBarra, CantidadBarras,X,Y;
    int AlturaBarra, YBarra, XBarra, i;
    float ValorBarra, ValorBarraMax;

    //Aqu� son datos fijos, pero se deben tomar de un archivo
    float Datos[CANTIDAD]={150.2, 180.3, 230, 125, 58.97, 450.67, 7.5, 75.6};

    //La cantidad depende de los datos guardados en el archivo
    CantidadBarras=nbarras;

    //Se debe encontrar el dato m�s grande
    ValorBarraMax=450.67;

    X=getmaxwidth();
    Y=getmaxheight();

    initwindow(X,Y,"Ventas");
    setbkcolor(COLOR(255,255,255));
	cleardevice();

    Xi=X*PORC/100;
    Xf=X-Xi;
    Yi=Y*PORC/100;
    Yf=Y-Yi;

    EspacioX=Xf-Xi;
    EspacioY=Yf-Yi;

    AnchoBarra=EspacioX/(CantidadBarras*2-1);

    XBarra=Xi;

    setlinestyle(SOLID_LINE,0,3);
    setcolor(YELLOW);
    line(Xi,Yf+2,Xf,Yf+2);

    for(i=0; i<nbarras; i++){
        setcolor(i+1);
        AlturaBarra=(Datos[i]/ValorBarraMax)*EspacioY;
        YBarra=Yi+(EspacioY-AlturaBarra);
        rectangle(XBarra,YBarra,XBarra+AnchoBarra,Yf);
        XBarra+=AnchoBarra*2;
    }

    //Ciclo para que se vea la gr�fica antes de que  se cierre la ventana
    while(!kbhit());

    closegraph();

}
