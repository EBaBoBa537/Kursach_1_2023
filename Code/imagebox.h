#ifndef IMAGEBOX_H
#define IMAGEBOX_H

class ImageBox{
private:
	int window_n;
	int x = 0; 
	int y = 0; 
	int w = 0; 
	int h = 0;
	sf::Sprite sprite;
    sf::Texture texture;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_w(){ return w; }
	int get_h(){ return h; }

	void change_image(string FILENAME){
		texture.loadFromFile(FILENAME); 
		sprite.setTexture(texture);
	}

	void change_position(int X, int Y){
		x = X; y = Y;
		sprite.setPosition(x + w/2, y + h/2);
	}

	void change_size(int W, int H){
		w = W; h = H;
		sprite.setTextureRect(sf::IntRect(0, 0, w, h));
		sprite.setPosition(x + w/2, y + h/2);
		sprite.setOrigin(w/2, h/2);
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
			window_add.draw(sprite);
			break;

		case 2:
			window_change.draw(sprite);
			break;

		case 3:
			window_delete.draw(sprite);
			break;
					
		case 4:
			window_login.draw(sprite);
			break;
		
		default:
			window_main.draw(sprite);
			break;
		}
	}

	void create_it(int WINDOW_N, int X, int Y, int W, int H, string FILENAME){
		window_n = WINDOW_N;
		x = X; 
		y = Y; 
		w = W; 
		h = H;
		texture.loadFromFile(FILENAME); 
		sprite.setTextureRect(sf::IntRect(0, 0, w, h));
		sprite.setTexture(texture);
        sprite.setPosition(x + w/2, y + h/2);
		sprite.setOrigin(w/2, h/2);
	}

	ImageBox(){}
	~ImageBox(){}
};

#endif