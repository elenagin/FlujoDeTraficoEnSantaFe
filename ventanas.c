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
  gtk_window_set_title(GTK_WINDOW (Widgets->SVentanas->VenB), "Flujo de Tráfico en Santa Fe");
  gtk_window_set_position(GTK_WINDOW(Widgets->SVentanas->VenB), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(Widgets->SVentanas->VenB),500,500);
  gtk_window_set_resizable(GTK_WINDOW(Widgets->SVentanas->VenB), FALSE);
  gtk_container_border_width(GTK_CONTAINER(Widgets->SVentanas->VenB),5);

  pixbuf = gdk_pixbuf_new_from_file_at_scale("Archivos/title.png", 500, 500, FALSE, NULL);
  imagen = gtk_image_new_from_pixbuf(pixbuf);
  boton= gtk_button_new();
  
  gtk_widget_show (imagen);

  gtk_signal_connect(GTK_OBJECT(boton),"clicked",GTK_SIGNAL_FUNC(VentanaObjetivo), Widgets);
  gtk_signal_connect(GTK_OBJECT(Widgets->SVentanas->VenB),"destroy",G_CALLBACK(CerrarVentana), Widgets);
  gtk_container_add(GTK_CONTAINER(Widgets->SVentanas->VenB), boton);
  gtk_container_add(GTK_CONTAINER(boton), vbox);
  gtk_container_add(GTK_CONTAINER(vbox), GTK_WIDGET(imagen));
  
  gtk_widget_show_all(Widgets->SVentanas->VenB);

}//VentanaBienvenida

/**
 * Función VentanaObjetivo: Se establecen todos los 
 * requerimientos para poder abrir la ventana de instrucciones
 * desde una imagen e introducir el juego de pente.
 * Regresa ventana en pantalla.
 *@Elena
 *@Param GtkWidget *Widget El botón apuntador
 *@Param gpointer data  Apuntador a todas las estructuras
 */
void VentanaObjetivo(GtkWidget *widget, gpointer data)
{
  GtkWidget *imagen, *boton, *vbox;
  GdkPixbuf *pixbuf; 
  ptrWidgets Widgets=(ptrWidgets)data;
  
  gtk_widget_hide(Widgets->SVentanas->VenB);
  vbox = gtk_vbox_new(TRUE,5);

  Widgets->SVentanas->VenO = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (Widgets->SVentanas->VenO), "Flujo de Tráfico en Santa Fe");
  gtk_window_set_position(GTK_WINDOW(Widgets->SVentanas->VenO), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(Widgets->SVentanas->VenO),500,500);
  gtk_window_set_resizable(GTK_WINDOW(Widgets->SVentanas->VenO), FALSE);
  gtk_container_border_width(GTK_CONTAINER(Widgets->SVentanas->VenO),5);

  pixbuf = gdk_pixbuf_new_from_file_at_scale("Archivos/objective.png", 500, 500, FALSE, NULL);
  imagen = gtk_image_new_from_pixbuf(pixbuf);
  boton= gtk_button_new();
  
  gtk_widget_show (imagen);

  gtk_signal_connect(GTK_OBJECT(boton),"clicked",GTK_SIGNAL_FUNC(VentanaInstrucciones), Widgets);
  gtk_signal_connect(GTK_OBJECT(Widgets->SVentanas->VenO),"destroy",G_CALLBACK(CerrarVentana), Widgets);
  gtk_container_add(GTK_CONTAINER(Widgets->SVentanas->VenO), boton);
  gtk_container_add(GTK_CONTAINER(boton), vbox);
  gtk_container_add(GTK_CONTAINER(vbox), GTK_WIDGET(imagen));
  
  gtk_widget_show_all(Widgets->SVentanas->VenO);
}//VentanaObjetivo

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
  
  
  gtk_widget_hide(Widgets->SVentanas->VenO);
  vbox = gtk_vbox_new(TRUE,5);

  Widgets->SVentanas->VenI = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (Widgets->SVentanas->VenI), "Flujo de Tráfico en Santa Fe");
  gtk_window_set_position(GTK_WINDOW(Widgets->SVentanas->VenI), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(Widgets->SVentanas->VenI),500,500);
  gtk_window_set_resizable(GTK_WINDOW(Widgets->SVentanas->VenI), FALSE);
  gtk_container_border_width(GTK_CONTAINER(Widgets->SVentanas->VenI),5);

  pixbuf = gdk_pixbuf_new_from_file_at_scale("Archivos/instructions.png", 500, 500, FALSE, NULL);
  imagen = gtk_image_new_from_pixbuf(pixbuf);
  boton= gtk_button_new();
  
  gtk_widget_show (imagen);

  gtk_signal_connect(GTK_OBJECT(boton),"clicked",GTK_SIGNAL_FUNC(VentanaPrincipal), Widgets);
  gtk_signal_connect(GTK_OBJECT(Widgets->SVentanas->VenI),"destroy",G_CALLBACK(CerrarVentana), Widgets);
  gtk_container_add(GTK_CONTAINER(Widgets->SVentanas->VenI), boton);
  gtk_container_add(GTK_CONTAINER(boton), vbox);
  gtk_container_add(GTK_CONTAINER(vbox), GTK_WIDGET(imagen));
  
  gtk_widget_show_all(Widgets->SVentanas->VenI);
}//VentanaIntrucciones

