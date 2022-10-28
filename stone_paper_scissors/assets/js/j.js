const score1 = document.querySelector('[data-score1]')
const score2 = document.querySelector('[data-score2]')

const score3 = document.querySelector('[data-score3]')
const score4 = document.querySelector('[data-score4]')


const finalColumn = document.querySelector('[data-final-column]')

const Buttons = document.querySelectorAll('[data-part]')
// console.log(parseInt(score1.innerText));

var val = [
    {
       name: '1',
       value: 'a',
       wins: 0
    },
    {
        name: '2' ,
        value: 'a',
        wins: 0
    },
    {
        name: '3' ,
        value: 'a',
        wins: 0
    },
    {
        name: '4' ,
        value: 'a',
        wins: 0
    },
]

const SELECTIONS = [
    {
      name: 'rock',
      
      beats: 'scissors'
    },
    {
      name: 'paper',
      
      beats: 'rock'
    },
    {
      name: 'scissors',
      
      beats: 'paper'
    }
  ]

  val.forEach(selectionButton => {
    // let i = 0;
    const computerSelection = randomSelection() 
    if(selectionButton.value === 'a'){
        selectionButton.value = computerSelection;
    }
    
  })
  val.forEach(call => {
    check(call);
    // addSelectionResult(computerSelection, computerWinner)
    // addSelectionResult(selection, yourWinner)
  })
  function check(player_beat){
    val.forEach(selection => {
        //   let p1 = selection.name;
        // selection.value
        // console.log(val[1].name)
        // if(selection.value.name === player_beat.value.name){
        //     continue
        // }
         console.log(selection.value.name === player_beat.value.beats);
         let ans = (selection.value.name === player_beat.value.beats);
        //  if(ans){
        //     if()
        //  }
        //  let s = Buttons.find(x => x.dataset.selection == selection[0].name)
        //  if(selection[0].name ===  s)
         addSelectionResult(selection , ans);
        //  return selection.value.name === player_beat.value.beats;
    
      })
  }

  function randomSelection() {
    const randomIndex = Math.floor(Math.random() * SELECTIONS.length);
    return SELECTIONS[randomIndex];
  };

  
//   function isWinner(player) {
//     val.forEach(member => {
//         // if(member.name === player){
//         //     continue;
//         // }
//         // else if()
//         return player === member.val;

//     })
//   }


function incrementWins(val) {
  val.wins = val.wins + 1
  console.log(val.wins)
}



function addSelectionResult(selection, winner) {
  const div = document.createElement('div')
  const div2 = document.createElement('div')

  // div.innerText = selection.value.name
  div.innerText = JSON.stringify(selection.value.name)

  div2.innerText = JSON.stringify(selection.wins)

  // let y;
//   val.forEach(t => {
//     if(t.name === selection.name){
//         y = 
//     }
//   })
// if()
  div.classList.add('result-selection')
  div2.classList.add('result-selection')

  if (winner){
    div.classList.add('winner');
  div2.classList.add('winner')

    incrementWins(selection)
    // console.log(parseInt(selection.wins))
  } 
//   console.log(selection.name)
//   console.log(score1.innerText)

  if(selection.name == score1.innerText){
    score1.after(div)
    score1.after(div2)
    
  }
  if(selection.name == score2.innerText){
    score2.after(div)
    score2.after(div2)

  }
  if(selection.name == score3.innerText){
    score3.after(div)
    score3.after(div2)

  }
  if(selection.name == score4.innerText){
    score4.after(div)
    score4.after(div2)

  }
//   finalColumn.after(div)
}

// const score1 = document.querySelector('[data-score1]')
