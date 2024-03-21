#ifndef WINDOW_MAIN_H
#define WINDOW_MAIN_H

class Window_Main{
private:
    int n = 0;
    sf::Color color_background = sf::Color(181,212,180);
    Button button_exit;
    Button button_add;
    Button button_delete;
    Button button_change;
    Button button_find;
    Button button_sort;
    Button button_login;
    TextBox text_nazvanie;
    TextBox text_version;
    TextBox text_datefirst;
    TextBox text_datesecond;
    TextBox text_price;
    TextBox text_from;
    TextBox text_to;
    TextBox text_cityfirst;
    TextBox text_citysecond;
    TextBox text_transporttype;
    TextBox text_number;
    TextBox text_way;
    TextBox text_date;
    TextBox text_transport;
    TextBox text_whatprice;
    TextBox text_biletov;
    TextBox text_choosesort;
    WriteBox writebox_datefirst;
    WriteBox writebox_datesecond;
    WriteBox writebox_pricefirst;
    WriteBox writebox_pricesecond;
    ChooseBox choosebox_cityfirst;
    ChooseBox choosebox_citysecond;
    ChooseBox choosebox_transporttype;
    ChooseBox choosebox_sorttype;
    Outputbox outputbox;
    Status status;

    bool button_exit_clicked;
    bool button_add_clicked;
    bool button_delete_clicked;
    bool button_change_clicked;
    bool button_find_clicked;
    bool button_sort_clicked;
    bool button_login_clicked;

public:

    void open_it(){ 
        window_main.create(sf::VideoMode(window_main_w, window_main_h), L"Программа автоматизации подбора туристических путёвок", sf::Style::Close);
        
        sf::Image icon;
        icon.loadFromFile("materials/images/icon.png");
        window_main.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        view_main.setSize(window_main_w, window_main_h);
        view_main.setCenter(window_main_w/2, window_main_h/2);
        view_main.setViewport(sf::FloatRect(0, 0, 1, 1));
        
        window_main.setKeyRepeatEnabled(false); // чтобы клавиши клавиатуры нажимались один раз
    }

    void close_it(){ 
        window_main.close(); 
    }

    void disable_it(){ 
        window_main.setActive(false);
    }

    bool is_open(){  
        return window_main.isOpen(); 
    }

    bool is_button_exit_clicked(){ return button_exit_clicked; }
    bool is_button_add_clicked(){ return button_add_clicked; }
    bool is_button_delete_clicked(){ return button_delete_clicked; }
    bool is_button_change_clicked(){ return button_change_clicked; }
    bool is_button_find_clicked(){ return button_find_clicked; }
    bool is_button_sort_clicked(){ return button_sort_clicked; }
    bool is_button_login_clicked(){ return button_login_clicked; }
    wstring get_writebox_datefirst_wstring() { return writebox_datefirst.get_string(); }
    wstring get_writebox_datesecond_wstring() { return writebox_datesecond.get_string(); }
    wstring get_writebox_pricefirst_wstring() { return writebox_pricefirst.get_string(); }
    wstring get_writebox_pricesecond_wstring() { return writebox_pricesecond.get_string(); }
    wstring get_choosebox_cityfirst_wstring() { return choosebox_cityfirst.get_choosestring(); }
    wstring get_choosebox_citysecond_wstring() { return choosebox_citysecond.get_choosestring(); }
    wstring get_choosebox_transporttype_wstring() { return choosebox_transporttype.get_choosestring(); }
    wstring get_choosebox_sorttype_wstring() { return choosebox_sorttype.get_choosestring(); }

    void change_output(){  
        outputbox.change_list(data_wstring);
    }

    void change_status(wstring RESULTSWSTRING){  
        status.change_it(0, RESULTSWSTRING);
    }

