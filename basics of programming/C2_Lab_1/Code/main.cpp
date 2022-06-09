#include <SFML/Graphics.hpp>
using namespace sf;

Vector2f speed(float t, bool z)
{
	if (z == true)
		return Vector2f{ 1.f, -4*cosf(t) };
	else
		return Vector2f{ -1.f, -4*cosf(t) };
}

int main()
{
	bool z = true;
	RenderWindow window(VideoMode(800, 600), "It's alive");
	window.setFramerateLimit(60);
	//Создание треугольника
	CircleShape triangle(50.f, 3);
	triangle.setPosition(0, 250);
	triangle.setFillColor(Color::Blue);
	Clock time;
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		triangle.move(speed(time.getElapsedTime().asSeconds(), z));
		window.draw(triangle);
		window.display();
		if (triangle.getPosition().x == 700)
			z = false;
		if (triangle.getPosition().x == 0)
			z = true;
	}
	return 0;
}