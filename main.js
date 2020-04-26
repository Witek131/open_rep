var cvs = document.getElementById("canvas");
var ctx = cvs.getContext("2d");

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

var fly = new Audio();
var score = new Audio();

fly.src = "sounds/fly.mp3";
score.src = "sounds/score.mp3";

var gap = 85;
var constant;

var bX = 10;
var bY = 150;

var points = 0;

document.addEventListener("keydown", moveUp);
document.addEventListener("click", moveUp);

function moveUp()
{
	bY -= 30;
	fly.play();
}

var pipe = [];

pipe[0] = {
    x : cvs.width,
    y : 0
};

function draw()
{
    
	ctx.drawImage(bg, 0, 0);
	
	for (var i = 0; i < pipe.length; i++)
	{
		constant = pipeNorth.height + gap;

		ctx.drawImage(pipeNorth, pipe[i].x, pipe[i].y);
		ctx.drawImage(pipeSouth, pipe[i].x, pipe[i].y + constant);

		pipe[i].x--;

		if (pipe[i].x == 100)
		{
			pipe.push({
				x : cvs.width,
				y : Math.floor(Math.random() * pipeNorth.height) - pipeNorth.height
			})
		} 

		/*****************************************************/
		if (bX + bird.width >= pipe[i].x && bX <= pipe[i].x + pipeNorth.width && (bY <= pipe[i].y + pipeNorth.height || bY + bird.height > pipe[i].y + constant) || bY + bird.height >= cvs.height - fg.height)
		{
			location.reload()
		}
		/*****************************************************/

		if (pipe[i].x == bX)
		{
			score.play();
			points++;
		}

	}
  
	ctx.drawImage(fg, 0, cvs.height - fg.height);
	ctx.drawImage(bird, bX, bY);

	ctx.fillStyle = "#0A0";
	ctx.font = "20px Verdana";
	ctx.fillText("Points: " + points, 100, cvs.height - 30);

	bY += 1.5;
    
    requestAnimationFrame(draw);
    
}

draw();

