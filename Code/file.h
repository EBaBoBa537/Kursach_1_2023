#ifndef FILE_H
#define FILE_H

class File{
private:
    std::string filename = "materials\\travel.txt";
    std::fstream file;
    int filelength = 0;

public:
    
    

    // ------ считает длину файла ----------------------------------------------------------------------------------------------------

    int length_it() {
        file.open(filename);
        filelength = -1;
        
        file.seekg(0, std::ios::end);
        if (file.tellg() == 0) {
            filelength = 0;
            return 0;
        } else {
            file.seekg(0, std::ios::beg);
        }

        while (file) {
            filelength++;
            std::string a;
            std::getline(file, a);
        }
        file.close();
        return filelength;
    }

    // ------ считывает данные из файла в вектор -------------------------------------------------------------------------------------

    std::vector<data_struct> read_it(){
        std::vector<data_struct> vector;
        vector.resize(filelength);
        file.open(filename);
        int num_lines = 1;
        for (unsigned int i = 0; i < vector.size(); i++) {
            file >> vector[i].cityfirst;
            file >> vector[i].dayfirst;
            file >> vector[i].monthfirst;
            file >> vector[i].daysecond;
            file >> vector[i].monthsecond;
            file >> vector[i].citysecond;
            file >> vector[i].price;
            file >> vector[i].transport;
            file >> vector[i].number;
            vector[i].num_file = i;
            if (vector[i].cityfirst == "#") {
                vector[i].num_line = -1;
            } else {
                vector[i].num_line = num_lines;
                num_lines++;
            }
        }
        file.close();
        return vector;
    }

    // ------ добавляет строчку с данными в файл -------------------------------------------------------------------------------------

    void add_it(std::string cityfirst, int dayfirst, int monthfirst, int daysecond, int monthsecond, std::string citysecond, int price, char transport, int number) {
        file.open(filename);
        file.seekp(0, std::ios::end);
        if (filelength > 0) {
            file << "\n";
        }
        file << cityfirst;
        for (int i = cityfirst.length(); i < 4; i++) { file << " "; }
        file << dayfirst;
        for (int i = std::to_string(dayfirst).length(); i < 3; i++) { file << " "; }
        file << monthfirst;
        for (int i = std::to_string(monthfirst).length(); i < 3; i++) { file << " "; }
        file << daysecond;
        for (int i = std::to_string(daysecond).length(); i < 3; i++) { file << " "; }
        file << monthsecond;
        for (int i = std::to_string(monthsecond).length(); i < 3; i++) { file << " "; }
        file << citysecond;
        for (int i = citysecond.length(); i < 4; i++) { file << " "; }
        file << price;
        for (int i = std::to_string(price).length(); i < 5; i++) { file << " "; }
        file << transport << " ";
        file << number;
        for (int i = std::to_string(number).length(); i < 8; i++) { file << " "; }
        file.close();
    }

    // ------ перезаписывает строчку с данными в файл --------------------------------------------------------------------------------

    void change_it(int num_file, std::string cityfirst, int dayfirst, int monthfirst, int daysecond, int monthsecond, std::string citysecond, int price, char transport, int number) {
        file.open(filename);
        file.seekp((num_file)*37, std::ios::beg);
        file << cityfirst;
        for (int i = cityfirst.length(); i < 4; i++) { file << " "; }
        file << dayfirst;
        for (int i = std::to_string(dayfirst).length(); i < 3; i++) { file << " "; }
        file << monthfirst;
        for (int i = std::to_string(monthfirst).length(); i < 3; i++) { file << " "; }
        file << daysecond;
        for (int i = std::to_string(daysecond).length(); i < 3; i++) { file << " "; }
        file << monthsecond;
        for (int i = std::to_string(monthsecond).length(); i < 3; i++) { file << " "; }
        file << citysecond;
        for (int i = citysecond.length(); i < 4; i++) { file << " "; }
        file << price;
        for (int i = std::to_string(price).length(); i < 5; i++) { file << " "; }
        file << transport << " ";
        file << number;
        for (int i = std::to_string(number).length(); i < 8; i++) { file << " "; }
        file.close();
    }

