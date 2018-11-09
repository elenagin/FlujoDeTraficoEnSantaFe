/**
 *@trafico.c
 *Codigo Fuente para implementar el programa del Flujo de tráfico en Santa Fe 
 *a funciones de GTK+ desarrollando un ambiente grafico 
 *para que los usuarios puedan jugar.
 *@Elena
 *@08/11/2018
 */

/*Archivos de Inclusion*/
#include <gtk/gtk.h>
#include <stdlib.h>
#include "tipos.h"
#include "senales.h"
#include "ventanas.h"

/**
 *Esta función es el main del programa, manda a llamar las ventanas necesarias
 *para que el usuario pueda empezar el programa.
 *Regresa fin de programa.
 *@Elena
 *@Param int argc
 *@Param char *argv
 *@return int 
 */
int main(int argc, char *argv[])
{
  ptrWidgets Widgets;/*Apuntada a estructura*/
  /*Inicializamos el ambiente*/
  gtk_init(&argc,&argv);
  Widgets=(ptrWidgets)malloc(sizeof(tWidgets));/*Creamos nuestro paquete de Widgets*/
  Widgets->SVentanas=(ptrVentanas)malloc(sizeof(tVentanas));

  VentanaBienvenida(Widgets);//Se crea la ventana de presentacion y se espera a que se le de aceptar
  VentanaJuego(Widgets);//Se crea la ventana de nueva partida
  gtk_main();/*funcion inicio iterada*/
}//main
