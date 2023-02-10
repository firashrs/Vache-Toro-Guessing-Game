# Vache-Toro-Guessing-Game
"Vache Toro" is a gueeeing game. Its meant to be played by two opponents. Each one chooses a secret code. Then, The players take turns guessing each others codes. The winner is the first one to guess the opponents code right.

## Secret code rules
* The secret code is a 4 digit number. 
* There should be no repeated digits in the code.
* The left-most digit could take any digit but not 0.

## Gameplay
1. Each player chooses a secret code. The codes must not be changed during the game.
2. Player 1 makes his suggestion
3. Player 2 answers with two values: how many T's and how many V's.
A T is a digit that exists in the secert code and is actually in the right place.
A V is a digit that exists in the secret code but is not in the right place.
4. Player 2 makes his suggestion
5. Player 1 answers with two values: how many T's and how many V's.
6. Step 2 through 5 are repeated untill one of the players gets 4T's.

## Example
* Secret code: 1486
* Suggestion 1: 1234 - Opponents answer: 1T 1V
* Suggestion 2: 5678 - Opponents answer: 0T 2V
* Suggestion 3: 1406 - Opponents answer: 3T 0V
* Suggestion 4: 1486 - Opponents answer: 4T 0V - The Game Is Won!!!!!

## Files
* vache_toro_opponent.py: is a file that replaces the opponent. It chooses a random secret code (and guarenteed that the code is valid). Then, the program takes suggestions and answers with how many T's and how many V's.
* VacheToro_player: is a file that replaces the player. It suggest codes and reads the opponents answers, then suggest again. The program keeps narrowing the possibilities until the secret code is found. The logic behind this program is that it saves each suggestion and the answer from the opponent as a list of rules. Then finds all possible combinations that fits each and every rule.