    void create_it(){
        button_exit.create_it(n, 1113, 650, 62, 25, 2, 20, sf::Color(150,137,14), sf::Color(237,220,55), sf::Color(250,243,158), 2, -2, L"Выйти");
        button_add.create_it(n, 766, 650, 90, 25, 2, 20, sf::Color(150,137,14), sf::Color(237,220,55), sf::Color(250,243,158), 2, -2, L"Добавить");
        button_delete.create_it(n, 665, 650, 78, 25, 2, 20, sf::Color(150,137,14), sf::Color(237,220,55), sf::Color(250,243,158), 2, -2, L"Удалить");
        button_change.create_it(n, 550, 650, 93, 25, 2, 20, sf::Color(150,137,14), sf::Color(237,220,55), sf::Color(250,243,158), 2, -2, L"Изменить");
        button_find.create_it(n, 1073, 125, 102, 25, 2, 20, sf::Color(150,137,14), sf::Color(237,220,55), sf::Color(250,243,158), 2, -2, L"Подобрать");
        button_sort.create_it(n, 1059, 190, 116, 25, 2, 20, sf::Color(150,137,14), sf::Color(237,220,55), sf::Color(250,243,158), 2, -2, L"Сортировать");
        button_login.create_it(n, 944, 650, 143, 25, 2, 20, sf::Color(150,137,14), sf::Color(237,220,55), sf::Color(250,243,158), 2, -2, L"Войти в аккаунт");
        text_nazvanie.create_it(n, 125, 20, 40, L"Программа «Туристпутёвподборавтоматизатор–4000»");
        text_version.create_it(n, 1080, 42, 18, L"V 1.7");
        text_datefirst.create_it(n, 25, 96, 20, L"Дата начала");
        text_datesecond.create_it(n, 167, 96, 20, L"Дата конца");
        text_price.create_it(n, 320, 96, 20, L"Цена, BYN");
        text_from.create_it(n, 300, 125, 20, L"от");
        text_to.create_it(n, 370, 125, 20, L"до");
        text_cityfirst.create_it(n, 471, 96, 20, L"Город отправления");
        text_citysecond.create_it(n, 682, 96, 20, L"Город прибытия");
        text_transporttype.create_it(n, 870, 96, 20, L"Вид транспорта");
        text_number.create_it(n, 30, 232, 20, L"№");
        text_way.create_it(n, 70, 232, 20, L"Город отправления и прибытия");
        text_date.create_it(n, 385, 232, 20, L"Даты отправления и прибытия");
        text_transport.create_it(n, 665, 232, 20, L"Вид транспорта");
        text_whatprice.create_it(n, 820, 232, 20, L"Цена, BYN");
        text_biletov.create_it(n, 930, 232, 20, L"В наличии");
        text_choosesort.create_it(n, 25, 161, 20, L"Выбрать сортировку");
        writebox_datefirst.create_it(n, 25, 125, 104, 25, 2, 20, 2, 0, 0);
        writebox_datesecond.create_it(n, 165, 125, 104, 25, 2, 20, 2, 0, 0);
        writebox_pricefirst.create_it(n, 325, 125, 40, 25, 2, 20, 2, 0, 1);
        writebox_pricesecond.create_it(n, 399, 125, 40, 25, 2, 20, 2, 0, 1);
        choosebox_cityfirst.create_it(n, 470, 125, 170, 25, 250, 18, 23, citynames_for_chooseboxes);
        choosebox_citysecond.create_it(n, 670, 125, 170, 25, 250, 18, 23, citynames_for_chooseboxes);
        choosebox_transporttype.create_it(n, 870, 125, 130, 25, 92, 18, 23, transportnames_for_chooseboxes);
        choosebox_sorttype.create_it(n, 25, 190, 300, 25, 184, 18, 23, {L"По умолчанию", L"По цене", L"По алфавиту (город 1)", L"По алфавиту (город 2)", L"По алфавиту (вид транспорта)", L"По количеству билетов", L"По дате отправления", L"По дате прибытия"});
        outputbox.create_it(n, 25, 260, 1150, 370, 25, 28, 5, 18, data_wstring);
        status.create_it(n, 25, 650, 20, 20, 18, 0, 0, 0, L"Программа открыта");
    }


