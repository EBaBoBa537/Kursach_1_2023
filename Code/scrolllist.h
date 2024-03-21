#ifndef SCROLLLIST_H
#define SCROLLLIST_H

class ScrollList{
private:
	int window_n;
	int x = 0;
	int y = 0;
	int w = 0;
	double h = 0;
	double h_area = 0;
	int scrollbarthickness = 0;
	Scrollbar scrollbar;
	RectangleBox rectanglebox;
	sf::View view;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_w(){ return w; }
	double get_h(){ return h; }
	double get_h_area(){ return h_area; }
	int get_scrollbarthickness(){ return scrollbarthickness; }
	sf::View get_view(){ return view; }

	void change_h_area(int H_AREA){
		h_area = H_AREA;
		scrollbar.create_it(window_n, x+w-scrollbarthickness, y, scrollbarthickness, h, x, y, x+w, y+h, round(static_cast<double>(h)/static_cast<double>(h_area)*100)/100);
		rectanglebox.create_it(window_n, 0,0,w-scrollbarthickness, h_area, sf::Color(255,255,255));
	}

	bool is_active(){
		if(mouse_position.x >= x && mouse_position.x <= x + w && mouse_position.y >= y && mouse_position.y <= y + h){ 
			return true; 
		} else { 
			return false; 
		}
	}

	void draw_it(){
		scrollbar.draw_it();
		switch (window_n) {
		case 1:
			window_add.setView(view);
			break;

		case 2:
			window_change.setView(view);
			break;

		case 3:
			window_delete.setView(view);
			break;

		case 4:
			window_login.setView(view);
			break;
		
		default:
			window_main.setView(view);
			break;
		}
		rectanglebox.draw_it();
	}

	void update_it(){
		scrollbar.update_it();
		view.setCenter((w-scrollbarthickness)/2, h/2+(h_area-h)*scrollbar.get_scroll_progress());
	}

	void create_it(int WINDOW_N, int X, int Y, int W, double H, double H_AREA, int SCROLLBARTHICKNESS) { 
		window_n = WINDOW_N;
		x = X;
		y = Y;
		w = W;
		h = H;
		h_area = H_AREA;
		scrollbarthickness = SCROLLBARTHICKNESS;
		scrollbar.create_it(window_n, x+w-scrollbarthickness, y, scrollbarthickness, h, x, y, x+w, y+h, round(static_cast<double>(h)/static_cast<double>(h_area)*100)/100);

		rectanglebox.create_it(window_n, 0,0,w-scrollbarthickness, h_area, sf::Color(255,255,255));
		view.setSize((w-scrollbarthickness), h);
		view.setCenter((w-scrollbarthickness)/2, h/2+(h_area-h)*scrollbar.get_scroll_progress());
		switch (window_n) {
		case 1:
			view.setViewport(sf::FloatRect(static_cast<float>(x)/static_cast<float>(window_add_w), static_cast<float>(y)/static_cast<float>(window_add_h), static_cast<float>(w-scrollbarthickness)/static_cast<float>(window_add_w), static_cast<float>(h)/static_cast<float>(window_add_h)));
			break;

		case 2:
			view.setViewport(sf::FloatRect(static_cast<float>(x)/static_cast<float>(window_change_w), static_cast<float>(y)/static_cast<float>(window_change_h), static_cast<float>(w-scrollbarthickness)/static_cast<float>(window_change_w), static_cast<float>(h)/static_cast<float>(window_change_h)));
			break;

		case 3:
			view.setViewport(sf::FloatRect(static_cast<float>(x)/static_cast<float>(window_delete_w), static_cast<float>(y)/static_cast<float>(window_delete_h), static_cast<float>(w-scrollbarthickness)/static_cast<float>(window_delete_w), static_cast<float>(h)/static_cast<float>(window_delete_h)));
			break;

		case 4:
			view.setViewport(sf::FloatRect(static_cast<float>(x)/static_cast<float>(window_login_w), static_cast<float>(y)/static_cast<float>(window_login_h), static_cast<float>(w-scrollbarthickness)/static_cast<float>(window_login_w), static_cast<float>(h)/static_cast<float>(window_login_h)));
			break;
		
		default:
			view.setViewport(sf::FloatRect(static_cast<float>(x)/static_cast<float>(window_main_w), static_cast<float>(y)/static_cast<float>(window_main_h), static_cast<float>(w-scrollbarthickness)/static_cast<float>(window_main_w), static_cast<float>(h)/static_cast<float>(window_main_h)));
			break;
		}
	}

	ScrollList(){}
	~ScrollList(){}
};

#endif