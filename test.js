//==================//
// 		Part 1	 	//
//==================//

var userBalance = 0;

// Gets called whenever the money finished tweening to the bottom.
function addFromCatch(value)
{
	userBalance += value;
}

// Gets called every frame. 
// Time elapsed since the last update is passed into the function(milliseconds)
function onUpdate({delta})
{
	if (delta == 2000) {
		updateBalance(userBalance.toString());//set ui to value
		delta = 0;//restart ttimer
	}
}

// You have access to a function updateBalance which 
// takes in a string and sets the ui to that value
// updateBalance("1");




//==================//
// 		Part 2	 	//
//==================//

function processSlots(input)
{
	var lines = 0;
	var points = 0;
	for (var i = 0 ; i < input.length ; i++) {
		const symbol = input[i][0];
		if (symbol == 1 || symbol == 2 || symbol == 3) {
			//horizontal line
			if (input[i][1] && input[i][2] && input[i][1] == symbol && input[i][2] == symbol) {
				lines ++;
				if (input[i][3] && input[i][3] == symbol) {
					if (input[i][4] && input[i][4] == symbol) {
						//5 consec
						if (symbol == 1) points += 20;
						else if (symbol == 2) points += 50;
						else if (symbol == 3) points += 100;
					}
					else {
						//4 consec
						if (symbol == 1) points += 10;
						else if (symbol == 2) points += 25;
						else if (symbol == 3) points += 50;
					}

				}
				else {
					//3 consecutive
					if (symbol == 1) points += 5;
					else if (symbol == 2) points += 10;
					else if (symbol == 3) points += 25;
				}
			}
			//diagonal line
			//diag start from top
			if (i == 0 && input[1][1] && input[2][2] && input[1][1] == symbol &&  input[2][2] == symbol) {
				lines ++;
				if (input[1][3] && input[1][3] == symbol) {
					if (input[0][4] && input[0][4] == symbol) {
						//5 consec
						if (symbol == 1) points += 20;
						else if (symbol == 2) points += 50;
						else if (symbol == 3) points += 100;
							
					}
					else {
						//4 consec
						if (symbol == 1) points += 10;
						else if (symbol == 2) points += 25;
						else if (symbol == 3) points += 50;

					}
				}
				else {
					//3 consecutive
					if (symbol == 1) points += 5;
					else if (symbol == 2) points += 10;
					else if (symbol == 3) points += 25;
				}

			}
			//diag start from bottom
			else if (i == 2 && input[1][1] && input[0][2] && input[1][1] == symbol &&  input[0][2] == symbol){
				lines ++;
				if (input[1][3] && input[1][3] == symbol) {
					if (input[2][4] && input[2][4] == symbol) {
						//5 consec
						if (symbol == 1) points += 20;
						else if (symbol == 2) points += 50;
						else if (symbol == 3) points += 100;	
					}
					else {
						//4 consec
						if (symbol == 1) points += 10;
						else if (symbol == 2) points += 25;
						else if (symbol == 3) points += 50;
					}
				}
				else {
					//3 consecutive
					if (symbol == 1) points += 5;
					else if (symbol == 2) points += 10;
					else if (symbol == 3) points += 25;
				}
			}
		}
	}
	console.log("Output: " + lines + " winning lines, socring a total " + points + " points.");
};

// examples input
var array = [
	[1,0,0,0,1],//20
	[0,1,0,1,0],
	[0,0,1,0,0]
];
//Output: '1 winning line, scoring 20 points.'

var array2 = [
	[2,4,2,2,3],//
	[1,1,1,4,1],//5
	[3,3,3,4,2]//25
];
//Output: '2 winning lines, scoring a total 30 points.'