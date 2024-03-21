#ifndef OUTPUTBOX_H
#define OUTPUTBOX_H

class Outputbox{
private:
	int window_n;
	int x; 
	int y; 
	int w; 
	int h;
	int h_area;
	int textsize;
	int h_text;
	int scrollbarthickness;
	int number;
	int otstup_left;
	ScrollList scrolllist;
	vector<TextBox> textbox_num_vector;
	vector<TextBox> textbox_city_1_vector;
	vector<TextBox> textbox_city_2_vector;
	vector<TextBox> textbox_date_1_vector;
	vector<TextBox> textbox_date_2_vector;
	vector<TextBox> textbox_transport_vector;
	vector<TextBox> textbox_price_vector;
	vector<TextBox> textbox_tickets_vector;
	vector<data_wstring_struct> data_wstring;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_w(){ return w; }
	int get_h(){ return h; }
	int get_h_area(){ return h_area; }
	int get_textsize(){ return textsize; }
	int get_h_text(){ return h_text; }
	int get_scrollbarthickness(){ return scrollbarthickness; }
	int get_number(){ return number; }
	int get_otstup_left(){ return otstup_left; }

	void update_it(){
		scrolllist.update_it();
	}

	void draw_it(){
		scrolllist.draw_it();
		for(int i = 0; i < number; i++){
			textbox_num_vector[i].draw_it();
			textbox_city_1_vector[i].draw_it();
			textbox_city_2_vector[i].draw_it();
			textbox_date_1_vector[i].draw_it();
			textbox_date_2_vector[i].draw_it();
			textbox_transport_vector[i].draw_it();
			textbox_price_vector[i].draw_it();
			textbox_tickets_vector[i].draw_it();
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

	void change_list(vector<data_wstring_struct> DATA_WSTRING){
		data_wstring = DATA_WSTRING;
		number = data_wstring.size();
		if(h_text*number > h){
			h_area = h_text*number;
		} else {
			h_area = h;
		}
		textbox_num_vector.resize(number);
		textbox_city_1_vector.resize(number);
		textbox_city_2_vector.resize(number);
		textbox_date_1_vector.resize(number);
		textbox_date_2_vector.resize(number);
		textbox_transport_vector.resize(number);
		textbox_price_vector.resize(number);
		textbox_tickets_vector.resize(number);

		for(int i = 0; i < number; i++){
			textbox_num_vector[i].create_it(window_n, otstup_left, i*h_text, textsize, data_wstring[i].num_line);
			textbox_city_1_vector[i].create_it(window_n, otstup_left + 40, i*h_text, textsize, data_wstring[i].cityfirst);
			textbox_city_2_vector[i].create_it(window_n, otstup_left + 200, i*h_text, textsize, data_wstring[i].citysecond);
			textbox_date_1_vector[i].create_it(window_n, otstup_left + 360, i*h_text, textsize, data_wstring[i].datefirst);
			textbox_date_2_vector[i].create_it(window_n, otstup_left + 500, i*h_text, textsize, data_wstring[i].datesecond);
			textbox_transport_vector[i].create_it(window_n, otstup_left + 640, i*h_text, textsize,data_wstring[i].transport);
			textbox_price_vector[i].create_it(window_n, otstup_left + 820, i*h_text, textsize, data_wstring[i].price);
			textbox_tickets_vector[i].create_it(window_n, otstup_left + 920, i*h_text, textsize, data_wstring[i].number);
		}

		scrolllist.change_h_area(h_area);
	}

	void create_it(int WINDOW_N, int X, int Y, int W, int H, int TEXTSIZE, int H_TEXT, int OTSTUP_LEFT, int scrollbarTHICKNESS, vector<data_wstring_struct> DATA_WSTRING){
		window_n = WINDOW_N;
		x = X;
		y = Y;
		w = W;
		h = H;
		h_text = H_TEXT;
		textsize = TEXTSIZE;
		otstup_left = OTSTUP_LEFT;
		scrollbarthickness = scrollbarTHICKNESS;
		data_wstring = DATA_WSTRING;
		number = data_wstring.size();
		if(h_text*number > h){
			h_area = h_text*number;
		} else {
			h_area = h;
		}
		textbox_num_vector.resize(number);
		textbox_city_1_vector.resize(number);
		textbox_city_2_vector.resize(number);
		textbox_date_1_vector.resize(number);
		textbox_date_2_vector.resize(number);
		textbox_transport_vector.resize(number);
		textbox_price_vector.resize(number);
		textbox_tickets_vector.resize(number);
		
		scrolllist.create_it(window_n, x, y, w, h, h_area, 18);
		for(int i = 0; i < number; i++){
			textbox_num_vector[i].create_it(window_n, otstup_left, i*h_text, textsize, data_wstring[i].num_line);
			textbox_city_1_vector[i].create_it(window_n, otstup_left + 40, i*h_text, textsize, data_wstring[i].cityfirst);
			textbox_city_2_vector[i].create_it(window_n, otstup_left + 200, i*h_text, textsize, data_wstring[i].citysecond);
			textbox_date_1_vector[i].create_it(window_n, otstup_left + 360, i*h_text, textsize, data_wstring[i].datefirst);
			textbox_date_2_vector[i].create_it(window_n, otstup_left + 500, i*h_text, textsize, data_wstring[i].datesecond);
			textbox_transport_vector[i].create_it(window_n, otstup_left + 640, i*h_text, textsize,data_wstring[i].transport);
			textbox_price_vector[i].create_it(window_n, otstup_left + 820, i*h_text, textsize, data_wstring[i].price);
			textbox_tickets_vector[i].create_it(window_n, otstup_left + 920, i*h_text, textsize, data_wstring[i].number);
		}
	}

	Outputbox(){}
	~Outputbox(){}	
};

#endif