#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        virtual std::string type() const = 0;
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
        virtual std::string print() const = 0;
    };

    class King : public Piece {
    public:
        King(ChessBoard::Color coler) : Piece(coler){}
        virtual std::string type() const override {
            return this->color_string()+" King";
        };

        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return abs(from_x - to_x) == 1 || abs(from_y - to_y) == 1;
        }

        virtual std::string print() const override {
            std::string color(1, this->color_string()[0]);
            return color +"K";
        }
    };

    class Knight : public Piece {
    public:
        Knight(ChessBoard::Color coler) : Piece(coler){}
        virtual std::string type() const override {
            return this->color_string()+" Knight";
        };

        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return abs((from_x - to_x)*(from_y- to_y)) == 2;
        }

        virtual std::string print() const override {
            std::string color(1, this->color_string()[0]);
            return color +"Kn";
        }
    };

    ChessBoard() {
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    vector<vector<unique_ptr<Piece>>> squares;
    function<void(const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares)> after_piece_move;
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &square)> on_piece_removed;
    function<void(Color color)> on_game_lost;
    function<void(const Piece &piece, const string &from, const string &to)> piece_invalid;
    function<void(const string &square)> piece_missing;

    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;
        bool return_val = false;

        auto &move_from = squares[from_x][from_y];
        if (move_from) {
            if (move_from->valid_move(from_x, from_y, to_x, to_y)) {
                if (on_piece_move)
                    on_piece_move(*move_from, from, to);
                auto &move_to = squares[to_x][to_y];
                if (move_to) {
                    if (move_from->color != move_to->color) {
                        if (on_piece_removed)
                            on_piece_removed(*move_to, to);
                        if (auto king = dynamic_cast<King *>(move_to.get())) {
                            if (on_game_lost)
                                on_game_lost(king->color);
                        }
                    } else {
                        if (piece_invalid)
                            piece_invalid(*move_from, from, to);
                        return_val = false;
                    }
                }
                move_to = move(move_from);
                return_val = true;
            } else {
                if (piece_invalid)
                    piece_invalid(*move_from, from, to);
                return_val = false;
            }
        } else {
            if (piece_missing)
                piece_missing(from);
            return_val = false;
        }
        if(return_val) after_piece_move(squares);

        return return_val;
    }
};

class ChessBoardPrint {
public:
    ChessBoardPrint(ChessBoard &board) {
        board.after_piece_move = [](const vector<vector<unique_ptr<ChessBoard::Piece>>>& squares) {
            for (size_t i = squares.size()-1; i + 1 > 0; i--) {
                cout << "  " << i+1 << "  ";
                for (size_t j = 0; j < squares.at(i).size(); j++) {
                    if (!squares.at(j).at(i)) {
                        cout << "  -  ";
                    } else {
                        auto &piece = squares.at(j).at(i);
                        cout << " " << piece->print() << " ";
                    }
                }
                cout << endl;
            }
            cout << "       A    B    C    D    E    F    G    H\n" << endl;
        };

        board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
            cout << piece.type() << ", removed from " << square << endl;
        };

        board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << piece.type() << ", moving from " << from << " to " << to << endl;
        };

        board.on_game_lost = [](ChessBoard::Color color) {
            if (color == ChessBoard::Color::BLACK) {
                cout << "Black";
            } else {
                cout << "White";
            }
            cout << ", lost the game!" << endl;
        };

        board.piece_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << "Cannot move " << piece.type() << " from " << from << " to " << to << endl;
        };

        board.piece_missing = [](const string &square) {
            cout << "no piece at " << square << endl;
        };

    }
};

int main() {
    ChessBoard board;
    ChessBoardPrint chessBoardPrint(board);

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
}