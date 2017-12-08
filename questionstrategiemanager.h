/*
 * questionstrategiemanager.h
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


#ifndef QUESTIONSTRATEGIEMANAGER_H
#define QUESTIONSTRATEGIEMANAGER_H

#include "datacontroller.h"

class QuestionStrategieManager
{
	public:
		QuestionStrategieManager();
		virtual ~QuestionStrategieManager();

		DataController dataController;

		void startWeights(std::vector<ConnectionToQuestionStrategie> & connectionsToQuestionStrategies)

		std::vector<ConnectionToQuestion> & possibleAnswerData();

		newQuestion(QuestionID & newQuestion);
		answer(Question ID & answer);


		std::vector<ConnectionToQuestionStrategie> startingConnections;
	
	private:
		///berechnet die Verbindungen zu den einzelnen Fragen, aufgrund der Verbindung zu den einzelnen Strategien
		std::vector<ConnectionToQuestion> & calculateConnectionsToQuestions(std::vector<ConnectionToQuestionStrategie> & connectionsToQuestionStrategies);

		///berchnet die Verbindung zu den einzelnen Strategien, auf grund der Startbedingungen
		///, den schlussaktionen dr vorherigen sections und der question strategie der vorherigen sections
		std::vector<ConnectionToQuestionStrategie> & calculateConnectionsToQuestionStrategies();


//		std::vector<QuestionStrategieID> questionStrategieIDs;
		std::vector<ItemID> answers;
		/* add your private declarations */
};

#endif /* QUESTIONSTRATEGIEMANAGER_H */ 
