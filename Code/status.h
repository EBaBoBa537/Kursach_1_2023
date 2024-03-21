#ifndef STATUS_H
#define STATUS_H

class Status{
private:
	int window_n;
	int x = 0;
	int y = 0;
	int w = 20;
	int h = 20;
	int otstup_left = 0;
	int otstup_top = 0;
	int textsize = 0;
	int image_num = 0;
	std::wstring message = L"";
	std::vector<std::string> image_filenames = {
		"materials/images/znachok_1.png",
		"materials/images/znachok_2.png",
		"materials/images/znachok_3.png"
	};
	ImageBox imagebox;
	TextBox textbox;

public:

	void set_window_n(int WINDOW_N) { window_n = WINDOW_N; }

	void update_it(){
		
	}

	void change_it(int IMAGE_NUM, std::wstring MESSAGE){
		image_num = IMAGE_NUM;
		imagebox.change_image(image_filenames[image_num]);
		message = MESSAGE;
		textbox.change_string(message);
	}

	void draw_it(){
		imagebox.draw_it();
		textbox.draw_it();
	}

	void create_it(int WINDOW_N, int X, int Y, int W, int H, int textSIZE, int OTSTUP_LEFT, int otstup_top_AAA, int IMAGE_NUM, std::wstring MESSAGE){
		window_n = WINDOW_N;
		x = X; 
		y = Y; 
		w = W; 
		h = H;
		textsize = textSIZE;
		message = MESSAGE;
		image_num = IMAGE_NUM;
		otstup_left = OTSTUP_LEFT;
		otstup_top = otstup_top_AAA;
		imagebox.create_it(window_n, x, y, w, h, image_filenames[image_num]);
		textbox.create_it(window_n, x+w+otstup_left, y+otstup_top, textsize, message, 1);
	}

	Status(){}
	~Status(){}
};

#endif