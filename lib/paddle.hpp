#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "./texture.hpp"

enum DIR {LEFT,RIGHT};

class Paddle{
    public:
        Paddle(Texture_Holder& texture_holder);

        void    set_move(DIR direction);

        sf::Vector2f get_position(){ return m_sprite.getPosition(); }
        sf::Sprite   get_sprite(){ return m_sprite; }
        sf::FloatRect get_hitbox(){ return m_sprite.getGlobalBounds(); }

    private:
        sf::Sprite      m_sprite;
        float           m_speed = 8.f;
};