#include <SFML/Graphics.hpp>

#include "application/spell-book.h"
#include "infra/SFMLRenderer.h"
#include "application/sprite-library.h"
#include "application/tile_map.h"
#include "domain/colisionableEntity.h"
#include "domain/fireball.h"
#include "world/projectiles.h"

const sf::Texture getTexture(std::string path) {
    const sf::Texture texture(path, false, sf::IntRect({0, 0}, {100, 100}));
    return texture;
};


int main() {
    unsigned int WINDOW_WIDTH = 768; // 15
    unsigned int WINDOW_HEIGHT = 768; // 30
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "SFML + CLion + Homebrew");

    // set up textures

    auto texture = getTexture("../graphics/player1.png");
    auto box = getTexture("../graphics/box.png");
    auto player1high = getTexture("../graphics/player-high-wing.png");
    auto player2low = getTexture("../graphics/player-low-wing.png");
    auto fireball = getTexture("../graphics/fireball.png");

    // set up sprites
    sf::Sprite sprite(texture);
    sprite.setScale({2, 2});

    sf::Sprite boxSprite(box);
    boxSprite.setScale({2, 2});

    sf::Sprite player1highsprite(player1high);
    player1highsprite.setScale({2, 2});

    sf::Sprite player2lowsprite(player2low);
    player2lowsprite.setScale({2, 2});

    sf::Sprite fireballSprite(fireball);


    SpriteLibrary spriteLibrary;
    spriteLibrary.addSprite(Sprite::Name::FlyingBoonCalm, sprite);
    spriteLibrary.addSprite(Sprite::Name::FlyingBoonUp, player1highsprite);
    spriteLibrary.addSprite(Sprite::Name::FlyingBoonDown, player2lowsprite);

    spriteLibrary.addSprite(Sprite::Name::Fireball, fireballSprite);

    spriteLibrary.addSprite(Sprite::Box, boxSprite);

    sf::Clock clock;

    clock.start();

    Player player = Player({10, 10}, 1, Sprite::Name::FlyingBoonCalm, 1, {25, 25});

    ColisionableEntity boxC = ColisionableEntity({100, 100}, Sprite::Box, {25, 25});

    SFMLRenderer smflRenderer = SFMLRenderer(&window, spriteLibrary);

    SpellDef fireballSpell = SpellDef{"fireball", Sprite::Name::Fireball, 100, 4, 60};

    std::unordered_map<unsigned int, SpellDef> spellBookMap = {
        {1, fireballSpell}
    };

    SpellBook spellBook = SpellBook(spellBookMap);

    Projectiles projectiles = Projectiles(spellBook, spriteLibrary);

    std::unordered_map<sf::Keyboard::Scancode, bool> keyStates;
    sf::VertexArray triangle(sf::PrimitiveType::Triangles, 3);


    TileMap map;
    unsigned int level[16][16] = {
        {1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {9, 10, 11, 12, 9, 10, 11, 12, 9, 10, 11, 12, 9, 10, 11, 12},
        {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
        {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
        {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
        {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
        {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
        {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
        {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
        {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
    };

    unsigned int level2[16][16] = {
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14},
        {21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21},
            {21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21},
            {21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21},
            {21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21},
            {21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21},
            {21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21},
            {21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21},
            {21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21},
    };

    unsigned int level3[16][16] = {
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {15, 16, 15, 16, 15, 16, 15, 16, 15, 16, 15, 16, 15, 16, 15, 16},
        {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},
        {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},
        {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},
        {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},
        {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},
        {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},
        {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},
        {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},
    };

    if (!map.load("../graphics/tilemap-backgrounds_packed.png", {24, 24}, level3, 16, 16))
        return -1;

    map.setScale({2,2});

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
            if (!boxC.willColide(player, Left)) {
                player.moveLeft();
            }
        }
        if (keyStates[sf::Keyboard::Scan::Right] || keyStates[sf::Keyboard::Scan::D]) {
            if (!boxC.willColide(player, Right)) {
                player.moveRight();
            }

        }
        if (keyStates[sf::Keyboard::Scan::Up] || keyStates[sf::Keyboard::Scan::W]) {
            if (!boxC.willColide(player, Up)) {
                player.moveUp();
            }
        }
        if (keyStates[sf::Keyboard::Scan::Down] || keyStates[sf::Keyboard::Scan::S]) {
            if (!boxC.willColide(player, Down)) {
                player.moveDown();
            }
        }


        window.clear();


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
        window.draw(map);
        player.draw(smflRenderer);

        boxC.draw(smflRenderer);



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
