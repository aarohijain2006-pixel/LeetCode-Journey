/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function(moves) {
    let board = [
        [' ', ' ', ' '],
        [' ', ' ', ' '],
        [' ', ' ', ' '],
    ]
    let n = moves.length;
    for(let i=0; i<n; i++){
        let row = moves[i][0];
        let col = moves[i][1];
        
        if(i%2 == 0){
            board[row][col] = 'X';
        }
        else{
            board[row][col] = 'O';
        }
    }
    
    let checkWinner = (ch) => {
        for(let i=0; i<3; i++){
            if (board[i][0] === ch &&
                board[i][1] === ch &&
                board[i][2] === ch)
                return true;
        }
        for(let i=0; i<3; i++){
            if (board[0][i] === ch &&
                board[1][i] === ch &&
                board[2][i] === ch)
                return true;
        }
        if(board[0][0] === ch &&
           board[1][1] === ch &&
           board[2][2] === ch)
           return true;
        if (board[0][2] === ch &&
            board[1][1] === ch &&
            board[2][0] === ch)
            return true;
        return false;
    };
    if(checkWinner('X'))
        return "A";
    if(checkWinner('O'))
        return "B";
    if(moves.length === 9)
        return "Draw";
    return "Pending";
};