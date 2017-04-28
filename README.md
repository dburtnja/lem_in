The goal of this project is to create an “Hex” simulator.

The program receive the data describing the ant farm from the standard outputin the following format:<br/>
  ◦ number_of_ants<br/>
  ◦ the_rooms<br/>
  ◦ the_links<br/>

The ant farm is defined by the following links:
##start<br/>
1 23 3<br/>
2 16 7<br/>
#comment<br/>
3 16 3<br/>
4 16 5<br/>
5 9 3<br/>
6 1 5<br/>
7 4 8<br/>
##end<br/>
0 9 5<br/>
0-4<br/>
0-6<br/>
1-3<br/>
4-3<br/>
5-2<br/>
3-5<br/>
#another comment<br/>
4-2<br/>
2-1<br/>
7-6<br/>
7-2<br/>
7-4<br/>
6-5<br/>

There are two parts:<br/>
  ◦ The rooms, which are defined by: name coord_x coord_y<br/>
  ◦ The links, which are defined by: name1-name2<br/>
  ◦ All of it is broken by comments, which start with #<br/>

Lines that start with ## are commands modifying the properties of the line thatcomes right after.

For example, ##start signals the ant farm’s entrance and ##end its exit.

Any non compliant or empty lines will automatically stop the ant farm’s reading as well as the orderly processing of the acquired data.

If there isn’t enough data to process normally you must display ERROR

Mandatory part:
• The goal of this project is to find the quickest way to get n ants across the farm.<br/>
• Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.<br/>
• At the beginning of the game, all the ants are in the room ##start. The goal is
to bring them to the room ##end with as few turns as possible. Each room can
only contain one ant at a time. (except at ##start and ##end which can contain
as many ants as necessary.)<br/>
• We consider that all the ants are in the room ##start at the beginning of the game.<br/>
• The results will be displayed on the standard output in the following format:<br/>
   ◦ number_of_ants<br/>
   ◦ the_rooms<br/>
   ◦ the_links<br/>
   ◦ Lx-y Lz-w Lr-o<br/>
    x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y, w, o represents the rooms’ names.<br/>

Subject for the project https://cdn.intra.42.fr/pdf/pdf/947/lem-in.en.pdf
