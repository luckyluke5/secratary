/*
 * questionstrategiemanager.cpp
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


#include "questionstrategiemanager.h"


QuestionStrategieManager::QuestionStrategieManager(DataController & _dataController) : dataController(_dataController)
{
	
}


QuestionStrategieManager::~QuestionStrategieManager()
{
	
}

std::vector<ConnectionToQuestion> & QuestionStrategieManager::possibleAnswerData(){
	
	return normateTheWeights(calculateConnectionsToQuestions(calculateConnectionsToQuestionStrategies()));


}

std::vector<ConnectionToQuestion> & QuestionStrategieManager::calculateConnectionsToQuestions(std::vector<ConnectionToQuestionStrategie> & connectionsToQuestionStrategies){

	// sollte so für immer gehen, da einfach nur die gewichte für die einzel fragen aus
	// den gewichten für die strategien kopiert wird

	// noch gedanken sind darüber zu machen, wie es geschafft werden kann, das die gewichte nicht immer wieder neu berechnet
	// werden müssen, sondern nur die änderungen drauf addiert werden.
	std::vector <ConnectionToQuestion> connectionsToQuestions;
	for (ItemID i=0;i<dataController.numberOfQuestions();i++){

		connectionsToQuestions.push_back(ConnectionToQuestion(QuestionID(i),0));

	}

	
	for (auto connectionToQuestionStrategie :connectionsToQuestionStrategies){

		connectionsToQuestions[connectionToQuestionStrategie.target.actuallQuestionID.id()]+=connectionToQuestionStrategie.weight();

	}

	return questionIDs;
}

std::vector<ConnectionToQuestionStrategie> & QuestionStrategieManager::calculateConnectionsToQuestionStrategies(){

	// diese Funktion braucht noch richtigen inhalt.
	// sie soll die fragen in sortierter gewichtsreihenfolge ausgeben
	// die jetzt aufgrund von antoworten in dieser section und den vorrangegangenen
	// fragestrategien am sinnvolsten sind. ob vorrangegangene end_actions zu breücksichtigen
	// sind ist noch zu überlegen.

	std::vector <ConnectionToQuestionStrategie> connectionsToQuestionStrategies;
	for (auto questionStrategieId : questionStrategieIDs){

		connectionsToQuestionStrategies.push_back(ConnectionToQuestionStrategie(questionStrategieId,1.0/questionStrategieIDs.sizeOf()));

	}
}

void QuestionStrategieManager::newQuestion(QuestionID & questionID){

	// neu frage die an dieser stelle gut gewesen wär
	// frage so verknüpfen und question strategies updaten,
	// das nächstes mal möglicherweise diese frage empfolen wird

}

void QuestionStrategieManager::answer(QuestionID & questionID){

	// diese frage wurde ausgewählt. gewichte so updaten, das diese frage das nächste mal genommen werden kann
	// ebenfalls question strategies array so updaten, das unmögliche question strategies entfernt werden

}
