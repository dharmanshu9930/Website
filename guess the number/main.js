let mode = document.querySelector(".mode");
let modeImg = document.querySelector(".mode img");
let popUp = document.querySelector(".mask");
let playBtn = document.querySelector(".play");
let rePlayBtn = document.querySelector(".replay");
let confirmBtn = document.querySelector(".confirm");
let radioBtn = document.querySelectorAll("input[name = 'range']");
let inputNumber = document.querySelector("#input-number");
let icon = document.querySelector(".fa-solid");
let info = document.querySelector(".info");
let moreSugg = document.querySelector(".more-suggetion");
let closeSugg = document.querySelector(".fa-xmark"); 
let hintsInfo = document.querySelector(".more-info");
let radioVlaue;
let randomNumber;
let lifes, hints;
let numberHint = 0;
mode.addEventListener("click", () => {
    if (modeImg.src == "http://127.0.0.1:5500/img/light_mode_FILL0_wght400_GRAD0_opsz48.svg") {
        modeImg.src ="http://127.0.0.1:5500/img/dark_mode_FILL0_wght400_GRAD0_opsz48.svg";
        darkMode();
  } else {
        modeImg.src = "http://127.0.0.1:5500/img/light_mode_FILL0_wght400_GRAD0_opsz48.svg";
        lightMode();
  }
});
window.onload = function() {
    popUp.classList.add("active");
}
rePlayBtn.addEventListener("click", () => {
    document.querySelector("main").firstChild.remove();
    playBtn.style.display = "block";
    popUp.classList.add("active");
    document.querySelector(".your-seggetion").innerHTML = "";
    document.querySelector(".heart").innerHTML = "";
    document.querySelector(".info").innerHTML = "";
    icon.classList.replace("fa-circle-check", "fa-circle-question");
    icon.classList.replace("fa-face-dizzy", "fa-circle-question");
    icon.classList.replace("fa-caret-down", "fa-circle-question");
    icon.classList.replace("fa-caret-up", "fa-circle-question");
    inputNumber.value = "";
    icon.style.color = "#E6E6E6";
    moreSugg.style.visibility = "hidden";
});
confirmBtn.addEventListener("click", () => {
    for (var radio of radioBtn){
        if (radio.checked) {
            radioVlaue =  radio.value;
            randomNumber = createRandomNumber(radioVlaue);
            console.log(randomNumber);
            popUp.classList.remove("active");
            // document.querySelector("main").children.remove();
            let title = document.createElement("h1");
            title.style.marginBottom = "20px";
            title.innerHTML = `Guess a Number Between 1 - ${radioVlaue}`;
            document.querySelector("main").prepend(title);
            lifes = lifesNumber();
            hints = hintNumber();
            createHeart(lifes);
        }
    }
    if (radioVlaue ==undefined) {
        alert("check a radio");
    }
});
playBtn.addEventListener("click", (e) => {
    changeIconRandom();
    removeHeart();
    checkRange();
    addSuggetion();
    createSuggetion();
    // runGameOver();
});
closeSugg.addEventListener("click", () => {
    moreSugg.style.visibility = "hidden";
    
})
function darkMode() {
  document.querySelector("main").style.backgroundColor = '#222222';
  document.querySelector(".suggetion").style.backgroundColor = '#666666';
  document.querySelector(".your-seggetion").style.backgroundColor = '#666666';
  document.querySelector(".your-seggetion").style.color = 'white';
  document.querySelector(".input-number").style.backgroundColor = '#666666';
    document.querySelector(".play").style.backgroundColor = 'rgb(29,39,85)';
    document.querySelector("h1").style.color = 'white';
    document.querySelector(".info").style.color = 'white';
}
function lightMode() {
    document.querySelector("main").style.backgroundColor = '#fff';
    document.querySelector(".suggetion").style.backgroundColor = 'rgb(211, 211, 211)';
    document.querySelector(".your-seggetion").style.backgroundColor = 'rgb(211, 211, 211)';
    document.querySelector(".your-seggetion").style.color = 'white';
    document.querySelector(".input-number").style.backgroundColor = 'rgb(211, 211, 211)';
    document.querySelector(".play").style.backgroundColor = 'rgb(42, 9, 189)';
    document.querySelector("h1").style.color = 'black';
    document.querySelector(".info").style.color = 'black';
}
function createRandomNumber(number) {
    return parseInt(Math.random() * (number - 1) + 1);
}
function changeIconRandom() {
    icon.classList.add("active");
    if (randomNumber ==inputNumber.value) {
        icon.classList.replace("fa-circle-question", "fa-circle-check");
        icon.classList.replace("fa-caret-up", "fa-circle-check");
        icon.classList.replace("fa-caret-down", "fa-circle-check");
        icon.style.color = "#24AA6B";
    } else if(randomNumber<inputNumber.value){
        icon.classList.replace("fa-circle-question", "fa-caret-down");
        icon.classList.replace("fa-caret-up", "fa-caret-down");
        icon.style.color = "#C22626";
    } else {
        icon.classList.replace("fa-circle-question", "fa-caret-up");
        icon.classList.replace("fa-caret-down", "fa-caret-up");
        icon.style.color = "#24AA6B";
    }
}
function removeHeart() {
    if (randomNumber != inputNumber.value) {
        document.querySelector(".fa-heart").parentNode.removeChild(document.querySelector(".fa-heart"));
    } 
}
function checkRange() {
    let t = inputNumber.value;
    if (t <1 || t>parseInt(radioVlaue)) {
        info.innerHTML = "out range";
        info.style.backgroundColor = "red";
        lifes--;
        if (lifes ===0) {
            gameOverFuntion();
        }
    } else {
        info.style.backgroundColor = "transparent";
        if (randomNumber ==inputNumber.value) {
            info.innerHTML = "Succes";
            removePlayBtn();
        } else if(randomNumber>inputNumber.value){
            info.innerHTML = "Your number is less";
            lifes--;
            if (lifes ===0) {
                gameOverFuntion();
            }
        } else if(randomNumber<inputNumber.value){
            info.innerHTML = "Your number is big";
            lifes--;
            if (lifes ===0) {
                gameOverFuntion();
            }
        } 
    }
}
function runGameOver(){
    if (document.querySelector(".heart").childElementCount !=0) {
        gameOverFuntion();
    }
}
function lifesNumber() {
    if (parseInt(radioVlaue) ==10) {
        return 2;
    } else if (parseInt(radioVlaue) ==50) {
        return 3;
    } else {
        return 4;
    }
}
function hintNumber() {
    if (parseInt(radioVlaue) ==10) {
        return 1;
    } else if (parseInt(radioVlaue) ==50) {
        return 2;
    } else {
        return 3;
    }
}

