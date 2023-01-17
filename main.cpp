#include "ctime";
#include <SFML/Graphics.hpp>
#include "Function.h"
#include "settings.h"
#include "BAT.h"
#include "BALL.h"
#include "Textobj.h"
using namespace sf;

int main()
{
	srand(time(0));
	// Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ
	RenderWindow window(VideoMode(width, height), title);
	window.setVerticalSyncEnabled(true);
	int score = 0;
	Bat bat;
	batInit(bat);
	//ШАР
	Ball ball;
	ballInit(ball);
	Textobj text;
	textInit(text, score);
	// Ãëàâíûé öèêë ïðèëîæåíèÿ. Âûïîëíÿåòñÿ, ïîêà îòêðûòî îêíî
	while (window.isOpen()) {
		checkEvents(window);
		updateGame(bat, ball, text, score);
		//игра закончилась?- прервать цикл
		if (ball.shape.getPosition().y >= height - 2 * ballradius)
			break;
		checkCollision(bat, ball);
		drawGame(window, bat, ball, text);
			
	}
	return 0;
}