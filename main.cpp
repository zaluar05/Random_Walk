#include <allegro5/allegro.h>
#include <bits/stdc++.h>

using namespace std;

#define al_init()    (al_install_system(ALLEGRO_VERSION_INT, atexit))

int main(int argc, char **argv){
    al_init();
    
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    al_get_new_display_flags();
    ALLEGRO_DISPLAY *teste = al_create_display(900,600);
    
    ALLEGRO_EVENT event;    
    ALLEGRO_TIMER *timer;
    al_start_timer(timer);


    bool display = true;
    while(display){
        al_flip_display();

        al_clear_to_color(al_map_rgb(0,0,0));

        al_rest(5.0);
        al_destroy_display(teste);
        display = false;
    }
    al_uninstall_system();
}