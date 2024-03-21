#ifndef WINDOW_ADD_H
#define WINDOW_ADD_H

class Window_Add{
private:
	int n = 1;	
    sf::Color color_background = sf::Color(242,222,150);
    TextBox text_name;
	TextBox text_datefirst;
	TextBox text_datesecond;
	TextBox text_price;
	TextBox text_biletov;
	TextBox text_cityfirst;
	TextBox text_citysecond;
	TextBox text_transporttype;
	WriteBox writebox_datefirst;
	WriteBox writebox_datesecond;
	WriteBox writebox_price;
	WriteBox writebox_tickets;
	ChooseBox choosebox_cityfirst;
	ChooseBox choosebox_citysecond;
	ChooseBox choosebox_transporttype;
	Button button_add;

    bool button_clicked;

public:

    void open_it(){ 
        window_add.create(sf::VideoMode(window_add_w, window_add_h), L"Добавление записи", sf::Style::Close);
        
        sf::Image icon;
        icon.loadFromFile("materials/images/icon.png");
        window_add.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        view_add.setSize(window_add_w, window_add_h);
        view_add.setCenter(window_add_w/2, window_add_h/2);
        view_add.setViewport(sf::FloatRect(0, 0, 1, 1));
        
        window_add.setKeyRepeatEnabled(false); // чтобы клавиши клавиатуры нажимались один раз
    }

    void close_it(){ 
        window_add.close(); 
    }

    void disable_it(){ 
        window_add.setActive(false);
    }

    bool is_open(){  
        return window_add.isOpen(); 
    }

    bool is_button_clicked(){ return button_clicked; }
    wstring get_writebox_datefirst_wstring() { return writebox_datefirst.get_string(); }
    wstring get_writebox_datesecond_wstring() { return writebox_datesecond.get_string(); }
    wstring get_writebox_price_wstring() { return writebox_price.get_string(); }
    wstring get_writebox_tickets_wstring() { return writebox_tickets.get_string(); }
    wstring get_choosebox_cityfirst_wstring() { return choosebox_cityfirst.get_choosestring(); }
    wstring get_choosebox_citysecond_wstring() { return choosebox_citysecond.get_choosestring(); }
    wstring get_choosebox_transporttype_wstring() { return choosebox_transporttype.get_choosestring(); }

    void create_it(){
        text_name.create_it(n, 185, 10, 30, L"Добавление записи");
		text_datefirst.create_it(n, 25, 66, 20, L"Дата начала");
		text_datesecond.create_it(n, 167, 66, 20, L"Дата конца");
		text_price.create_it(n, 320, 66, 20, L"Цена, BYN");
		text_biletov.create_it(n, 420, 66, 20, L"В наличии");
		text_cityfirst.create_it(n, 25, 131, 20, L"Город отправления");
		text_citysecond.create_it(n, 220, 131, 20, L"Город прибытия");
		text_transporttype.create_it(n, 420, 131, 20, L"Вид транспорта");
		writebox_datefirst.create_it(n, 25, 95, 104, 25, 2, 20, 2, 0, 0);
		writebox_datesecond.create_it(n, 165, 95, 104, 25, 2, 20, 2, 0, 0);
		writebox_price.create_it(n, 325, 95, 40, 25, 2, 20, 2, 0, 1);
		writebox_tickets.create_it(n, 420, 95, 40, 25, 2, 20, 2, 0, 1);
		choosebox_cityfirst.create_it(n, 25, 160, 170, 25, 100, 18, 23, add_change_citynames_for_chooseboxes);
		choosebox_citysecond.create_it(n, 220, 160, 170, 25, 100, 18, 23, add_change_citynames_for_chooseboxes);
		choosebox_transporttype.create_it(n, 420, 160, 130, 25, 69, 18, 23, add_change_transportnames_for_chooseboxes);
		button_add.create_it(n, 475, 250, 90, 25, 2, 20, sf::Color(132,60,12), sf::Color(244,177,131), sf::Color(247,202,171), 2, -2, L"Добавить");
    }


    void run_it(){

        // ------ events ----------------------------------------------------------------------------------------------------------

        sf::Event e;
        mouse_position = sf::Vector2f(sf::Mouse::getPosition(window_add).x, sf::Mouse::getPosition(window_add).y);
        events_mouse.mouse_scroll = 0;
        while (window_add.pollEvent(e)) {
            if (e.type == sf::Event::Closed) { window_add.close(); }
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

        button_clicked = button_add.is_clicked();

        // ------ update ----------------------------------------------------------------------------------------------------------

        window_add.setMouseCursor(cursor_arrow);

		writebox_datefirst.update_it();
		writebox_datesecond.update_it();
		writebox_price.update_it();
		writebox_tickets.update_it();
		choosebox_cityfirst.update_it();
		choosebox_citysecond.update_it();
		choosebox_transporttype.update_it();
		button_add.update_it();

        // ------ draw ------------------------------------------------------------------------------------------------------------

		window_add.setView(view_add);
        window_add.clear(color_background);

		text_name.draw_it();
		text_datefirst.draw_it();
		text_datesecond.draw_it();
		text_price.draw_it();
		text_cityfirst.draw_it();
		text_citysecond.draw_it();
		text_transporttype.draw_it();
		text_biletov.draw_it();
		writebox_datefirst.draw_it();
		writebox_datesecond.draw_it();
		writebox_price.draw_it();
		writebox_tickets.draw_it();
		choosebox_cityfirst.draw_it();
		choosebox_citysecond.draw_it();
		choosebox_transporttype.draw_it();
		button_add.draw_it();

		window_add.display();
		for(int i = 0; i < events_nums.size(); i++){ events_nums[i].pressed = false; }
		for(int i = 0; i < events_text.size(); i++){ events_text[i].pressed = false; }
		events_mouse.backspace_pressed = false;
    }


	Window_Add(){}
	~Window_Add(){}
};



#endif