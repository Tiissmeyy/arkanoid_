#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "./texture.hpp"
#include "./paddle.hpp"
#include "./ball.hpp"
#include "./block.hpp"
#include "./sounds.hpp"

struct Btns {bool btn_left,btn_right = false;};

class App{
    public:
        App();
        void run();

    private:
        void chek_event();
        void update();
        void display();
        void check_btns();

        sf::RenderWindow m_window;
        Sound_Handler    m_sounds;
        Texture_Holder   m_texture_holder;
        Btns             m_btns;
        Paddle           m_paddle;
        Ball             m_ball;
        sf::Sprite       m_background;
        std::vector<Block> m_blocks_array;
};