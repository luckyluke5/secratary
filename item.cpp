/*
 * item.cpp
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


#include "item.h"


Item::Item(ItemTyp _itemTyp,std::string _string,itemID _id) :itemTyp(_itemTyp),lable(_string),id(_id)
{
	
}

void Item::printConnections(){

//	std::cout<<"Itemtyp: "<<itemTyp<<" Answertyp: "<<answerTyp<< " Text:\""<<text<<"\""<<std::endl;
	for(auto & connection : connections){
		std::cout<<"Gewicht:"<<std::get<0>(connection)<<" Ziel\""<<std::get<1>(connection)<<"\""<<std::endl;
	}
}



void Item::addConnection(float weight,itemID target){

	connection.push_back(std::make_tupel(weight,target));
}
