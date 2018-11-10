/**
 *@ventanas.c
 *Codigo Fuente para implementar el funcionamiento de las ventanas 
 *principales del juego así como su relación y orden. Además inicia
 *el ambiente gráfico e interactivo para los jugadores.
 *@Elena
 *@09/05/2018
 */

/*Archivos de Inclusion*/
#include <gtk/gtk.h>
#include <stdlib.h>
#include "tipos.h"
#include "ventanas.h"

/**
 *Función VentanaBienvenida: Se establecen todos los 
 * requerimientos para poder abrir la ventana de bienvenida
 * desde una imagen e introducir el juego de pente.
 * Regresa ventana en pantalla.
 *@Elena
 *@Param Widgets Apuntador a todas las estructuras
 */
void VentanaBienvenida(ptrWidgets Widgets)
{
  GtkWidget *imagen, *boton, *vbox;
  GdkPixbuf *pixbuf; 

  vbox = gtk_vbox_new(TRUE,5);
  Widgets->SVentanas->VenB = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (Widgets->SVentanas->VenB), "Pente");
  gtk_window_set_position(GTK_WINDOW(Widgets->SVentanas->VenB), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(Widgets->SVentanas->VenB),500,500);
  gtk_window_set_resizable(GTK_WINDOW(Widgets->SVentanas->VenB), FALSE);
  gtk_container_border_width(GTK_CONTAINER(Widgets->SVentanas->VenB),5);

  pixbuf = gdk_pixbuf_new_from_file_at_scale("Archivos/logo.png", 500, 500, FALSE, NULL);
  imagen = gtk_image_new_from_pixbuf(pixbuf);
  boton= gtk_button_new();
  
  gtk_widget_show (imagen);

  gtk_signal_connect(GTK_OBJECT(boton),"clicked",GTK_SIGNAL_FUNC(VentanaInstrucciones), Widgets);
  gtk_signal_connect(GTK_OBJECT(Widgets->SVentanas->VenB),"destroy",G_CALLBACK(CerrarJuego), Widgets);
  gtk_container_add(GTK_CONTAINER(Widgets->SVentanas->VenB), boton);
  gtk_container_add(GTK_CONTAINER(boton), vbox);
  gtk_container_add(GTK_CONTAINER(vbox), GTK_WIDGET(imagen));
  
  gtk_widget_show_all(Widgets->SVentanas->VenB);

}//VentanaBienvenida

/**
 * Función VentanaInstrucciones: Se establecen todos los 
 * requerimientos para poder abrir la ventana de instrucciones
 * desde una imagen e introducir el juego de pente.
 * Regresa ventana en pantalla.
 *@Elena
 *@Param GtkWidget *Widget El botón apuntador
 *@Param gpointer data  Apuntador a todas las estructuras
 */
void VentanaInstrucciones(GtkWidget *widget, gpointer data)
{
  GtkWidget *imagen, *boton, *vbox;
  GdkPixbuf *pixbuf; 
  ptrWidgets Widgets=(ptrWidgets)data;
  
  gtk_widget_hide(Widgets->SVentanas->VenB);
  vbox = gtk_vbox_new(TRUE,5);

  Widgets->SVentanas->VenI = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (Widgets->SVentanas->VenI), "Pente");
  gtk_window_set_position(GTK_WINDOW(Widgets->SVentanas->VenI), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(Widgets->SVentanas->VenI),500,500);
  gtk_window_set_resizable(GTK_WINDOW(Widgets->SVentanas->VenI), FALSE);
  gtk_container_border_width(GTK_CONTAINER(Widgets->SVentanas->VenI),5);

  pixbuf = gdk_pixbuf_new_from_file_at_scale("Archivos/instrucciones.png", 500, 500, FALSE, NULL);
  imagen = gtk_image_new_from_pixbuf(pixbuf);
  boton= gtk_button_new();
  
  gtk_widget_show (imagen);

  gtk_signal_connect(GTK_OBJECT(boton),"clicked",GTK_SIGNAL_FUNC(CerrarJuego), Widgets);
  gtk_signal_connect(GTK_OBJECT(Widgets->SVentanas->VenI),"destroy",G_CALLBACK(CerrarJuego), Widgets);
  gtk_container_add(GTK_CONTAINER(Widgets->SVentanas->VenI), boton);
  gtk_container_add(GTK_CONTAINER(boton), vbox);
  gtk_container_add(GTK_CONTAINER(vbox), GTK_WIDGET(imagen));
  
  gtk_widget_show_all(Widgets->SVentanas->VenI);
}//VentanaInstrucciones

void CerrarJuego(GtkWidget *Widget, gpointer data)
{
  ptrWidgets Widgets=(ptrWidgets)data;
  gtk_main_quit();
}//CerrarJuego2
