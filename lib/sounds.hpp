#pragma once

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>

enum SOUND {HIT};

class Sound_Handler{
    public: 
        Sound_Handler();
        void play_sound(SOUND sound);
        void play_music();

    private:
        sf::SoundBuffer m_buffer1;
        sf::Sound      m_sound1;
        sf::Music music;
};