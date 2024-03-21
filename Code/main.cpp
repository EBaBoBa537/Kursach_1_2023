/// Автор: А.И.Лойко, гр.210901
// Тема: «Программа автоматизации подбора туристических путёвок»

// ------- ⚠ ------------------- Курсач курсач курсач курсач -------------------------------------------------

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <cmath> // для round (округления в scrolllist)
#include <windows.h> // чтобы скрыть консоль при запуске

using namespace std;

bool admin_or_user = false;

sf::RenderWindow window_main;
sf::RenderWindow window_add;
sf::RenderWindow window_change;
sf::RenderWindow window_delete;
sf::RenderWindow window_login;
const int window_main_w = 1200; 
const int window_main_h = 700;
const int window_add_w = 600; 
const int window_add_h = 300;
const int window_change_w = 600; 
const int window_change_h = 300;
const int window_delete_w = 600; 
const int window_delete_h = 300;
const int window_login_w = 600; 
const int window_login_h = 300;

sf::View view_main;
sf::View view_add;
sf::View view_change;
sf::View view_delete;
sf::View view_login;

sf::Vector2f mouse_position;

sf::Cursor cursor_arrow;
sf::Cursor cursor_hand;
sf::Cursor cursor_text;

// --------------- перевод кода города в название --------------- 
struct codetoname {
    string code = "";
    wstring name = L"";
};
vector<codetoname> citynames = {
    {"MIN", L"Минск"},
    {"MOL", L"Молодечно"},
    {"BAR", L"Барановичи"},
    {"SOL", L"Солигорск"},
    {"SVE", L"Светлогорск"},
    {"MOZ", L"Мозырь"},
    {"ZHL", L"Жлобин"},
    {"ZHO", L"Жодино"},
    {"GLU", L"Глубокое"},
    {"SHA", L"Шарковщина"},
    {"BES", L"Бешенковичи"},
    {"SLO", L"Слоним"},
    {"NES", L"Несвиж"},
    {"KLI", L"Кличев"},
    {"DOB", L"Добруш"},
    {"LYA", L"Ляховичи"},
    {"KOP", L"Копыль"},
    {"DOK", L"Докшицы"},
    {"CHA", L"Чашники"},
    {"LYK", L"Лукомль"},
    {"DZE", L"Дзержинск"},
    {"VIT", L"Витебск"},
    {"BRE", L"Брест"},
    {"GOM", L"Гомель"},
    {"GRO", L"Гродно"},
    {"MOG", L"Могилев"},
    {"PIN", L"Пинск"},
    {"KRI", L"Кричев"},
    {"OST", L"Островец"},
	{"LID", L"Лида"},
    {"SLU", L"Слуцк"},
    {"BOB", L"Бобруйск"},
    {"ROG", L"Рогачев"},
    {"LOG", L"Логойск"},
    {"FAN", L"Фаниполь"},
    {"MIO", L"Миоры"},
    {"BRA", L"Браслав"},
    {"POL", L"Полоцк"},
    {"NOV", L"Новополоцк"},
    {"STO", L"Столбцы"},
    {"BEG", L"Бегомль"}
};
vector<codetoname> transportnames = {
    {"a", L"Автобус"},
    {"p", L"Поезд"},
    {"m", L"Маршрутка"}
};

// для преобразования из wstring в int
struct wstringtoint_struct {
    int code = 0;
    wchar_t name = L'0';
};
vector<wstringtoint_struct> wstringtoint = {
    {0, L'0'},
    {1, L'1'},
    {2, L'2'},
    {3, L'3'},
    {4, L'4'},
    {5, L'5'},
    {6, L'6'},
    {7, L'7'},
    {8, L'8'},
    {9, L'9'}
};
struct codetonamechar {
    char code = ' ';
    wstring name = L"";
};
vector<codetonamechar> transportnameschar = {
    {'a', L"Автобус"},
    {'p', L"Поезд"},
    {'m', L"Маршрутка"}
};

// --------------- структура записи и вывода записи --------------- 
struct data_struct {
	int num_line;
    int num_file;
    string cityfirst;
    int dayfirst;
    int monthfirst;
    int daysecond;
    int monthsecond;
    string citysecond;
    int price;
    string transport;
    int number;
};
struct data_wstring_struct {
    wstring num_line;
    wstring cityfirst;
    wstring datefirst;
    wstring datesecond;
    wstring citysecond;
    wstring price;
    wstring transport;
    wstring number;
};

// --------------- структура администратора --------------- 
struct admin {
    wstring login;
    wstring password;
};

