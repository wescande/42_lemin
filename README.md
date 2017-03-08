# 42_lemin

This project is a path solver, with a display implementation.

## The rules are :
* You have X ants in a room called **##start**, they all have to go to the room **##end**.
* All room have a name and have 0 or some connection to other room.
* Each turn, 1 or more ants can move from one room to another room connected to the ant's room.
* A room can contain only one ant at the same time. (except for the room **##start** & **##end**)
* The map file can have some comments inside.

## Use : 
`./lem-in < maps/mapX | ./visualizer` where `mapX` is a valid map.
