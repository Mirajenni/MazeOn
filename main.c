#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jogar.h"
#include "tutorial.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

int FPS = 60;
int LARGURA = 1280;
int ALTURA = 720;

int mouseX=0;
int mouseY=0;
int posX = 1280 / 2;
int posY = (720 / 2) - 80;
float charX = (1280 / 2) + 480;
float charY = (720 / 2) + 190;

bool escolha = false;
bool pausou = false;

int main() {

	/* Aspectos do menu */
	int posUm = (720 / 2) - 125;
	int posNovoJogo = posUm + 30;
	int posTutorial = posNovoJogo + 90;
	int posSair = posTutorial + 90;
	int posMeio = (1280 / 2) + 30;

	/*Aspector do Allegro*/
	ALLEGRO_DISPLAY *janela = NULL;
	ALLEGRO_SAMPLE *efeitoMouse;
	ALLEGRO_SAMPLE *musica = NULL;
	ALLEGRO_SAMPLE_INSTANCE *instanciaMusica=NULL;
	ALLEGRO_TIMER *tempo = NULL;
	ALLEGRO_BITMAP *mouse = NULL;
	ALLEGRO_BITMAP *menu = NULL;
	ALLEGRO_BITMAP *somDepois = NULL;
	ALLEGRO_BITMAP *semSom = NULL;
	ALLEGRO_BITMAP *voltarSom = NULL;
	ALLEGRO_BITMAP *menuDepois = NULL;
	ALLEGRO_BITMAP *novoJogo = NULL;
	ALLEGRO_BITMAP *tutorial = NULL;
	ALLEGRO_BITMAP *sair = NULL;
	ALLEGRO_EVENT_QUEUE *filaTempo = NULL;
	ALLEGRO_EVENT_QUEUE *filaMenu = NULL;

	if (!al_init()) {
		printf("Erro ao abrir MazeOn!\n");
		return -1;
	}
	else {
		al_init_primitives_addon();
		al_init_image_addon();
		al_install_audio();
		al_init_acodec_addon();

		al_reserve_samples(2);

		efeitoMouse = al_load_sample("choice.ogg");
		musica = al_load_sample("musicaMenu.ogg");

		instanciaMusica = al_create_sample_instance(musica);

		al_attach_sample_instance_to_mixer(instanciaMusica, al_get_default_mixer());

		janela = al_create_display(LARGURA, ALTURA);
		tempo = al_create_timer(1.0 / FPS);
		filaTempo = al_create_event_queue();
		al_register_event_source(filaTempo, al_get_timer_event_source(tempo));
		al_start_timer(tempo);


		al_reserve_samples(2);

		al_install_mouse();
		al_hide_mouse_cursor(janela);

		menu = al_load_bitmap("menuMazeOn.png");
		al_draw_bitmap(menu, 0, 0, 0);
		al_flip_display();
		al_rest(2.0);

		al_set_sample_instance_playmode(instanciaMusica, ALLEGRO_PLAYMODE_LOOP);
		al_set_sample_instance_playing(instanciaMusica, true);
		menuDepois = al_load_bitmap("menuMazeOnDepois.png");
		al_draw_bitmap(menuDepois, 0, 0, 0);
		al_flip_display();

		mouse = al_load_bitmap("mouseIcone.png");
		somDepois = al_load_bitmap("iconeSomDepois.png");
		semSom = al_load_bitmap("iconeSemSom.png");
		voltarSom = al_load_bitmap("iconeVoltarSom.png");
		novoJogo = al_load_bitmap("novoJogo.png");
		tutorial = al_load_bitmap("tutorial.png");
		sair = al_load_bitmap("sair.png");

		filaMenu = al_create_event_queue();
		al_register_event_source(filaMenu, al_get_display_event_source(janela));
		al_register_event_source(filaMenu, al_get_mouse_event_source());
		while (!escolha) {
			ALLEGRO_EVENT eventoMenu;
			al_wait_for_event(filaMenu, &eventoMenu);
			if (eventoMenu.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				escolha = true;
			}
			else if (eventoMenu.type == ALLEGRO_EVENT_MOUSE_AXES) {
				mouseX = eventoMenu.mouse.x;
				mouseY = eventoMenu.mouse.y;
			}
			if (mouseX >= (posMeio - 200) && mouseX <= (posMeio + 200) && mouseY >= posNovoJogo - 25 && mouseY <= posNovoJogo + 50) {
				al_draw_bitmap(novoJogo, 0, 0, 0);
				if (eventoMenu.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					al_play_sample(efeitoMouse, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
					al_set_sample_instance_playing(instanciaMusica, false);
					jogar(janela);
				}
			}
			else if (mouseX >= (posMeio - 200) && mouseX <= (posMeio + 200) && mouseY >= posTutorial - 25 && mouseY <= posTutorial + 50) {
				al_draw_bitmap(tutorial, 0, 0, 0);
				if (eventoMenu.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					al_play_sample(efeitoMouse, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
					abrirTutorial(janela);
				}
			}
			else if (mouseX >= (posMeio - 200) && mouseX <= (posMeio + 200) && mouseY >= posSair - 25 && mouseY <= posSair + 50) {
				al_draw_bitmap(sair, 0, 0, 0);
				if (eventoMenu.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					al_play_sample(efeitoMouse, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
					escolha = true;
				}
			}
			else if (mouseX >= 26 && mouseX <= 141 && mouseY >= 26 && mouseY <= 114) {
				if (pausou == false) {
					al_draw_bitmap(somDepois, 0, 0, 0);
					if (eventoMenu.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
						menuDepois = al_load_bitmap("iconeSemSom.png");
						al_draw_bitmap(semSom, 0, 0, 0);
						al_flip_display();
						al_set_sample_instance_playing(instanciaMusica, false);
						pausou = true;
					}
				}
				else {
					al_draw_bitmap(voltarSom, 0, 0, 0);
					if (eventoMenu.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
						menuDepois = al_load_bitmap("menuMazeOnDepois.png");
						al_flip_display();
						al_set_sample_instance_playing(instanciaMusica, true);
						pausou = false;
					}
				}

			}
			al_grab_mouse(janela);
			al_draw_bitmap(mouse, mouseX-20, mouseY-20, 0); //preciso arrumar a centralização do desenho do ponteiro
			al_flip_display();
			al_draw_bitmap(menuDepois, 0, 0, 0);
		}
	}
	al_destroy_display(janela);
	al_destroy_event_queue(filaMenu);
	al_destroy_event_queue(filaTempo);
	system("pause");
	return 0;
}