function createHeart(life) {
    for (let i = 0;i < life;i++){
        let heart = document.createElement("i");
        heart.classList.add("fa-solid");
        heart.classList.add("fa-heart");
        document.querySelector(".heart").appendChild(heart);
    }
}
function gameOverFuntion() {

        info.innerHTML = "Game over !!";
        icon.classList.replace("fa-circle-question", "fa-face-dizzy");
        icon.classList.replace("fa-caret-up", "fa-face-dizzy");
        icon.classList.replace("fa-caret-down", "fa-face-dizzy");
        icon.style.color = "#FFC83D";
        removePlayBtn();
    
    
}
function addSuggetion() {
    let number = document.createElement("div");
    number.classList.add("number");
    number.innerHTML = inputNumber.value;
    document.querySelector(".your-seggetion").appendChild(number);
}
function removePlayBtn() {
    playBtn.style.display = "none";
}
function visibleMoreSugg() {
    moreSugg.style.visibility = "visible";
}
function createSuggetion() {
    numberHint++;
    visibleMoreSugg();
    if (inputNumber.value !=randomNumber) {
        if (hints ==1) {
            if (randomNumber >=5) {
                hintsInfo.innerHTML = "the number between 4 and 10"
            } else {
                hintsInfo.innerHTML = "the number between 1 and 5"
                
            }
        } else if (hints == 2) {
            if (numberHint ==1) {
                if (randomNumber >=25) {
                    hintsInfo.innerHTML = "the number between 25 and 50"
                } else {
                    hintsInfo.innerHTML = "the number between 1 and 25"    
                }
            }
            if (numberHint ==2) {
                if (randomNumber %2 ==0) {
                    hintsInfo.innerHTML = "the number is even"
                } else {
                    hintsInfo.innerHTML = "the number is odd"    
                }
            }
            
        } else {
            if (numberHint ==1) {
                if (randomNumber >=50) {
                    hintsInfo.innerHTML = "the number between 50 and 100"
                } else {
                    hintsInfo.innerHTML = "the number between 1 and 50"
                    
                }
            }
            if (numberHint ==2) {
                if (randomNumber %2 ==0) {
                    hintsInfo.innerHTML = "the number is even"
                } else {
                    hintsInfo.innerHTML = "the number is odd"    
                }
            }
            if (numberHint ==3) {
                if (Prime(randomNumber)) {
                    hintsInfo.innerHTML = "the number is prime"
                } else {
                    hintsInfo.innerHTML = "the number is not prime"
                }
            }
            
        }
    }
}
function Prime(number) {
    if (number === 1) {
        return true
    }
    
    // check if number is greater than 1
    else if (number > 1) {
    
        // looping through 2 to number-1
        for (let i = 2;i < number;i++) {
            if (number % i == 0) {
                return false;
                break;
            }
        }
        return true;
    }
}