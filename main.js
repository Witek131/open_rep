var cvs = document.getElementById("canvas");
var ctx = cvs.getContext("2d");

// load images

var bird = new Image();
var bg = new Image();
var fg = new Image();
var pipeNorth = new Image();
var pipeSouth = new Image();

bird.src = "images/bird.png";
bg.src = "images/bg.png";
fg.src = "images/fg.png";
pipeNorth.src = "images/pipeNorth.png";
pipeSouth.src = "images/pipeSouth.png";


var gap = 85;
var constant;

var bX = 10;
var bY = 150;

document.addEventListener("keydown",moveUp);

function moveUp()
{
    bY -= 20;
}

var pipe = [];

pipe[0] = {
    x : cvs.width,
    y : 0
};


function draw()
{
    
    ctx.drawImage(bg, 0, 0);

    ctx.drawImage(fg, 0, cvs.height - fg.height);
    
    ctx.drawImage(bird, bX, bY);
    
    bY += 1;
    
    requestAnimationFrame(draw);
    
}

draw();

