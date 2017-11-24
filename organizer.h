/*
 * organizer.h
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


#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <vector>
#include "item.h"


class Organizer
{
	public:
		Organizer();
		void make_ready();
		std::vector<Item*> print_actuall(Item & item,ItemTyp itemTyp);

		std::vector<Item> items;

		void print(Item & item);
			
	private:

	
		void printText(std::string text);
		/* add your private declarations */
};

#endif /* ORGANIZER_H */ 
