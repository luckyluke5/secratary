/*
 * main.cpp
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


#include <iostream>
#include "organizer.h"

void print(const char* text){


	std::cout<<std::string(text)<<std::endl;
	}

int main(int argc, char **argv)
{

	Organizer o;

	o.make_ready();

	std::vector<size_t> visitedElements;
	
	size_t actuallElement=0;
	bool continu=true;
	while (continu){

		//o.print(actuallElement);
		
		visitedElements.push_back(actuallElement);
		std::vector<size_t> output=o.print_actuall(visitedElements,o.items[actuallElement].answerTyp);
		//std::cout<<"tippen sie eine zahl grosser null ein oder 0 für eine eigene antwort"<<std::endl;

		//o.print(actuallElement);
		
		int i;
		std::cin>>i;

		if (i==0 && o.items[actuallElement].answerTyp!=question){
			
			std::string name;
			std::cout << "Tippen sie die Antwort ein: ";
			std::cin.ignore();
			std::getline (std::cin,name);

			std::cout<<name<<std::endl;
			//o.print(actuallElement);
			
			o.items.push_back(Item(o.items[actuallElement].answerTyp,question,name,o.items.size()));

			//o.print(o.items.size()-1);

			//o.print(actuallElement);
			
			//o.items[actuallElement].item_add_conection(0,o.items.size()-1);

			//o.print(actuallElement);

			o.update_weights(visitedElements,o.items.size()-1); //keine adresse
			//std::cout << "vor print actuall"<<std::endl;

			//o.print(actuallElement);

			o.print_actuall(visitedElements,o.items[actuallElement].answerTyp);
			//std::cout << "nach printactuall"<<std::endl;

			actuallElement=o.items.size()-1; //keine adresse
			//std::cout << "Test 6"<<std::endl;

			//o.print_actuall(*output[i-1],output[i-1]->answerTyp);

			if (o.items[actuallElement].answerTyp==question){
				visitedElements.push_back(actuallElement);
				actuallElement=0;
			}

		}else if(i==-1){
			break;
		}else if(i==-2){
			actuallElement=0;
			visitedElements.clear();
		}else{
			
			o.update_weights(visitedElements,output[i-1]);

			o.print_actuall(visitedElements,o.items[actuallElement].answerTyp);
			
			actuallElement=output[i-1];

			if (o.items[actuallElement].answerTyp==question){
				visitedElements.push_back(actuallElement);
				actuallElement=0;
			}
		}

		

		

		
	}


	return 0;
}

