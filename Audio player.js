
let now_playing = document.querySelector(".now-playing");
let track_art = document.querySelector(".track-art");
let track_name = document.querySelector(".track-name");
let track_artist = document.querySelector(".track-artist");

let playpause_btn = document.querySelector(".playpause-track");
let next_btn = document.querySelector(".next-track");
let prev_btn = document.querySelector(".prev-track");

let seek_slider = document.querySelector(".seek_slider");
let volume_slider = document.querySelector(".volume_slider");
let curr_time = document.querySelector(".current-time");
let total_duration = document.querySelector(".total-duration");

let track_index = 0;
let isPlaying = false;
let updateTimer;


let curr_track = document.createElement('audio');


let track_list = [
{
	name: "Night Owl",
	artist: "Broke For Free",
	image: "Image URL",
	path: "Night_Owl.mp3"
},
{
	name: "Enthusiast",
	artist: "Tours",
	image: "Image URL",
	path: "Enthusiast.mp3"
},
{
	name: "Shipping Lanes",
	artist: "Chad Crouch",
	image: "Image URL",
	path: "Shipping_Lanes.mp3",
},
];