    // ------ удалить строчку  ------------------------------------------------------------------------------------------------------

    void delete_it(int num_file) {
        file.open(filename);
        file.seekp((num_file)*37, std::ios::beg);
        file << "#   0  0  0  0  #   0    # 0       ";
        file.close();
    }

    // ------ изменить размер data_wstring ------------------------------------------------------------------------------------------

    int resize_wstring_data(vector<data_struct> data){
		int howmany = 0;
		for(unsigned int i = 0; i < data.size(); i++){
			if(data[i].num_line != -1){
				howmany++;
			}
		}
        return howmany;
    }

    // ------ перезаписать data_wstring ---------------------------------------------------------------------------------------------

    vector<data_wstring_struct> read_wstring_data(vector<data_struct> data){
        vector<data_wstring_struct> data_wstring;
		int howmany = resize_wstring_data(data);
		data_wstring.resize(howmany);
		int k = 0;
		for(unsigned int i = 0; i < data.size(); i++){
			if(data[i].num_line != -1){
				data_wstring[k].num_line = to_wstring(data[i].num_line);
				for(int j = 0; j < citynames.size(); j++){
					if (data[i].cityfirst == citynames[j].code) {
						data_wstring[k].cityfirst = citynames[j].name;
					}
				}
				for(int j = 0; j < citynames.size(); j++){
					if (data[i].citysecond == citynames[j].code) {
						data_wstring[k].citysecond = citynames[j].name;
					}
				}
				data_wstring[k].datefirst = to_wstring(data[i].dayfirst) + L"." + to_wstring(data[i].monthfirst) + L".2023";
				data_wstring[k].datesecond = to_wstring(data[i].daysecond) + L"." + to_wstring(data[i].monthsecond) + L".2023";
				data_wstring[k].number = to_wstring(data[i].number);
				data_wstring[k].price = to_wstring(data[i].price);
				for(int j = 0; j < transportnames.size(); j++){
					if (data[i].transport == transportnames[j].code) {
						data_wstring[k].transport = transportnames[j].name;
					}
				}
				k++;
			}
		}

        return data_wstring;
    }

    // ------ изменить размер data_wstring (поиск) -----------------------------------------------------------------------------------

    int resize_wstring_data_find(vector<data_struct> data, data_struct data_find_min, data_struct data_find_max){
		int howmany = 0;
		for(unsigned int i = 0; i < data.size(); i++){
			if(data[i].num_line != -1){
                if(
                    (data_find_min.cityfirst == "-----" || data[i].cityfirst == data_find_min.cityfirst) &&
                    (data_find_min.citysecond == "-----" || data[i].citysecond == data_find_min.citysecond) && 
                    (data_find_min.dayfirst == -1 || data[i].dayfirst >= data_find_min.dayfirst) &&
                    (data_find_max.dayfirst == -1 || data[i].dayfirst <= data_find_max.dayfirst) &&
                    (data_find_min.monthfirst == -1 || data[i].monthfirst >= data_find_min.monthfirst) &&
                    (data_find_max.monthfirst == -1 || data[i].monthfirst <= data_find_max.monthfirst) &&
                    (data_find_min.daysecond == -1 || data[i].daysecond >= data_find_min.daysecond) &&
                    (data_find_max.daysecond == -1 || data[i].daysecond <= data_find_max.daysecond) &&
                    (data_find_min.monthsecond == -1 || data[i].monthsecond >= data_find_min.monthsecond) &&
                    (data_find_max.monthsecond == -1 || data[i].monthsecond <= data_find_max.monthsecond) &&
                    (data_find_min.transport == "-----" || data[i].transport == data_find_min.transport) && 
                    (data_find_min.price == -1 || data[i].price >= data_find_min.price) &&
                    (data_find_max.price == -1 || data[i].price <= data_find_max.price) &&
                    (data_find_min.number == -1 || data[i].number >= data_find_min.number) &&
                    (data_find_max.number == -1 || data[i].number <= data_find_max.number)
                ){
                    howmany++;
                }
			}
		}
        return howmany;
    }

