/*
 * surveyforinformation.cpp
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


#include "surveyforinformation.h"


SurveyForInformation::SurveyForInformation()
{
	
}


SurveyForInformation::~SurveyForInformation()
{
	
}

void SurveyForInformation::start(){

	generateQuestion();
	askForInput();
	interpretInput();
	handleInput();




	int i=iohandler.askForInt();
	
}

void SurveyForInformation::generateQuestion(){
	
	iohandler.printQuestion()
}

void SurveyForInformation::askForInput(){

	iohandler.askForInt();
	

}

void SurveyForInformation::interpretInput(){

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

void SurveyForInformation::newItem(){

	dataController.addItem(iohandler.new_object_name(),typOfsearchedObject);

}

void SurveyForInformation::handelInput(){

	networkController.updateWeights();

}
