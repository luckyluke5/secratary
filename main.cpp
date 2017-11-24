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


	std::vector<Item*> output=o.print_actuall(o.items[0],question);

	
	int i;
	std::cin>>i;

//	(*output[i]).print();

	std::vector<Item*> output2=o.print_actuall(*output[i-1],output[i-1]->answerTyp);
	
	int j;
	std::cin>>j;

//	(*output[j]).print();
	

	if (j==0){
		std::cout<<"test1"<<std::endl;
		std::string name;
		std::cout<<"test2"<<std::endl;
		std::cout << "Please, enter your full name: ";
		std::cin.ignore();
		std::getline (std::cin,name);
		std::cout<<"test3"<<name<<std::endl;
		o.items.push_back(Item(output[i-1]->answerTyp,question,name));
		std::cout<<"test4"<<std::endl;
		(*output[i-1]).item_add_conection(0.5,o.items.back());
		std::cout<<"test5"<<std::endl;
		o.print_actuall(*output[i-1],output[i-1]->answerTyp);
	}else{
		
		o.print_actuall(*output[j-1],output[j-1]->answerTyp);
	}

//	o.items[0].print();

/*	o.items[0].print();
	o.items[1].print();
	o.print_actuall(o.items[0],question);
	std::cout<<"item 1"<<std::endl;
	o.print_actuall(o.items[1],question);
	std::cout<<"item 2"<<std::endl;
	o.print_actuall(o.items[2],question);
	std::cout<<"item 3"<<std::endl;
	o.print_actuall(o.items[3],question);
	std::cout<<"item 4"<<std::endl;
	o.print_actuall(o.items[4],question);
	std::cout<<"item 5"<<std::endl;
	o.print_actuall(o.items[5],question);
	std::cout<<"item 6"<<std::endl;
	o.print_actuall(o.items[6],question);
	std::cout<<"item 7"<<std::endl;
	o.print_actuall(o.items[7],question);

	o.print();
*/	
	return 0;
}

