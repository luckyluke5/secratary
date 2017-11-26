/*
 * survey.cpp
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


#include "survey.h"


Survey::survey()
{
	
}


Survey::~survey()
{
	
}

void Survey::start(){

	generateQuestion();
	askForInput();
	interpretInput();
	handleInput();




	int i=iohandler.askForInt();
	
}

void Survey::generateQuestion(){
	
	iohandler.printQuestion()
}

void Survey::askForInput(){

	iohandler.askForInt();
	

}

void Survey::interpretInput(){

	if(i=-2){
			closeSurvey();
		}else if(i=-1){
			closeSession()
		}else if(i=0){
			newItem();
		}else if(i<0){
			handelInput(i);
		}else{
			std::cout<<"INPUT:ERORR: \""<<i<<"\""<<std::endl;
		}
	
}

void Survey::newItem(){

	dataOrganizer.addItem(iohandler.new_object_name(),typOfsearchedObject);

}

void Survey::handelInput(){

	networkController.updateWeights();

}
