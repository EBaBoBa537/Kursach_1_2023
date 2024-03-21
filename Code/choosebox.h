#ifndef CHOOSEBOX_H
#define CHOOSEBOX_H

class ChooseBox{
private:
	int window_n;
	int x = 0; 
	int y = 0; 
	int w = 0; 
	int h_button = 0; 
	int h = 0;
	int h_area = 0;
	int borderthickness = 2;
	int scrollbarthickness = 18;
	bool choosing = false;
	bool active = false;
	int choosenum = 0;
	sf::Color color_border = sf::Color(10,10,10);
	sf::Color color_decor =  sf::Color(149,194,148);
	sf::Color color_decor_active = sf::Color(182,213,181);
	sf::Color color_decor_border = sf::Color(84,130,53);
	BorderBox borderbox;
	RectangleBox rectanglebox;
	RectangleBox rectanglebox_decor;
	BorderBox borderbox_decor;
	TextBox textbox;
	ClickedArea clickedarea;
	ScrollList scrolllist;
	vector<Button> button_list;
	vector<wstring> button_texts;
	int number;
	int h_text;
	sf::CircleShape triangle;

	sf::View view;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_w(){ return w; }
	int get_h(){ return h; }
	int get_h_button(){ return h_button; }
	int get_h_area(){ return h_area; }
	int get_h_text(){ return h_text; }
	int get_borderthickness(){ return borderthickness; }
	int get_scrollbarthickness(){ return scrollbarthickness; }
	bool get_choosing(){ return choosing; }
	int get_choosenum(){ return choosenum; }
	sf::Color get_color_border(){ return color_border; }
	sf::Color get_color_decor(){ return color_decor; }
	sf::Color get_color_decor_active(){ return color_decor_active; }
	sf::Color get_color_decor_border(){ return color_decor_border; }
	int get_number(){ return number; }

	wstring get_choosestring(){
		return(button_list[choosenum].get_string());
	}

	bool is_active(){
		check_it();
		return active;
	}
	
	bool is_choosing(){
		check_it();
		return choosing;
	}
	
	void update_it(){
		check_it();
		if(choosing){
			scrolllist.update_it();
			for(int i = 0; i < button_list.size(); i++){
				switch (window_n) {
				case 1:
					button_list[i].update_without_cursor(window_add.mapPixelToCoords(sf::Mouse::getPosition(window_add), scrolllist.get_view()));
					break;

				case 2:
					button_list[i].update_without_cursor(window_change.mapPixelToCoords(sf::Mouse::getPosition(window_change), scrolllist.get_view()));
					break;

				case 3:
					button_list[i].update_without_cursor(window_delete.mapPixelToCoords(sf::Mouse::getPosition(window_delete), scrolllist.get_view()));
					break;

				case 4:
					button_list[i].update_without_cursor(window_login.mapPixelToCoords(sf::Mouse::getPosition(window_login), scrolllist.get_view()));
					break;
				
				default:
					button_list[i].update_without_cursor(window_main.mapPixelToCoords(sf::Mouse::getPosition(window_main), scrolllist.get_view()));
					break;
				}
			}
		} else {
			textbox.change_string(button_texts[choosenum]);
		}

		if(is_active()){
			switch (window_n) {
				case 1:
					window_add.setMouseCursor(cursor_hand);
					break;

				case 2:
					window_change.setMouseCursor(cursor_hand);
					break;

				case 3:
					window_delete.setMouseCursor(cursor_hand);
					break;

				case 4:
					window_login.setMouseCursor(cursor_hand);
					break;
				
				default:
					window_main.setMouseCursor(cursor_hand);
					break;
				}
		}
	}

