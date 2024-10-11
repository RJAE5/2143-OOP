# P02B - Class Design
## Rykir Evans

### Player Class
* Data:
  * `name`
  * `username`
  * `score`

* Actions:
  * `take_turn`: Generic take turn, should be overriden.
  * `get_score()`: Retrieve the current score.
  * `update_score(points)`: Update the player's score after each roll.

* Relationships
  * A Player **IS-A** participant in the game.

### KnucklebonesPlayer Class
* Data:
  * `dice_set`: Array of Dice objects
  * `streak`
  * `player_stats`: Struct of different stats

* Actions:
  * `roll_dice`: Roll the dice to begin turn, orverriden from player.
  * `get_streak()`: Retrieve the current streak.
  * `update_streak(streak)`: Update the player's streak after a win/loss.
  * `get_stats()`: Retrieve list of stats
  * `update_stat_attribute(stat)`: Update specific stat

* Relationships
  * A KnucklebonesPlayer **IS-A** Player
  * A KnucklebonesPlayer **HAS-A** Dice 


### Dice Class:
* Data:
  * `num_of_dice`
  * `sides`
  * `current_value`

* Actions:
  * `roll()`: Roll the dice for a value.
  * `get_value()`: Retrieve the current value.
  * `set_seed(seed)`: Set a seed for the die rolls

* Relationships
  * Dice **IS-A** tool used by the player
  * Dice **IS-A** component of the game

### Game Class:
* Data:
  * `players`
  * `rules`
  * `current_round`

* Actions:
  * `start_game()`: Begin the game session
  * `end_game()` : End the game session
  * `get_winner()` : Retrieve the winner of the session

* Relationships
  * A game **HAS-A** Player

### Kucklebones Class:
* Data:
  * `board`
  * `kucklebones_specific_rules`

* Actions:
  * `start_round()`: Begin the singular round
  * `end_round()`: End the current round
  * `calculate_winner()`: Compares scores to determine winner

* Relationships
  * Knucklebones **IS-A** type of game

### Keywords and Feature List
* Necessary
  * First name
  * High score
  * Leaderboard
  * Score
  * Streak
  * Userid
  * Winner

* Possible
  * Chat
  * Coins
  * Last name
  * Levels
  * Player stats
 
* Wishful
  * Cosmetics
  * Messaging
  * Profiles
  * Team stats
  * Teams
  * Tournament lobbies


