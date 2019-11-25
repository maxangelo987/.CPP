/******************************************************************************
 * Author:           Robert Kety
 * Date Created:     12/2/2013
 * Last Modified:    06/23/2014
 * Description:      
 Demonstrates the creation of a maze comprised of doubly
 *                   linked roomNode's.  A member function assigns a random
 *                   room in the list as an entrance and exit for each 
 *                   iteration of the program.  A search algorithm locates 
 *                   the random maze exit from the random entrance by 
 *                   simulating a path where the explorer keeps their
 *                   left hand on the wall as they progress through the maze.
 *                   This method of maze navigation is appropriate as this
 *                   is not an island maze.  The program completes once the 
 *                   algorithm finds the exit to the maze.
 * Output:           Describes initial and conclusion scenarios.  Outputs
 *                   passage directions to the user.  
 * Acknowledgements: Absolute C++, Seventh Edition.
******************************************************************************/

#include <iostream>  //For input/output
#include <string>    //For use of string
#include <cctype>    //For use of toupper()
#include <cstdlib>   //For rand()
#include <ctime>     //For generating "random" numbers
#include <climits>   //For SHRT_MAX

using std::cout;
using std::cin;
using std::string;

/* The roomNode class has a destructor that is customized for use with the 
   custom maze in the maze class.  If you change the maze layout in the maze
   class, be sure to compensate by adjusting the destructor in the roomNode
   class. The destructor will only delete nodes in one lateral and one 
   longitudinal direction (i.e., east and south).  If your maze has any 
   north or west passages when only turning east and south through the maze, 
   you must delete these tail lists separately.  See "junction" in the maze 
   class as an example. */
class roomNode{
    public:
        /* Constructors */
        roomNode(): north(NULL), east(NULL), south(NULL), west(NULL) {}
        roomNode(roomNode* up): north(up), east(NULL), south(NULL), west(NULL) {}
        roomNode(roomNode* up, roomNode* right): north(up), east(right), 
                        south(NULL), west(NULL) {}
        roomNode(roomNode* up, roomNode* right, roomNode* down): north(up), 
                        east(right), south(down), west(NULL) {}
        roomNode(roomNode* up, roomNode* right, roomNode* down, roomNode* left): 
                        north(up), east(right), south(down), west(left) {}
        
        ~roomNode(){
            delete this->east;
            delete this->south;
        }      /*Destructor - Assumes east and south to avoid infinite loop in 
                                    doubly linked list */
        
        /* Accessors */
        roomNode* getNorth() const{ return north; }
        roomNode* getEast() const{ return east; }
        roomNode* getSouth() const{ return south; }
        roomNode* getWest() const{ return west; }
        
        /* Mutators */
        void setNorth(roomNode* up){
            north = up;
            if(up->getSouth() == NULL)
                up->setSouth(this);
        }
        
        void setEast(roomNode* right){
            east = right;
            if(right->getWest() == NULL)
                right->setWest(this); 
        }
        
        void setSouth(roomNode* down){
            south = down;
            if(down->getNorth() == NULL)
                down->setNorth(this);
        }
        
        void setWest(roomNode* left){
            west = left;
            if(left->getEast() == NULL)
                left->setEast(this);
        }

        /* Member Functions */
        bool isNorth(){
            if(north == NULL)
                return false;
            return true;
        }
        
        bool isEast(){
            if(east == NULL)
                return false;
            return true;
        }
        
        bool isSouth(){
            if(south == NULL)
                return false;
            return true;
        }
        
        bool isWest(){
            if(west == NULL)
                return false;
            return true;
        }
        
        /* Counts the number of available directions in the room, outputs those 
            directions to the user, and prompts the user for a direction. */
        void describeRoom();
        
    private:
        roomNode *north, *east, *south, *west;
};

