#ifndef DATA_H
#define DATA_H

class Data{
public:
    File file;   

    void read_file(){
        data_file.resize(file.length_it());
        data_file = file.read_it();
        data_wstring.resize(file.resize_wstring_data(data_file));
        data_wstring = file.read_wstring_data(data_file);
    }

    void find_by_parameters(wstring cityfirstwstring, wstring citysecondwstring, wstring transportwstring, wstring datefirstwstring, wstring datesecondwstring, wstring pricefirstwstring, wstring pricesecondwstring){
        data_struct data_find_min = {-1, -1, " ", 0, 0, 0, 0, " ", 0, " ", 0};
		data_struct data_find_max = {-1, -1, " ", 0, 0, 0, 0, " ", 0, " ", 0};

		if(cityfirstwstring == L"-----") { 
			data_find_min.cityfirst = "-----";
			data_find_max.cityfirst = "-----";
		} else {
			for (int i = 0; i < citynames.size(); i++){
				if(cityfirstwstring == citynames[i].name){
					data_find_min.cityfirst = citynames[i].code;
					data_find_max.cityfirst = citynames[i].code;
				}
			}
		}
			
		if(citysecondwstring == L"-----") { 
			data_find_min.citysecond = "-----";
			data_find_max.citysecond = "-----";
		} else {
			for (int i = 0; i < citynames.size(); i++){
				if(citysecondwstring == citynames[i].name){
					data_find_min.citysecond = citynames[i].code;
					data_find_max.citysecond = citynames[i].code;
				}
			}
		}
				
		if(transportwstring == L"-----") { 
			data_find_min.transport = "-----";
			data_find_max.transport = "-----";
		} else {
			for (int i = 0; i < transportnames.size(); i++){
				if(transportwstring == transportnames[i].name){
					data_find_min.transport = transportnames[i].code;
					data_find_max.transport = transportnames[i].code;
				}
			}
		}
				
		if(datefirstwstring == L"") { 
			data_find_min.dayfirst = -1;
			data_find_max.dayfirst = -1;
			data_find_min.monthfirst = -1;
			data_find_max.monthfirst = -1;
		} else {
			for(int i = 0; i < wstringtoint.size(); i++){
				if(datefirstwstring[0] == wstringtoint[i].name){
					data_find_min.dayfirst += 10*wstringtoint[i].code;
					data_find_max.dayfirst += 10*wstringtoint[i].code;
				}
				if(datefirstwstring[1] == wstringtoint[i].name){
					data_find_min.dayfirst += wstringtoint[i].code;
					data_find_max.dayfirst += wstringtoint[i].code;
				}
				if(datefirstwstring[3] == wstringtoint[i].name){
					data_find_min.monthfirst += 10*wstringtoint[i].code;
					data_find_max.monthfirst += 10*wstringtoint[i].code;
				}
				if(datefirstwstring[4] == wstringtoint[i].name){
					data_find_min.monthfirst += wstringtoint[i].code;
					data_find_max.monthfirst += wstringtoint[i].code;
				}
			}
		}
			
		if(datesecondwstring == L"") { 
			data_find_min.daysecond = -1;
			data_find_max.daysecond = -1;
			data_find_min.monthsecond = -1;
			data_find_max.monthsecond = -1;
		} else {
			for(int i = 0; i < wstringtoint.size(); i++){
				if(datesecondwstring[0] == wstringtoint[i].name){
					data_find_min.daysecond += 10*wstringtoint[i].code;
					data_find_max.daysecond += 10*wstringtoint[i].code;
				}
				if(datesecondwstring[1] == wstringtoint[i].name){
					data_find_min.daysecond += wstringtoint[i].code;
					data_find_max.daysecond += wstringtoint[i].code;
				}
				if(datesecondwstring[3] == wstringtoint[i].name){
					data_find_min.monthsecond += 10*wstringtoint[i].code;
					data_find_max.monthsecond += 10*wstringtoint[i].code;
				}
				if(datesecondwstring[4] == wstringtoint[i].name){
					data_find_min.monthsecond += wstringtoint[i].code;
					data_find_max.monthsecond += wstringtoint[i].code;
				}
			}
		}
					
		if(pricefirstwstring == L"") { 
			data_find_min.price = -1;
		} else {
			if(pricefirstwstring.size() == 1){
				for(int i = 0; i < wstringtoint.size(); i++){
					if(pricefirstwstring[0] == wstringtoint[i].name){
						data_find_min.price += wstringtoint[i].code;
					}
				}
			}
			if(pricefirstwstring.size() == 2){
				for(int i = 0; i < wstringtoint.size(); i++){
					if(pricefirstwstring[0] == wstringtoint[i].name){
						data_find_min.price += 10*wstringtoint[i].code;
					}
					if(pricefirstwstring[1] == wstringtoint[i].name){
						data_find_min.price += wstringtoint[i].code;
					}
				}
			}
			if(pricefirstwstring.size() == 3){
				for(int i = 0; i < wstringtoint.size(); i++){
					if(pricefirstwstring[0] == wstringtoint[i].name){
						data_find_min.price += 100*wstringtoint[i].code;
					}
					if(pricefirstwstring[1] == wstringtoint[i].name){
						data_find_min.price += 10*wstringtoint[i].code;
					}
					if(pricefirstwstring[2] == wstringtoint[i].name){
						data_find_min.price += wstringtoint[i].code;
					}
				}
			}
		}
					
		if(pricesecondwstring == L"") { 
			data_find_max.price = -1;
		} else {
			if(pricesecondwstring.size() == 1){
				for(int i = 0; i < wstringtoint.size(); i++){
					if(pricesecondwstring[0] == wstringtoint[i].name){
						data_find_max.price += wstringtoint[i].code;
					}
				}
			}
			if(pricesecondwstring.size() == 2){
				for(int i = 0; i < wstringtoint.size(); i++){
					if(pricesecondwstring[0] == wstringtoint[i].name){
						data_find_max.price += 10*wstringtoint[i].code;
					}
					if(pricesecondwstring[1] == wstringtoint[i].name){
						data_find_max.price += wstringtoint[i].code;
					}
				}
			}
			if(pricesecondwstring.size() == 3){
				for(int i = 0; i < wstringtoint.size(); i++){
					if(pricesecondwstring[0] == wstringtoint[i].name){
						data_find_max.price += 100*wstringtoint[i].code;
					}
					if(pricesecondwstring[1] == wstringtoint[i].name){
						data_find_max.price += 10*wstringtoint[i].code;
					}
					if(pricesecondwstring[2] == wstringtoint[i].name){
						data_find_max.price += wstringtoint[i].code;
					}
				}
			}
		}
			
		data_find_min.number = -1;
		data_find_max.number = -1;

		data_wstring.resize(file.resize_wstring_data_find(data_file, data_find_min, data_find_max));
		data_wstring = file.read_wstring_data_find(data_file, data_find_min, data_find_max);
    }

