#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

void abrirTutorial(ALLEGRO_DISPLAY *janela) {
	ALLEGRO_BITMAP *comoJogar = NULL;
	ALLEGRO_BITMAP *mouse = NULL;
	ALLEGRO_EVENT_QUEUE *filaVoltar = NULL;
	int mouseX = 1280 / 2;
	int mouseY = 720 / 2;
	bool voltar = false;
	comoJogar = al_load_bitmap("menuComoJogar.png");
	mouse=al_load_bitmap("mouseIcone.png");
	al_init_primitives_addon();
	al_install_mouse();
	al_init_image_addon();
	al_draw_bitmap(comoJogar, 0, 0, 0);
	al_flip_display();
	filaVoltar = al_create_event_queue(); 
	al_register_event_source(filaVoltar, al_get_display_event_source(janela));
	al_register_event_source(filaVoltar, al_get_mouse_event_source());
	while (!voltar) {
		ALLEGRO_EVENT eventoVoltar;
		al_wait_for_event(filaVoltar, &eventoVoltar);
		if (eventoVoltar.type == ALLEGRO_EVENT_MOUSE_AXES) {
				mouseX = eventoVoltar.mouse.x;
				mouseY = eventoVoltar.mouse.y;
		}
		else if (eventoVoltar.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			voltar = true;
		}
		al_draw_bitmap(mouse, mouseX - 20, mouseY - 20, 0);
		al_flip_display();
		al_draw_bitmap(comoJogar, 0, 0, 0);
	}
	al_destroy_bitmap(comoJogar);
	al_destroy_bitmap(mouse);
	al_destroy_event_queue(filaVoltar);
}