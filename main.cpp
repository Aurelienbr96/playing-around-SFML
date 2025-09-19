#include <iostream>
#include <SFML/Graphics.hpp>

#include "application/spell-book.h"
#include "infra/SFMLRenderer.h"
#include "application/sprite-library.h"
#include "domain/fireball.h"
#include "world/projectiles.h"

const sf::Texture getTexture(std::string path) {
    const sf::Texture texture(path, false, sf::IntRect({0, 0}, {100, 100}));
    return texture;
};


int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML + CLion + Homebrew");

    // set up textures
    // const sf::Texture texture("../graphics/player1.png", false, sf::IntRect({0, 0}, {100, 100}));
    auto texture = getTexture("../graphics/player1.png");
    auto player1high = getTexture("../graphics/player-high-wing.png");
    auto player2low = getTexture("../graphics/player-low-wing.png");
    auto fireball = getTexture("../graphics/fireball.png");
    const sf::Texture midBackground1("../graphics/mid-background1.png", false, sf::IntRect({0, 0}, {100, 100}));
    const sf::Texture midBackground2("../graphics/mid-background2.png", false, sf::IntRect({0, 0}, {100, 100}));

    const sf::Texture highBackground1("../graphics/high-background1.png", false, sf::IntRect({0, 0}, {100, 100}));
    const sf::Texture highBackground2("../graphics/high-background2.png", false, sf::IntRect({0, 0}, {100, 100}));

    const sf::Texture lowBackground1("../graphics/low-background1.png", false, sf::IntRect({0, 0}, {100, 100}));
    const sf::Texture lowBackground2("../graphics/low-background2.png", false, sf::IntRect({0, 0}, {100, 100}));

    // set up sprites
    sf::Sprite sprite(texture);
    sprite.setScale({2, 2});

    sf::Sprite player1highsprite(player1high);
    player1highsprite.setScale({2, 2});

    sf::Sprite player2lowsprite(player2low);
    player2lowsprite.setScale({2, 2});

    sf::Sprite midBackgroundSprite1(midBackground1);
    sf::Sprite midBackgroundSprite2(midBackground2);

    sf::Sprite highBackgroundSprite1(highBackground1);
    sf::Sprite highBackgroundSprite2(highBackground2);

    sf::Sprite lowBackgroundSprite1(lowBackground1);
    sf::Sprite lowBackgroundSprite2(lowBackground2);

    sf::Sprite fireballSprite(fireball);

    midBackgroundSprite1.setScale({2, 2});
    midBackgroundSprite2.setScale({2, 2});
    highBackgroundSprite1.setScale({2, 2});
    highBackgroundSprite2.setScale({2, 2});
    lowBackgroundSprite1.setScale({2, 2});
    lowBackgroundSprite2.setScale({2, 2});


    SpriteLibrary spriteLibrary;
    spriteLibrary.addSprite(Sprite::Name::FlyingBoonCalm, sprite);
    spriteLibrary.addSprite(Sprite::Name::FlyingBoonUp, player1highsprite);
    spriteLibrary.addSprite(Sprite::Name::FlyingBoonDown, player2lowsprite);

    spriteLibrary.addSprite(Sprite::Name::BackgroundMedium, midBackgroundSprite1);
    spriteLibrary.addSprite(Sprite::Name::BackgroundMedium2, midBackgroundSprite2);

    spriteLibrary.addSprite(Sprite::Name::BackgroundHigh, highBackgroundSprite1);
    spriteLibrary.addSprite(Sprite::Name::BackgroundHigh2, highBackgroundSprite2);

    spriteLibrary.addSprite(Sprite::Name::BackgroundLow, lowBackgroundSprite1);
    spriteLibrary.addSprite(Sprite::Name::BackgroundLow2, lowBackgroundSprite2);

    spriteLibrary.addSprite(Sprite::Name::Fireball, fireballSprite);

    sf::Clock clock;

    clock.start();

    Player player = Player({10, 10}, 1, Sprite::Name::FlyingBoonCalm, 1, {25, 25});

    SFMLRenderer smflRenderer = SFMLRenderer(&window, spriteLibrary);


    std::unordered_map<unsigned int, Sprite::Name> mapIntToSprite = {
            {4, Sprite::Name::BackgroundHigh2},
            {5, Sprite::Name::BackgroundHigh},
            {2, Sprite::Name::BackgroundMedium},
            {3, Sprite::Name::BackgroundMedium2},
            {6, Sprite::Name::BackgroundLow},
            {7, Sprite::Name::BackgroundLow2}
    };

    std::vector<std::vector<unsigned int>> bgtileMap = {
        { 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5 },
        { 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5 },
        { 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5 },
        { 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5 },
        { 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2 ,3 },
        { 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7 },
        { 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7 },
        { 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7 },
        { 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7 },
        { 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7 },
        { 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7 },
        { 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7 },
        { 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7 },
    };

    SpellDef fireballSpell = SpellDef{"fireball", Sprite::Name::Fireball, 100, 4, 60};

    std::unordered_map<unsigned int, SpellDef> spellBookMap = {
        {1, fireballSpell}
    };

    SpellBook spellBook = SpellBook(spellBookMap);

    Projectiles projectiles = Projectiles(spellBook, spriteLibrary);

    std::unordered_map<sf::Keyboard::Scancode, bool> keyStates;

    int loop = 0;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                keyStates[keyPressed->scancode] = true;
            }
            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                keyStates[keyReleased->scancode] = false;
            }

            // Casting
            if (keyStates[sf::Keyboard::Scan::Space]) {
                player.castSpell(1, projectiles);
            }
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (keyStates[sf::Keyboard::Scan::Left] || keyStates[sf::Keyboard::Scan::A]) {
            player.moveLeft();
        }
        if (keyStates[sf::Keyboard::Scan::Right] || keyStates[sf::Keyboard::Scan::D]) {
            player.moveRight();
        }
        if (keyStates[sf::Keyboard::Scan::Up] || keyStates[sf::Keyboard::Scan::W]) {
            player.moveUp();
        }
        if (keyStates[sf::Keyboard::Scan::Down] || keyStates[sf::Keyboard::Scan::S]) {
            player.moveDown();
        }


        window.clear();

        for (int i = 0; i< bgtileMap.size(); i++) {
            for (int j = 0; j< bgtileMap[i].size(); j++) {
                auto spriteName = mapIntToSprite.at(bgtileMap[i][j]);
                smflRenderer.render({static_cast<float>(j * 48), static_cast<float>(i * 48)}, spriteName);
            }
        }

        if (clock.getElapsedTime().asMilliseconds() > 150) {
            if (loop == 0) {
                player.setSpriteName(Sprite::Name::FlyingBoonUp);
                loop = 1;
            } else if (loop == 1) {
                player.setSpriteName(Sprite::Name::FlyingBoonCalm);
                loop = 2;
            } else {
                player.setSpriteName(Sprite::Name::FlyingBoonDown);
                loop = 0;
            }

            clock.restart();
        }

        player.draw(smflRenderer);

        auto ongoingProjectiles = projectiles.getProjectiles();
        projectiles.update();

        for (int i = 0; i < ongoingProjectiles.size(); i++) {
            Fireball ongoingProjectile = ongoingProjectiles[i];
            ongoingProjectile.draw(smflRenderer);
        }

        window.display();
    }
    return 0;
}
