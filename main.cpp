#include <SFML/Graphics.hpp>
#include "const.h"
#include "ball.h"
using namespace sf;
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Works!");
	window.setFramerateLimit(60);
	// Главный цикл приложения. Выполняется, пока открыто окно
	Ball ball(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		ball.update();
		// Отрисовка окна
		window.clear();
		window.draw(ball.getShape());
		window.display();
	}
	return 0;
}