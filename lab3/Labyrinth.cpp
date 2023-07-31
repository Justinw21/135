#include "Labyrinth.h"
#include <iostream>

void checkItems(MazeCell *path, bool items[]){
    if (path -> whatsHere == Item::SPELLBOOK)
        items[0] = true;
    if (path -> whatsHere == Item::POTION)
        items[1] = true;
    if (path -> whatsHere == Item::WAND)
        items[2] = true;
}

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    bool items[] = {false,false,false};

    MazeCell* current = start;
    for(int i = 0; i < moves.length(); i++){

        if(items[0] && items[1] && items[2]){
            return true;
        }

        if(moves[i] == 'N'){
            if(current -> north != nullptr)
            {
                current = current -> north;
            }
        }else if(moves[i] == 'E'){
            if(current -> east != nullptr)
            {
                current = current -> east;
            }
        }else if(moves[i] == 'S'){
            if(current -> south != nullptr)
            {
                current = current -> south;
            }     
        }else if(moves[i] == 'W'){
            if(current -> west != nullptr)
            {
                current = current -> west;
            }
        }
        checkItems(current, items);
    }
    return items[0] && items[1] && items[2];
}
