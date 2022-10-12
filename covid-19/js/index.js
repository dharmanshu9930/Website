const header = document.querySelector('.header');
window.onscroll = function(){
    var top = window.scrollY;
    console.log(top);
    if(top){
        header.classList.add('black');
    }
    else{
        header.classList.remove('black')
    }
}