#include "../lib/paddle.hpp"

Paddle::Paddle(Texture_Holder& texture_holder){
    texture_holder.set_texture(m_sprite,PADDLE);
    m_sprite.setPosition(200,420);
}

void Paddle::set_move(DIR direction){
    if(direction == LEFT){
        m_sprite.move(sf::Vector2f(-m_speed,0));
        if(m_sprite.getPosition().x < 0)
            m_sprite.setPosition(0,420); 
    } 
        
    if(direction == RIGHT){
        m_sprite.move(sf::Vector2f(m_speed,0));
        if(m_sprite.getPosition().x > 520 - m_sprite.getGlobalBounds().width )
            m_sprite.setPosition(520 - m_sprite.getGlobalBounds().width,420); 
    } 
         
}