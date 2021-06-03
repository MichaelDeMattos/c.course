#include <gtk/gtk.h>

// gcc -o app "%f" `pkg-config --libs --cflags gtk+-3.0`

GtkLabel *label;
GtkEntry *entry;

void on_bt_apply_clicked(GtkWidget *widget, gpointer data)
{
    const gchar *text = gtk_entry_get_text(entry);
    gtk_label_set_text(label, text);
}

void on_main_window_destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv); 
    GtkBuilder *builder = gtk_builder_new_from_file("interface.glade");
    gtk_builder_add_callback_symbols(
        builder,
        "on_main_window_destroy", G_CALLBACK(on_main_window_destroy),
        "on_bt_apply_clicked", G_CALLBACK(on_bt_apply_clicked),
        NULL
    );
    
    gtk_builder_connect_signals(builder, NULL);
    label = GTK_LABEL(gtk_builder_get_object(builder, "lb_text"));
    entry = GTK_ENTRY(gtk_builder_get_object(builder, "inp_text"));
    GtkWidget *window = GTK_WIDGET(
        gtk_builder_get_object(builder, "main_window")
    );
    
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