    // ------ перезаписать data_wstring (поиск) -------------------------------------------------------------------------------------

    vector<data_wstring_struct> read_wstring_data_find(vector<data_struct> data, data_struct data_find_min, data_struct data_find_max){
        vector<data_wstring_struct> data_wstring;
		int howmany = resize_wstring_data_find(data, data_find_min, data_find_max);
		data_wstring.resize(howmany);
		int k = 0;
		for(unsigned int i = 0; i < data.size(); i++){
			if(data[i].num_line != -1){
                if(
                    (data_find_min.cityfirst == "-----" || data[i].cityfirst == data_find_min.cityfirst) &&
                    (data_find_min.citysecond == "-----" || data[i].citysecond == data_find_min.citysecond) && 
                    (data_find_min.dayfirst == -1 || data[i].dayfirst >= data_find_min.dayfirst) &&
                    (data_find_max.dayfirst == -1 || data[i].dayfirst <= data_find_max.dayfirst) &&
                    (data_find_min.monthfirst == -1 || data[i].monthfirst >= data_find_min.monthfirst) &&
                    (data_find_max.monthfirst == -1 || data[i].monthfirst <= data_find_max.monthfirst) &&
                    (data_find_min.daysecond == -1 || data[i].daysecond >= data_find_min.daysecond) &&
                    (data_find_max.daysecond == -1 || data[i].daysecond <= data_find_max.daysecond) &&
                    (data_find_min.monthsecond == -1 || data[i].monthsecond >= data_find_min.monthsecond) &&
                    (data_find_max.monthsecond == -1 || data[i].monthsecond <= data_find_max.monthsecond) &&
                    (data_find_min.transport == "-----" || data[i].transport == data_find_min.transport) && 
                    (data_find_min.price == -1 || data[i].price >= data_find_min.price) &&
                    (data_find_max.price == -1 || data[i].price <= data_find_max.price) &&
                    (data_find_min.number == -1 || data[i].number >= data_find_min.number) &&
                    (data_find_max.number == -1 || data[i].number <= data_find_max.number)
                ){
                    data_wstring[k].num_line = to_wstring(data[i].num_line);
                    for(int j = 0; j < citynames.size(); j++){
                        if (data[i].cityfirst == citynames[j].code) {
                            data_wstring[k].cityfirst = citynames[j].name;
                        }
                    }
                    for(int j = 0; j < citynames.size(); j++){
                        if (data[i].citysecond == citynames[j].code) {
                            data_wstring[k].citysecond = citynames[j].name;
                        }
                    }
                    data_wstring[k].datefirst = to_wstring(data[i].dayfirst) + L"." + to_wstring(data[i].monthfirst) + L".2023";
                    data_wstring[k].datesecond = to_wstring(data[i].daysecond) + L"." + to_wstring(data[i].monthsecond) + L".2023";
                    data_wstring[k].number = to_wstring(data[i].number);
                    data_wstring[k].price = to_wstring(data[i].price);
                    for(int j = 0; j < transportnames.size(); j++){
                        if (data[i].transport == transportnames[j].code) {
                            data_wstring[k].transport = transportnames[j].name;
                        }
                    }
                    k++;
                }
			}
		}

        return data_wstring;
    }

    // ------ сортировать по цене ---------------------------------------------------------------------------------------------------

    vector<data_wstring_struct> sort_by_price(vector<data_wstring_struct> DATA_WSTRING){
        vector<data_wstring_struct> data_wstring = DATA_WSTRING;

        data_wstring_struct a; 
        for (int i = 0; i < data_wstring.size() - 1; i++) {
            for (int j = 0; j < data_wstring.size() - i - 1; j++) {
                if (data_wstring[j].price > data_wstring[j + 1].price) {
                    a = data_wstring[j];
                    data_wstring[j] = data_wstring[j + 1];
                    data_wstring[j + 1] = a;
                }
            }
        }

        return data_wstring;
    }

    // ------ сортировать по алфавиту ---------------------------------------------------------------------------------------------------

