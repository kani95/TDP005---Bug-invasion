HOW TO RUN GAME:

1   clone the repo  

In linux terminal run:  

2   cmake .  
3   make  
4   ./game  



HOW TO PLAY:  

Arrow keys are used for navigation both in menu and in the game.  
Use enter for selecting options in the menus.  
Escape will either take you back to the previous menu or quit the game if in Playstate.  
Lshift will half the movement of the player making it easier to dodge bullets.  
Spacebar shoots projectiles.  



HOW TO CREATE LEVELS:  

In order to edit the level you could either edit the Level.txt file or  
create your own level and push it on the state stack in Game.cpp in the update()  
function.  

Here is what each parameter in the file means:  


PLAYER:  
Object type|texture_file|shot_texture|pos.x|pos.y|dir.x|dir.y|size.x|size.y|  
Movespd|hp|attack_tmr|shot_dim.x|shot_dim.y|shot_dir.x|shot_dir.y|  

LEAF:  
Object type|texture_file|pos.x|pos.y|size.x|size.y|  

ANTSWARM:  
Object type|texture_file|shot_texture|pos.x|pos.y|size.x|size.y|dist.x|  
dist.y|dir.x|dir.y|shot_dir.x|shot_dir.y|shot_dim.x|shot_dir.y|  
border_limit_left|border_limit_right|number_of_ants|number_of_rows|score|hp|attack_tmr|  

SPIDERSWARM:  
Object type|texture_file|dim.x|dim.y|dir.x|dir.y|spw_lim_x.x|spw_lim_x.y|  
spw_lim_y.x|spw_lim_y.y|spw_timer|score|hp|  
