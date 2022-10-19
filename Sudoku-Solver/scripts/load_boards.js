const boards = {
    0: [0,0,0,0,1,7,2,0,0,0,0,0,4,0,0,0,0,0,0,0,9,0,0,3,0,0,0,4,0,0,7,8,0,5,0,0,0,2,5,0,0,0,8,0,0,0,0,0,6,0,0,0,0,0,6,0,1,5,0,0,0,0,0,0,0,0,0,0,6,0,3,0,2,0,0,0,0,1,7,0,4],
    1: [0,5,1,3,6,2,7,0,0,0,4,0,0,5,8,0,0,0,0,0,0,4,0,0,0,2,5,0,8,0,0,0,0,9,0,3,0,0,0,0,0,0,0,0,0,7,0,5,0,0,0,0,8,0,1,2,0,0,0,9,0,0,0,0,0,0,2,8,0,0,6,0,0,0,8,5,3,4,2,9,0]
}
const size = Object.keys(boards).length

export function loadRandomBoard() {
    const inputs = document.querySelectorAll('input')
    let index = Math.floor(Math.random()*size)
    let savedBoard = boards[index]
    
    for(let i=0; i<savedBoard.length; i++) {
        if(savedBoard[i] == 0) {
             inputs[i].value = ""
        } else {
            inputs[i].value = savedBoard[i]
        }
    }
    savedBoard = []
}