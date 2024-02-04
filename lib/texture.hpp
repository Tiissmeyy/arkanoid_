#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

enum TEXT_TYPE {BACKGROUND,PADDLE,BALL,BLOCK_0,BLOCK_1,BLOCK_2,BLOCK_3,BLOCK_4};

class Texture_Holder{
    public:
        Texture_Holder();
        void set_texture(sf::Sprite& sprite, TEXT_TYPE text_type){ sprite.setTexture(textures[text_type]);}

    private:
        std::vector<sf::Texture> textures; 
};