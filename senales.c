/**
 * @file senales.c
 * @brief Este programa permite capturar las señales que recibe el 
 * programa gráfico y realiza las funciones necesarias para lo que
 * piden dichos widgets gráficos.
 * @author Elena Ginebra
 * @date 08/11/2018 
 */

/**
 *ARCHIVOS DE INCLUSIÓN*/
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 *MÓDULOS INCLUÍDOS*/
#include "tipos.h"
#include "ventanas.h"
#include "senales.h"

void EsconderVentana(GtkWidget *Widget, gpointer data)
{
  gtk_widget_hide(Widget);
}//esconderventana
