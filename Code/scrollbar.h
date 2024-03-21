#ifndef SCROLLBAR_H
#define SCROLLBAR_H

class Scrollbar{
private:
	int window_n;
	double scroll_progress = 0; // прогресс прокрутки (от 0 до 1)
	double scroll_speed = 0.05; // скорость прокрутки (прибавляется к scroll_progress)
	double scroll_size = 0.2; // относительный размер rectangle_holder (от 0 до 1)
	int active_x = 0; 
	int active_y = 0; 
	int active_w = 0; 
	int active_h = 0;
	sf::Color color_line = sf::Color(219,219,219);
	sf::Color color_holder = sf::Color(165,165,165);
	sf::Color color_holder_grabbed = sf::Color(110,110,110);
	int x = 0; 
	int y = 0; 
	int length = 200; 
	int thickness = 18;
	double mouse_x_grabbed_first = 0;
	double mouse_y_grabbed_first = 0;
	double scroll_progress_first = 0;
	RectangleBox rectanglebox_line;
	RectangleBox rectanglebox_holder;
	ClickedArea clickedarea_activearea;
	ClickedArea clickedarea_holder;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_length(){ return length; }
	int get_thickness(){ return thickness; }
	int get_active_x(){ return active_x; }
	int get_active_y(){ return active_y; }
	int get_active_w(){ return active_w; }
	int get_active_h(){ return active_h; }
	double get_scroll_progress(){ return scroll_progress; }
	double get_scroll_speed(){ return scroll_speed; }
	double get_scroll_size(){ return scroll_size; }
	sf::Color get_color_line(){ return color_line; }
	sf::Color get_color_holder(){ return color_holder; }
	sf::Color get_color_holder_grabbed(){ return color_holder_grabbed; }
	double get_mouse_x_grabbed_first(){ return mouse_x_grabbed_first; }
	double get_mouse_y_grabbed_first(){ return mouse_y_grabbed_first; }
	double get_scroll_progress_first(){ return scroll_progress_first; }

	// void change_holdersize(double SCROLL_SIZE){
	// 	scroll_size = SCROLL_SIZE;
	// }

	void check_it(){
		// изменить scroll_progress прокруткой
		if(events_mouse.mouse_scroll != 0  && clickedarea_activearea.is_active()){
			if(events_mouse.mouse_scroll == 1){
				if(scroll_progress - scroll_speed > 0){ scroll_progress -= scroll_speed; } 
				else { scroll_progress = 0; }
			}
			if(events_mouse.mouse_scroll == -1){
				if(scroll_progress + scroll_speed < 1){ scroll_progress += scroll_speed; } 
				else { scroll_progress = 1; }
			}
		}
		// изменить scroll_progress перетаскиванием
		if(clickedarea_holder.is_grabbed()){
			scroll_progress_first = scroll_progress;
			mouse_x_grabbed_first = mouse_position.x;
			mouse_y_grabbed_first = mouse_position.y;
		} else {
			if(clickedarea_holder.is_grabbing()){
				if(scroll_progress_first + (mouse_position.y - mouse_y_grabbed_first)/(length-length*scroll_size) > 0 && scroll_progress + (mouse_position.y - mouse_y_grabbed_first)/(length-length*scroll_size) < 1){
					scroll_progress = scroll_progress_first + (mouse_position.y - mouse_y_grabbed_first)/(length-length*scroll_size);
				} else {
					if(scroll_progress_first + (mouse_position.y - mouse_y_grabbed_first)/(length-length*scroll_size) <= 0) {
						scroll_progress = 0;
					}
						if(scroll_progress_first + (mouse_position.y - mouse_y_grabbed_first)/(length-length*scroll_size) >= 1) {
						scroll_progress = 1;
					}
				}
			}
		}
	}

	void update_it(){
		check_it();
		rectanglebox_holder.change_position(x, y+(length-length*scroll_size)*scroll_progress);
		clickedarea_holder.change_position(x, y+(length-length*scroll_size)*scroll_progress);
		if(clickedarea_holder.is_pressing() || clickedarea_holder.is_active()){
			rectanglebox_holder.change_color(color_holder_grabbed);
		} else {
			rectanglebox_holder.change_color(color_holder);
		}
	}

	void draw_it(){
		rectanglebox_line.draw_it();
		rectanglebox_holder.draw_it();
	}

	void create_it(int WINDOW_N, int X, int Y, int THICKNESS, int LENGTH, int ACTIVE_X, int ACTIVE_Y, int ACTIVE_W, int ACTIVE_H, double SCROLL_SIZE){
		window_n = WINDOW_N;
		x = X; 
		y = Y; 
		thickness = THICKNESS; 
		length = LENGTH;
		active_x = ACTIVE_X; 
		active_y = ACTIVE_Y; 
		active_w = ACTIVE_W; 
		active_h = ACTIVE_H;
		scroll_size = SCROLL_SIZE;
		rectanglebox_line.create_it(window_n, x, y, thickness, length, color_line);
		rectanglebox_holder.create_it(window_n, x, y+(length-length*scroll_size)*scroll_progress, thickness, length*scroll_size, color_holder);
		clickedarea_holder.create_it(window_n, x, y+(length-length*scroll_size)*scroll_progress, thickness, length*scroll_size);
		clickedarea_activearea.create_it(window_n, active_x, active_y, active_w, active_h);
	}

	Scrollbar(){}
	~Scrollbar(){}
};

#endif