	void check_it(){
		if(choosing){
			if(mouse_position.x >= x && mouse_position.x <= x+w && mouse_position.y >= y && mouse_position.y <= y+h){
				for(int i = 0; i < button_list.size(); i++){
					switch (window_n) {
					case 1:
						if(button_list[i].is_clicked(window_add.mapPixelToCoords(sf::Mouse::getPosition(window_add), scrolllist.get_view()))){
							choosenum = i;
							choosing = false;
						}
						break;

					case 2:
						if(button_list[i].is_clicked(window_change.mapPixelToCoords(sf::Mouse::getPosition(window_change), scrolllist.get_view()))){
							choosenum = i;
							choosing = false;
						}
						break;

					case 3:
						if(button_list[i].is_clicked(window_delete.mapPixelToCoords(sf::Mouse::getPosition(window_delete), scrolllist.get_view()))){
							choosenum = i;
							choosing = false;
						}
						break;

					case 4:
						if(button_list[i].is_clicked(window_login.mapPixelToCoords(sf::Mouse::getPosition(window_login), scrolllist.get_view()))){
							choosenum = i;
							choosing = false;
						}
						break;
					
					default:
						if(button_list[i].is_clicked(window_main.mapPixelToCoords(sf::Mouse::getPosition(window_main), scrolllist.get_view()))){
							choosenum = i;
							choosing = false;
						}
						break;
					}
				}
			}
		} else {
			if(clickedarea.is_clicked()){ choosing = true; }
		}
		if(events_mouse.L_mouse && !(mouse_position.x >= x && mouse_position.x <= x+w && mouse_position.y >= y && mouse_position.y <= y+h)){ choosing = false; }

		if(!choosing){
			if(rectanglebox.is_active()){ active = true; } 
			else { active = false; }
		} else {
			if(mouse_position.x >= x && mouse_position.x <= x+w-scrollbarthickness && mouse_position.y >= y && mouse_position.y <= y+h){ active = true; } 
			else { active = false; }
		}
	}

	void draw_it(){
		if(!choosing){
			rectanglebox.draw_it();
			rectanglebox_decor.draw_it();
			borderbox_decor.draw_it();
			textbox.draw_it();
			switch (window_n) {
			case 1:
				window_add.draw(triangle);
				break;

			case 2:
				window_change.draw(triangle);
				break;

			case 3:
				window_delete.draw(triangle);
				break;

			case 4:
				window_login.draw(triangle);
				break;
			
			default:
				window_main.draw(triangle);
				break;
			}
		} else {
			borderbox.draw_it();
			scrolllist.draw_it();
			for(int i = 0; i < button_list.size(); i++){
				button_list[i].draw_it();
			}
			switch (window_n) {
			case 1:
				window_add.setView(view_add);
				break;

			case 2:
				window_change.setView(view_change);
				break;

			case 3:
				window_delete.setView(view_delete);
				break;

			case 4:
				window_login.setView(view_delete);
				break;
			
			default:
				window_main.setView(view_main);
				break;
			}
		}
	}

	void create_it(int WINDOW_N, int X, int Y, int W, int H_BUTTON, int H, int SCROLLBARTHICKNESS, int H_TEXT, vector<wstring> BUTTON_TEXTS){
		window_n = WINDOW_N;
		x = X;
		y = Y;
		w = W;
		h_button = H_BUTTON;
		h = H;
		h_text = H_TEXT;
		scrollbarthickness = SCROLLBARTHICKNESS;
		button_texts = BUTTON_TEXTS;
		number = button_texts.size();
		button_list.resize(number);
		if(h_text*(number) > h){
			h_area = h_text*(number);
		} else {
			h_area = h;
		}

		if(window_n == 1 || window_n == 2 || window_n == 3){
			color_decor =  sf::Color(237,220,55);
			color_decor_active = sf::Color(250,243,158);
			color_decor_border =  sf::Color(150,137,14);
		}

		borderbox.create_it(window_n, x, y, w, h, borderthickness, color_border);
		rectanglebox.create_it(window_n, x, y, w, h_button, sf::Color(255,255,255));
		rectanglebox_decor.create_it(window_n, x+w-scrollbarthickness, y, scrollbarthickness, h_button, color_decor);
		borderbox_decor.create_it(window_n, x+w-scrollbarthickness+2, y+2, scrollbarthickness-4, h_button-4, 2, color_decor_border);
		clickedarea.create_it(window_n, x, y, w, h_button);
		scrolllist.create_it(window_n, x, y, w, h, h_area, scrollbarthickness);
		textbox.create_it(window_n, x+3, y, 20, L"");

		for(int i = 0; i < number; i++){
			button_list[i].create_it(window_n, 0, h_text*i, w-scrollbarthickness, h_text, 0, 20, sf::Color(255,255,255), sf::Color(255,255,255), sf::Color(220,220,220), 3, 0, button_texts[i]);
		}
		

		triangle.setRadius(7);
		triangle.setPointCount(3);
		triangle.setRotation(180);
		triangle.setFillColor(sf::Color(50,50,50));
		triangle.setPosition(x+w-2, y+h_button-6);
	}

	ChooseBox(){}
	~ChooseBox(){}
};

#endif