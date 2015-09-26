//
//  TreeDungeonGameFunctions.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 5/09/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

void updateGame(BTree &MapTree, Node* &CurrentNode, class Character &Character, Maps &Map, TreeDungeonGraphics &MappedSprites){
    if(Character.getOnTreasure() == true){
        if(Character.goal == 1){
            if(CurrentNode->keyValue == MapTree.goalInOrder.at(Character.getTreasureCollected())){
                Character.incTreasure();
                Character.treasureInventory += CurrentNode->keyValue;
                Character.setOnTreasure(false);
                CurrentNode->treasureCollected = true;
            }
        }
        if(Character.goal == 2){
            if(CurrentNode->keyValue == MapTree.goalPreOrder.at(Character.getTreasureCollected())){
                Character.incTreasure();
                Character.treasureInventory += CurrentNode->keyValue;
                Character.setOnTreasure(false);
                CurrentNode->treasureCollected = true;
            }
        }
        if(Character.goal == 3){
            if(CurrentNode->keyValue == MapTree.goalPostOrder.at(Character.getTreasureCollected())){
                Character.incTreasure();
                Character.treasureInventory += CurrentNode->keyValue;
                Character.setOnTreasure(false);
                CurrentNode->treasureCollected = true;
            }
        }
    }
    Character.setOnTreasure(false);
    
    if(Character.getTreasureCollected() == 10){
        resetGameState(MapTree, CurrentNode, Character, Map, MappedSprites);
    }
}

void resetGameState(BTree &MapTree, Node* &CurrentNode, class Character &Character, Maps &Map, TreeDungeonGraphics &MappedSprites){
    Node *RootNode;
    int depth = 0;
    while(depth != 4){
        MapTree.~BTree();
        new (&MapTree) class BTree();
        MappedSprites.MapText = generateMap(MapTree);
        RootNode = MapTree.getRoot();
        depth = maxDepth(RootNode);
    }
    Character.~Character();
    new (&Character) class Character();
    MapTree.mapTree(RootNode);
    Map.setCurrentMap(RootNode->NodeMap.currentMap);
    MapTree.inOrder(CurrentNode);
    MapTree.preOrder(CurrentNode);
    MapTree.postOrder(CurrentNode);
    CurrentNode = MapTree.getRoot();
}
