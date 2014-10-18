/**
* \file Game.h
*
* \author Zachary Walters
*
* \brief Maintains aspects of the game
*
* This Class will represent the game features that will be used when playing the game in aquarium
*/

#pragma once
#include <string>
#include <memory>
#include "XmlNode.h"

class CAquarium;


/*! \brief Represents the game played in the aquarium
 * 
 * Instance of this class is created when the aquarium is created
 * and this is where the current of the game is stored.
 * It also determines if the user can afford the item or fish 
 * they wish to add at that time.
 * Ultimitely determines when the game is over when the score is negative
 */
class CGame
{
public:
	CGame();
	virtual ~CGame();

	void AddScore(int add);
	
	void ReduceScore(int reduction);

	/** \brief Returns a boolean stating if cost is less than the total amount of points available to spend */
	bool CanAfford(int cost) { return cost <= mScore; }

	/** \brief Returns the current score of the game */
	int GetScore() { return mScore; }

	void SetScore(int score);

	/** \brief Returns a boolean stating if the game is over */
	bool Loser() { return mGameOver; }

	void ResetGame();

private:
	/// Current score of the player
	int mScore = 10;

	/// If score is negative number and game is over
	bool mGameOver = false;
};

