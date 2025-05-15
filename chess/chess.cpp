#include "chess.h"
#include "ui_chess.h"
#include <QTimer>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <algorithm>

const int PawnValue = 100;
const int KnightValue = 320;
const int BishopValue = 330;
const int RookValue = 500;
const int QueenValue = 900;
const int KingValue = 20000;
const int CellSize = 80;

chess::chess(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::chess),
    selectedRow(-1),
    selectedCol(-1),
    isWhiteTurn(true),
    moveCount(0),
    whiteKingRow(7),
    whiteKingCol(4),
    blackKingRow(0),
    blackKingCol(4),
    boardWidget(nullptr),
    outerLayout(nullptr),
    boardLayout(nullptr)
{
    ui->setupUi(this);
    initializeBoard();
    setupUI();
    setupBoard();  // Added this missing call
    setInitialPosition();
}

chess::~chess()
{
    delete ui;
}

void chess::initializeBoard()
{
    boardWidget = new QWidget(this);
    outerLayout = new QGridLayout(boardWidget);
    boardLayout = new QGridLayout();
    boardLayout->setSpacing(0);
    boardLayout->setContentsMargins(0, 0, 0, 0);
    outerLayout->addLayout(boardLayout, 0, 0, 1, 1);
    boardWidget->setFixedSize(CellSize * 8, CellSize * 8);
}

void chess::setupUI()
{
    QWidget* central = new QWidget(this);
    QVBoxLayout* centerLayout = new QVBoxLayout(central);
    centerLayout->addStretch();
    centerLayout->addWidget(boardWidget, 0, Qt::AlignCenter);
    centerLayout->addStretch();
    central->setLayout(centerLayout);
    setCentralWidget(central);

    // Menu bar
    QMenuBar* menuBar = new QMenuBar(this);
    QMenu* gameMenu = menuBar->addMenu("Game");
    QAction* newGameAction = gameMenu->addAction("New Game");
    QAction* resignAction = gameMenu->addAction("Resign");
    QAction* quitAction = gameMenu->addAction("Quit");

    connect(newGameAction, &QAction::triggered, this, &chess::newGame);
    connect(resignAction, &QAction::triggered, this, &chess::resign);
    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

    setMenuBar(menuBar);
}

void chess::setupBoard()
{
    QString files = "abcdefgh";

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QWidget* squareWidget = new QWidget(this);
            QStackedLayout* stack = new QStackedLayout(squareWidget);
            stack->setStackingMode(QStackedLayout::StackAll);
            stack->setContentsMargins(0, 0, 0, 0);

            QPushButton* btn = new QPushButton(squareWidget);
            btn->setFixedSize(CellSize, CellSize);
            QString color = ((row + col) % 2 == 0) ? "#eeeed2" : "#769656";
            btn->setStyleSheet(QString("background-color: %1; border: none;").arg(color));
            connect(btn, &QPushButton::clicked, [=]() { handleSquareClick(row, col); });

            boardButtons[row][col] = btn;

            QLabel* coordLabel = new QLabel(squareWidget);
            QString file = QString(files[col]);
            QString rank = QString::number(8 - row);
            QString labelText = file + rank;
            QString textColor = ((row + col) % 2 == 0) ? "#333" : "#f0f0f0";

            coordLabel->setText(labelText);
            coordLabel->setStyleSheet(QString("font: bold 10px; color: %1;").arg(textColor));
            coordLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
            coordLabel->setFixedSize(CellSize, CellSize);
            coordLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
            coordLabel->setMargin(4);

            stack->addWidget(btn);
            stack->addWidget(coordLabel);
            squareWidget->setLayout(stack);

            boardLayout->addWidget(squareWidget, row, col);
        }
    }
}

// [Rest of the implementation remains the same as in your original chess.cpp]
// Continue with all the other methods exactly as you had them...

