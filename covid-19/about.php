<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>About</title>
    <link rel="stylesheet" href="css/about.css">
    <script src="https://code.jquery.com/jquery-3.6.0.js"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Alfa+Slab+One&family=Orbitron:wght@900&display=swap"
        rel="stylesheet">
</head>

<body>
    <header>
        <nav class="header">
            <div class="menu">
                <ul>

                    <li><a href="./index.php">Home</a></li>
                    <li><a href="./active.php">Active Cases</a></li>
                    <li><a href="./about.php">About</a></li>
                </ul>
            </div>
        </nav>
        <img src="./images/IMG_20190323_114833.jpg" width="20%" height="30%">
        <div class="developer">
            <h2>SAI RAM KAUSHIK</h2>
        </div>
       
        <svg width="100vw" height="100vh">
            <text x="37%" y="10%">DEVELOPER</text>
        </svg>
        <a href="https://www.instagram.com/sairamkaushik/" target="_blank"><i class="fa fa-instagram" aria-hidden="true"
                id="insta"></i></a>
        <a href="https://github.com/sai-ram-kaushik" target="_blank"><i class="fa fa-github" aria-hidden="true"
                id="github"></i></a>
        <a href="https://www.linkedin.com/in/sairam-kaushik-711a40210/" target="_blank"><i class="fa fa-linkedin"
                aria-hidden="true" id="linkedin"></i></a>
          
    </header>
</body>
<!-- <script src="./js/index.js"></script> -->
<script>
    const header = document.querySelector('.header');
    window.onscroll = function(){
    var top = window.scrollY;
    console.log(top);
    if(top>=200){
        header.classList.add('black');
    }
    else{
        header.classList.remove('black')
    }
}
</script>

</html>