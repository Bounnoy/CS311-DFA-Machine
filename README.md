# CS311-DFA-Machine
This program simulates a DFA machine that recognizes a floating point number.

## The language accepted by the machine is:
<img src="https://latex.codecogs.com/gif.latex?L&space;=&space;(&plus;\cup&space;-\cup&space;\O&space;)&space;(0-9)^*[\O&space;\cup&space;.&space;\cup&space;.(0-9)^*(\O&space;\cup&space;e&space;\cup&space;E)(&plus;&space;\cup&space;-&space;\cup&space;\O)(0-9)(0-9)*]" title="L = (+\cup -\cup \O ) (0-9)^*[\O \cup . \cup .(0-9)^*(\O \cup e \cup E)(+ \cup - \cup \O)(0-9)(0-9)*]" />

## The alphabet accepted by the machine is:
<img src="https://latex.codecogs.com/gif.latex?\sum&space;=&space;\{0-9,&space;e,&space;E,&space;&plus;,&space;-,&space;.\}" title="\sum = \{0-9, e, E, +, -, .\}" />

## State Diagram
<img src="img/floatpoint.png" />