/**
 * Función VentanaInstrucciones: Se establecen todos los 
 * requerimientos para poder abrir la ventana de instrucciones
 * desde una imagen e introducir el juego de pente.
 * Regresa ventana en pantalla.
 *@Elena
 *@Param GtkWidget *Widget El botón apuntador
 *@Param gpointer data  Apuntador a todas las estructuras
 */
void VentanaPrincipal(GtkWidget *widget, gpointer data)
{
  GtkWidget *boton, *vbox;
  ptrWidgets Widgets=(ptrWidgets)data;
  GtkWidget *Tool;
  GtkToolItem *ToolSalir, *Separador,  *ToolAyuda, *ToolAcercaDe;
  
  gtk_widget_hide(Widgets->SVentanas->VenI);
  vbox = gtk_vbox_new(TRUE,5);

  //Creación de ventana
  Widgets->SVentanas->VenP = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (Widgets->SVentanas->VenP), "Flujo de Tráfico en Santa Fe");
  gtk_window_set_position(GTK_WINDOW(Widgets->SVentanas->VenP), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(Widgets->SVentanas->VenP),500,500);
  gtk_window_set_resizable(GTK_WINDOW(Widgets->SVentanas->VenB), FALSE);
  gtk_container_border_width(GTK_CONTAINER(Widgets->SVentanas->VenP),5);

  //Barra de accesos directos
  Tool=gtk_toolbar_new();//definimos tool bar
  ToolAyuda=gtk_tool_button_new_from_stock(GTK_STOCK_HELP);//creacion del boton ayuda
  g_signal_connect(ToolAyuda,"clicked",G_CALLBACK(VentanaInstrucciones2),Widgets);//llamada a la funcion Manual
  ToolAcercaDe=gtk_tool_button_new_from_stock(GTK_STOCK_ABOUT);//creacion del icono acerca de
  g_signal_connect(ToolAcercaDe,"clicked",G_CALLBACK(VentanaObjetivo2),Widgets->SVentanas);//llamada a la funcion Acerca de
  Separador=gtk_separator_tool_item_new();//creamos un separador
  ToolSalir=gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);//creacion del icono salir
  g_signal_connect(ToolSalir,"clicked",G_CALLBACK(CerrarVentana),Widgets);//llamada a la funcion Salir

  /*Definimos la jerarquia para meter los iconos en la TOOLBAR*/
  gtk_toolbar_set_style(GTK_TOOLBAR(Tool), GTK_TOOLBAR_BOTH);
  gtk_toolbar_insert(GTK_TOOLBAR(Tool), ToolAyuda, -1);
  gtk_toolbar_insert(GTK_TOOLBAR(Tool), ToolAcercaDe, -1);
  gtk_toolbar_insert(GTK_TOOLBAR(Tool), Separador, -1);
  gtk_toolbar_insert(GTK_TOOLBAR(Tool), ToolSalir, -1);
  gtk_box_pack_start (GTK_BOX(vbox),Tool,FALSE,TRUE,0);//incluimos la toolbar en la caja vertical
  
  
  //Organización de elementos gráficos
  gtk_signal_connect(GTK_OBJECT(Widgets->SVentanas->VenP),"destroy",G_CALLBACK(CerrarVentana), Widgets);
  gtk_container_add(GTK_CONTAINER(Widgets->SVentanas->VenP), vbox);
  //gtk_container_add(GTK_CONTAINER(boton), vbox);
  
  gtk_widget_show_all(Widgets->SVentanas->VenP);

}//VentanaPrincipal

