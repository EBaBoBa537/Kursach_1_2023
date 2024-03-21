#ifndef WINDOW_LOGIN_H
#define WINDOW_LOGIN_H

class Window_Login{
private:
	int n = 4;
    sf::Color color_background = sf::Color(205,205,205);
    TextBox text_name;
	TextBox text_login;
    TextBox text_password;
	WriteBox writebox_login;
	WriteBox writebox_password;
	Button button_login;
    TextBox text_name_no;
    TextBox text_no;
    Button button_yes;
    Button button_no;

    bool button_clicked;
    bool button_yes_clicked;
    bool button_no_clicked;

public:

    void open_it(){ 
        window_login.create(sf::VideoMode(window_login_w, window_login_h), L"Авторизиция", sf::Style::Close);
        
        sf::Image icon;
        icon.loadFromFile("materials/images/icon.png");
        window_login.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        view_login.setSize(window_login_w, window_login_h);
        view_login.setCenter(window_login_w/2, window_login_h/2);
        view_login.setViewport(sf::FloatRect(0, 0, 1, 1));
        
        window_login.setKeyRepeatEnabled(false); // чтобы клавиши клавиатуры нажимались один раз
    }

    void close_it(){ 
        window_login.close(); 
    }

    void disable_it(){ 
        window_login.setActive(false);
    }

    bool is_open(){  
        return window_login.isOpen(); 
    }

    bool is_button_clicked(){ return button_clicked; }
    bool is_button_yes_clicked(){ return button_yes_clicked; }
    bool is_button_no_clicked(){ return button_no_clicked; }
    wstring get_writebox_login_wstring() { return writebox_login.get_string(); }
    wstring get_writebox_password_wstring() { return writebox_password.get_string(); }

    void create_it(){
        text_name.create_it(n, 195, 10, 30, L"Войти в аккаунт");
		text_login.create_it(n, 25, 66, 20, L"Логин");
        text_password.create_it(n, 25, 131, 20, L"Пароль");
        writebox_login.create_it(n, 25, 95, 254, 25, 2, 20, 2, 0, 2);
		writebox_password.create_it(n, 25, 160, 304, 25, 2, 20, 2, 0, 2);
        text_name_no.create_it(n, 195, 10, 30, L"Выйти из аккаунта");
        text_no.create_it(n, 125, 66, 20, L"Вы точно хотите выйти из аккаунта?");
		button_login.create_it(n, 475, 250, 60, 25, 2, 20, sf::Color(31,78,121), sf::Color(145,188,227), sf::Color(189,215,238), 2, -2, L"Войти");
        button_yes.create_it(n, 85, 250, 40, 25, 2, 20, sf::Color(31,78,121), sf::Color(145,188,227), sf::Color(189,215,238), 6, -2, L"Да");
        button_no.create_it(n, 465, 250, 40, 25, 2, 20, sf::Color(31,78,121), sf::Color(145,188,227), sf::Color(189,215,238), 2, -2, L"Нет");
    }


