#include <SFML/Graphics.hpp>
#include "const.h"
#include "ball.h"
using namespace sf;
int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Works!");
	window.setFramerateLimit(60);
	// ������� ���� ����������. �����������, ���� ������� ����
	Ball ball(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		ball.update();
		// ��������� ����
		window.clear();
		window.draw(ball.getShape());
		window.display();
	}
	return 0;
}