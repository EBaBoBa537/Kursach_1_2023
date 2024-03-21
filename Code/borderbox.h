#ifndef BORDERBOX_H
#define BORDERBOX_H

class BorderBox{
private:
	int window_n;
	int x = 0; 
	int y = 0; 
	int w = 0; 
	int h = 0;
	int thickness = 0;
	sf::Color color = sf::Color(255,255,255);
	sf::RectangleShape rectangle_left;
	sf::RectangleShape rectangle_right;
	sf::RectangleShape rectangle_top;
	sf::RectangleShape rectangle_bottom;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_w(){ return w; }
	int get_h(){ return h; }
	int get_thickness(){ return thickness; }
	sf::Color get_color(){ return color; }

	void change_color(sf::Color COLOR){
		color = COLOR;
		rectangle_left.setFillColor(color);
		rectangle_right.setFillColor(color);
		rectangle_top.setFillColor(color);
		rectangle_bottom.setFillColor(color);
	}

	void change_position(int X, int Y){
		x = X; 
		y = Y;
		rectangle_left.setPosition(x-thickness, y-thickness);
		rectangle_right.setPosition(x+w, y);
		rectangle_top.setPosition(x, y-thickness);
		rectangle_bottom.setPosition(x-thickness, y+h);
	}

	void change_size(int W, int H){
		w = W; 
		h = H;
		rectangle_left.setPosition(x-thickness, y-thickness);
		rectangle_right.setPosition(x+w, y);
		rectangle_top.setPosition(x, y-thickness);
		rectangle_bottom.setPosition(x-thickness, y+h);
		rectangle_left.setSize(sf::Vector2f(thickness, h+thickness));
		rectangle_right.setSize(sf::Vector2f(thickness, h+thickness));
		rectangle_top.setSize(sf::Vector2f(w+thickness, thickness));
		rectangle_bottom.setSize(sf::Vector2f(w+thickness, thickness));
	}

	void change_thickness(int THICKNESS){
		thickness = THICKNESS;
		rectangle_left.setPosition(x-thickness, y-thickness);
		rectangle_right.setPosition(x+w, y);
		rectangle_top.setPosition(x, y-thickness);
		rectangle_bottom.setPosition(x-thickness, y+h);
		rectangle_left.setSize(sf::Vector2f(thickness, h+thickness));
		rectangle_right.setSize(sf::Vector2f(thickness, h+thickness));
		rectangle_top.setSize(sf::Vector2f(w+thickness, thickness));
		rectangle_bottom.setSize(sf::Vector2f(w+thickness, thickness));
	}

	void draw_it(){
		switch (window_n) {
		case 1:
			window_add.draw(rectangle_left);
			window_add.draw(rectangle_right);
			window_add.draw(rectangle_top);
			window_add.draw(rectangle_bottom);
			break;

		case 2:
			window_change.draw(rectangle_left);
			window_change.draw(rectangle_right);
			window_change.draw(rectangle_top);
			window_change.draw(rectangle_bottom);
			break;

		case 3:
			window_delete.draw(rectangle_left);
			window_delete.draw(rectangle_right);
			window_delete.draw(rectangle_top);
			window_delete.draw(rectangle_bottom);
			break;

		case 4:
			window_login.draw(rectangle_left);
			window_login.draw(rectangle_right);
			window_login.draw(rectangle_top);
			window_login.draw(rectangle_bottom);
			break;
		
		default:
			window_main.draw(rectangle_left);
			window_main.draw(rectangle_right);
			window_main.draw(rectangle_top);
			window_main.draw(rectangle_bottom);
			break;
		}
	}

	void create_it(int WINDOW_N, int X, int Y, int W, int H, int THICKNESS, sf::Color COLOR){
		window_n = WINDOW_N;
		x = X; 
		y = Y; 
		w = W; 
		h = H;
		thickness = THICKNESS;
		color = COLOR;
		rectangle_left.setFillColor(color);
		rectangle_right.setFillColor(color);
		rectangle_top.setFillColor(color);
		rectangle_bottom.setFillColor(color);
		rectangle_left.setSize(sf::Vector2f(thickness, h+thickness));
		rectangle_right.setSize(sf::Vector2f(thickness, h+thickness));
		rectangle_top.setSize(sf::Vector2f(w+thickness, thickness));
		rectangle_bottom.setSize(sf::Vector2f(w+thickness, thickness));
		rectangle_left.setPosition(x-thickness, y-thickness);
		rectangle_right.setPosition(x+w, y);
		rectangle_top.setPosition(x, y-thickness);
		rectangle_bottom.setPosition(x-thickness, y+h);
	}

	BorderBox(){}
	~BorderBox(){}
};

#endif