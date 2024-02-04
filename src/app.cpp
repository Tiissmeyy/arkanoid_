#include "../lib/app.hpp"

App::App()
    : m_paddle(m_texture_holder), m_ball(m_texture_holder)
{
    m_window.create(sf::VideoMode(520, 450), "My Game");
    m_window.setFramerateLimit(60);

    m_texture_holder.set_texture(m_background,BACKGROUND);

    m_blocks_array.resize(50);
    int n =0;
    for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 5; j++){
        if(i+j%2){
            Block block(m_texture_holder);
            block.set_position(i * 42, (j+1) * 20);
            m_blocks_array[n] = block;
            n++;
        }
        else {
            Block block(m_texture_holder,1);
            block.set_position(i * 42, (j+1) * 20);
            m_blocks_array[n] = block;
            n++;
        }
    }
}

void App::run()
{
    m_sounds.play_music();
    while (m_window.isOpen())
    {
        chek_event();
        update();
        display();
    }
}

void App::chek_event()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                m_btns.btn_left = true;
                break;
            case sf::Keyboard::Right:
                m_btns.btn_right = true;
                break;
            default:
                break;
            }
        }
        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                m_btns.btn_left = false;
                break;
            case sf::Keyboard::Right:
                m_btns.btn_right = false;
                break;
            default:
                break;
            }
        }
    }
}

void App::update()
{
    check_btns();
    m_ball.process_move(m_paddle.get_hitbox(), m_blocks_array);
}

void App::display()
{
    m_window.clear();
    m_window.draw(m_background);
    m_window.draw(m_paddle.get_sprite());
    m_window.draw(m_ball.get_sprite());
    for (auto &block : m_blocks_array)
    {
        m_window.draw(block.get_sprite());
    }
    m_window.display();
}

void App::check_btns()
{
    if (m_btns.btn_left)
    {
        m_paddle.set_move(LEFT);
    }
    else if (m_btns.btn_right)
    {
        m_paddle.set_move(RIGHT);
    }
}
