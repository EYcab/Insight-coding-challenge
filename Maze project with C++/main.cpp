//author: Chenxi Yu

#include <iostream>
#include "Maze.h"
#include <queue>
#include <stack>
#include <stdlib.h>
using namespace std;

/* Entry point of the program. Simply gets the filename from the user and then
    launches the one-player game. 
*/
    // declare a location struct
struct Location
{
    int row;
    int col;
    Location *prev;//declare a previous pointer
};


int main()
{
    string fileName;
    cout << "Enter a maze file name: ";
    cin >> fileName;
    
    Maze m(fileName);
    
    m.display();
    cout << "Starting in " << m.getStartRow() << ", " << m.getStartCol() << endl;

    int selection;
    cout << "How would you like to explore the maze?" << endl;
    cout << "0: Exit" << endl;
    cout << "1: Stack" << endl;
    cout << "2: Queue" << endl;
    cout << "What would you like to do? ";
    cin >> selection;

    bool endReached = false;
    if (selection == 0)
    {
        exit(0);
    }
    else if (selection == 1)
    {
      //declare a stack contains Location pointers
        stack<Location*> st;
     //declare a starting location pointer 
        Location *loc = new Location;
        loc->row = m.getStartRow();
        loc->col = m.getStartCol();
        //create a location starting point
        st.push(loc);
        //directly push loc into the stack 
        while(!st.empty() && endReached == false)
        {
            Location *l;
            l = st.top();
            st.pop();
           //every run,we read the top of the stack and remove it until the end is reached
              if (l->row==m.getEndRow() && l->col==m.getEndCol())
              {
                endReached = true;
                st.push(l); //push l back on stack;
              }
            //explore the maze and if l is "." or "o",explore the surrounding location by
            //pushing in the 4 directions 
              else if (m.explore(l->row,l->col)=='.'|| m.explore(l->row,l->col)=='o')
              {
                Location* left = new Location;
                left->row = l->row;
                left->col = l->col-1;
                left->prev = l;

                Location* right = new Location;
                right->row = l->row;
                right->col = l->col+1;
                right->prev = l;

                Location* up = new Location;
                up->row = l->row+1;
                up->col = l->col;
                up->prev = l;
                
                Location* down = new Location;
                down->row = l->row-1;
                down->col = l->col;
                down->prev = l;
    
                st.push(left);
                st.push(right);
                st.push(up);
                st.push(down);  

                m.setVisited(l->row, l->col);
                m.display();    
              }    
         // if endReached is true,state out "Yes,at least a solution exists!!"
        // show a direction starting from the end point.
            if (endReached == true)
            {
                cout << "Yes,at least a solution exists!!" <<endl;
                loc = st.top();
                cout << "please read the direction from the bottom to the top" <<endl;

                while (loc != NULL)
                {
                    cout << loc->row << " " << loc->col << endl;
                    loc = loc->prev;
                }
            }   
           
        } 
    }
    else if (selection == 2)
    {
        queue<Location> q;
    //create a queue and find the goal under the queue approach 
        Location loc;
        loc.row = m.getStartRow();
        loc.col = m.getStartCol();
    //most part similar to the stack approach   
        q.push(loc);
        while(!q.empty() && endReached == false)
        {
            Location l;
            l = q.front();
            q.pop();
              if (l.row==m.getEndRow() && l.col==m.getEndCol())
              {
                endReached = true;
                cout << "Yes,at least a solution exists!!" <<endl;
              }
              else if (m.explore(l.row,l.col)=='.'|| m.explore(l.row,l.col)=='o')
              {
                Location left;
                left.row = l.row;
                left.col = l.col-1;
               
                Location right;
                right.row = l.row;
                right.col = l.col+1;
                
                Location up;
                up.row = l.row+1;
                up.col = l.col;
                
                Location down;
                down.row = l.row-1;
                down.col = l.col;

                q.push(left);
                q.push(right);
                q.push(up);
                q.push(down);  

                m.setVisited(l.row, l.col);
                m.display();      
              }
               
        }
      

    }
    return 0;


}
