/*
Determine winner of 2/9 number game 

Two players play the following game: they pick a random number N (less than 2 billion) then, 
starting from 1, take turns multiplying the number from the previous turn with either 2 or 9 (their choice). 
Whoever reaches N first wins. 
The candidate should write a function that given N decides who wins (first or second player)?
*/

int is_first_player_winner (int n)
{
  /* Returns 1 if Player_1 can control and win the game
   Returns 0 if the Player_1 cannot control and win the game */

  if ( n <= 1 ) 
  {
    // should not reach here
    // exit
  }
  if (n > 2 && n <= 9)
    return 1;         // first player wins
  if (n > 9 && n <= 18) 
    return 0;         // first player cannot win
  
  /* Consider the first two moves in the game
   They can be one of the following: (2,2), (2,9), (9,2), (9,9) */
  
  // case 2,2              
  int win_2_2 = is_first_player_winner (ceil((float)n/4));

  // case 2,9 or 9,2 
  int win_2_9 = is_first_player_winner (ceil((float)n/18));

  // case 9,9
  int win_9_9 = is_first_player_winner (ceil((float)n/81));

  if ((win_2_2 && win_2_9) || (win_9_9 && win_2_9))
    return 1;
  else 
    return 0;
}