    void run_it(){

        // ------ events ----------------------------------------------------------------------------------------------------------

        sf::Event e;
        mouse_position = sf::Vector2f(sf::Mouse::getPosition(window_main).x, sf::Mouse::getPosition(window_main).y);
        events_mouse.mouse_scroll = 0;
        while (window_main.pollEvent(e)) {
            if (e.type == sf::Event::Closed) { window_main.close(); }
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

        button_exit_clicked = button_exit.is_clicked(); 
        if(admin_or_user){
            button_add_clicked = button_add.is_clicked(); 
            button_delete_clicked = button_delete.is_clicked(); 
            button_change_clicked = button_change.is_clicked(); 
        }
        button_find_clicked = button_find.is_clicked(); 
        button_sort_clicked = button_sort.is_clicked(); 
        button_login_clicked = button_login.is_clicked();

        // ------ update ----------------------------------------------------------------------------------------------------------

        window_main.setMouseCursor(cursor_arrow);

		button_exit.update_it();
        if(admin_or_user){
            button_add.update_it();
            button_delete.update_it();
            button_change.update_it();
        }
		button_find.update_it();
		button_sort.update_it();
        button_login.update_it();
		writebox_datefirst.update_it();
		writebox_datesecond.update_it();
		writebox_pricefirst.update_it();
		writebox_pricesecond.update_it();
		choosebox_cityfirst.update_it();
		choosebox_citysecond.update_it();
		choosebox_transporttype.update_it();
		choosebox_sorttype.update_it();
		outputbox.update_it();
		status.update_it();

        if(admin_or_user){
            button_login.create_it(n, 923, 650, 164, 25, 2, 20, sf::Color(150,137,14), sf::Color(237,220,55), sf::Color(250,243,158), 2, -2, L"Выйти из аккаунта");
        } else {
            button_login.create_it(n, 923, 650, 164, 25, 2, 20, sf::Color(150,137,14), sf::Color(237,220,55), sf::Color(250,243,158), 10, -2, L"Войти в аккаунт");
        }

        // ------ draw ------------------------------------------------------------------------------------------------------------

        window_main.setView(view_main);
		window_main.clear(color_background);

		outputbox.draw_it();
		button_exit.draw_it();
        if(admin_or_user){
            button_add.draw_it();
            button_delete.draw_it();
            button_change.draw_it();
        }
		button_find.draw_it();
		button_sort.draw_it();
        button_login.draw_it();
		text_nazvanie.draw_it();
		text_version.draw_it();
		text_datefirst.draw_it();
		text_datesecond.draw_it();
		text_price.draw_it();
		text_cityfirst.draw_it();
		text_citysecond.draw_it();
		text_number.draw_it();
		text_transport.draw_it();
		text_way.draw_it();
		text_date.draw_it();
		text_biletov.draw_it();
		text_transporttype.draw_it();
		text_from.draw_it();
		text_to.draw_it();
		text_whatprice.draw_it();
		text_choosesort.draw_it();
		writebox_datefirst.draw_it();
		writebox_datesecond.draw_it();
		writebox_pricefirst.draw_it();
		writebox_pricesecond.draw_it();
		choosebox_cityfirst.draw_it();
		choosebox_citysecond.draw_it();
		choosebox_transporttype.draw_it();
		choosebox_sorttype.draw_it();
		status.draw_it();

		window_main.display();
		for(int i = 0; i < events_nums.size(); i++){ events_nums[i].pressed = false; }
		for(int i = 0; i < events_text.size(); i++){ events_text[i].pressed = false; }
		events_mouse.backspace_pressed = false;
    }


	Window_Main(){}
	~Window_Main(){}
};


#endif