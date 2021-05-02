//cpp
#include "tic_tac_toe_data.h"
using std::vector;
using std::string;
using std::unique_ptr;
using std::make_unique;
#include<fstream>
#include<iostream>

void tic_tac_toe_data::save_games(const std::vector<std::unique_ptr<tic_tac_toe>>& games)
{
    std::ofstream out_file;
    out_file.open(file_name);
    
    if(out_file.is_open())
    {
        for(auto& game1 : games)
        {
            for(auto& pegs: game1->get_pegs())
            {
                out_file<<pegs;

            }
            out_file<<game1->get_winner();
            out_file<<"\n";
        }
    }
    out_file.close();
}
vector<unique_ptr<tic_tac_toe>> tic_tac_toe_data::get_games()
{
    vector<unique_ptr<tic_tac_toe>>games;
    std::ifstream in_file;
    in_file.open(file_name);
    string line;

    if(in_file.is_open())
    {
        while(std::getline(in_file, line))
        {
            vector<string> pegs;
            for(size_t i = 0; i<(line.size() -1); ++i)
            {
                string ch(1, line[i]);
                pegs.push_back(ch);
            }
            string winner{line[line.size() -1]};
            unique_ptr<tic_tac_toe> game1;

            if(pegs.size() == 9)
            {
                game1 = make_unique<tic_tac_toe_3>(pegs, winner);
            }
            else if(pegs.size() == 16)
            {
                game1 = make_unique<tic_tac_toe_4>(pegs, winner);
            }
            games.push_back(std::move(game1));
        }
        in_file.close();
    }
    return games;
}