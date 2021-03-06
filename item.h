/*
 * item.h
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


#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <vector>

enum ItemTyp{nothing, question,place,person, action };

class Item
{
	public:
		Item(ItemTyp _itemTyp,ItemTyp _answerTyp,std::string _string,size_t _id);
		
		ItemTyp itemTyp;
		ItemTyp answerTyp;
		std::string text;
		size_t id;
		std::vector<float> weights;
		std::vector<size_t> targets;
		
		void print();

		void item_add_conection(float weight,size_t target);
 			
	private:
		/* add your private declarations */
};

#endif /* ITEM_H */ 
