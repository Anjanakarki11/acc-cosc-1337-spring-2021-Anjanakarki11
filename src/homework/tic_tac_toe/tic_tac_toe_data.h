//h
#include "tic_tac_toe_3.h"
#include "tic_tac_toe.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H
#include<memory>
using std::vector;
using std::string;
using std::unique_ptr;
using std::make_unique;
#include<iostream>

class tic_tac_toe_data
{
public:
    void save_games(const std::vector<std::unique_ptr<tic_tac_toe>>& games);
    std::vector<std::unique_ptr<tic_tac_toe>> get_games();

private:
    const std::string file_name{"tic_tac_toe.dat"};
};
#endif