    void sort_it(wstring sorttype){
        if(sorttype == L"По умолчанию"){
		    data_file.resize(file.length_it());
			data_file = file.read_it();
			data_wstring.resize(file.resize_wstring_data(data_file));
			data_wstring = file.read_wstring_data(data_file);
		}
		if(sorttype == L"По цене"){
			data_wstring = file.sort_by_price(data_wstring);
		}
		if(sorttype == L"По алфавиту (город 1)"){
			data_wstring = file.sort_by_alphabet_1(data_wstring);
		}
		if(sorttype == L"По алфавиту (город 2)"){
			data_wstring = file.sort_by_alphabet_2(data_wstring);
		}
		if(sorttype == L"По алфавиту (вид транспорта)"){
			data_wstring = file.sort_by_alphabet_3(data_wstring);
		}
		if(sorttype == L"По количеству билетов"){
			data_wstring = file.sort_by_tickets (data_wstring);
		}
		if(sorttype == L"По дате отправления"){
			data_wstring = file.sort_by_date_1 (data_wstring);
		}
		if(sorttype == L"По дате прибытия"){
			data_wstring = file.sort_by_date_2 (data_wstring);
		}
    }

    void add_it(wstring cityfirstwstring, wstring datefirstwstring, wstring datesecondwstring, wstring citysecondwstring, wstring pricewstring, wstring transportwstring, wstring ticketswstring){
		string cityfirst;
		for (int i = 0; i < citynames.size(); i++){
			if(cityfirstwstring == citynames[i].name){
				cityfirst = citynames[i].code;
			}
		}

		
		int dayfirst = 0;
		int monthfirst = 0;
		for(int i = 0; i < wstringtoint.size(); i++){
            if(datefirstwstring[0] == wstringtoint[i].name){
                dayfirst += 10*wstringtoint[i].code;
            }
            if(datefirstwstring[1] == wstringtoint[i].name){
                dayfirst += wstringtoint[i].code;
            }
            if(datefirstwstring[3] == wstringtoint[i].name){
                monthfirst += 10*wstringtoint[i].code;
            }
            if(datefirstwstring[4] == wstringtoint[i].name){
                monthfirst += wstringtoint[i].code;
            }
        }

        
        int daysecond = 0;
        int monthsecond = 0;
        for(int i = 0; i < wstringtoint.size(); i++){
            if(datesecondwstring[0] == wstringtoint[i].name){
                daysecond += 10*wstringtoint[i].code;
            }
            if(datesecondwstring[1] == wstringtoint[i].name){
                daysecond += wstringtoint[i].code;
            }
            if(datesecondwstring[3] == wstringtoint[i].name){
                monthsecond += 10*wstringtoint[i].code;
            }
            if(datesecondwstring[4] == wstringtoint[i].name){
                monthsecond += wstringtoint[i].code;
            }
        }

        
        string citysecond;
        for (int i = 0; i < citynames.size(); i++){
            if(citysecondwstring == citynames[i].name){
                citysecond = citynames[i].code;
            }
        }
                                
        
		int price;
		if(pricewstring.size() == 1){
			for(int i = 0; i < wstringtoint.size(); i++){
			    if(pricewstring[0] == wstringtoint[i].name){
				    price += wstringtoint[i].code;
				}
			}
		}
		if(pricewstring.size() == 2){
			for(int i = 0; i < wstringtoint.size(); i++){
			    if(pricewstring[0] == wstringtoint[i].name){
					price += 10*wstringtoint[i].code;
				}
                if(pricewstring[1] == wstringtoint[i].name){
                    price += wstringtoint[i].code;
                }
			}
		}
		if(pricewstring.size() == 3){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(pricewstring[0] == wstringtoint[i].name){
					price += 100*wstringtoint[i].code;
				}
				if(pricewstring[1] == wstringtoint[i].name){
					price += 10*wstringtoint[i].code;
				}
				if(pricewstring[2] == wstringtoint[i].name){
					price += wstringtoint[i].code;
				}
			}
		}

		
		char transport;
		for (int i = 0; i < transportnameschar.size(); i++){
			if(transportwstring == transportnameschar[i].name){
				transport = transportnameschar[i].code;
				transport = transportnameschar[i].code;
			}
		}

		
		int tickets;
		if(ticketswstring.size() == 1){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(ticketswstring[0] == wstringtoint[i].name){
					tickets += wstringtoint[i].code;
				}
			}
		}
		if(ticketswstring.size() == 2){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(ticketswstring[0] == wstringtoint[i].name){
					tickets += 10*wstringtoint[i].code;
				}
				if(ticketswstring[1] == wstringtoint[i].name){
					tickets += wstringtoint[i].code;
				}
			}
		}
		if(ticketswstring.size() == 3){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(ticketswstring[0] == wstringtoint[i].name){
					tickets += 100*wstringtoint[i].code;
				}
				if(ticketswstring[1] == wstringtoint[i].name){
					tickets += 10*wstringtoint[i].code;
				}
				if(ticketswstring[2] == wstringtoint[i].name){
					tickets += wstringtoint[i].code;
				}
			}
		}
		file.add_it(cityfirst, dayfirst, monthfirst, daysecond, monthsecond, citysecond, price, transport, tickets);
		read_file();
    }

	void change_it(wstring numwstring, wstring cityfirstwstring, wstring datefirstwstring, wstring datesecondwstring, wstring citysecondwstring, wstring pricewstring, wstring transportwstring, wstring ticketswstring){
		
		int line_num = 0;
		if(numwstring.size() == 1){
			for(int i = 0; i < wstringtoint.size(); i++){
			    if(numwstring[0] == wstringtoint[i].name){
				    line_num += wstringtoint[i].code;
				}
			}
		}
		if(numwstring.size() == 2){
			for(int i = 0; i < wstringtoint.size(); i++){
			    if(numwstring[0] == wstringtoint[i].name){
					line_num += 10*wstringtoint[i].code;
				}
                if(numwstring[1] == wstringtoint[i].name){
                    line_num += wstringtoint[i].code;
                }
			}
		}
		if(numwstring.size() == 3){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(numwstring[0] == wstringtoint[i].name){
					line_num += 100*wstringtoint[i].code;
				}
				if(numwstring[1] == wstringtoint[i].name){
					line_num += 10*wstringtoint[i].code;
				}
				if(numwstring[2] == wstringtoint[i].name){
					line_num += wstringtoint[i].code;
				}
			}
		}
		
		int file_num = 0;
        for (int i = 0; i < data_file.size(); i++) {
            if (data_file[i].num_line == line_num) {
                file_num = data_file[i].num_file;
            }
        }
		
		
		string cityfirst;
		for (int i = 0; i < citynames.size(); i++){
			if(cityfirstwstring == citynames[i].name){
				cityfirst = citynames[i].code;
			}
		}

		
		int dayfirst = 0;
		int monthfirst = 0;
		for(int i = 0; i < wstringtoint.size(); i++){
            if(datefirstwstring[0] == wstringtoint[i].name){
                dayfirst += 10*wstringtoint[i].code;
            }
            if(datefirstwstring[1] == wstringtoint[i].name){
                dayfirst += wstringtoint[i].code;
            }
            if(datefirstwstring[3] == wstringtoint[i].name){
                monthfirst += 10*wstringtoint[i].code;
            }
            if(datefirstwstring[4] == wstringtoint[i].name){
                monthfirst += wstringtoint[i].code;
            }
        }

        
        int daysecond = 0;
        int monthsecond = 0;
        for(int i = 0; i < wstringtoint.size(); i++){
            if(datesecondwstring[0] == wstringtoint[i].name){
                daysecond += 10*wstringtoint[i].code;
            }
            if(datesecondwstring[1] == wstringtoint[i].name){
                daysecond += wstringtoint[i].code;
            }
            if(datesecondwstring[3] == wstringtoint[i].name){
                monthsecond += 10*wstringtoint[i].code;
            }
            if(datesecondwstring[4] == wstringtoint[i].name){
                monthsecond += wstringtoint[i].code;
            }
        }

        
        string citysecond;
        for (int i = 0; i < citynames.size(); i++){
            if(citysecondwstring == citynames[i].name){
                citysecond = citynames[i].code;
            }
        }
                                
        
		int price;
		if(pricewstring.size() == 1){
			for(int i = 0; i < wstringtoint.size(); i++){
			    if(pricewstring[0] == wstringtoint[i].name){
				    price += wstringtoint[i].code;
				}
			}
		}
		if(pricewstring.size() == 2){
			for(int i = 0; i < wstringtoint.size(); i++){
			    if(pricewstring[0] == wstringtoint[i].name){
					price += 10*wstringtoint[i].code;
				}
                if(pricewstring[1] == wstringtoint[i].name){
                    price += wstringtoint[i].code;
                }
			}
		}
		if(pricewstring.size() == 3){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(pricewstring[0] == wstringtoint[i].name){
					price += 100*wstringtoint[i].code;
				}
				if(pricewstring[1] == wstringtoint[i].name){
					price += 10*wstringtoint[i].code;
				}
				if(pricewstring[2] == wstringtoint[i].name){
					price += wstringtoint[i].code;
				}
			}
		}

		
		char transport;
		for (int i = 0; i < transportnameschar.size(); i++){
			if(transportwstring == transportnameschar[i].name){
				transport = transportnameschar[i].code;
				transport = transportnameschar[i].code;
			}
		}

		
		int tickets;
		if(ticketswstring.size() == 1){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(ticketswstring[0] == wstringtoint[i].name){
					tickets += wstringtoint[i].code;
				}
			}
		}
		if(ticketswstring.size() == 2){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(ticketswstring[0] == wstringtoint[i].name){
					tickets += 10*wstringtoint[i].code;
				}
				if(ticketswstring[1] == wstringtoint[i].name){
					tickets += wstringtoint[i].code;
				}
			}
		}
		if(ticketswstring.size() == 3){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(ticketswstring[0] == wstringtoint[i].name){
					tickets += 100*wstringtoint[i].code;
				}
				if(ticketswstring[1] == wstringtoint[i].name){
					tickets += 10*wstringtoint[i].code;
				}
				if(ticketswstring[2] == wstringtoint[i].name){
					tickets += wstringtoint[i].code;
				}
			}
		}
		
		file.change_it(file_num, cityfirst, dayfirst, monthfirst, daysecond, monthsecond, citysecond, price, transport, tickets);
		read_file();
	}

	void delete_it(wstring numwstring){
		int line_num = 0;
		if(numwstring.size() == 1){
			for(int i = 0; i < wstringtoint.size(); i++){
			    if(numwstring[0] == wstringtoint[i].name){
				    line_num += wstringtoint[i].code;
				}
			}
		}
		if(numwstring.size() == 2){
			for(int i = 0; i < wstringtoint.size(); i++){
			    if(numwstring[0] == wstringtoint[i].name){
					line_num += 10*wstringtoint[i].code;
				}
                if(numwstring[1] == wstringtoint[i].name){
                    line_num += wstringtoint[i].code;
                }
			}
		}
		if(numwstring.size() == 3){
			for(int i = 0; i < wstringtoint.size(); i++){
				if(numwstring[0] == wstringtoint[i].name){
					line_num += 100*wstringtoint[i].code;
				}
				if(numwstring[1] == wstringtoint[i].name){
					line_num += 10*wstringtoint[i].code;
				}
				if(numwstring[2] == wstringtoint[i].name){
					line_num += wstringtoint[i].code;
				}
			}
		}
		
		int file_num = 0;
        for (int i = 0; i < data_file.size(); i++) {
            if (data_file[i].num_line == line_num) {
                file_num = data_file[i].num_file;
            }
        }

		file.delete_it(file_num);
		read_file();
	}

    void create_it(){
        data_file.resize(file.length_it());
        data_file = file.read_it();
        data_wstring.resize(file.resize_wstring_data(data_file));
        data_wstring = file.read_wstring_data(data_file);

        citynames_for_chooseboxes.resize(citynames.size()+1);
        citynames_for_chooseboxes[0] = L"-----";
        for(int i = 1; i < citynames_for_chooseboxes.size(); i++){
            citynames_for_chooseboxes[i] = citynames[i-1].name;
        }
        transportnames_for_chooseboxes.resize(transportnames.size()+1);
        transportnames_for_chooseboxes[0] = L"-----";
        for(int i = 1; i < transportnames_for_chooseboxes.size(); i++){
            transportnames_for_chooseboxes[i] = transportnames[i-1].name;
        }

        add_change_citynames_for_chooseboxes.resize(citynames.size());
        for(int i = 0; i < add_change_citynames_for_chooseboxes.size(); i++){
            add_change_citynames_for_chooseboxes[i] = citynames[i].name;
        }
        add_change_transportnames_for_chooseboxes.resize(transportnames.size());
        for(int i = 0; i < add_change_transportnames_for_chooseboxes.size(); i++){
            add_change_transportnames_for_chooseboxes[i] = transportnames[i].name;
        }
	}

    Data(){
        file.create_it("materials/travel.txt");
    }
    ~Data(){}
};

#endif