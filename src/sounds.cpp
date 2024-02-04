#include "../lib/sounds.hpp"

Sound_Handler::Sound_Handler(){
    if(!m_buffer1.loadFromFile("./res/sounds/hit.wav")){
        std::cout << " sound file not find" << std::endl;
    }

    m_sound1.setBuffer(m_buffer1);

    if(!music.openFromFile("./res/musics/retro.ogg")){
        std::cout << " music file not find" << std::endl;
    }
}

void Sound_Handler::play_sound(SOUND sound_flag){
    std::cout << " sound " << std::endl;
    m_sound1.play();
}

void Sound_Handler::play_music(){
    std::cout << " music " << std::endl;

    music.play();
}