# MMR  

The program gives the optimal team configuration which satisfies:
    
    - Each player has a value called MMR.
    - Each player is in a single class.
    - No people in higher class has lower MMR than the people in lower class.
    - Each class has equal number of people.
    - Exactly one people in each class is in a single team. 

How to use the program :

1. Make an input
There are two ways to give input to the program.

    1-1. Make a .csv file

    (For those who aren't familiar with .csv files, make a file with Google spreadsheets or Microsoft Excel, then you may easily change the file into .csv form. You may open the file with a notepad to see how it looks like.)

    The input should be as shown below:
    
    The input file is **input.csv**.
    
    The first line contains two integers: number of players(N) and size of each team(M) separated by a comma.
    
    Next N lines contain player's name and player's mmr, separated by a comma.

    1-2. Input with a console
    
    The input should be as shown in 1-1.

2. Get an output, which is also in .csv form.
    
    The output is as shown below:
    
    The output file is **output.csv** and the file contains N/M lines.
    
    Each line contains M names in increasing order of MMR, with a blank and a sum of MMR coming after that.
    
    The lines represent the members of the team.