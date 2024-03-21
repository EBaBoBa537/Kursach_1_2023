#ifndef CLICKEDAREA_H
#define CLICKEDAREA_H

class ClickedArea{
private:
	int window_n;
	bool active = true; // активный ли для нажатия
	bool pressing = false; // нажат ли
	bool grabbing = false; // зажат ли
	bool clicked = false; // срабатывает 1 раз после нажатия
	bool grabbed = false; // срабатывает 1 раз при зажатии
	int x = 0; 
	int y = 0; 
	int w = 0; 
	int h = 0;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_w(){ return w; }
	int get_h(){ return h; }

	bool is_active(sf::Vector2f MOUSE_POSITION = mouse_position){
		check_it(MOUSE_POSITION);
		return active;
	}

	bool is_pressing(sf::Vector2f MOUSE_POSITION = mouse_position){
		check_it(MOUSE_POSITION);
		return pressing;
	}

	bool is_grabbing(sf::Vector2f MOUSE_POSITION = mouse_position){
		check_it(MOUSE_POSITION);
		return grabbing;
	}

	bool is_clicked(sf::Vector2f MOUSE_POSITION = mouse_position){
		check_it(MOUSE_POSITION);
		return clicked;
	}

	bool is_grabbed(sf::Vector2f MOUSE_POSITION = mouse_position){
		check_it(MOUSE_POSITION);
		return grabbed;
	}

	void change_position(int X, int Y){
		x = X; 
		y = Y; 
	}

	void change_size(int W, int H){
		w = W; 
		h = H;
	}

	void check_it(sf::Vector2f MOUSE_POSITION = mouse_position){
		if (MOUSE_POSITION.x >= x && MOUSE_POSITION.x <= x + w && MOUSE_POSITION.y >= y && MOUSE_POSITION.y <= y + h){ 
			active = true; 
		}  else { 
			active = false; 
		}

		if (events_mouse.L_mouse){
			if (active){ 
				pressing = true; 
				if(!grabbing){
					grabbed = true;
				} else {
					grabbed = false;
				}
				grabbing = true;
			}  else { 
				pressing = false; 
			}
		} else {
			if (pressing){ 
				clicked = true; 
				pressing = false; 
			} else { 
				clicked = false; 
			}
			grabbing = false;
			grabbed = false;
		}
	}

	void create_it(int WINDOW_N, int X, int Y, int W, int H){
		window_n = WINDOW_N;
		x = X; 
		y = Y; 
		w = W; 
		h = H;
	}

	ClickedArea(){}
	~ClickedArea(){}
};

#endif