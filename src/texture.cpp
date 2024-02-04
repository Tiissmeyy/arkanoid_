#include "../lib/texture.hpp"

Texture_Holder::Texture_Holder(){
    textures.resize(8);
    textures[BACKGROUND].loadFromFile("./res/images/starred_sky.jpg");
    textures[PADDLE].loadFromFile("./res/images/paddle.png");
    textures[BALL].loadFromFile("./res/images/ball.png");
    textures[BLOCK_0].loadFromFile("./res/images/block01.png");
    textures[BLOCK_1].loadFromFile("./res/images/block02.png");
    textures[BLOCK_2].loadFromFile("./res/images/block03.png");
    textures[BLOCK_3].loadFromFile("./res/images/block04.png");
    textures[BLOCK_4].loadFromFile("./res/images/block05.png");
}