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
	Item wasmachen(question, action, std::string("Um welche Action geht es?"),1);

	Item wielange(question, place, std::string("Um welchen Ort geht es?"),2);

	Item mitwem(question, person, std::string("Um welche Person geht es?"),3);
	
	Item start=Item(question,question, std::string("Mit welcher Frage willst du weitermachen"),0);
	
//	printText(std::string("Was möchtest du machen?"));
	items.push_back(start);
	items.push_back(wasmachen);
	items.push_back(wielange);
	items.push_back(mitwem);


	items[0].item_add_conection(1.0/3,1);
	items[0].item_add_conection(1.0/3,2);
	items[0].item_add_conection(1.0/3,3);


	
//	items[0].print();
//	items[1].print();
//	std::cout<<items.size()<<std::endl;
}

std::vector<size_t>  Organizer::print_actuall(std::vector<size_t> visitedElements,ItemTyp itemTyp){

	size_t item =visitedElements.back();
	
	printname(item);

	items[item];

	std::vector<size_t> topFiveI(1,0);
	std::vector<float> topFiveF(1,0);
	//std::cout<<"test in print actuall and size of top"<<topFiveF.size()<<std::endl;
	for (size_t i=0;i<items[item].weights.size();i++){
		//std::cout<<"test in print actuall"<<i<<std::endl;
		if(items[items[item].targets[i]].itemTyp==itemTyp){
			for (size_t j=0;j<=topFiveF.size();j++){
				if (topFiveF[j] < items[item].weights[i]){
					topFiveI.insert(topFiveI.begin()+j,items[item].targets[i]);
					topFiveF.insert(topFiveF.begin()+j,items[item].weights[i]);
					break;
				}
			}
		}
	}

	topFiveF.pop_back();
	topFiveI.pop_back();

//	std::cout<<"test"<<topFiveF.size()<<std::endl;
	for(size_t i=0;i<topFiveF.size();i++ ){
		std::cout<<i+1<<": "<<items[topFiveI[i]].text<<" \t\t\t(W:"<<topFiveF[i]<<")"<<std::endl;
	}

	return topFiveI;

}

void Organizer::print(size_t item){

	std::cout<<"Itemtyp: "<<items[item].itemTyp<<" Answertyp: "<<items[item].answerTyp<< " Text:\""<<items[item].text<<"\""<<std::endl;
	for(size_t i=0;i<items[item].targets.size();i++ ){
		std::cout<<"Gewicht:"<<items[item].weights[i]<<" Ziel\""<<items[items[item].targets[i]].text<<"\""<<std::endl;
	}
}

void Organizer::printname(size_t item){

	std::cout<<items[item].text<<std::endl;
}



void Organizer::update_weights(size_t from_id,size_t to_id){

//	print();
	float sumweightsbefore=0;
	for (size_t i=0; i<items[from_id].weights.size();i++){
		sumweightsbefore+=items[from_id].weights[i];	

	}
	float differenc=0;
	for (size_t i=0; i<items[from_id].weights.size();i++){
		if (items[from_id].targets[i]!=to_id){
			differenc+=items[from_id].weights[i]*0.1;
			items[from_id].weights[i]-=items[from_id].weights[i]*0.1;
		}

	}
	if (differenc==0) differenc=1;
	for (size_t i=0; i<items[from_id].weights.size();i++){
		if (items[from_id].targets[i]==to_id){
			items[from_id].weights[i]+=differenc;
		}	

	}
	float sumweightsafter=0;
	for (size_t i=0; i<items[from_id].weights.size();i++){
		sumweightsafter+=items[from_id].weights[i];	

	}

	std::cout<<items[from_id].text<<", WeightsSumBefore: "<<sumweightsbefore<<" WeightsSumAfter: "<<sumweightsafter<<std::endl;
//	print();

}



