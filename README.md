# drawing-01-JoshKeenMurr
drawing-01-JoshKeenMurr created by GitHub Classroom   

The draw() function is very inefficient...you're getting a copy of the vector *every time through the loop*. Call your getter function *once*, then use that one copy to display stuff   
On your memory leak...the only place you would do a delete is in the destructor for ShapeMgr...where did you try putting the delete?   
Grade: 48/50
