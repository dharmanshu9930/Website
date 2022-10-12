// $("h1").css("color", "red");

// $("h1");
// $("button");

// $("h1").addClass("big-title margin-50");
// $("h1").removeClass("big-title");
// $("h1").hasClass("big-title");

// $("h1").text("bye!");
// $("button").html("<em>dont click me</em>");

// $("img").attr("src");
// $("a").attr("href", "https://www.yahoo.com");

// console.log($("h1").attr("class"));

// $("button").click(function(){
//   $("h1").css("color", "purple");
// })

// $(document).keydown(function(e){
//   $("h1").text(e.key);
// })

// $("h1").on("mouseover",function(){
//   $("h1").css("color","purple");
// })

// $("h1").before("<button>new</button>");
// $("h1").after("<button>new</button>");
// $("h1").prepend("<button>new</button>");
// $("h1").append("<button>new</button>");

$("button").click(function(){
  // $("h1").fadeOut();
  // $("h1").fadeIn();
  // $("h1").fadeToggle();
  // $("h1").slideUp();
  // $("h1").slideDown();
  // $("h1").slideToggle();
  $("h1").slideUp().slideDown().animate({opacity:"50%"});
})
