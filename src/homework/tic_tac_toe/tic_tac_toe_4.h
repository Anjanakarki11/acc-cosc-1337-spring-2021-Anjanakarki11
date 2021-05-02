//h
#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H
#include "tic_tac_toe.h"
#include<vector>
#include<string>
#include<iostream>
#include<string>
using std::vector;
using std::string;

class tic_tac_toe_4 : public tic_tac_toe
{
public:
    tic_tac_toe_4() : tic_tac_toe(4){}
    tic_tac_toe_4(std::vector<std::string>pegs, string winner) : tic_tac_toe(pegs,winner){}

private:
    bool check_column_win() override;
    bool check_row_win() override;
    bool check_diagonal_win() override;

};

#endif