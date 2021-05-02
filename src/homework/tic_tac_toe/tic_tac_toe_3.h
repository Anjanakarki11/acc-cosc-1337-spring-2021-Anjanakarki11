//h
#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H
#include "tic_tac_toe.h"
#include<vector>
#include<string>
#include<iostream>
#include<string>
using std::vector;
using std::string;

class tic_tac_toe_3 : public tic_tac_toe
{
public:
    tic_tac_toe_3() : tic_tac_toe(3){}
    tic_tac_toe_3(std::vector<std::string>p, string winner) : tic_tac_toe(p,winner){}

private:
    bool check_column_win() override;
    bool check_row_win() override;
    bool check_diagonal_win() override;

};

#endif