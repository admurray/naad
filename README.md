# naad

It should be possible to generate music given all the rules. :)

Rules are needed to generate sound - How to define these rules and what
will they specify (i.e what frequency comes ater what frequency)

### Rules
So define an emotion and rules under it, a particular emotion can have
multipe rules, So for happy we couls have Major Notes together in
various permutaions

Once we have a rule chose based on the emotion, we can then generate
data based on a random seed.

This data then needs to be mapped to frequencies and notes to be played.

This data can be a set of random numbers generated via th rules and the
emotions

```
Emotion-----|---Rule 1
            |---Rule 2
```
We can pick the rule randomly and then move to generate the sequence,
the sequence will have a length (beats * number of beats) There also
needs to be a denomination of half, quater, eighths etc. This could be
a part of the sequence.

We could have numbers as note denominations, so 12 numbers each for a
halfstep.

1   2   3   4   5   6   7   8   9   10  11  12
C   C#  D   D#  E   F   F#  G   G#  A   A#  B

Another thing that needs to done is to have a particular formula for the
conversion of C from one octave to another.

If we write to a score card then how do I represent C on the 10th
octave.

12 halfnotes should specify an octave.

An example of note rules could be:
Aaroh : C C# D E F G G# B C
Avroh : C B G# G F E D C# C


![Alt text](/Readme_Files/Diagram1.jpeg?raw=true "Basic Architecture")

