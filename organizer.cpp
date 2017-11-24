/*
 * organizer.cpp
 * 
 * Copyright 2017 Lucas <lucas@linux-n51u>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include "organizer.h"


Organizer::Organizer() 
{
	
}

void Organizer::printText(std::string text){


	std::cout<<std::string(text)<<std::endl;
}

void Organizer::make_ready(){
	Item wasmachen(question, action, std::string("Was möchtest du machen?"));

	Item wielange(question, action, std::string("Wie lange?"));

	Item wohin(question, action, std::string("Wohin?"));

	Item wann(question, action, std::string("Wann?"));

	Item mitwem(question, action, std::string("Mit wem?"));
	Item wie(question, action, std::string("Wie?"));
	
	Item start=Item(action,nothing, std::string("Start"));
	
	printText(std::string("Was möchtest du machen?"));
	items.push_back(start);
	items.push_back(wasmachen);
	items.push_back(wielange);
	items.push_back(wohin);
	items.push_back(wann);
	items.push_back(mitwem);
	items.push_back(wie);

	items[0].item_add_conection(1,items[1]);
	items[2].item_add_conection(0.5,items[1]);
	items[2].item_add_conection(0.5,items[3]);
	items[3].item_add_conection(0.1,items[1]);
	items[3].item_add_conection(0.2,items[2]);
	items[3].item_add_conection(0.3,items[3]);
	items[3].item_add_conection(0.4,items[4]);
	items[3].item_add_conection(0.5,items[5]);
	items[3].item_add_conection(0.6,items[6]);
	items[4].item_add_conection(0.4,items[2]);
	items[4].item_add_conection(0.5,items[3]);

	
//	items[0].print();
//	items[1].print();
	std::cout<<items.size()<<std::endl;
}

void Organizer::print_actuall(Item & item,ItemTyp itemTyp){

	Item zeroItem(itemTyp,nothing,"Leer");
	std::vector<Item*> topFiveI={&zeroItem};
	std::vector<float> topFiveF={0};
//	std::cout<<"test"<<topFiveF.size()<<std::endl;
	for (size_t i=0;i<item.weights.size();i++){
		if(item.targets[i]->itemTyp==itemTyp){
			for (size_t j=0;j<=topFiveF.size();j++){
				if (topFiveF[j] < item.weights[i]){
					topFiveI.insert(topFiveI.begin()+j,item.targets[i]);
					topFiveF.insert(topFiveF.begin()+j,item.weights[i]);
					break;
				}
			}
		}
	}
				

//	std::cout<<"test"<<topFiveF.size()<<std::endl;
	for(size_t i=0;i<topFiveF.size();i++ ){
		std::cout<<"Gewicht:"<<topFiveF[i]<<" Ziel\""<<topFiveI[i]->text<<"\""<<std::endl;
	}

}

void Organizer::print(){
	//std::cout<<items[0].text<<std::endl;

}


