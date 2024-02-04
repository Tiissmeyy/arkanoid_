#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "./texture.hpp"


class Block{
    public:
        Block() = default;
        Block(Texture_Holder& texture_holder);
        Block(Texture_Holder& texture_holder, int life);

        void set_position(float x, float y){m_sprite.setPosition(sf::Vector2f(x,y));}

        sf::Vector2f get_position(){ return m_sprite.getPosition(); }
        sf::Sprite   get_sprite(){ return m_sprite; }
        sf::FloatRect get_hitbox(){ return m_sprite.getGlobalBounds(); }

    private:
        sf::Sprite      m_sprite;
        int             m_life;
};