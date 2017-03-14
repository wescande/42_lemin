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

### Normal output ask to validate the project
```
L1-1 L2-5 L3-2
L1-e L2-6 L3-3 L4-1 L5-5 L6-2
L2-7 L3-4 L4-e L5-6 L6-3 L7-1 L8-5 L9-2
L2-e L3-e L5-7 L6-4 L7-e L8-6 L9-3 L10-1 L11-5 L12-2
L5-e L6-e L8-7 L9-4 L10-e L11-6 L12-3 L13-1 L14-5 L15-2
L8-e L9-e L11-7 L12-4 L13-e L14-6 L15-3 L16-1 L17-5 L18-2
L11-e L12-e L14-7 L15-4 L16-e L17-6 L18-3 L19-1
L14-e L15-e L17-7 L18-4 L19-e L20-1
L17-e L18-e L20-e
```
### My output with [42 minilibx](https://github.com/wescande/minilibx) display
![](pics/Screenshot_lem_in.png)
