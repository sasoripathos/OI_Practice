# [Joyless Game](https://open.kattis.com/problems/joylessgame)

This is a typical impartial game. So my thought is to find the Sprague-Grundy function for this game. 

First of all, when string length is 2 ("aa", "ab"), the game is in P-position. Since we cannot delete the first and last characters, the graph of the game contains at least two parts (like two trees) -- one is strings have different first and last characters (say class A), the other is strings have the same first and last character (say class B).

After list some strings with length <= 5, I found that in class A, if length is even then the game is in P-position, else is in N-position. In class B, if length is even then the game is in N-position, else is in P-position. Then the solution is clear.

BTW, the first few pages of this [note](http://web.mit.edu/sp.268/www/nim.pdf) may provide some definitions of some terms above.
