#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
//#include <SFML/Graphics.hpp>

const int w = 500;

void _Oneo_Kuu(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    auto t = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count() / 1000.0;

    for (int i = 1; i < 250; ++i) {
        double u = t * 99;
        double a = i + u - fmod(u, 1);
        double X = sin(a) * w * 59 / (i * 2 - fmod(u, 1)) + (sin(a / w * 3)) * 200;
        double Y = cos(a) * w * 59 / (i * 2 - fmod(u, 1)) + (sin(a / w * 2)) * 100;

        sf::CircleShape dot(w / i);
        dot.setFillColor(sf::Color(255, 128, 0));
        dot.setPosition(X, Y);
        window.draw(dot);
    }

    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    _Oneo_Kuu(window);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Dwitter Conversion");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        _Oneo_Kuu(window);
    }

    return 0;
}
