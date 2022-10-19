let board = []

export function insertValues() {
    const inputs = document.querySelectorAll('input')
    
    inputs.forEach((input) => {
        if(input.value) {
            board.push(parseInt(input.value))
            input.classList.add('input-el') 
        } else {
            board.push(0)
            input.classList.add('empty-el')
        }
    })
}

const indexToRowCol = (index) => { 
    return {row: Math.floor(index/9), col: index%9} 
}
const rowColToIndex = (row, col) => (row * 9 + col)

const acceptable = (board, index, value) => {
    let { row, col } = indexToRowCol(index)
    for (let r = 0; r < 9; ++r) {
        if (board[rowColToIndex(r, col)] == value) return false
    }
    for (let c = 0; c < 9; ++c) {
        if (board[rowColToIndex(row, c)] == value) return false
    }

    let r1 = Math.floor(row / 3) * 3
    let c1 = Math.floor(col / 3) * 3
    for (let r = r1; r < r1 + 3; ++r) {
        for (let c = c1; c < c1 + 3; ++c) {
            if (board[rowColToIndex(r, c)] == value) return false
        }
    }
    return true
}

const getChoices = (board, index) => {
    let choices = []
    for (let value = 1; value <= 9; ++value) {
        if (acceptable(board, index, value)) {
            choices.push(value)
        }
    }
    return choices
}

const bestBet = (board) => {
    let index, moves, bestLen = 100
    for (let i = 0; i < 81; ++i) {
        if (!board[i]) {
            let m = getChoices(board, i)
            if (m.length < bestLen) {
                bestLen = m.length
                moves = m
                index = i
                if (bestLen == 0) break
            }
        }
    }
    return { index, moves }
}

export const solve = () => {
    let { index, moves } = bestBet(board) 
    if (index == null) return true          
    for (let m of moves) {
        board[index] = m                  
        if (solve()) return true        
    }
    board[index] = 0
    return false
}

export function populateValues() {
    const inputs = document.querySelectorAll('input')
    inputs.forEach((input, i) => input.value = board[i])
}