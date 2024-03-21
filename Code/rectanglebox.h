#ifndef RECTANGLEBOX_H
#define RECTANGLEBOX_H

class RectangleBox{
private:
	int window_n;
	int x = 0; 
	int y = 0; 
	int w = 0; 
	int h = 0;
	sf::Color color = sf::Color(255,255,255);
	sf::RectangleShape rectangle;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_w(){ return w; }
	int get_h(){ return h; }
	sf::Color get_color(){ return color; }

	void change_color(sf::Color COLOR){
		color = COLOR;
		rectangle.setFillColor(color);
	}

	void change_position(int X, int Y){
		x = X; 
		y = Y; 
		rectangle.setPosition(x, y);
	}

	void change_size(int W, int H){
		w = W; 
		h = H;
		rectangle.setSize(sf::Vector2f(w, h));
	}

	bool is_active(sf::Vector2f MOUSE_POSITION = mouse_position){
		if(MOUSE_POSITION.x >= x && MOUSE_POSITION.x <= x + w && MOUSE_POSITION.y >= y && MOUSE_POSITION.y <= y + h){ 
			return true; 
		} else { 
			return false; 
		}
	}

	void draw_it(){
		switch (window_n) {
		case 1:
			window_add.draw(rectangle);
			break;

		case 2:
			window_change.draw(rectangle);
			break;

		case 3:
			window_delete.draw(rectangle);
			break;

		case 4:
			window_login.draw(rectangle);
			break;
		
		default:
			window_main.draw(rectangle);
			break;
		}
	}

	void create_it(int WINDOW_N, int X, int Y, int W, int H, sf::Color COLOR){
		window_n = WINDOW_N;
		x = X; 
		y = Y; 
		w = W; 
		h = H;
		color = COLOR;
		rectangle.setSize(sf::Vector2f(w, h));
		rectangle.setFillColor(color);
		rectangle.setPosition(x, y);
	}

	RectangleBox(){}
	~RectangleBox(){}
};

#endif