void VentanaObjetivo2(GtkWidget *widget, gpointer data)
{
  GtkWidget *imagen, *boton, *vbox;
  GdkPixbuf *pixbuf; 
  ptrWidgets Widgets=(ptrWidgets)data;
  
  vbox = gtk_vbox_new(TRUE,5);

  Widgets->SVentanas->VenO = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (Widgets->SVentanas->VenO), "Flujo de Tráfico en Santa Fe");
  gtk_window_set_position(GTK_WINDOW(Widgets->SVentanas->VenO), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(Widgets->SVentanas->VenO),300,300);
  gtk_window_set_resizable(GTK_WINDOW(Widgets->SVentanas->VenO), FALSE);
  gtk_container_border_width(GTK_CONTAINER(Widgets->SVentanas->VenO),5);

  pixbuf = gdk_pixbuf_new_from_file_at_scale("Archivos/objective.png", 300, 300, FALSE, NULL);
  imagen = gtk_image_new_from_pixbuf(pixbuf);
  boton= gtk_button_new();
  
  gtk_widget_show (imagen);

  gtk_signal_connect(GTK_OBJECT(boton),"clicked",GTK_SIGNAL_FUNC(Esconder), Widgets);
  gtk_signal_connect(GTK_OBJECT(Widgets->SVentanas->VenO),"destroy",G_CALLBACK(Esconder), Widgets);
  gtk_container_add(GTK_CONTAINER(Widgets->SVentanas->VenO), boton);
  gtk_container_add(GTK_CONTAINER(boton), vbox);
  gtk_container_add(GTK_CONTAINER(vbox), GTK_WIDGET(imagen));
  
  gtk_widget_show_all(Widgets->SVentanas->VenO);
}//VentanaObjetivo2

void VentanaInstrucciones2(GtkWidget *widget, gpointer data)
{
  GtkWidget *imagen, *boton, *vbox;
  GdkPixbuf *pixbuf; 
  ptrWidgets Widgets=(ptrWidgets)data;
  
  vbox = gtk_vbox_new(TRUE,5);

  Widgets->SVentanas->VenI = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (Widgets->SVentanas->VenI), "Flujo de Tráfico en Santa Fe");
  gtk_window_set_position(GTK_WINDOW(Widgets->SVentanas->VenI), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(Widgets->SVentanas->VenI),300,300);
  gtk_window_set_resizable(GTK_WINDOW(Widgets->SVentanas->VenI), FALSE);
  gtk_container_border_width(GTK_CONTAINER(Widgets->SVentanas->VenI),5);

  pixbuf = gdk_pixbuf_new_from_file_at_scale("Archivos/instructions.png", 300, 300, FALSE, NULL);
  imagen = gtk_image_new_from_pixbuf(pixbuf);
  boton= gtk_button_new();
  
  gtk_widget_show (imagen);

  gtk_signal_connect(GTK_OBJECT(boton),"clicked",GTK_SIGNAL_FUNC(Esconder), Widgets);
  gtk_signal_connect(GTK_OBJECT(Widgets->SVentanas->VenI),"destroy",G_CALLBACK(Esconder), Widgets);
  gtk_container_add(GTK_CONTAINER(Widgets->SVentanas->VenI), boton);
  gtk_container_add(GTK_CONTAINER(boton), vbox);
  gtk_container_add(GTK_CONTAINER(vbox), GTK_WIDGET(imagen));
  
  gtk_widget_show_all(Widgets->SVentanas->VenI);
}//VentanaIntrucciones2



void CerrarVentana(GtkWidget *Widget, gpointer data)
{
  ptrWidgets Widgets=(ptrWidgets)data;
  gtk_main_quit();
}//CerrarVentana

void Esconder(GtkWidget *Widget, gpointer data)
{
  ptrWidgets Widgets=(ptrWidgets)data;
  gtk_widget_hide(Widget);
}//esconder
