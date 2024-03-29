#include <iostream>
#include <memory>
#include <string>
#include <vector>

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

    virtual std::string print_piece() const = 0;
  };

  class King : public Piece {
    public:
        King(ChessBoard::Color color) : Piece(color) {}

        virtual std::string type() const override {
            return this->color_string() + " King";
        }

        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            if (abs(from_x - to_x) == 1 || abs(from_y - to_y) == 1 || (abs(from_x - to_x) == 1 && abs(from_y - to_y))) {
                return true;
            } else {
                return false;
            }
        }

        virtual std::string print_piece() const override {
            std::string color(1, this->color_string()[0]);
            return color + "k";
        }
  };

  class Knight : public Piece {
      public:
        Knight(ChessBoard::Color color) : Piece(color) {}

        virtual std::string type() const override {
            return this->color_string() + " Knight";
        }

        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            if ((from_x - to_x == 2 || from_x - to_x == -2) && (from_y - to_y == 1 || from_y - to_y == -1)) {
                return true;
            }
            else if((from_x - to_x == 1 || from_x - to_x == -1) && (from_y - to_y == 2 || from_y - to_y == -2)) {
                return true;
            } else {
                return false;
            }
        }

        virtual std::string print_piece() const override {
            std::string color(1, this->color_string()[0]);
            return color + "kn";
        }
  };

  ChessBoard() {
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  vector<vector<unique_ptr<Piece>>> squares;

  void print_piece() {
      for (size_t i = squares.size()-1; i + 1 > 0; i--) {
            cout << "  " << i+1 << "  ";
            for (size_t j = 0; j < squares.at(i).size(); j++) {
                if (!squares.at(j).at(i)) {
                    cout << "  - ";
                } else {
                    auto &piece = squares.at(j).at(i);
                    cout << " " << piece->print_piece() << " ";
                }
            }
            cout << endl;
        }
        cout << "       A   B   C   D   E    F   G   H \n" << endl;
  }

  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
        cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            cout << piece_to->type() << " is being removed from " << to << endl;
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              cout << king->color_string() << " lost the game" << endl;
          } else {
            cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
            return false;
          }
        }
        piece_to = move(piece_from);
        return true;
      } else {
        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
        return false;
      }
    } else {
      cout << "no piece at " << from << endl;
      return false;
    }
  }
};

int main() {
  ChessBoard board;

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  board.print_piece();
  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.print_piece();
  board.move_piece("g8", "h6");
  board.print_piece();
  board.move_piece("b1", "c3");
  board.print_piece();
  board.move_piece("h6", "g8");
  board.print_piece();
  board.move_piece("c3", "d5");
  board.print_piece();
  board.move_piece("g8", "h6");
  board.print_piece();
  board.move_piece("d5", "f6");
  board.print_piece();
  board.move_piece("h6", "g8");
  board.print_piece();
  board.move_piece("f6", "e8");
  board.print_piece();
}