#include "../lib/ball.hpp"

Ball::Ball(Texture_Holder& texture_holder){
    texture_holder.set_texture(m_sprite,BALL);
    m_sprite.setPosition(250,250);
}

void Ball::process_move(sf::FloatRect paddle_hitbox, std::vector<Block>& blocks){
    // DO X MOVE
    m_sprite.move(sf::Vector2f(m_speedX,0));
        //check window collision
    if(m_sprite.getPosition().x < 0 || m_sprite.getPosition().x > 520 - m_sprite.getGlobalBounds().width){
        m_speedX=-m_speedX;
    }
        //check blocks collision
    bool can_invert_speed = true;
    for(auto& block: blocks){
        if(m_sprite.getGlobalBounds().intersects(block.get_hitbox())){
            block.set_position(-100,0);
            m_sounds.play_sound(HIT);
            if(can_invert_speed){
                m_speedX=-m_speedX;
                can_invert_speed = false;
            }
        }
    }
    // DO Y MOVE
    m_sprite.move(sf::Vector2f(0,m_speedY));
        //check window collision
    if(m_sprite.getPosition().y < 0 || m_sprite.getPosition().y > 450 - m_sprite.getGlobalBounds().height){
        m_speedY=-m_speedY;
    }
        //check blocks collision
    can_invert_speed = true;
    for(auto& block: blocks){
        if(m_sprite.getGlobalBounds().intersects(block.get_hitbox())){
            block.set_position(-100,0);
            m_sounds.play_sound(HIT);
            if(can_invert_speed){
                m_speedY=-m_speedY;
                can_invert_speed = false;
            }
        }
    }
    
    // check paddle collision
    if(m_sprite.getGlobalBounds().intersects(paddle_hitbox)){
        m_speedY=-m_speedY;
    }
}