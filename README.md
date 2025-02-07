### ToolBox library for C 


A library that contain simple C shortcut or integration to ensure that every single time in any C project I don't have to rewrite the 
same shit over and over again jsut to simplify some operation. So the ToolBox contain simple library or other things that sometime turn to 
be useful. 

By the fact that this is something desined for me what's inside may change over time.


There is a simple garbage collector that replace the allocation command with a custom MALLOC that will allocate what you need AND will push that address into 
an array to store it and never lose it. At the end of the execution you need to free all the stored address with the "free_trash" function.
This integration rely heavily on the main entry point of the application, you must not exit from the execution with "exit()" or generaly breaking the relation with 
the main function, because in it the garbage collector will be created and cleared at the end.


An Example:


    #include <stdio.h>
    #include <stdlib.h>

    #include <toolbox.h>

    int main(){
        init_gc(general_gc);


        ..................
        ..your code here..
        ..................


        free_trash(general_gc); // to ensure memory likage you need to call this before exit the execution;
        return 0;
    }