    void run_it(){

        // ------ events ----------------------------------------------------------------------------------------------------------

        sf::Event e;
        mouse_position = sf::Vector2f(sf::Mouse::getPosition(window_login).x, sf::Mouse::getPosition(window_login).y);
        events_mouse.mouse_scroll = 0;
        while (window_login.pollEvent(e)) {
            if (e.type == sf::Event::Closed) { window_login.close(); }
            if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Right){ events_mouse.R_mouse = true; } 
            if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Right){ events_mouse.R_mouse = false; } 
            if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left){ events_mouse.L_mouse = true; } 
            if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left){ events_mouse.L_mouse = false; } 
            if (e.type == sf::Event::MouseWheelScrolled){
                if(e.mouseWheelScroll.delta > 0){ events_mouse.mouse_scroll = 1; }
                else { events_mouse.mouse_scroll = -1; }
            }
            if (e.type == sf::Event::KeyPressed){
                if (e.key.code == sf::Keyboard::BackSpace){ events_mouse.backspace_pressed = true; } 
                if (e.key.code == sf::Keyboard::Num0){ events_nums[0].pressed = true; } 
                if (e.key.code == sf::Keyboard::Num1){ events_nums[1].pressed = true; } 
                if (e.key.code == sf::Keyboard::Num2){ events_nums[2].pressed = true; } 
                if (e.key.code == sf::Keyboard::Num3){ events_nums[3].pressed = true; } 
                if (e.key.code == sf::Keyboard::Num4){ events_nums[4].pressed = true; } 
                if (e.key.code == sf::Keyboard::Num5){ events_nums[5].pressed = true; } 
                if (e.key.code == sf::Keyboard::Num6){ events_nums[6].pressed = true; } 
                if (e.key.code == sf::Keyboard::Num7){ events_nums[7].pressed = true; } 
                if (e.key.code == sf::Keyboard::Num8){ events_nums[8].pressed = true; } 
                if (e.key.code == sf::Keyboard::Num9){ events_nums[9].pressed = true; } 
                if (e.key.code == sf::Keyboard::A){ events_text[0].pressed = true; } 
                if (e.key.code == sf::Keyboard::B){ events_text[1].pressed = true; } 
                if (e.key.code == sf::Keyboard::C){ events_text[2].pressed = true; } 
                if (e.key.code == sf::Keyboard::D){ events_text[3].pressed = true; } 
                if (e.key.code == sf::Keyboard::E){ events_text[4].pressed = true; } 
                if (e.key.code == sf::Keyboard::F){ events_text[5].pressed = true; } 
                if (e.key.code == sf::Keyboard::G){ events_text[6].pressed = true; } 
                if (e.key.code == sf::Keyboard::H){ events_text[7].pressed = true; } 
                if (e.key.code == sf::Keyboard::I){ events_text[8].pressed = true; } 
                if (e.key.code == sf::Keyboard::J){ events_text[9].pressed = true; } 
                if (e.key.code == sf::Keyboard::K){ events_text[10].pressed = true; } 
                if (e.key.code == sf::Keyboard::L){ events_text[11].pressed = true; } 
                if (e.key.code == sf::Keyboard::M){ events_text[12].pressed = true; } 
                if (e.key.code == sf::Keyboard::N){ events_text[13].pressed = true; } 
                if (e.key.code == sf::Keyboard::O){ events_text[14].pressed = true; } 
                if (e.key.code == sf::Keyboard::P){ events_text[15].pressed = true; } 
                if (e.key.code == sf::Keyboard::Q){ events_text[16].pressed = true; } 
                if (e.key.code == sf::Keyboard::R){ events_text[17].pressed = true; } 
                if (e.key.code == sf::Keyboard::S){ events_text[18].pressed = true; } 
                if (e.key.code == sf::Keyboard::T){ events_text[19].pressed = true; } 
                if (e.key.code == sf::Keyboard::U){ events_text[20].pressed = true; } 
                if (e.key.code == sf::Keyboard::V){ events_text[21].pressed = true; } 
                if (e.key.code == sf::Keyboard::W){ events_text[22].pressed = true; } 
                if (e.key.code == sf::Keyboard::X){ events_text[23].pressed = true; } 
                if (e.key.code == sf::Keyboard::Y){ events_text[24].pressed = true; } 
                if (e.key.code == sf::Keyboard::Z){ events_text[25].pressed = true; } 
            }
        }

        button_clicked = button_login.is_clicked();
        button_yes_clicked = button_yes.is_clicked();
        button_no_clicked = button_no.is_clicked();

        // ------ update ----------------------------------------------------------------------------------------------------------

        window_login.setMouseCursor(cursor_arrow);

		button_login.update_it();
        button_yes.update_it();
        button_no.update_it();
		writebox_login.update_it();
        writebox_password.update_it();

        // ------ draw ------------------------------------------------------------------------------------------------------------

        window_login.setView(view_login);
		window_login.clear(color_background);

        if(admin_or_user){
            text_name_no.draw_it();
            text_no.draw_it();
            button_yes.draw_it();
            button_no.draw_it();
        } else {
            text_name.draw_it();
            text_login.draw_it();
            text_password.draw_it();
            writebox_login.draw_it();
            writebox_password.draw_it();
            button_login.draw_it();
        }
		

		window_login.display();
		for(int i = 0; i < events_nums.size(); i++){ events_nums[i].pressed = false; }
		for(int i = 0; i < events_text.size(); i++){ events_text[i].pressed = false; }
		events_mouse.backspace_pressed = false;
    }


	Window_Login(){}
	~Window_Login(){}
};



#endif