void PlayMusicSimple (MUSICELMT music[], float tempo)
// Plays notes from the music array. Only elements of type
// PLAYNOTE are considered, other elements are ignored.
{
    for (int i = 0; music[i].type != PLAYSTOP; i++)
    if (music[i].type == PLAYNOTE)
    PlayNote(music[i].note, tempo);
}
