//DEFINE YOUR TEST
#define RUN02

#ifdef RUN01

#include<string>
using std::string;
#include"stack.h"
#include"queue.h"
//g++ -g main.cpp actor.cpp aquarium.cpp game.cpp player.cpp point.cpp shark.cpp utils.cpp -std=c++11
int main() {

	Stack<std::string> stack;
	Queue<std::string> queue;

	stack.push("Feynman");
	stack.push("Turing");
	stack.push("Einstein");
	stack.push("Bohr");
	stack.push("Sanchez");

	stack.print();

	queue.push(stack.top());
	stack.pop();

	queue.push(stack.top());
	stack.pop();

	queue.push(stack.top());
	stack.pop();

	queue.push(stack.top());
	stack.pop();

	queue.pop();
	queue.pop();
	
	queue.print();
	stack.print();
	
	return 0;
}

#elif defined(RUN02) //Test the game


#include"game.h"

int main() {

	
	//Setup game
	Game g("settings.ini");

	//Exectute game loop
	g.play();
	
	return 0;
}
#else


#endif