/* The roomNode class has a destructor that is customized for use with the 
    custom maze in the maze class.  If you change the maze layout in the maze
    class, be sure to compensate by adjusting the destructor in the roomNode
    class. The destructor will only delete nodes in one lateral and one 
    longitudinal direction (i.e., east and south).  If your maze has any 
    north or west passages when only turning east and south through the maze, 
    you must delete these tail lists separately.  See "junction" in the maze 
    class as an example. */
class maze{
    public:
        /* Constructors */
        /* Creates unique maze as defined in Chapter 17, Programming Project 11 */
        maze(){
            roomNode *current;
            
            //Entrance - The user entrance is random, this is now the list header
            entrance = new roomNode(); 
            current = entrance;
            current->setEast(new roomNode());
            current->setSouth(new roomNode());
            
            //East Tunnel
            current = current->getEast();
            current->setSouth(new roomNode());
            current = current->getSouth();
            current->setEast(new roomNode());
            current = current->getEast();
            junction = current;
            current->setNorth(new roomNode());
            current->setEast(new roomNode());
            current->setSouth(new roomNode());
    
            //Junction North
            current = current->getNorth();
            current->setEast(new roomNode());
            current = junction;
            
            //Junction East
            current = current->getEast();
            current->setSouth(new roomNode());
            exit = current->getSouth();     //Exit is now random
            current = junction;
        
            //South Tunnel
            current = entrance;
            current = current->getSouth();
            current->setSouth(new roomNode());
            current = current->getSouth();
            current->setEast(new roomNode());
        
            exit = randomRoom();
        }
        ~maze(){ 
            delete junction->getNorth();
            delete entrance; 
        }      /* Destructor - Delete any north or west passages in the doubly 
                    linked list first */
        
        /* Accessors */
        roomNode* getEntrance() const{ return entrance; }
        roomNode* getExit() const{ return exit; }
        
        /* Mutators */
        roomNode* randomRoom();
    private:
        roomNode *entrance, *exit;
        /* Additional junction pointers should be added as necessary for each 
            junction.  A junction is a room where the maze constructor adds a 
            north or west passage. */
        roomNode *junction;
};

typedef roomNode* roomPtr;

/* Alters directional character to next clockwise character on the compass. */
void clockwise(char &direction);

/* Steps through the maze from the origin point taking the next clock-wise
    or left passage until reaching the exit. */
void findExit(maze* labyrinth, roomPtr current, char direction);

int main(){
    srand(time(NULL));
    char direction = 'N';
    maze *labyrinth = new maze();
    roomPtr current = labyrinth->randomRoom();
    
    /* Describe scenario to user */
    cout << "\nThe earth gives way beneath your feet.  You\n";
    cout << "fall into a large room - one of many in a dank\n";
    cout << "underground maze!\n";
    cout << "The light from the hole above goes out and your\n";
    cout << "eyes adjust to the dark.\n";
    cout << "You must find your way out of this maze!\n\n";
    cout << "You decide to find your way out of the maze by\n";
    cout << "moving forward with your left hand on the wall.\n";
    
    findExit(labyrinth, current, direction);
    
    /* Output conclusion and congratulate user on their success */
    cout << "\nAs you walk out of the underground maze, you stop to rub\n" 
          << "your eyes.  The sunlight is warm on your skin and you are\n"
          << "happy to be alive!\n";
    cout << "\nCongratulations! You survived the maze!\n\n";
    
    delete labyrinth;
    
    return 0;
}

/* Counts the number of available directions in the room, outputs those 
    directions to the user, and prompts the user for a direction. */
