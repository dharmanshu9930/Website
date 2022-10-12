<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Covid-19</title>
    <link rel="stylesheet" href="css/style.css">

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
        <svg width="100vw" height="100vh">
            <text x="15%" y="35%">WEAR MASK, WASH YOUR HANDS</text>
            <text x="55%" y="50%">AND STAY SAFE</text>
        </svg>
    </header>

    <div class="main">
        <p>COVID-19 affects different people in different ways. Most infected people will develop mild to moderate
            illness and recover without hospitalization.</p>
        <img src="./images/image1.jpg" width="20%" height="250vh">
    </div>
    <div class="main1">
        <img src="./images/image2.jpg" width="20%" height="250vh">
        <p>Coronavirus disease 2019 (COVID-19) is a contagious disease caused by severe acute respiratory syndrome
            coronavirus 2 (SARS-CoV-2). The first known case was identified in Wuhan, China in December 2019.The
            disease has since spread worldwide, leading to an ongoing pandemic.</p>
    </div>
    <div class="main2">
        <p>Symptoms of COVID-19 are variable, but often include fever, cough, headache, fatigue, breathing
            difficulties, and loss of smell and taste. Symptoms may begin one to fourteen days after
            exposure to the virus. At least a third of people who are infected do not develop noticeable symptoms.</p>
            <img src="./images/image3.jpg">
    </div>

</body>
<!-- <script src="./js/index.js"></script> -->
<script>
    const header = document.querySelector('.header');
    window.onscroll = function () {
        var top = window.scrollY;
        console.log(top);
        if (top >= 100) {
            header.classList.add('black');
        }
        else {
            header.classList.remove('black')
        }
    }
</script>

</html>