#include <iostream>
#include <SFML/Graphics.hpp>
#include "infra/SFMLRenderer.h"
#include "application/sprite-library.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML + CLion + Homebrew");

    const sf::Texture texture("../graphics/player1.png", false, sf::IntRect({0, 0}, {100, 100}));

    sf::Sprite sprite(texture);
    sprite.setScale({2, 2});


    SpriteLibrary spriteLibrary;

    spriteLibrary.addSprite(1, sprite);

    Player player = Player({10, 10}, 4, 1);

    SFMLRenderer smflRenderer = SFMLRenderer(&window, spriteLibrary);


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scan::Left) {
                    std::cout << "Left key pressed" << std::endl;
                    player.moveLeft();
                }
                if (keyPressed->scancode == sf::Keyboard::Scan::Right) {
                    std::cout << "Left key pressed" << std::endl;
                    player.moveRight();
                }
                if (keyPressed->scancode == sf::Keyboard::Scan::Down) {
                    std::cout << "Left key pressed" << std::endl;
                    player.moveDown();
                }
                if (keyPressed->scancode == sf::Keyboard::Scan::Up) {
                    std::cout << "Left key pressed" << std::endl;
                    player.moveUp();
                }
            }
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        player.draw(smflRenderer);

        window.display();
    }
    return 0;
}
