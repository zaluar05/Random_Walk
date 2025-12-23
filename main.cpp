#include "random_walk.h"

int main(int argc, char **argv){
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-1, 2);

    int quantidade_agentes;
    le_quantidade_agentes(quantidade_agentes);
    
    al_install_system(ALLEGRO_VERSION_INT, atexit);
    al_init();
    al_init_primitives_addon();
    
    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    ALLEGRO_DISPLAY *screen = al_create_display(HEIGHT, WIDTH);
    al_set_window_title(screen, "Random Walk");

    float central_x = al_get_display_width(screen) / 2.0f;
    float central_y = al_get_display_height(screen) / 2.0f;

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 120.0);
    al_start_timer(timer);
    
    ALLEGRO_EVENT event;    
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_display_event_source(screen));
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));
    
    std::vector<std::vector<std::pair<float, float>>> posicoes(quantidade_agentes);
    std::vector<std::vector<int>> cores;
    Cores_Aleatorias(cores, quantidade_agentes);

    for(int i = 0; i < quantidade_agentes; i++){
        posicoes[i].push_back({central_x, central_y});
    }
    
    bool display = true;
    while(display){
        
        al_wait_for_event(fila_eventos, &event);
        
        while(al_is_event_queue_empty(fila_eventos) == false){
            al_get_next_event(fila_eventos, &event);
            
            if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                display = false;
            }
        }
        
        if(event.type == ALLEGRO_EVENT_TIMER){
            al_clear_to_color(al_map_rgb(0, 0, 0));
            Imprime_agentes(posicoes, cores);
            al_flip_display();
        }
    }
    al_destroy_event_queue(fila_eventos);
    al_destroy_timer(timer);
    al_destroy_display(screen);
    al_uninstall_system();
    return EXIT_SUCCESS;
}