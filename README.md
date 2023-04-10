# savant

This is a program to do an emprical test as to whether Marilyn Vos Savant's
solution to the Monty Hall problem is correct or not.

It's written in C so people can't complain I'm using weird and unknown
languages.  But I stay away from the tricky bits of C, so it should be
easy for people with even minimal programming skills to understand
and modify.  It should also be easy for a person with even minimal coding
skills to write their own version of this program for themselves- this
is actually not a bad exercise.

# The Monty Hall Problem

So a game show contest is shown three doors.  Behind one of the doors
is a new car.  Behind the other two doors are goats.  The contestant
picks one door.  The host then opens one of the other two doors, 
showing that it has a goat behind it.  The contestant is then given
the choice to either stay with their selected door, or switch to the
other.  Should the contestant switch doors, or not?

# The Results

The results depend upon an unstated part of the problem: when the host
opens one of the other two doors, is it always a goat, or is it some
times the car?  In other words, does the host not know which door
hides the car, or does the host know and deliberately pick the other
door, to keep the tension?

If the host knows, and thus never opens the door with the car, then
Vos Savant was right.  Switching wins the car about 2/3rds of the time.
If the host doesn't know, then switching doesn't affect the odds.
However, the host will about 1/3rd the time, open the door to reveal
the car.

Which of these makes for better television is left as an exercise for
the reader.
