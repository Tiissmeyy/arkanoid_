#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "./texture.hpp"
#include "./paddle.hpp"
#include "./block.hpp"
#include "./sounds.hpp"

class Ball{
    public:
        Ball(Texture_Holder& texture_holder);

        void process_move(sf::FloatRect paddle_hitbox, std::vector<Block>& blocks);

        sf::Vector2f get_position(){ return m_sprite.getPosition(); }
        sf::Sprite   get_sprite(){ return m_sprite; }

    private:
        Sound_Handler    m_sounds;
        sf::Sprite      m_sprite;
        float           m_speedX = 5.f, m_speedY = 5.f;
};