#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

// For compile
// gcc -o app "%f" `pkg-config --libs --cflags gtk+-3.0`

GtkLabel *result;
GtkEntry *inp_heigth;
GtkEntry *inp_weigth;


// Gtk.Button | Signal: Clicked
void on_bt_apply_clicked(GtkWidget *widget, gpointer data)
{
    const gchar *weigth_str = gtk_entry_get_text(inp_weigth);
    const gchar *heigth_str = gtk_entry_get_text(inp_heigth);
    
    float heigth_float = atof(heigth_str);
    float weigth_float = atof(weigth_str);
    
    float imc_float = weigth_float / (heigth_float * heigth_float);
    
    char text[] = "Your IMC is: ";
    char _result[20];
    g_snprintf(_result, 20, "%s%f.2", text, imc_float);
    gtk_label_set_text(result, _result);
    
}

// Gtk.Window | Signal: Destroy
void on_main_window_destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

// Main Function
int main(int argc, char *argv[])
{
    // Init gtk lib
    gtk_init(&argc, &argv);
     
    // GtkBuilder for load widgets in user interface to xml generate with Glade 
    GtkBuilder *builder = gtk_builder_new_from_file("interface.glade");
    
    // how to connect signals do application
    gtk_builder_add_callback_symbols(
        builder,
        "on_main_window_destroy", G_CALLBACK(on_main_window_destroy),
        "on_bt_apply_clicked", G_CALLBACK(on_bt_apply_clicked),
        NULL
    );
    gtk_builder_connect_signals(builder, NULL);
    
    // Create instance for acess widget in user interface
    result = GTK_LABEL(gtk_builder_get_object(builder, "lb_result"));
    inp_heigth = GTK_ENTRY(gtk_builder_get_object(builder, "inp_heigth"));
    inp_weigth = GTK_ENTRY(gtk_builder_get_object(builder, "inp_weigth"));
    GtkWidget *window = GTK_WIDGET(
        gtk_builder_get_object(builder, "main_window")
    );
    
    // Show widgets in window
    gtk_widget_show_all(window);
    
    // Create loop gtk
    gtk_main();
    return 0;
}
