# small-c-projects
While I was learning how to code in C, I made these small projects for fun and 
to get a better undersanding of the language. I don't plan on improving these
in C, just put these here for reference.

## Conway's game of life
This program simulates Conway's game of life either in a txt file or in stdout. 
It takes in a text file with the first row containing the number of rows and
columns, and the rest containing 1s and 0s to represent initial "live" and
"dead" tiles. I included some examples of the files.


The Conway's game of life program includes 2 main files:

#### main_static.c
This outputs each iteration of the game for a set number of iterations. It takes
in command line arguments for the file name and number of iterations.
If ommited the program will ask for the file name and number of iterations in
stdin.

#### main_dynamic.c
This outputs a sudo-animation in a txt file named "out.txt" by overwriting the
file every second. This will go on forever, to close the program use the break
command in the terminal you used to start the program (usually CTRL + C).
It takes in command line arguments for the file name, if ommited the program
will ask for the file name.  
To see the animation, you can use the following in a UNIX terminal:
```
watch -n 0.5 'tail -n [a number >= lines in output] out.txt'
```


## Wordle
Here I created a simple Worlde "helper". You can input the word that you guess
along with the results from that word, and this will give you a list of possible
words left. To use it, input the word you tryed. For the result, type in a 5
character representaion of the results containing 'y' for yellow, 'g' for green,
and 'b' for black/blank.

For example, take the input word "genie":  
![Genie Word example](./wordle/wordle_example.png?raw=true)  
Here you would input "ygbbg" as the result.

The program will continue until there is 1 or no words left.
