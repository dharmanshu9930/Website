document.querySelectorAll("button").forEach((item, i) => {
  item.addEventListener("click", function() {

    playAudio(item.innerHTML);
    animate(item.innerHTML);
  })
});

document.addEventListener("keydown", function(e) {

  playAudio(e.key);
  animate(e.key);
})

function playAudio(c) {
  switch (c) {
    case "w":
      var audio = new Audio('sounds/tom-1.mp3');
      audio.play();
      break;

    case "a":
      var audio = new Audio('sounds/tom-2.mp3');
      audio.play();
      break;

    case "s":
      var audio = new Audio('sounds/tom-3.mp3');
      audio.play();
      break;

    case "d":
      var audio = new Audio('sounds/tom-4.mp3');
      audio.play();
      break;

    case "j":
      var audio = new Audio('sounds/crash.mp3');
      audio.play();
      break;

    case "k":
      var audio = new Audio('sounds/kick-bass.mp3');
      audio.play();
      break;

    case "l":
      var audio = new Audio('sounds/snare.mp3');
      audio.play();
      break;
    default:
      console.log(item.innerHTML);
  }
}

function animate(keyPressed){
  document.querySelector('.'+keyPressed).classList.add("pressed");

  setTimeout(function(){
    document.querySelector('.'+keyPressed).classList.remove("pressed");
  },100);

}
