#ifndef CHESS_H
#define CHESS_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QStackedLayout>
#include <QLabel>
#include <QPropertyAnimation>
#include <QMenuBar>
#include <QMenu>
#include <QPair>

namespace Ui {
    class chess;
}

class chess : public QMainWindow
{
    Q_OBJECT

public:
    explicit chess(QWidget* parent = nullptr);
    ~chess();

private slots:
    void newGame();
    void resign();
    void makeAIMove();

private:
    Ui::chess* ui;

    // Board state
    QString boardState[8][8];
    QPushButton* boardButtons[8][8];
    int selectedRow;
    int selectedCol;
    bool isWhiteTurn;
    int moveCount;
    int whiteKingRow;
    int whiteKingCol;
    int blackKingRow;
    int blackKingCol;

    // UI elements
    QWidget* boardWidget;
    QGridLayout* outerLayout;
    QGridLayout* boardLayout;

    // Game functions
    void initializeBoard();
    void setupUI();
    void setupBoard();
    void setInitialPosition();
    void updateSquareIcon(int row, int col);
    void handleSquareClick(int row, int col);
    void selectPiece(int row, int col);
    void deselectPiece();
    void makeMove(int fromRow, int fromCol, int toRow, int toCol);
    void checkGameEnd();
    void clearHighlights();
    void highlightLegalMoves(int row, int col);
    bool isSquareAttacked(int row, int col, bool byWhite);
    bool isInCheck(bool white);
    bool isLegalMove(int fromRow, int fromCol, int toRow, int toCol);
    bool isCheckmate();
    bool isStalemate();
    void applyMove(const QPair<QPair<int, int>, QPair<int, int>>& move, QString capturedPiece);
    void undoMove(const QPair<QPair<int, int>, QPair<int, int>>& move, QString capturedPiece);
    int evaluatePosition();
    QList<QPair<QPair<int, int>, QPair<int, int>>> generateMoves();
    int minimax(int depth, bool isMaximizingPlayer, int alpha, int beta, int& nodesEvaluated);
    void animateMove(int fromRow, int fromCol, int toRow, int toCol);
};

#endif // CHESS_H