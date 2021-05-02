//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
#include<iostream>
#include<string>
#include<vector>
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include<memory>
using std::vector;
using std::string;
using std::unique_ptr;
class tic_tac_toe_manager
{
public:
    tic_tac_toe_manager(tic_tac_toe_data data);
    void save_game(std::unique_ptr<tic_tac_toe>& b);
    //void update_winner_count(std::string winner);
    friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager);
    void get_winner_total(int& o, int& x, int& t);
    ~tic_tac_toe_manager();

private:
    
    std::vector<std::unique_ptr<tic_tac_toe>> games{};
    tic_tac_toe_data data;
    int x_win{0};
    int o_win{0};
    int ties{0};
    void update_winner_count(std::string winner);

};
#endif