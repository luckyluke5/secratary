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
#include <tupel>

enum ItemTyp{nothing, question,place,person, action };

typedef size_t itemID;

class Item
{
	public:
		Item(ItemTyp _itemTyp,std::string _string,itemID _id);
		
		ItemTyp itemTyp;
		std::string lable;
		itemID id;
		std::vector<std::tupel<float,itemID>> connections;

		
		void printConnections();
		void addConnection(float weight,itemID target);



 			
	private:
		/* add your private declarations */
};

#endif /* ITEM_H */ 
