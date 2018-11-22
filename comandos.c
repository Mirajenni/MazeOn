#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>


ALLEGRO_BITMAP *frente = NULL;
ALLEGRO_BITMAP *costas = NULL;
ALLEGRO_BITMAP *ladoDireito = NULL;
ALLEGRO_BITMAP *ladoEsquerdo = NULL;
ALLEGRO_EVENT_QUEUE *filaAndar = NULL;
enum SETAS { UP, DOWN, LEFT, RIGHT };
bool setas[4] = { false, false, false, false };
bool parar = false;


int abrirPainel1(ALLEGRO_DISPLAY *janela, int charX, int charY) {
	ALLEGRO_BITMAP *costas = NULL;
	ALLEGRO_BITMAP *circuitoE = NULL;
	ALLEGRO_BITMAP *escuridao = NULL;
	ALLEGRO_BITMAP *mouse = NULL;
	ALLEGRO_BITMAP *painel = NULL;
	ALLEGRO_BITMAP *painelECompleto = NULL;
	ALLEGRO_BITMAP *on1 = NULL;
	ALLEGRO_BITMAP *on2 = NULL;
	ALLEGRO_BITMAP *off1 = NULL;
	ALLEGRO_BITMAP *off2 = NULL;
	ALLEGRO_EVENT_QUEUE *filaClicar = NULL;
	int mouseX = 1280 / 2, mouseY = 720 / 2;
	int painelE[2] = { 0, 0 };
	bool parar = false;
	al_init_image_addon();
	painelECompleto = al_load_bitmap("painelECompleto.png");
	costas = al_load_bitmap("costas.png");
	escuridao = al_load_bitmap("escuridao.png");
	circuitoE = al_load_bitmap("circuitoEON.png");
	mouse = al_load_bitmap("mouseIcone.png");
	painel = al_load_bitmap("painelE.png");
	on1 = al_load_bitmap("on1.png");
	on2 = al_load_bitmap("on2.png");
	off1 = al_load_bitmap("off1.png");
	off2 = al_load_bitmap("off2.png");
	al_draw_bitmap(painel, 384, 166, 0);
	al_flip_display();
	al_install_mouse();
	al_show_mouse_cursor(janela);
	filaClicar = al_create_event_queue();
	al_register_event_source(filaClicar, al_get_display_event_source(janela));
	al_register_event_source(filaClicar, al_get_mouse_event_source());
	al_show_mouse_cursor(janela);
	while (!parar) {
		ALLEGRO_EVENT eventoClicar;
		if (painelE[0] * painelE[1] == 1) {
			al_draw_bitmap(painelECompleto, 384, 166, 0);
			al_draw_bitmap(on1, 384, 166, 0);
			al_draw_bitmap(on2, 384, 166, 0);
			al_flip_display();
			return 1;
		}
		al_wait_for_event(filaClicar, &eventoClicar);
		if (eventoClicar.type == ALLEGRO_EVENT_MOUSE_AXES) {
			mouseX = eventoClicar.mouse.x;
			mouseY = eventoClicar.mouse.y;
		}
		else if (mouseX >= 473 && mouseX <= 606 && mouseY >= 340 && mouseY <= 472) {
			if (eventoClicar.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
				al_draw_bitmap(on1, 384, 166, 0);
				painelE[0] = 1;
			}
		}
		else if (mouseX >= 681 && mouseX <= 814 && mouseY >= 340 && mouseY <= 472) {
			if (eventoClicar.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
				al_draw_bitmap(on2, 384, 166, 0);
				painelE[1] = 1;
			}
		}
		else if (mouseX <= 384 || mouseX >= 894 && mouseY <= 166 || mouseY >= 550) {
			if (eventoClicar.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
				return 0;
			}
		}
		al_flip_display();
		//al_draw_bitmap(mouse, mouseX - 20, mouseY - 20, 0);
	}
}

int abrirPainel2(ALLEGRO_DISPLAY *janela, int charX, int charY) {
	ALLEGRO_BITMAP *costas = NULL;
	ALLEGRO_BITMAP *circuitoOU = NULL;
	ALLEGRO_BITMAP *escuridao = NULL;
	ALLEGRO_BITMAP *mouse = NULL;
	ALLEGRO_BITMAP *painel = NULL;
	ALLEGRO_BITMAP *painelOUCompleto = NULL;
	ALLEGRO_BITMAP *on1 = NULL;
	ALLEGRO_BITMAP *on2 = NULL;
	ALLEGRO_BITMAP *off1 = NULL;
	ALLEGRO_BITMAP *off2 = NULL;
	ALLEGRO_EVENT_QUEUE *filaClicar = NULL;
	int mouseX = 1280 / 2, mouseY = 720 / 2;
	int painelOU[2] = { 0, 0 };
	bool parar = false;
	al_init_image_addon();
	painelOUCompleto = al_load_bitmap("painelOUCompleto.png");
	costas = al_load_bitmap("costas.png");
	escuridao = al_load_bitmap("escuridao.png");
	circuitoOU = al_load_bitmap("circuitoOUON.png");
	mouse = al_load_bitmap("mouseIcone.png");
	painel = al_load_bitmap("painelOU.png");
	on1 = al_load_bitmap("on1.png");
	on2 = al_load_bitmap("on2.png");
	off1 = al_load_bitmap("off1.png");
	off2 = al_load_bitmap("off2.png");
	al_draw_bitmap(painel, 384, 166, 0);
	al_flip_display();
	al_install_mouse();
	al_show_mouse_cursor(janela);
	filaClicar = al_create_event_queue();
	al_register_event_source(filaClicar, al_get_display_event_source(janela));
	al_register_event_source(filaClicar, al_get_mouse_event_source());
	al_show_mouse_cursor(janela);
	while (!parar) {
		ALLEGRO_EVENT eventoClicar;
		if (painelOU[0] + painelOU[1] >= 1) {
			al_draw_bitmap(painelOUCompleto, 384, 166, 0);
			if (painelOU[0] == 1) {
				al_draw_bitmap(on1, 384, 166, 0);
				al_draw_bitmap(off2, 384, 166, 0);
			}
			else if (painelOU[1] == 1) {
				al_draw_bitmap(on2, 384, 166, 0);
				al_draw_bitmap(off1, 384, 166, 0);
			}
			else {
				al_draw_bitmap(on1, 384, 166, 0);
				al_draw_bitmap(on2, 384, 166, 0);
			}
			al_flip_display();
			return 1;
		}
		al_wait_for_event(filaClicar, &eventoClicar);
		if (eventoClicar.type == ALLEGRO_EVENT_MOUSE_AXES) {
			mouseX = eventoClicar.mouse.x;
			mouseY = eventoClicar.mouse.y;
		}
		else if (mouseX >= 473 && mouseX <= 606 && mouseY >= 340 && mouseY <= 472) {
			if (eventoClicar.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
				al_draw_bitmap(on1, 384, 166, 0);
				painelOU[0] = 1;
			}
		}
		else if (mouseX >= 681 && mouseX <= 814 && mouseY >= 340 && mouseY <= 472) {
			if (eventoClicar.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
				al_draw_bitmap(on2, 384, 166, 0);
				painelOU[1] = 1;
			}
		}
		else if (mouseX <= 384 || mouseX >= 894 && mouseY <= 166 || mouseY >= 550) {
			if (eventoClicar.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
				return 0;
			}
		}
		al_flip_display();
		//al_draw_bitmap(mouse, mouseX - 20, mouseY - 20, 0);
	}
}