void roomNode::describeRoom(){
    int paths = 0;
    string directionList[4];
    
    /* Count number of available directions and record corresponding string 
        values */
    if(this->isNorth()){
        directionList[paths] = "north"; 
        paths++;
    }
    if(this->isEast()){
        directionList[paths] = "east";
        paths++;
    }
    if(this->isSouth()){
        directionList[paths] = "south";
        paths++;
    }
    if(this->isWest()){
        directionList[paths] = "west";
        paths++;
    }
    
    /* Output available directions to user */
    cout << "\nThis room has passages to the ";
    for(int i = 0; i < paths; i++){
        if(i > 0)
            cout << " ";
        cout << directionList[i];
        if(paths > 1){
            if(i < paths - 2)
                cout << ",";
            if(i == paths - 2)
                cout << " and";
        }
        if(i > paths - 2)
            cout << ".\n";
    }
    
    /* Prompt user for a direction */
    cout << "Which direction do you wish to travel (";
    for(int i = 0; i < paths; i++){
        if(i > 0)
            cout << " ";
        cout << directionList[i][0];
        if(paths > 1){
            if(i < paths - 2)
                cout << ",";
            if(i == paths - 2)
                cout << " or";
        }
        if(i > paths - 2)
            cout << "): ";
    }
    
    return;
}

roomNode* maze::randomRoom(){
    unsigned int numPassages = 0, randCount;
    char direction = 'N';
    roomNode* current = entrance;
    randCount = ((rand() % 66) + 3) / 3;    //1 through 22
    
    /* Steps through a random number of passages. Passages selected clockwise */
    while(numPassages < randCount){
        clockwise(direction);
        
        switch(direction){
            case 'N':
                if(current->isNorth()){
                    current = current->getNorth();
                    numPassages++;
                    direction = 'S';  //Reverse direction simulates origin
                }
                break;
            case 'E':
                if(current->isEast()){
                    current = current->getEast();
                    numPassages++;
                    direction = 'W';  //Reverse direction simulates origin
                }
                break;
            case 'S':
                if(current->isSouth()){
                    current = current->getSouth();
                    numPassages++;
                    direction = 'N';  //Reverse direction simulates origin
                }
                break;
            case 'W':
                if(current->isWest()){
                    current = current->getWest();
                    numPassages++;
                    direction = 'E';  //Reverse direction simulates origin
                }
                break;
            default:
                cout << "That is not a valid direction!\n";
                break;
        }
        /* Prevents beginning the maze at the exit */
        if((numPassages == randCount) && (current == exit))
            numPassages -= (randCount / 2);
    }
    
    return current;
}

/* Alters directional character to next clockwise character on the compass. */
void clockwise(char &direction){
    if(direction == 'N')
        direction = 'E';
    else if(direction == 'E')
        direction = 'S';
    else if(direction == 'S')
        direction = 'W';
    else if(direction == 'W')
        direction = 'N';
    else
        direction = 'N';
}

/* Steps through the maze from the origin point taking the next clock-wise
    or left passage until reaching the exit. */
void findExit(maze* labyrinth, roomPtr current, char direction){
    /* Added a contextual clue that the program has reached the lowest
        recursive element.  */
    if(current == labyrinth->getExit()){
        cout << "\nYou see a light ahead!\n";
        return;
    }
    
    clockwise(direction);
    /* Determines next recursion call based on direction */
    switch(direction){
        case 'N':
            if(current->isNorth()){
                cout << "You take the northern passage.\n";
                current = current->getNorth();
                findExit(labyrinth, current, 'S');
            }
            else
                findExit(labyrinth, current, 'N');
            break;
        case 'E':
            if(current->isEast()){
                cout << "You take the eastern passage.\n";
                current = current->getEast();
                findExit(labyrinth, current, 'W');
            }
            else
                findExit(labyrinth, current, 'E');
            break;
        case 'S':
            if(current->isSouth()){
                cout << "You take the southern passage.\n";
                current = current->getSouth();
                findExit(labyrinth, current, 'N');
            }
            else
                findExit(labyrinth, current, 'S');
            break;
        case 'W':
            if(current->isWest()){
                cout << "You take the western passage.\n";
                current = current->getWest();
                findExit(labyrinth, current, 'E');
            }
            else
                findExit(labyrinth, current, 'W');
            break;
        default:
            cout << "That is not a valid direction!\n";
            break;
    }
}
