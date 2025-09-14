//
// Created by Aurélien Brachet on 13/09/2025.
//

#ifndef SFMLRENDERER_H
#define SFMLRENDERER_H
#include "../domain/player.h"
#include "../domain/renderer.h"
#include "../application/sprite-library.h"
#include "../../../../../opt/homebrew/Cellar/sfml/3.0.1/include/SFML/Graphics/RenderWindow.hpp"


class SFMLRenderer: public Renderer {
    SpriteLibrary spriteLibrary;
    sf::RenderWindow *window;
    public:
    SFMLRenderer(sf::RenderWindow *w, SpriteLibrary& spriteLibrary);

    void render(PositionData pos, unsigned int spriteId);
};

#endif //SFMLRENDERER_H
