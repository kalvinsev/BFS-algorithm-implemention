#include"player.h"
#include"actor.h"
#include"stack.h"
#include"list.h"
#include"point.h"
#include"aquarium.h"
#include<iostream>

//  Player( ... )
//		Constructs and initializes the Player/Actor and its member variables
//		Remembers and discovers the starting point.
Player::Player(Aquarium* aquarium, Point p, std::string name, char sprite)
	:Actor(aquarium, p, name, sprite),
	m_look(),
	m_discovered(),
	m_btQueue(),
	m_btStack(),
	m_toggleBackTracking(false) {

	// Discover the starting point
	m_discovered.push_front(p);
	m_look.push(p);
}

//  stuck() 
//		See if the player is stuck in the maze (no solution)
bool Player::stuck() const {
	return Actor::getState() == State::STUCK;
}

//  foundExit()
//		See if the player has found the exit
bool Player::foundExit() const {
	return Actor::getState() == State::FREEDOM;
}
//  toggleBackTrack( ... )
//		Turn on/off backtracking
void Player::toggleBackTrack(bool toggle) {
	m_toggleBackTracking = toggle;
}

//  getTargetPoint()
//		Get the point the player wants to look around next.
//      If m_look is empty then return an invalid point.
Point Player::getTargetPoint() const {
	if (m_look.empty()) return Point(-1, -1);
	return m_look.front();
}

// discovered
//		returns true if the item is in the list
bool Player::discovered(const Point &p) const {
	return (m_discovered.find(p) != -1);
}



// say()
//		What does the player say?
//		Already Implemented, nothing to do here
void Player::say() {

	// Freedom supercedes being eaten
	if (getState() == State::FREEDOM) {
		std::cout << getName() << ": WEEEEEEEEE!";
		return;
	} 
 
	// Being eaten supercedes being lost
	switch (getInteract()) {
	case Interact::ATTACK:
		std::cout << getName() << ": OUCH!";     
		break;
	case Interact::GREET:
		break;
	case Interact::ALONE:
	default:
		switch (getState()) {
		case State::LOOKING:
			std::cout << getName() << ": Where is the exit?";
			break;
		case State::STUCK:
			std::cout << getName() << ": Oh no! I am Trapped!";
			break;
		case State::BACKTRACK:
			std::cout << getName() << ": Got to backtrack...";
			break;
		default:
			break;
		}

		break;
	}
}


//  update() 
//		This function implements an algorithm to look through the maze
//      for places to move (STATE::LOOKING). update also handles moving the 
//		player as well, if there is an open undiscovered cell to move to the  
//		player just moves there.  However, there will be cases in the next 
//		desired point to look around is not adjacent (more than one cell away), 
//		at this point the player must backtrack (State::BACKTRACK) to a point 
//		that is adjacent to the next point the player was planning to visit
//
//		The player can only do one thing each call, they can either LOOK or 
//		BACKTRACK not both.  Nor should the player move more than one cell per
//		call to update.  If you examine the function calls for the entire game
//		you should observe that this is already be called within a loop. Your
//		Implementation should NOT have any loops that pertain to actual movement 
//		of the player.  
//
//		Backtracking is challenging, save it for the very very very last thing.
//		Make sure the STATE::LOOKING aspect compiles and works first.
void Player::update() {

	/* TODO */
	
	moveTo(getTargetPoint());
	
	Point p = currentPosition();
	Point west(p.x()-1, p.y());
	Point east(p.x()+1, p.y());
	Point north(p.x(), p.y()-1);
	Point south(p.x(), p.y()+1);
	//m_look.push(east);
	switch(getState()){
		case State::LOOKING: 
			//moveTo(getTargetPoint());
			if(m_look.empty()){
				setState(State::STUCK);	
				break;
			}
			//moveTo(getTargetPoint());
			
			//if(currentPosition() == m_look.front()){
				m_look.pop();
			//}
			if(currentPosition() == getAquarium()->getEndPoint()){
				setState(State::FREEDOM);
				break;
			}
			if(getAquarium()->isOpen(west) && !discovered(west)){
				m_discovered.push_rear(west);
				m_look.push(west);
				//moveTo(getTargetPoint());
				
			}
			if(getAquarium()->isOpen(east) && m_discovered.find(east) == -1){
				m_discovered.push_rear(east);	
				m_look.push(east);
				//moveTo(getTargetPoint());
				
			}
			if(getAquarium()->isOpen(north) && m_discovered.find(north) == -1){
				m_discovered.push_rear(north);
				m_look.push(north);
				//moveTo(getTargetPoint());
				
			}
			if(getAquarium()->isOpen(south) && m_discovered.find(south) == -1){
				m_discovered.push_rear(south);
				m_look.push(south);
				//moveTo(getTargetPoint());
				
			}
			
			break;

		case State::BACKTRACK:

			break;

		default:
			break;

	}
	// Set by the settings file, if m_toggleBackTracking is false, then
	// your program should behave exactly as seen in the slides or
	// example executables (with teleporting).
	// if(m_toggleBackTracking) { ... code relating to backtracking 

	//moveTo(getTargetPoint());
	//m_look.push(east);
}