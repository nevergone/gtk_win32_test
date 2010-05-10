/* 
   GTK+ source build Windows32
   2006.07.06  --  The NeverGone
*/

#include <gtk/gtk.h>


GtkWidget * main_window = NULL;

/* ha a kilepes gombra kattintottak */
void exit_button_clicked (GtkWidget * button, gpointer user_data) {
  g_print ("Yeeehaaaa...!\n");
  gtk_main_quit ();
}

int main (int argc, char *argv[]) {
  GtkWidget * exit_button = NULL;
  
  gtk_init (&argc, &argv);
  /* letrehozzuk a szukseges widgeteket */
  main_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  exit_button = gtk_button_new_from_stock (GTK_STOCK_QUIT);
  gtk_container_add (GTK_CONTAINER (main_window), exit_button);
	/* beallitunk par tulajdonsagot */
  gtk_container_set_border_width (GTK_CONTAINER (main_window), 20);
  gtk_window_set_title (GTK_WINDOW(main_window), "Sample cross-compiling application");
  /* szignalok beallitasa */
  g_signal_connect (G_OBJECT (exit_button), "clicked", G_CALLBACK (exit_button_clicked), NULL);
  g_signal_connect_swapped (G_OBJECT (main_window), "delete-event", G_CALLBACK (gtk_main_quit), G_OBJECT (main_window));
  gtk_widget_show_all (main_window);
  /* esemenykezeles inditasa */
  gtk_main();
  return 0; 
}
