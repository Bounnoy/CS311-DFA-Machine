# CS311-DFA-Machine
This program simulates a DFA machine that recognizes a floating point number.

## The language accepted by the machine is:
<img src="https://latex.codecogs.com/gif.latex?L&space;=&space;(&plus;\cup&space;-\cup&space;\O&space;)&space;(0-9)^*[\O&space;\cup&space;.&space;\cup&space;.(0-9)^*(\O&space;\cup&space;e&space;\cup&space;E)(&plus;&space;\cup&space;-&space;\cup&space;\O)(0-9)(0-9)*]" title="L = (+\cup -\cup \O ) (0-9)^*[\O \cup . \cup .(0-9)^*(\O \cup e \cup E)(+ \cup - \cup \O)(0-9)(0-9)*]" />

## The alphabet accepted by the machine is:
<img src="https://latex.codecogs.com/gif.latex?\sum&space;=&space;\{0-9,&space;e,&space;E,&space;&plus;,&space;-,&space;.\}" title="\sum = \{0-9, e, E, +, -, .\}" />

## State Diagram
<img src="img/floatpoint.png" />

## Transition Table
DFA | 0-9  | +    | -    | .    | e    | E
--- | ---- | ---- | ---- | ---- | ---- | ----
q0  | q3   | q2   | q1   | q4   | Dead | Dead
q1  | q3   | Dead | Dead | q5   | Dead | Dead
q2  | q3   | Dead | Dead | q5   | Dead | Dead
q3  | q3   | Dead | Dead | q4   | Dead | Dead
q4  | q6   | Dead | Dead | Dead | q7   | q8
q5  | q6   | Dead | Dead | Dead | q7   | q8
q6  | q6   | Dead | Dead | Dead | q7   | q8
q7  | q9   | q10  | q11  | Dead | Dead | Dead
q8  | q9   | q10  | q11  | Dead | Dead | Dead
q9  | q9   | Dead | Dead | Dead | Dead | Dead
q10 | q9   | Dead | Dead | Dead | Dead | Dead
q11 | q9   | Dead | Dead | Dead | Dead | Dead
Dead| Dead | Dead | Dead | Dead | Dead | Dead

## Examples of Accepted Strings
0.5
.5
.5e+4
.5e4
.5E4
.5E-4
+.5E-4
-.5E-4
-2.E-4
23.
23.e2
232663
23.3523e21
