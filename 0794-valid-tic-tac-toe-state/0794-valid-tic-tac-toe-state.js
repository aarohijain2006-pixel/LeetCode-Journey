/**
 * @param {string[]} board
 * @return {boolean}
 */
var validTicTacToe = function(board) {
    let countO = 0;
    let countX = 0;
    for(let i=0; i<3; i++){
        for(let j=0; j<3; j++){
            if(board[i][j] === 'X')
               countX++;
            else if(board[i][j] === 'O')
               countO++;
        }
    }
    if (countX !== countO && countX !== countO + 1)
        return false;
    
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

    if(checkWinner('X') && checkWinner('O'))
       return false;
    if (checkWinner('X') && countX !== countO + 1)
        return false;
    if (checkWinner('O') && countO !== countX)
        return false;
    return true;
};