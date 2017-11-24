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
	
	Item start=Item(action,nothing, std::string("Start"));
	start.item_add_conection(1,wasmachen);
	printText(std::string("Was möchtest du machen?"));
	items.push_back(start);
	items.push_back(wasmachen);
	

	items[0].print();
	items[1].print();
	std::cout<<items.size()<<std::endl;
	}



void Organizer::print(){
	std::cout<<items[0].text<<std::endl;

	}


