//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include<vector>
#include<string>
#include<iostream>
#include<string>
using std::vector;
using std::string;
class tic_tac_toe
{
public:
    //void display_board()const ;
    tic_tac_toe(){};
    tic_tac_toe(int size) : pegs(size*size, " "){};
    tic_tac_toe(std::vector<std::string> p, std::string w) : pegs(p), winner(w) {}
    void mark_board(int position);
    void start_game(string first_player);
    void get_player();
    bool game_over();
    string get_winner(){return winner;};
    std::vector<std::string> get_pegs()const{return pegs;}
    friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe& game1);
    friend std::istream& operator>>(std::istream& in, tic_tac_toe& game1);

private:
    //vector<string>pegs;
   // vector<string> pegs = {" "," "," "," "," "," "," "," "," ",};
    string player;
    void clear_board();
    bool check_board_full();
    void set_next_player();
    //bool check_column_win();
   // bool check_row_win();
    //bool check_diagonal_win();
    void set_winner();
    string winner;

protected:
    vector<std::string> pegs{9, " "};
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();


};
#endif