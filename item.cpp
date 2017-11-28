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



Item::Item(ItemTyp _itemTyp,ItemTyp _answerTyp,std::string _string,size_t _id) :itemTyp(_itemTyp),answerTyp(_answerTyp),text(_string),id(_id)
{
	
}

void Item::print(){

	std::cout<<"Itemtyp: "<<itemTyp<<" Answertyp: "<<answerTyp<< " Text:\""<<text<<"\""<<std::endl;
	for(size_t i=0;i<targets.size();i++ ){
		std::cout<<"Gewicht:"<<weights[i]<<" Ziel\""<<targets[i]<<"\""<<std::endl;
	}
}



void Item::item_add_conection(float weight,size_t target){

	weights.push_back(weight);
	targets.push_back(target);
}
