
# Linked_Lists_Lottery
## A demonstration of a custom doubly linked list class.

###### The list class data structure is implemented on a lottery program.

1. The Lottery
   - The list class is called to make a list of 40 ints (ordered 0 - 40).
   - A random seed generates the traversal distance of the list.
     - If the random number is even, the traversal will be forwards equal to the random number.
       - Traversal starts from the current position or last accessed position (initialized to the head).
     - Else, if odd, traversal will be backwards equal to the random number.
       - i.e. random num drawn 26 will traverse the list 26 nodes, then return that number (0 - 40).
   - The node landed on is returned and added as a lottery number, and the node is removed from the list.
   - This occurs 6 times so there are 6 generated lottery numbers (order matters).
2. Comparison
   - The user picks 6 numbers (1 - 40).
   - The 6 picked numbers are compared in order with the generated lottery.
   - Depending on the amount of matching numbers, determines how much "money" the user wins.
   
 My [LinkedIn](https://www.linkedin.com/in/eric-brown-fi/)