void chess::setInitialPosition()
{
    QString initBoard[8][8] = {
        {"br", "bn", "bb", "bq", "bk", "bb", "bn", "br"},
        {"bp", "bp", "bp", "bp", "bp", "bp", "bp", "bp"},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"wp", "wp", "wp", "wp", "wp", "wp", "wp", "wp"},
        {"wr", "wn", "wb", "wq", "wk", "wb", "wn", "wr"}
    };

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            boardState[row][col] = initBoard[row][col];
            if (boardState[row][col] == "wk") {
                whiteKingRow = row;
                whiteKingCol = col;
            }
            else if (boardState[row][col] == "bk") {
                blackKingRow = row;
                blackKingCol = col;
            }
            updateSquareIcon(row, col);
        }
    }

    selectedRow = selectedCol = -1;
    isWhiteTurn = true;
    moveCount = 0;
}

void chess::newGame()
{
    setInitialPosition();
    clearHighlights();
}

void chess::resign()
{
    QString winner = isWhiteTurn ? "Black" : "White";
    QMessageBox::information(this, "Game Over", winner + " wins by resignation!");
    newGame();
}

void chess::updateSquareIcon(int row, int col)
{
    if (row < 0 || row >= 8 || col < 0 || col >= 8) return;

    QString piece = boardState[row][col];
    QPushButton* btn = boardButtons[row][col];

    if (piece.isEmpty()) {
        btn->setIcon(QIcon());
        btn->setText("");
    }
    else {
        QString path = QString(":/chess_pieces/%1.png").arg(piece);
        QIcon icon(path);
        btn->setIcon(icon);
        btn->setIconSize(QSize(64, 64));
        if (icon.isNull()) {
            btn->setText(piece);
        }
        else {
            btn->setText("");
        }
    }

    QString color = ((row + col) % 2 == 0) ? "#eeeed2" : "#769656";
    QString border = (row == selectedRow && col == selectedCol) ? "border: 2px solid yellow;" : "border: none;";
    btn->setStyleSheet(QString("background-color: %1; %2").arg(color).arg(border));
}



void chess::handleSquareClick(int row, int col)
{
    QString piece = boardState[row][col];

    if (selectedRow == -1) {
        if (!piece.isEmpty() && ((isWhiteTurn && piece[0] == 'w') || (!isWhiteTurn && piece[0] == 'b'))) {
            selectPiece(row, col);
        }
    }
    else {
        if (row == selectedRow && col == selectedCol) {
            deselectPiece();
        }
        else if (isLegalMove(selectedRow, selectedCol, row, col)) {
            makeMove(selectedRow, selectedCol, row, col);
        }
        else if (!piece.isEmpty() && ((isWhiteTurn && piece[0] == 'w') || (!isWhiteTurn && piece[0] == 'b'))) {
            deselectPiece();
            selectPiece(row, col);
        }
    }
}

void chess::selectPiece(int row, int col)
{
    selectedRow = row;
    selectedCol = col;
    clearHighlights();
    boardButtons[row][col]->setStyleSheet(
        QString("background-color: %1; border: 2px solid yellow;")
        .arg(((row + col) % 2 == 0) ? "#eeeed2" : "#769656"));
    highlightLegalMoves(row, col);
}

void chess::deselectPiece()
{
    clearHighlights();
    selectedRow = selectedCol = -1;
}

void chess::makeMove(int fromRow, int fromCol, int toRow, int toCol)
{
    QString capturedPiece = boardState[toRow][toCol];
    applyMove({ {fromRow, fromCol}, {toRow, toCol} }, capturedPiece);
    isWhiteTurn = !isWhiteTurn;
    moveCount++;

    // Clear selection and highlights after move
    deselectPiece();  // Add this line
    clearHighlights(); // Add this line

    checkGameEnd();

    if (!isWhiteTurn) {
        QTimer::singleShot(500, this, &chess::makeAIMove);
    }
}

