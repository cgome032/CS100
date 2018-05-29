#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"
#include <vector>


class Menu {
	private:
		unsigned int history_index;
		vector<Command*> history;

	public:
		Menu() {
			//Base constructor to set up all necessary members
		  history_index = 0;
		};
		void execute() {
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			//std::cout << "I was called too!" << std::endl;
			if(history.size() == 0){
			  std::cout << 0 << std::endl;
			}
			else{
			  //std::cout << "Else was called!" << std::endl;
			  std::cout << history[history_index]->execute() << std::endl;
			  // history_index++;
			}
		};
		bool initialized() {
			//Return true if the history has been primed with a single op instruciton
			//This is necessary because that is the base of a calculation
			if (history.empty()){
				return false;
			}
			else
			  return true;
		
		};

		void add_command(Command* cmd) {
			//Adds a command to history in the appropriate position (based on history_index)
			if (history.size() == 0){
				history.push_back(cmd);
				//std::cout << "Zero was called!" << std::endl;
				//std::cout << "Size of commands is " << history.size() << std::endl;
				//std::cout << "Index is at " << history_index << std::endl;
			}
			//else if(history.size() >= 1){
			  //history.push_back(cmd);
			  //history_index++;
			  //std::cout << "Size of commands is " << history.size() << std::endl;
			  //std::cout << "Index is at " << history_index << std::endl;			
			//}
			else{
				//std::cout << "Iterator was called too!." << std::endl;	
				vector<Command*>::iterator check = history.begin();
				unsigned int i = 0;
				for (i = 0; i < history_index  + 1; i++){
					check++;
				}
				history.insert(check, cmd);
				//history_index++;
				history_index = i;
			}				
		};

		Command* get_command() {
			//Returns the command in history we are currently referring to (based on history_index)
			return history.at(history_index);
		};


		void undo() {
			//Moves to the last command in history (if possible)
			if (history_index == 0){
				std::cout << "Could not undo any further." << std::endl;
				return;
			}
			else{
				history_index = history_index - 1;
			}
		};

		void redo() {
			//Moves to the next command in history (if possible)
			if ((history_index == history.size() - 1) || (history.size() == 0)){
				std::cout << "Could not redo any further." << std::endl;
				return;
			}
			else{
				history_index = history_index + 1;
			}
		};
};

#endif //__MENU_CLASS__
