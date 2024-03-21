#ifndef TEXTBOX_H
#define TEXTBOX_H

class TextBox{
private:
	int window_n;
	int x = 0;
	int y = 0;
	int size = 0;
	wstring string = L"";
	int stylenum = 0;
	sf::Color color = sf::Color(0,0,0);
	sf::Text text;

public:
	
	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	// для font
	static sf::Font font;
	class TextBox_font{
	public:
		TextBox_font(){
			font.loadFromFile("materials/fonts/calibri.ttf");
		}
		~TextBox_font(){}
	}; static TextBox_font textbox_font_initialize;

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_size(){ return size; }
	wstring get_wstring(){ return string; }
	int get_stylenum(){ return stylenum; }
	sf::Color get_color(){ return color; }

	void change_string(wstring STRING){
		string = STRING;
		text.setString(string);
	}

	void draw_it(){
		switch (window_n) {
		case 1:
			window_add.draw(text);
			break;

		case 2:
			window_change.draw(text);
			break;

		case 3:
			window_delete.draw(text);
			break;

		case 4:
			window_login.draw(text);
			break;
		
		default:
			window_main.draw(text);
			break;
		}
	}

	void create_it(int WINDOW_N, int X, int Y, int SIZE, wstring STRING, int STYLENUM = 0){
		window_n = WINDOW_N;
		x = X; 
		y = Y;
		size = SIZE;
		string = STRING;
		stylenum = STYLENUM;
		text.setFont(TextBox::font);
		text.setFillColor(color);
		text.setString(string);
		text.setPosition(x, y);
		text.setCharacterSize(size);
		if(stylenum == 1){ 
			text.setStyle(sf::Text::Italic); 
		} else { 
			text.setStyle(sf::Text::Regular); 
		}
	}

	TextBox(){}
	~TextBox(){}
};

#endif