    vector<data_wstring_struct> sort_by_alphabet_1(vector<data_wstring_struct> DATA_WSTRING){
        vector<data_wstring_struct> data_wstring = DATA_WSTRING;

        data_wstring_struct a; 
        for (int i = 0; i < data_wstring.size() - 1; i++) {
            for (int j = 0; j < data_wstring.size() - i - 1; j++) {
                if (data_wstring[j].cityfirst > data_wstring[j + 1].cityfirst) {
                    a = data_wstring[j];
                    data_wstring[j] = data_wstring[j + 1];
                    data_wstring[j + 1] = a;
                }
            }
        }

        return data_wstring;
    }

    vector<data_wstring_struct> sort_by_alphabet_2(vector<data_wstring_struct> DATA_WSTRING){
        vector<data_wstring_struct> data_wstring = DATA_WSTRING;

        data_wstring_struct a; 
        for (int i = 0; i < data_wstring.size() - 1; i++) {
            for (int j = 0; j < data_wstring.size() - i - 1; j++) {
                if (data_wstring[j].citysecond > data_wstring[j + 1].citysecond) {
                    a = data_wstring[j];
                    data_wstring[j] = data_wstring[j + 1];
                    data_wstring[j + 1] = a;
                }
            }
        }

        return data_wstring;
    }

     vector<data_wstring_struct> sort_by_alphabet_3(vector<data_wstring_struct> DATA_WSTRING){
        vector<data_wstring_struct> data_wstring = DATA_WSTRING;

        data_wstring_struct a; 
        for (int i = 0; i < data_wstring.size() - 1; i++) {
            for (int j = 0; j < data_wstring.size() - i - 1; j++) {
                if (data_wstring[j].transport > data_wstring[j + 1].transport) {
                    a = data_wstring[j];
                    data_wstring[j] = data_wstring[j + 1];
                    data_wstring[j + 1] = a;
                }
            }
        }

        return data_wstring;
    }

    // ------ сортировать по количеству билетов ---------------------------------------------------------------------------------------

    vector<data_wstring_struct> sort_by_tickets(vector<data_wstring_struct> DATA_WSTRING){
        vector<data_wstring_struct> data_wstring = DATA_WSTRING;

        data_wstring_struct a; 
        for (int i = 0; i < data_wstring.size() - 1; i++) {
            for (int j = 0; j < data_wstring.size() - i - 1; j++) {
                if (data_wstring[j].number > data_wstring[j + 1].number) {
                    a = data_wstring[j];
                    data_wstring[j] = data_wstring[j + 1];
                    data_wstring[j + 1] = a;
                }
            }
        }

        return data_wstring;
    }

    // ------ сортировать по датам отправления и прибытия ----------------------------------------------------------------------------

    vector<data_wstring_struct> sort_by_date_1(vector<data_wstring_struct> DATA_WSTRING){
        vector<data_wstring_struct> data_wstring = DATA_WSTRING;

        data_wstring_struct a; 
        for (int i = 0; i < data_wstring.size() - 1; i++) {
            for (int j = 0; j < data_wstring.size() - i - 1; j++) {
                if (data_wstring[j].datefirst > data_wstring[j + 1].datefirst) {
                    a = data_wstring[j];
                    data_wstring[j] = data_wstring[j + 1];
                    data_wstring[j + 1] = a;
                }
            }
        }

        return data_wstring;
    }

    vector<data_wstring_struct> sort_by_date_2(vector<data_wstring_struct> DATA_WSTRING){
        vector<data_wstring_struct> data_wstring = DATA_WSTRING;

        data_wstring_struct a; 
        for (int i = 0; i < data_wstring.size() - 1; i++) {
            for (int j = 0; j < data_wstring.size() - i - 1; j++) {
                if (data_wstring[j].datesecond > data_wstring[j + 1].datesecond) {
                    a = data_wstring[j];
                    data_wstring[j] = data_wstring[j + 1];
                    data_wstring[j + 1] = a;
                }
            }
        }

        return data_wstring;
    }

    void create_it(std::string FILENAME){
        filename = FILENAME;
    }

    File(std::string FILENAME){
        filename = FILENAME;
    }
    File(){}
	~File(){}	
};

#endif