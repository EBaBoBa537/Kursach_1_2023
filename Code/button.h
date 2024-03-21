#ifndef BUTTON_H
#define BUTTON_H

class Button{
private:
	int window_n;
	int x = 0; 
	int y = 0; 
	int w = 0; 
	int h = 0;
	int thickness = 0; 
	int textsize = 20;
	int otstup_left = 0;
	int otstup_top = 0;
	wstring string = L"";
	sf::Color color_border = sf::Color(150,137,14);
	sf::Color color_fill = sf::Color(237,220,55);
	sf::Color color_fill_pressing = sf::Color(250,243,158);
	RectangleBox rectanglebox;
	BorderBox borderbox;
	TextBox textbox;
	ClickedArea clickedarea;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_w(){ return w; }
	int get_h(){ return h; }
	int get_thickness(){ return thickness; }
	int get_textsize(){ return textsize; }
	int get_otstup_left(){ return otstup_left; }
	int get_otstup_top(){ return otstup_top; }
	wstring get_string(){ return string; }
	sf::Color get_color_border(){ return color_border; }
	sf::Color get_color_fill(){ return color_fill; }
	sf::Color get_color_fill_pressing(){ return color_fill_pressing; }

	bool is_active(sf::Vector2f MOUSE_POSITION = mouse_position){
		return clickedarea.is_active(MOUSE_POSITION);
	}

	bool is_clicked(sf::Vector2f MOUSE_POSITION = mouse_position){
		return clickedarea.is_clicked(MOUSE_POSITION);
	}

	void update_it(sf::Vector2f MOUSE_POSITION = mouse_position){
		if(clickedarea.is_active(MOUSE_POSITION)){ 
			rectanglebox.change_color(color_fill_pressing);

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
			
		} else { 
			rectanglebox.change_color(color_fill); 
		}
	}

	void update_without_cursor(sf::Vector2f MOUSE_POSITION = mouse_position){
		if(clickedarea.is_active(MOUSE_POSITION)){ 
			rectanglebox.change_color(color_fill_pressing);
		} else { 
			rectanglebox.change_color(color_fill); 
		}
	}

	void draw_it(){
		rectanglebox.draw_it();
		borderbox.draw_it();
		textbox.draw_it();
	}

	void create_it(int WINDOW_N, int X, int Y, int W, int H, int THICKNESS, int TEXTSIZE, sf::Color COLOR_BORDER, sf::Color COLOR_FILL, sf::Color COLOR_FILL_PRESSING, int OTSTUP_LEFT, int OTSTUP_TOP, wstring STRING){
		window_n = WINDOW_N;
		x = X; 
		y = Y; 
		w = W; 
		h = H;
		textsize = TEXTSIZE;
		thickness = THICKNESS;
		color_border = COLOR_BORDER;
		color_fill = COLOR_FILL;
		color_fill_pressing = COLOR_FILL_PRESSING;
		otstup_left = OTSTUP_LEFT;
		otstup_top = OTSTUP_TOP;
		string = STRING;
		rectanglebox.create_it(window_n, x, y, w, h, color_fill);
		borderbox.create_it(window_n, x+thickness, y+thickness, w-2*thickness, h-2*thickness, thickness, color_border);
		textbox.create_it(window_n, x + thickness + otstup_left, y + thickness + otstup_top, textsize, string);
		clickedarea.create_it(window_n, x, y, w, h);
	}

	Button(){}
	~Button(){}
};

#endif