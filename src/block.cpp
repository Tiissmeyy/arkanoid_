#include "../lib/block.hpp"

Block::Block(Texture_Holder& texture_holder)
: m_life(0){
    texture_holder.set_texture(m_sprite,BLOCK_0);
}

Block::Block(Texture_Holder& texture_holder, int life)
: m_life(life){
    texture_holder.set_texture(m_sprite,static_cast<TEXT_TYPE>(BLOCK_0 + m_life));
}