#ifndef WRITEBOX_H
#define WRITEBOX_H

class WriteBox{
private:
	int window_n; 
	bool writing = false;
	bool active = false;
	int type; // 0 - дата, 1 - цена, 2 - логин/пароль
	int x = 0; 
	int y = 0; 
	int w = 100; 
	int h = 25;
	int thickness = 2;
	int textsize = 20;
	int otstup_left = 0;
	int otstup_top = 0;
	sf::Color color = sf::Color(255,255,255);
	sf::Color color_border = sf::Color(10,10,10);
	RectangleBox rectanglebox;
	ClickedArea clickedarea;
	BorderBox borderbox;
	TextBox textbox;
	wstring string = L"";

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_w(){ return w; }
	int get_h(){ return h; }
	int get_type(){ return type; }
	int get_thickness(){ return thickness; }
	int get_textsize(){ return textsize; }
	int get_otstup_left(){ return otstup_left; }
	int get_otstup_top(){ return otstup_top; }
	wstring get_string(){ return string; }
	sf::Color get_color(){ return color; }
	sf::Color get_color_border(){ return color_border; }

	bool is_active(sf::Vector2f MOUSE_POSITION = mouse_position){
		check_it(MOUSE_POSITION);
		return active;
	}

	bool is_writing(sf::Vector2f MOUSE_POSITION = mouse_position){
		check_it(MOUSE_POSITION);
		return writing;
	}

	void change_string(wstring STRING){
		string = STRING;
		textbox.change_string(string);
	}

	void check_it(sf::Vector2f MOUSE_POSITION = mouse_position){
		if(clickedarea.is_clicked(MOUSE_POSITION)){
			if(writing){
				writing = false;
			} else {
				writing = true;
			}
		}
		if(events_mouse.L_mouse && !clickedarea.is_active(MOUSE_POSITION)){
			writing = false;
		}
		active = clickedarea.is_active(MOUSE_POSITION);
	}

	void update_it(sf::Vector2f MOUSE_POSITION = mouse_position){
		if(is_writing(MOUSE_POSITION)){ 
			borderbox.change_thickness(thickness);
		} else {
			borderbox.change_thickness(0);	
		}

		switch (type) {
			// --------------------- для ввода даты --------------------- 
		case 0:
			if(writing){
				if(string.size() < 10){
					for(int i = 0; i < events_nums.size(); i++){
						if(events_nums[i].pressed){
							string += to_wstring(events_nums[i].text);
						}
					}
				}
				if(string.size() == 2){
					string += L".";
				}
				if(string.size() == 5){
					string += L".2023";
				}
				if(events_mouse.backspace_pressed && string.size() > 0){
					if(string.size() == 3){
						string.erase(string.size()-1);
					}
					if(string.size() == 10){
						string.erase(string.size()-5);
					}
					string.erase(string.size()-1);
				}
				textbox.change_string(string);
			}
			break;

			// -------------------- для ввода цены -------------------- 
		case 1:
			if(writing){
				if(string.size() < 3){
					for(int i = 0; i < events_nums.size(); i++){
						if(events_nums[i].pressed){
							string += to_wstring(events_nums[i].text);
						}
					}
				}
				if(events_mouse.backspace_pressed && string.size() > 0){
					string.erase(string.size()-1);
				}
				textbox.change_string(string);
			}
			break;

			case 2:
			if(writing){
				if(string.size() < 20){
					for(int i = 0; i < events_nums.size(); i++){
						if(events_nums[i].pressed){
							string += to_wstring(events_nums[i].text);
						}
					}
					for(int i = 0; i < events_text.size(); i++){
						if(events_text[i].pressed){
							string += events_text[i].text;
						}
					}
				}
				if(events_mouse.backspace_pressed && string.size() > 0){
					string.erase(string.size()-1);
				}
				textbox.change_string(string);
			}
			break;
		}

		if(is_active(MOUSE_POSITION)) { 
			switch (window_n) {
			case 1:
				window_add.setMouseCursor(cursor_text);
				break;

			case 2:
				window_change.setMouseCursor(cursor_text);
				break;

			case 3:
				window_delete.setMouseCursor(cursor_text);
				break;

			case 4:
				window_login.setMouseCursor(cursor_text);
				break;
			
			default:
				window_main.setMouseCursor(cursor_text);
				break;
			}
		}
	}

	void draw_it(){
		rectanglebox.draw_it();
		borderbox.draw_it();
		textbox.draw_it();
	}

	void create_it(int WINDOW_N, int X, int Y, int W, int H, int THICKNESS, int TEXTSIZE, int OTSTUP_LEFT, int OTSTUP_TOP, int TYPE, wstring STRING = L""){
		window_n = WINDOW_N;
		x = X;
		y = Y;
		w = W;
		h = H;
		type = TYPE;
		thickness = THICKNESS;
		textsize = TEXTSIZE;
		otstup_left = OTSTUP_LEFT;
		otstup_top = OTSTUP_TOP;
		string = STRING;
		rectanglebox.create_it(window_n, x, y, w, h, color);
		clickedarea.create_it(window_n, x, y, w, h);
		textbox.create_it(window_n, x+otstup_left, y+otstup_top, textsize, string);
		borderbox.create_it(window_n, x, y, w, h, thickness, color_border);
	}

	WriteBox(){}
	~WriteBox(){}
};

#endif