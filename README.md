#Description

This is a demo of a 1D Wolfram Cellular Automata.
The program executes CA rule 110 (0,1,1,1,0,1,1,0) by default
but other rules can be created by the user or randomly
http://mathworld.wolfram.com/Rule110.html

##Usage

This program has two modes: a preview mode(default) and an edit mode

##General keys

Press UP to go into Edit mode
Press Down to reset/redraw the current rule

##Preview mode

Press START to randomize the current rule

##Edit mode

The edit mode displays a single row of 8 bits: the current CA rule.
This rule can be changed using the following controls:

Use the LEFT/RIGHT keys to move the blinking cursor.
The LED will indicate the state o the bit under your cursor (on or off)
Use START to toggle the current bit's state

Press DOWN when you're happy with your rule and you want to test it out.

##Improvements

There could be additional controls to allow a user to step through the 1D CA 
one generation/row at a time. A simple logic exercise would be to mentally calculate
the how the next generation would look based on how the current row looks like
and the current rule.

Using the BigImage scroll example a bigger CA (e.g. 16x16, 32x32, etc.) can be generated
and then scrolled through to get more intriguing patterns: a nicer 1D CA explorer