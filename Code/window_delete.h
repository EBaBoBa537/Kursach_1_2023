#ifndef WINDOW_DELETE_H
#define WINDOW_DELETE_H

class Window_Delete{
private:
	int n = 3;
    sf::Color color_background = sf::Color(242,222,150);
    TextBox text_name;
	TextBox text_num;
	ChooseBox choosebox_num;
	Button button_delete;

    bool button_clicked;

public:

    void open_it(){ 
        window_delete.create(sf::VideoMode(window_delete_w, window_delete_h), L"Удаление записи", sf::Style::Close);
        
        sf::Image icon;
        icon.loadFromFile("materials/images/icon.png");
        window_delete.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        view_delete.setSize(window_delete_w, window_delete_h);
        view_delete.setCenter(window_delete_w/2, window_delete_h/2);
        view_delete.setViewport(sf::FloatRect(0, 0, 1, 1));
        
        window_delete.setKeyRepeatEnabled(false); // чтобы клавиши клавиатуры нажимались один раз
    }

    void close_it(){ 
        window_delete.close(); 
    }

    void disable_it(){ 
        window_delete.setActive(false);
    }

    bool is_open(){  
        return window_delete.isOpen(); 
    }

    bool is_button_clicked(){ return button_clicked; }
    wstring get_choosebox_num_wstring() { return choosebox_num.get_choosestring(); }

    void create_it(){
        text_name.create_it(n, 195, 10, 30, L"Удаление записи");
		text_num.create_it(n, 25, 200, 20, L"Номер");
        
        vector<wstring> numwstrings_for_choosebox;
        int for_size = 0;
        for(int i = 0; i < data_file.size(); i++){
            if(data_file[i].cityfirst != "#"){
                for_size++;
            }
        }
        numwstrings_for_choosebox.resize(for_size);
        for_size = 0;
        for(int i = 0; i < data_file.size(); i++){
            if(data_file[i].cityfirst != "#"){
                numwstrings_for_choosebox[for_size] = to_wstring(data_file[i].num_line);
                for_size++;
            }
        }

		choosebox_num.create_it(n, 25, 229, 130, 25, 50, 18, 23, numwstrings_for_choosebox);
		button_delete.create_it(n, 475, 250, 78, 25, 2, 20, sf::Color(132,60,12), sf::Color(244,177,131), sf::Color(247,202,171), 2, -2, L"Удалить");
    }


    void run_it(){

        // ------ events ----------------------------------------------------------------------------------------------------------

        sf::Event e;
        mouse_position = sf::Vector2f(sf::Mouse::getPosition(window_delete).x, sf::Mouse::getPosition(window_delete).y);
        events_mouse.mouse_scroll = 0;
        while (window_delete.pollEvent(e)) {
            if (e.type == sf::Event::Closed) { window_delete.close(); }
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

        button_clicked = button_delete.is_clicked();

        // ------ update ----------------------------------------------------------------------------------------------------------

        window_delete.setMouseCursor(cursor_arrow);

		button_delete.update_it();
		choosebox_num.update_it();

        // ------ draw ------------------------------------------------------------------------------------------------------------

        window_delete.setView(view_delete);
		window_delete.clear(color_background);

		text_name.draw_it();
		text_num.draw_it();
		choosebox_num.draw_it();
		button_delete.draw_it();

		window_delete.display();
		for(int i = 0; i < events_nums.size(); i++){ events_nums[i].pressed = false; }
		for(int i = 0; i < events_text.size(); i++){ events_text[i].pressed = false; }
		events_mouse.backspace_pressed = false;
    }


	Window_Delete(){}
	~Window_Delete(){}
};



#endif