void chess::checkGameEnd()
{
    if (isCheckmate()) {
        QString winner = isWhiteTurn ? "Black" : "White";
        QMessageBox::information(this, "Game Over", winner + " wins by checkmate!");
        newGame();
    }
    else if (isStalemate()) {
        QMessageBox::information(this, "Game Over", "Draw by stalemate!");
        newGame();
    }
}

void chess::clearHighlights()
{
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QString color = ((row + col) % 2 == 0) ? "#eeeed2" : "#769656";
            QString border = (row == selectedRow && col == selectedCol) ? "border: 2px solid yellow;" : "border: none;";
            boardButtons[row][col]->setStyleSheet(QString("background-color: %1; %2").arg(color).arg(border));
        }
    }
}

void chess::highlightLegalMoves(int row, int col)
{
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            if (isLegalMove(row, col, r, c)) {
                QString baseColor = ((r + c) % 2 == 0) ? "#eeeed2" : "#769656";
                boardButtons[r][c]->setStyleSheet(
                    QString("background-color: %1; border: 2px solid rgba(0, 255, 0, 0.5);")
                    .arg(baseColor));
            }
        }
    }
}

bool chess::isSquareAttacked(int row, int col, bool byWhite)
{
    // Check pawn attacks
    int pawnDir = byWhite ? 1 : -1;
    if (row - pawnDir >= 0 && row - pawnDir < 8) {
        if (col - 1 >= 0) {
            QString piece = boardState[row - pawnDir][col - 1];
            if (!piece.isEmpty() && piece[0] == (byWhite ? 'w' : 'b') && piece[1] == 'p') {
                return true;
            }
        }
        if (col + 1 < 8) {
            QString piece = boardState[row - pawnDir][col + 1];
            if (!piece.isEmpty() && piece[0] == (byWhite ? 'w' : 'b') && piece[1] == 'p') {
                return true;
            }
        }
    }

    // Check knight attacks
    int knightMoves[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };
    for (const auto& move : knightMoves) {
        int r = row + move[0];
        int c = col + move[1];
        if (r >= 0 && r < 8 && c >= 0 && c < 8) {
            QString piece = boardState[r][c];
            if (!piece.isEmpty() && piece[0] == (byWhite ? 'w' : 'b') && piece[1] == 'n') {
                return true;
            }
        }
    }

    // Check bishop/queen diagonal attacks
    int diagDirs[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
    for (const auto& dir : diagDirs) {
        int r = row + dir[0];
        int c = col + dir[1];
        while (r >= 0 && r < 8 && c >= 0 && c < 8) {
            QString piece = boardState[r][c];
            if (!piece.isEmpty()) {
                if (piece[0] == (byWhite ? 'w' : 'b') && (piece[1] == 'b' || piece[1] == 'q')) {
                    return true;
                }
                break;
            }
            r += dir[0];
            c += dir[1];
        }
    }

    // Check rook/queen straight attacks
    int straightDirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (const auto& dir : straightDirs) {
        int r = row + dir[0];
        int c = col + dir[1];
        while (r >= 0 && r < 8 && c >= 0 && c < 8) {
            QString piece = boardState[r][c];
            if (!piece.isEmpty()) {
                if (piece[0] == (byWhite ? 'w' : 'b') && (piece[1] == 'r' || piece[1] == 'q')) {
                    return true;
                }
                break;
            }
            r += dir[0];
            c += dir[1];
        }
    }

    // Check king attacks
    int kingMoves[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
    for (const auto& move : kingMoves) {
        int r = row + move[0];
        int c = col + move[1];
        if (r >= 0 && r < 8 && c >= 0 && c < 8) {
            QString piece = boardState[r][c];
            if (!piece.isEmpty() && piece[0] == (byWhite ? 'w' : 'b') && piece[1] == 'k') {
                return true;
            }
        }
    }

    return false;
}

bool chess::isInCheck(bool white)
{
    int kingRow = white ? whiteKingRow : blackKingRow;
    int kingCol = white ? whiteKingCol : blackKingCol;
    return isSquareAttacked(kingRow, kingCol, !white);
}

bool chess::isLegalMove(int fromRow, int fromCol, int toRow, int toCol)
{
    QString piece = boardState[fromRow][fromCol];
    if (piece.isEmpty()) return false;

    bool isWhitePiece = piece[0] == 'w';
    if (isWhitePiece != isWhiteTurn) return false;

    QString target = boardState[toRow][toCol];
    if (!target.isEmpty() && target[0] == piece[0]) return false;

    char type = piece[1].toLatin1();
    int dr = toRow - fromRow;
    int dc = toCol - fromCol;

    bool moveValid = false;
    switch (type) {
    case 'p': {
        int forward = isWhitePiece ? -1 : 1;
        if (dc == 0 && target.isEmpty()) {
            if (dr == forward) {
                moveValid = true;
            }
            else if (dr == 2 * forward && fromRow == (isWhitePiece ? 6 : 1)) {
                moveValid = boardState[fromRow + forward][fromCol].isEmpty();
            }
        }
        else if (abs(dc) == 1 && dr == forward && !target.isEmpty()) {
            moveValid = true;
        }
        break;
    }
    case 'n': {
        moveValid = (abs(dr) == 2 && abs(dc) == 1) || (abs(dr) == 1 && abs(dc) == 2);
        break;
    }
    case 'b': {
        if (abs(dr) == abs(dc)) {
            int stepR = dr > 0 ? 1 : -1;
            int stepC = dc > 0 ? 1 : -1;
            int r = fromRow + stepR;
            int c = fromCol + stepC;
            moveValid = true;
            while (r != toRow) {
                if (!boardState[r][c].isEmpty()) {
                    moveValid = false;
                    break;
                }
                r += stepR;
                c += stepC;
            }
        }
        break;
    }
    case 'r': {
        if (dr == 0 || dc == 0) {
            int stepR = dr == 0 ? 0 : (dr > 0 ? 1 : -1);
            int stepC = dc == 0 ? 0 : (dc > 0 ? 1 : -1);
            int r = fromRow + stepR;
            int c = fromCol + stepC;
            moveValid = true;
            while (r != toRow || c != toCol) {
                if (!boardState[r][c].isEmpty()) {
                    moveValid = false;
                    break;
                }
                r += stepR;
                c += stepC;
            }
        }
        break;
    }
    case 'q': {
        if (abs(dr) == abs(dc)) {
            int stepR = dr > 0 ? 1 : -1;
            int stepC = dc > 0 ? 1 : -1;
            int r = fromRow + stepR;
            int c = fromCol + stepC;
            moveValid = true;
            while (r != toRow) {
                if (!boardState[r][c].isEmpty()) {
                    moveValid = false;
                    break;
                }
                r += stepR;
                c += stepC;
            }
        }
        else if (dr == 0 || dc == 0) {
            int stepR = dr == 0 ? 0 : (dr > 0 ? 1 : -1);
            int stepC = dc == 0 ? 0 : (dc > 0 ? 1 : -1);
            int r = fromRow + stepR;
            int c = fromCol + stepC;
            moveValid = true;
            while (r != toRow || c != toCol) {
                if (!boardState[r][c].isEmpty()) {
                    moveValid = false;
                    break;
                }
                r += stepR;
                c += stepC;
            }
        }
        break;
    }
    case 'k': {
        moveValid = abs(dr) <= 1 && abs(dc) <= 1;
        if (!moveValid && abs(dc) == 2 && dr == 0) {
            if (isWhitePiece) {
                if (fromRow == 7 && fromCol == 4 && !isInCheck(true)) {
                    if (dc == 2 && toCol == 6 && boardState[7][5].isEmpty() && boardState[7][6].isEmpty() &&
                        boardState[7][7] == "wr" && !isSquareAttacked(7, 5, false)) {
                        moveValid = true;
                    }
                    else if (dc == -2 && toCol == 2 && boardState[7][3].isEmpty() && boardState[7][2].isEmpty() &&
                        boardState[7][0] == "wr" && !isSquareAttacked(7, 3, false)) {
                        moveValid = true;
                    }
                }
            }
            else {
                if (fromRow == 0 && fromCol == 4 && !isInCheck(false)) {
                    if (dc == 2 && toCol == 6 && boardState[0][5].isEmpty() && boardState[0][6].isEmpty() &&
                        boardState[0][7] == "br" && !isSquareAttacked(0, 5, true)) {
                        moveValid = true;
                    }
                    else if (dc == -2 && toCol == 2 && boardState[0][3].isEmpty() && boardState[0][2].isEmpty() &&
                        boardState[0][0] == "br" && !isSquareAttacked(0, 3, true)) {
                        moveValid = true;
                    }
                }
            }
        }
        break;
    }
    default:
        return false;
    }

    if (!moveValid) return false;

    QString capturedPiece = boardState[toRow][toCol];
    boardState[toRow][toCol] = piece;
    boardState[fromRow][fromCol] = "";

    if (piece == "wk") {
        whiteKingRow = toRow;
        whiteKingCol = toCol;
    }
    else if (piece == "bk") {
        blackKingRow = toRow;
        blackKingCol = toCol;
    }

    bool inCheck = isInCheck(isWhitePiece);

    boardState[fromRow][fromCol] = piece;
    boardState[toRow][toCol] = capturedPiece;
    if (piece == "wk") {
        whiteKingRow = fromRow;
        whiteKingCol = fromCol;
    }
    else if (piece == "bk") {
        blackKingRow = fromRow;
        blackKingCol = fromCol;
    }

    return !inCheck;
}

bool chess::isCheckmate()
{
    if (!isInCheck(isWhiteTurn)) return false;

    for (int fromRow = 0; fromRow < 8; ++fromRow) {
        for (int fromCol = 0; fromCol < 8; ++fromCol) {
            QString piece = boardState[fromRow][fromCol];
            if (!piece.isEmpty() && piece[0] == (isWhiteTurn ? 'w' : 'b')) {
                for (int toRow = 0; toRow < 8; ++toRow) {
                    for (int toCol = 0; toCol < 8; ++toCol) {
                        if (isLegalMove(fromRow, fromCol, toRow, toCol)) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

bool chess::isStalemate()
{
    if (isInCheck(isWhiteTurn)) return false;

    for (int fromRow = 0; fromRow < 8; ++fromRow) {
        for (int fromCol = 0; fromCol < 8; ++fromCol) {
            QString piece = boardState[fromRow][fromCol];
            if (!piece.isEmpty() && piece[0] == (isWhiteTurn ? 'w' : 'b')) {
                for (int toRow = 0; toRow < 8; ++toRow) {
                    for (int toCol = 0; toCol < 8; ++toCol) {
                        if (isLegalMove(fromRow, fromCol, toRow, toCol)) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

void chess::applyMove(const QPair<QPair<int, int>, QPair<int, int>>& move, QString capturedPiece)
{
    int fromRow = move.first.first;
    int fromCol = move.first.second;
    int toRow = move.second.first;
    int toCol = move.second.second;

    QString piece = boardState[fromRow][fromCol];

    // Handle castling
    if (piece == "wk" && fromRow == 7 && fromCol == 4) {
        if (toCol == 6) { // Kingside
            boardState[7][5] = boardState[7][7];
            boardState[7][7] = "";
            updateSquareIcon(7, 7);
            updateSquareIcon(7, 5);
        }
        else if (toCol == 2) { // Queenside
            boardState[7][3] = boardState[7][0];
            boardState[7][0] = "";
            updateSquareIcon(7, 0);
            updateSquareIcon(7, 3);
        }
    }
    else if (piece == "bk" && fromRow == 0 && fromCol == 4) {
        if (toCol == 6) { // Kingside
            boardState[0][5] = boardState[0][7];
            boardState[0][7] = "";
            updateSquareIcon(0, 7);
            updateSquareIcon(0, 5);
        }
        else if (toCol == 2) { // Queenside
            boardState[0][3] = boardState[0][0];
            boardState[0][0] = "";
            updateSquareIcon(0, 0);
            updateSquareIcon(0, 3);
        }
    }

    // Handle pawn promotion
    if (piece[1] == 'p' && ((piece[0] == 'w' && toRow == 0) || (piece[0] == 'b' && toRow == 7))) {
        piece = QString("%1q").arg(piece[0]);
    }

    boardState[toRow][toCol] = piece;
    boardState[fromRow][fromCol] = "";

    if (piece == "wk") {
        whiteKingRow = toRow;
        whiteKingCol = toCol;
    }
    else if (piece == "bk") {
        blackKingRow = toRow;
        blackKingCol = toCol;
    }

    updateSquareIcon(fromRow, fromCol);
    updateSquareIcon(toRow, toCol);
}

void chess::undoMove(const QPair<QPair<int, int>, QPair<int, int>>& move, QString capturedPiece)
{
    int fromRow = move.first.first;
    int fromCol = move.first.second;
    int toRow = move.second.first;
    int toCol = move.second.second;

    QString piece = boardState[toRow][toCol];
    boardState[fromRow][fromCol] = piece;
    boardState[toRow][toCol] = capturedPiece;

    if (piece == "wk") {
        whiteKingRow = fromRow;
        whiteKingCol = fromCol;
    }
    else if (piece == "bk") {
        blackKingRow = fromRow;
        blackKingCol = fromCol;
    }

    updateSquareIcon(fromRow, fromCol);
    updateSquareIcon(toRow, toCol);
}

int chess::evaluatePosition()
{
    int score = 0;

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QString piece = boardState[row][col];
            if (piece.isEmpty()) continue;

            int value = 0;
            char type = piece[1].toLatin1();
            switch (type) {
            case 'p': value = PawnValue; break;
            case 'n': value = KnightValue; break;
            case 'b': value = BishopValue; break;
            case 'r': value = RookValue; break;
            case 'q': value = QueenValue; break;
            case 'k': value = KingValue; break;
            }
            score += (piece[0] == 'w' ? value : -value);

            if (type == 'p') {
                if (piece[0] == 'w') {
                    score += (7 - row) * 5;
                    if (col == 3 || col == 4) score += 15;
                }
                else {
                    score -= row * 5;
                    if (col == 3 || col == 4) score -= 15;
                }
            }
            else if (type == 'n') {
                if (row >= 2 && row <= 5 && col >= 2 && col <= 5) {
                    score += (piece[0] == 'w' ? 20 : -20);
                }
            }
        }
    }

    if (isInCheck(true)) score -= 50;
    if (isInCheck(false)) score += 50;

    return score;
}

QList<QPair<QPair<int, int>, QPair<int, int>>> chess::generateMoves()
{
    QList<QPair<QPair<int, int>, QPair<int, int>>> moves;

    for (int fromRow = 0; fromRow < 8; ++fromRow) {
        for (int fromCol = 0; fromCol < 8; ++fromCol) {
            QString piece = boardState[fromRow][fromCol];
            if (piece.isEmpty() || (piece[0] == 'w') != isWhiteTurn) continue;

            for (int toRow = 0; toRow < 8; ++toRow) {
                for (int toCol = 0; toCol < 8; ++toCol) {
                    if (isLegalMove(fromRow, fromCol, toRow, toCol)) {
                        moves.append({ {fromRow, fromCol}, {toRow, toCol} });
                    }
                }
            }
        }
    }

    return moves;
}

int chess::minimax(int depth, bool isMaximizingPlayer, int alpha, int beta, int& nodesEvaluated)
{
    nodesEvaluated++;
    if (nodesEvaluated > 5000) {
        return evaluatePosition();
    }

    if (depth == 0 || isCheckmate() || isStalemate()) {
        return evaluatePosition();
    }

    QList<QPair<QPair<int, int>, QPair<int, int>>> moves = generateMoves();
    if (moves.isEmpty()) {
        return evaluatePosition();
    }

    if (isMaximizingPlayer) {
        int maxEval = -1000000;
        for (const auto& move : moves) {
            QString capturedPiece = boardState[move.second.first][move.second.second];
            applyMove(move, capturedPiece);
            int eval = minimax(depth - 1, false, alpha, beta, nodesEvaluated);
            undoMove(move, capturedPiece);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) break;
        }
        return maxEval;
    }
    else {
        int minEval = 1000000;
        for (const auto& move : moves) {
            QString capturedPiece = boardState[move.second.first][move.second.second];
            applyMove(move, capturedPiece);
            int eval = minimax(depth - 1, true, alpha, beta, nodesEvaluated);
            undoMove(move, capturedPiece);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) break;
        }
        return minEval;
    }
}

void chess::makeAIMove()
{
    QList<QPair<QPair<int, int>, QPair<int, int>>> moves = generateMoves();
    if (moves.isEmpty()) return;

    // Simple immediate move if in check
    if (isInCheck(false)) {
        for (const auto& move : moves) {
            QString piece = boardState[move.first.first][move.first.second];
            if (piece == "bk") {
                animateMove(move.first.first, move.first.second, move.second.first, move.second.second);
                isWhiteTurn = !isWhiteTurn;
                checkGameEnd();
                return;
            }
        }
    }

    // Limit search depth and nodes
    int bestEval = 1000000;
    QPair<QPair<int, int>, QPair<int, int>> bestMove = moves.first();
    int nodesEvaluated = 0;

    for (const auto& move : moves) {
        if (nodesEvaluated > 1000) break; // Limit nodes

        QString capturedPiece = boardState[move.second.first][move.second.second];
        applyMove(move, capturedPiece);
        int eval = evaluatePosition(); // Immediate evaluation instead of minimax
        undoMove(move, capturedPiece);

        if (eval < bestEval) {
            bestEval = eval;
            bestMove = move;
        }
        nodesEvaluated++;
    }

    animateMove(bestMove.first.first, bestMove.first.second, bestMove.second.first, bestMove.second.second);
    isWhiteTurn = !isWhiteTurn;
    checkGameEnd();
}

void chess::animateMove(int fromRow, int fromCol, int toRow, int toCol)
{
    QPushButton* fromBtn = boardButtons[fromRow][fromCol];
    QPushButton* toBtn = boardButtons[toRow][toCol];

    // Create a temporary button for animation
    QPushButton* tempBtn = new QPushButton(boardWidget);
    tempBtn->setFixedSize(CellSize, CellSize);
    tempBtn->setIcon(fromBtn->icon());
    tempBtn->setIconSize(fromBtn->iconSize());
    tempBtn->move(fromCol * CellSize, fromRow * CellSize);
    tempBtn->show();

    QPropertyAnimation* animation = new QPropertyAnimation(tempBtn, "pos", this);
    animation->setDuration(300);
    animation->setStartValue(tempBtn->pos());
    animation->setEndValue(QPoint(toCol * CellSize, toRow * CellSize));

    connect(animation, &QPropertyAnimation::finished, [=]() {
        QString capturedPiece = boardState[toRow][toCol];
        applyMove({ {fromRow, fromCol}, {toRow, toCol} }, capturedPiece);

        // Clean up
        tempBtn->deleteLater();
        delete animation;

        // Ensure buttons are in correct state
        updateSquareIcon(fromRow, fromCol);
        updateSquareIcon(toRow, toCol);
        });

    animation->start();
}