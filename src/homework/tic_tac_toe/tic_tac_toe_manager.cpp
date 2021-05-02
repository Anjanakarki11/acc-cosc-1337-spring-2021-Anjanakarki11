//cpp
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include<iostream>
using std::cout;
using namespace std;

tic_tac_toe_manager::tic_tac_toe_manager(tic_tac_toe_data d) : data{d}
{
    games = data.get_games();
    for (auto& game1 : games)
    {
        update_winner_count(game1->get_winner());
    }
}

void tic_tac_toe_manager::save_game(std::unique_ptr<tic_tac_toe>& b)
{
    //games.push_back(std::move(b));
    update_winner_count(b->get_winner());
    games.push_back(std::move(b));
}
std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager)
{
    //int i;
    for( auto& game1 : manager.games)
    {
        out<<*game1;
        out<<"\n";
    }
    return out;

}
void tic_tac_toe_manager::get_winner_total(int& o, int& x, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;

}
void tic_tac_toe_manager::update_winner_count(std::string winner)
{
    if (winner == "X")
    {
        x_win += 1;
    }
    else if (winner == "O")
    {
        o_win += 1;
    }
    else
    {
        ties += 1;
    }
}
tic_tac_toe_manager::~tic_tac_toe_manager()
{
    std::cout<<"\n save games\n";
    data.save_games(games);
}