// --------------- события мыши и клавиатуры --------------- 
struct textkey {
	bool pressed = false;
	wstring text = L"A";
};
struct numkey {
	bool pressed = false;
	int text = 0;
};
struct events_struct {
	bool R_mouse = false;
	bool L_mouse = false;
	int mouse_scroll = 0;
	bool backspace_pressed = false;
}; events_struct events_mouse;
vector<numkey> events_nums = {
	{false, 0},
	{false, 1},
	{false, 2},
	{false, 3},
	{false, 4},
	{false, 5},
	{false, 6},
	{false, 7},
	{false, 8},
	{false, 9}
};
vector<textkey> events_text = {
	{false, L"A"},
	{false, L"B"},
	{false, L"C"},
	{false, L"D"},
	{false, L"E"},
	{false, L"F"},
	{false, L"G"},
	{false, L"H"},
	{false, L"I"},
	{false, L"J"},
	{false, L"K"},
	{false, L"L"},
	{false, L"M"},
	{false, L"N"},
	{false, L"O"},
	{false, L"P"},
	{false, L"Q"},
	{false, L"R"},
	{false, L"S"},
	{false, L"T"},
	{false, L"U"},
	{false, L"V"},
	{false, L"W"},
	{false, L"X"},
	{false, L"Y"},
	{false, L"Z"}
};

vector<data_struct> data_file;
vector<data_wstring_struct> data_wstring;
vector<wstring> citynames_for_chooseboxes;
vector<wstring> transportnames_for_chooseboxes;
vector<wstring> add_change_citynames_for_chooseboxes;
vector<wstring> add_change_transportnames_for_chooseboxes;

#include "file.h"
#include "data.h"
#include "textbox.h"
#include "rectanglebox.h"
#include "borderbox.h"
#include "imagebox.h"
#include "clickedarea.h"
#include "scrollbar.h"
#include "button.h"
#include "writebox.h"
#include "scrolllist.h"
#include "choosebox.h"
#include "outputbox.h"
#include "status.h"
#include "window_main.h"
#include "window_add.h"
#include "window_change.h"
#include "window_delete.h"
#include "window_login.h"
Window_Main program_main;
Window_Add program_add;
Window_Change program_change;
Window_Delete program_delete;
Window_Login program_login;
Data data;

// чтобы загрузить font
sf::Font TextBox::font;
TextBox::TextBox_font TextBox::textbox_font_initialize;

// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAАА

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE); // чтобы скрыть консоль при запуске
	
	TextBox::font.loadFromFile("materials/fonts/calibri.ttf");

	cursor_arrow.loadFromSystem(sf::Cursor::Arrow);
	cursor_hand.loadFromSystem(sf::Cursor::Hand);
	cursor_text.loadFromSystem(sf::Cursor::Text);

	data.create_it();

	vector<admin> admins = {
		{L"ADMIN", L"1111"},
		{L"ADMIN2", L"2222"},
	};


	program_main.open_it();
	program_main.create_it();

	double timer = 0;   
	double delay = 0.01;
	sf::Clock clock;

	while(program_main.is_open()) {

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		if (timer > delay){
			program_main.run_it();

			// ------ control ---------------------------------------------------------------------------------------------------------

			if(program_main.is_button_exit_clicked()){
				window_main.close();
			}

			// --------------- поиск по параметрам --------------- 

			if(program_main.is_button_find_clicked()) {
				wstring cityfirstwstring = program_main.get_choosebox_cityfirst_wstring();
				wstring citysecondwstring = program_main.get_choosebox_citysecond_wstring();
				wstring transportwstring = program_main.get_choosebox_transporttype_wstring();
				wstring datefirstwstring = program_main.get_writebox_datefirst_wstring();
				wstring datesecondwstring = program_main.get_writebox_datesecond_wstring();
				wstring pricefirstwstring = program_main.get_writebox_pricefirst_wstring();
				wstring pricesecondwstring = program_main.get_writebox_pricesecond_wstring();
				data.find_by_parameters(cityfirstwstring, citysecondwstring, transportwstring, datefirstwstring, datesecondwstring, pricefirstwstring, pricesecondwstring);
				
				program_main.change_output();

				wstring resultswstring = L"Найдено: " + to_wstring(data_wstring.size()) + L" результатов";
				program_main.change_status(resultswstring);
			// 	// cout << "dayfirst: " << data_find_min.dayfirst << " monthfirst: " << data_find_min.monthfirst << " daysecond: " << data_find_min.daysecond << " monthsecond: " << data_find_min.monthsecond << " cityfirst: " << data_find_min.cityfirst << " citysecond: " << data_find_min.citysecond << " transport: " << data_find_min.transport << " min.price: " << data_find_min.price << " max.price: " << data_find_max.price << "\n";
			}
				
			// --------------- сортировать --------------- 

			if(program_main.is_button_sort_clicked()){
				wstring sorttype = program_main.get_choosebox_sorttype_wstring();
				data.sort_it(sorttype);
			
				program_main.change_status(L"Записи отсортированы");
				program_main.change_output();
			}

			// --------------- добавить запись --------------- 

			if(program_main.is_button_add_clicked()){
				program_main.disable_it();

				program_add.open_it();
				program_add.create_it();

				while (program_add.is_open()) {
					float time = clock.getElapsedTime().asSeconds();
					clock.restart();
					timer += time;

					if(timer > delay){
						program_add.run_it();

						// ------ control ---------------------------------------------------------------------------------------------------------

						if(program_add.is_button_clicked()){
							wstring cityfirstwstring = program_add.get_choosebox_cityfirst_wstring();
							wstring datefirstwstring = program_add.get_writebox_datefirst_wstring();
							wstring datesecondwstring = program_add.get_writebox_datesecond_wstring();
							wstring citysecondwstring = program_add.get_choosebox_citysecond_wstring();
							wstring pricewstring = program_add.get_writebox_price_wstring();
							wstring transportwstring = program_add.get_choosebox_transporttype_wstring();
							wstring ticketswstring = program_add.get_writebox_tickets_wstring();
							data.add_it(cityfirstwstring, datefirstwstring, datesecondwstring, citysecondwstring, pricewstring, transportwstring, ticketswstring);
							program_main.change_output();

							window_add.close();
						}

						timer = 0;
					}
				}
				program_main.change_status(L"Запись добавлена");
			}

			// --------------- изменить запись ---------------

			if(program_main.is_button_change_clicked()){
				program_main.disable_it();

				program_change.open_it();
				program_change.create_it();

				while (program_change.is_open()) {
					float time = clock.getElapsedTime().asSeconds();
					clock.restart();
					timer += time;

					if(timer > delay){
						program_change.run_it();

						// ------ control ---------------------------------------------------------------------------------------------------------

						if(program_change.is_button_clicked()){
							wstring numwstring = program_change.get_choosebox_num_wstring();
							wstring cityfirstwstring = program_change.get_choosebox_cityfirst_wstring();
							wstring datefirstwstring = program_change.get_writebox_datefirst_wstring();
							wstring datesecondwstring = program_change.get_writebox_datesecond_wstring();
							wstring citysecondwstring = program_change.get_choosebox_citysecond_wstring();
							wstring pricewstring = program_change.get_writebox_price_wstring();
							wstring transportwstring = program_change.get_choosebox_transporttype_wstring();
							wstring ticketswstring = program_change.get_writebox_tickets_wstring();
							data.change_it(numwstring, cityfirstwstring, datefirstwstring, datesecondwstring, citysecondwstring, pricewstring, transportwstring, ticketswstring);
							program_main.change_output();

							window_change.close();
						}

						timer = 0;
					}
				}
				program_main.change_status(L"Запись изменена");
			} 

			// --------------- удалить запись --------------- 

			if(program_main.is_button_delete_clicked()){
				program_main.disable_it();

				program_delete.open_it();
				program_delete.create_it();

				while (program_delete.is_open()) {
					float time = clock.getElapsedTime().asSeconds();
					clock.restart();
					timer += time;

					if(timer > delay){
						program_delete.run_it();

						// ------ control ---------------------------------------------------------------------------------------------------------

						if(program_delete.is_button_clicked()){
							wstring numwstring = program_delete.get_choosebox_num_wstring();

							data.delete_it(numwstring);
							program_main.change_output();

							window_delete.close();
						}

						timer = 0;
					}
				}
				program_main.change_status(L"Запись удалена");
			}

			// --------------- войти в аккаунт --------------- 

			if(program_main.is_button_login_clicked()){
				program_main.disable_it();

				program_login.open_it();
				program_login.create_it();

				while (program_login.is_open()) {
					float time = clock.getElapsedTime().asSeconds();
					clock.restart();
					timer += time;

					if(timer > delay){
						program_login.run_it();

						// ------ control ---------------------------------------------------------------------------------------------------------
						if(admin_or_user) {
							if(program_login.is_button_yes_clicked()){
								admin_or_user = false;
								program_main.change_status(L"Вы вышли из аккаунта");
								window_login.close();
							}
							if(program_login.is_button_no_clicked()){
								window_login.close();
							}
						} else {
							if(program_login.is_button_clicked()){

								bool is = false;
								for(int i = 0; i < admins.size(); i++){
									if(admins[i].login == program_login.get_writebox_login_wstring() && admins[i].password == program_login.get_writebox_password_wstring()){
										is = true;
									}
								}

								if(is){
									admin_or_user = true;
									program_main.change_status(L"Вы вошли в аккаунт");
									window_login.close();
								}

							}
						}

						timer = 0;
					}
				}
			}

			timer = 0;
		}
	}
}