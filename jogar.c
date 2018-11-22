#include "jogar.h"
#include "comandos.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

int MapaLabirinto1[37][68] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 ,1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 ,1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },

};


void jogar(ALLEGRO_DISPLAY *janela) {
	int coluna = 63;
	int linha = 32;
	int passo = 18;//9;
	int posX = 1280 / 2;
	int posY = (720 / 2) - 80;
	int charX = (1280 / 2) + 520;
	int charY = (720 / 2) + 210;
	int mouseX;
	int mouseY;
	int fimCircuitoE = 0;
	int fimCircuitoOU = 0;
	enum SETAS { UP, DOWN, LEFT, RIGHT };
	bool setas[4] = { false, false, false, false };
	bool acabou = false;
	bool parar = false;
	bool playEfeito = 1;

	ALLEGRO_BITMAP *labirinto = NULL;
	ALLEGRO_BITMAP *escuridao = NULL;
	ALLEGRO_BITMAP *frente = NULL;
	ALLEGRO_BITMAP *costas = NULL;
	ALLEGRO_BITMAP *ladoDireito = NULL;
	ALLEGRO_BITMAP *ladoEsquerdo = NULL;
	ALLEGRO_BITMAP *fim = NULL;
	ALLEGRO_BITMAP *fimDepois = NULL;
	ALLEGRO_FONT *aviso = NULL;
	ALLEGRO_FONT *avisoPaineis = NULL;
	ALLEGRO_FONT *dica = NULL;
	ALLEGRO_EVENT_QUEUE *filaAndar = NULL;
	ALLEGRO_SAMPLE *passos;
	ALLEGRO_SAMPLE_ID musicaID;
	ALLEGRO_SAMPLE *musica = NULL;
	ALLEGRO_SAMPLE *certo;
	ALLEGRO_SAMPLE *portaFechada;
	ALLEGRO_SAMPLE *portaAberta;
	ALLEGRO_SAMPLE *win;

	al_init_primitives_addon();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();

	al_reserve_samples(6);

	/*Load e aspectos de sons*/

	musica = al_load_sample("musicaLabirinto.ogg");
	passos = al_load_sample("passos.ogg");
	portaFechada = al_load_sample("efeitoPortaFechada.ogg");
	portaAberta = al_load_sample("efeitoPorta.ogg");
	win = al_load_sample("win.ogg");
	certo = al_load_sample("certo.ogg");

	avisoPaineis = al_load_font("yunapixel.ttf", 20, 0);
	aviso = al_load_font("yunapixel.ttf", 20, 0);
	dica = al_load_font("yunapixel.ttf", 20, 0);
	labirinto = al_load_bitmap("labirinto1.png");
	escuridao = al_load_bitmap("escuridao.png");
	costas = al_load_bitmap("costas.png");
	frente = al_load_bitmap("frente.png");
	ladoEsquerdo = al_load_bitmap("ladoEsquerdo.png");
	ladoDireito = al_load_bitmap("ladoDireito.png");
	fim = al_load_bitmap("fimLabirinto.png");
	fimDepois = al_load_bitmap("fimLabirintoDepois.png");

	al_play_sample(musica, 0.2, 0, 1, ALLEGRO_PLAYMODE_LOOP, &musicaID);
	al_draw_bitmap(labirinto, 0, 0, 0);
	al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
	al_draw_bitmap(costas, charX, charY, 0);
	al_draw_text(aviso, al_map_rgb(66, 244, 134), 970, 510, 0, "Tente chegar ao fim do Labirinto!");
	al_flip_display();
	al_rest(0.5);

	filaAndar = al_create_event_queue();
	al_install_keyboard();
	al_register_event_source(filaAndar, al_get_keyboard_event_source());
	al_register_event_source(filaAndar, al_get_display_event_source(janela));

	while (!parar) {
		ALLEGRO_EVENT eventoAndar;
		al_wait_for_event(filaAndar, &eventoAndar);
		if (eventoAndar.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (eventoAndar.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				parar = true;
				break;
			case ALLEGRO_KEY_UP:
				al_draw_bitmap(costas, charX, charY, 0);
				if (!acabou) {
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
				}
				al_flip_display();
				if (MapaLabirinto1[linha - 1][coluna] == 0) {
					linha--;
					setas[UP] = true;
					al_play_sample(passos, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				}
				break;
			case ALLEGRO_KEY_DOWN:
				al_draw_bitmap(frente, charX, charY, 0);
				if (!acabou) {
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
				}
				al_flip_display();
				if (MapaLabirinto1[linha + 1][coluna] == 0) {
					linha++;
					setas[DOWN] = true;
					al_play_sample(passos, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				}
				break;
			case ALLEGRO_KEY_LEFT:
				al_draw_bitmap(ladoEsquerdo, charX, charY, 0);
				if (!acabou) {
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
				}
				al_flip_display();
				if (MapaLabirinto1[linha][coluna - 1] == 0) {
					coluna--;
					setas[LEFT] = true;
					al_play_sample(passos, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				}
				break;
			case ALLEGRO_KEY_RIGHT:
				al_draw_bitmap(ladoDireito, charX, charY, 0);
				if (!acabou) {
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
				}
				al_flip_display();
				if (MapaLabirinto1[linha][coluna + 1] == 0) {
					coluna++;
					setas[RIGHT] = true;
					al_play_sample(passos, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				}
				break;
			case ALLEGRO_KEY_SPACE:
				if (charX >= 153 && charX <= 243 && charY >= 22 && charY <= 50) {
					al_draw_bitmap(costas, charX, charY, 0);
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
					fimCircuitoE = abrirPainel1(janela, charX, charY);
					al_flip_display();
					if (fimCircuitoE == 1 && fimCircuitoOU == 1) {
						labirinto = al_load_bitmap("labirinto1Completo.png");

					}
					else if (fimCircuitoE == 1) {
						al_play_sample(certo, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
						labirinto = al_load_bitmap("labirinto1CompletoE.png");
					}
				}
				else if (charX >= 53 && charX <= 138 && charY >= 22 && charY <= 50) {
					al_draw_bitmap(costas, charX, charY, 0);
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
					fimCircuitoOU = abrirPainel2(janela, charX, charY);
					al_flip_display();
					if (fimCircuitoE == 1 && fimCircuitoOU == 1) {
						labirinto = al_load_bitmap("labirinto1Completo.png");
					}
					else if (fimCircuitoOU == 1) {
						al_play_sample(certo, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
						labirinto = al_load_bitmap("labirinto1CompletoOU.png");
					}
				}
				else if (charX >= 35 && charX <= 88 && charY >= 250 && charY <= 409) {
					if (acabou == true) {
						al_rest(0.8);
						al_stop_sample(&musicaID);
						al_play_sample(win, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
						al_draw_bitmap(fim, 0, 0, 0);
						al_flip_display();
						al_rest(2.0);
						al_draw_bitmap(fimDepois, 0, 0, 0);
						al_flip_display();
						al_rest(3.0);
						parar = true;
					}
					else {
						al_play_sample(portaFechada, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
						al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
						al_draw_bitmap(ladoEsquerdo, charX, charY, 0);
						al_draw_text(dica, al_map_rgb(66, 244, 134), 49, 221, 0, "Dica: Volte aos paineis e tente os resolver!");
						al_flip_display();
						al_rest(0.5);
					}
				}
				al_draw_bitmap(labirinto, 0, 0, 0);
				break;
			}
		} /*O evento abaixo é para o pressionamento das teclas e melhor fluidez na hora de movimentar*/
		else if (eventoAndar.type == ALLEGRO_EVENT_KEY_UP) {
			switch (eventoAndar.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				parar = true;
				break;
			case ALLEGRO_KEY_UP:
				al_draw_bitmap(costas, charX, charY, 0);
				if (!acabou) {
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
				}
				al_flip_display();
				al_play_sample(passos, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				setas[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				al_draw_bitmap(frente, charX, charY, 0);
				if (!acabou) {
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
				}
				al_flip_display();
				setas[DOWN] = false;
				al_play_sample(passos, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				break;
			case ALLEGRO_KEY_LEFT:
				al_draw_bitmap(ladoEsquerdo, charX, charY, 0);
				if (!acabou) {
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
				}
				al_flip_display();
				setas[LEFT] = false;
				al_play_sample(passos, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				break;
			case ALLEGRO_KEY_RIGHT:
				al_draw_bitmap(ladoDireito, charX, charY, 0);
				if (!acabou) {
					al_draw_bitmap(escuridao, charX - 2020, charY - 700, 0);
				}
				al_flip_display();
				setas[RIGHT] = false;
				al_play_sample(passos, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				break;
			}
		}

		else if (eventoAndar.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			parar = true;
		}
		else if (fimCircuitoE == 1 && fimCircuitoOU == 1) {
			labirinto = al_load_bitmap("labirinto1Completo.png");
			if (playEfeito == 1) {
				al_play_sample(portaAberta, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				playEfeito = 0;
			}
			acabou = true;
		}
		else if (!acabou) {
			al_draw_bitmap(escuridao, charX - 1218, charY - 1136, 0);
		}
		al_draw_bitmap(labirinto, 0, 0, 0);

		if (setas[UP]) {
			charY -= setas[UP] * passo;
			setas[UP] = false;
		}
		if (setas[DOWN]) {
			charY += setas[DOWN] * passo;
			setas[DOWN] = false;
		}
		if (setas[LEFT]) {
			charX -= setas[LEFT] * passo;
			setas[LEFT] = false;
		}
		if (setas[RIGHT]) {
			charX += setas[RIGHT] * passo;
			setas[RIGHT] = false;
		}
	}
	al_destroy_bitmap(labirinto);
	al_destroy_bitmap(escuridao);
	al_destroy_bitmap(frente);
	al_destroy_bitmap(costas);
	al_destroy_bitmap(ladoDireito);
	al_destroy_bitmap(ladoEsquerdo);
	al_destroy_bitmap(fim);
	al_destroy_bitmap(fimDepois);
	al_destroy_font(aviso);
	al_destroy_font(avisoPaineis);
	al_destroy_font(dica);
	al_destroy_event_queue(filaAndar);
	al_destroy_sample(passos);
	al_destroy_sample(musica);
	al_destroy_sample(certo);
	al_destroy_sample(portaFechada);
	al_destroy_sample(portaAberta);
	al_destroy_sample(win);
}