#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
#include<iostream>
#include<memory>
#include<string>
#include<vector>
using std::string;
using std::cout; using std::cin;
using std:: make_unique;

int main() 

{
	int a = 0;
	int b = 0;
	int c = 0;
	int board_choice;
	string choice;
	tic_tac_toe_data data;
	//tic_tac_toe_manager manager(data);
	std::unique_ptr<tic_tac_toe> game1;
	tic_tac_toe_manager manager(data);
		
	string continue_ = "y";
	while (continue_ == "y")
	{
		cout<<"Which board size game do you want to play 3x3 4x4?: \n";
		cin>>board_choice;
		if(board_choice == 3)
		{
			game1 = make_unique<tic_tac_toe_3>();
		}
		else
		{
			game1 = make_unique<tic_tac_toe_4>();
		}
		cout<<"Which player do you want X or O? \n";
		cin>>choice;
		game1->start_game(choice);
	
		while(game1->game_over() == false)
		{
			
			cin>>*game1;
			cout<<*game1;
		}
		
		cout<<"The winner is "<<game1->get_winner()<<"\n";
		manager.save_game(game1);
		manager.get_winner_total(a,b,c);
		cout<<"X wins: "<<b<<"\n"<<"O wins: "<<a<<"\n"<<"Ties: "<<c<<"\n";
		cout<<"\n Do you want to continue the game(y/n)?: \n";
		cin>>continue_;
		
	}
	
	return 0;
}