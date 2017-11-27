/*
 * datacontroler.cpp
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


#include "datacontroller.h"


DataController::DataController()
{
	
}


DataController::~DataController()
{
	
}

void DataController::make_ready(){

	Item wasmachen(question, action, std::string("Um welche Action geht es?"),1);

	Item wielange(question, place, std::string("Um welchen Ort geht es?"),2);

	Item mitwem(question, person, std::string("Um welche Person geht es?"),3);
	
	Item start=Item(question,question, std::string("Mit welcher Frage willst du weitermachen"),0);

	items.push_back(start);
	items.push_back(wasmachen);
	items.push_back(wielange);
	items.push_back(mitwem);


	items[0].item_add_conection(1.0/3,1);
	items[0].item_add_conection(1.0/3,2);
	items[0].item_add_conection(1.0/3,3);

}






