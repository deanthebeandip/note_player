void PlayMusic (MUSICELMT music[], float tempo)
// Plays notes and fragments from the music array.
// A fragment is played until the program reaches its finish or
// a PLAYSTOP element. The length of the initial fragment
// is unknown: it must end with a PLAYSTOP element.
{
    const int MAXSTACK = 400, MAXARRAY = 9999;
    STACK stack;
    PLAY type; // Will hold the type of the current MUSICELMT
    // Create a stack for MAXSTACK of integers:
        if (Create(stack, MAXSTACK) == FAILED) 
        {
            cerr << "*** MUSIC: Stack allocation error. ***\n";
            return;
        }

    CHAPTER 0. 16. 13 STACKS
    int current = 0; // Index of the current element.
    int finish = MAXARRAY; // Index of the last element in a fragment
    
    
    // initially set to an arbitrary large
    // number.
    while (OK) 
    { // Repeat until break
    type = music[current].type;
    // If more elements remain in this fragment...
    if (current <= finish && type != PLAYSTOP) 
    {
        if (type == PLAYNOTE)
            PlayNote(music[current++].note, tempo);
        else if (type == PLAYFRAGMENT) 
        {
    // Save next and final element indices in the current
    // fragment on stack:
        ...
        ...
    // Set current to the start of the new fragment and
    // finish to the finish of the new fragment.
        ...
        ...
        }
    }
        // ...else if some interrupted fragments remain on stack...
    else if (!IsEmpty(stack)) 
    {
        // Return to the last interrupted fragment
        ...
        ...
    }
 else
 // Nothing else to do
 
 
 break;
    }
    Destroy(stack);
}
