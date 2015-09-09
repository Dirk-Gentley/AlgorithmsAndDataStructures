//
//  RunBinaryTreeDungeon.cpp
//  Trevors_Traversal
//
//  Created by Benjamin Waters on 9/09/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include <ResourcePath.hpp>

void beginBinaryTreeDungeon(sf::RenderWindow& window){
    Node *RootNode;
    int depth = 0;
    //sf::Event Event;

    sf::Texture BinaryTreeTexture = MappedSprites.initTextures();
    sf::Texture BinaryTreeBackground = MappedSprites.initBackground();
    MappedSprites.initSprites(BinaryTreeTexture, Character);
    MappedSprites.initBGSprite(BinaryTreeBackground);

    while(depth != 4){
        MapTree.~BTree();
        new (&MapTree) class BTree();
        MappedSprites.MapText = generateMap(MapTree);
        RootNode = MapTree.getRoot();
        depth = maxDepth(RootNode);
    }
    RootNode = MapTree.getRoot();
    Node *CurrentNode = MapTree.getRoot();
    CurrentNode = MapTree.getRoot();
    MapTree.mapTree(CurrentNode);
    
    // Start the binary tree dungeon game loop
    
    while (1){
        Map.setCurrentMap(CurrentNode->NodeMap.currentMap);
        if(input(window, Character, Map, CurrentNode, MapTree, MappedSprites) == 0){
            return;
        }
        lineOfSight(Map, Character);
        updateGraphics(window, MappedSprites, Map, Character, MapTree, CurrentNode);
        CurrentNode = updateMap(Character, Map, CurrentNode, RootNode);
        updateGame(MapTree, CurrentNode, Character, Map, MappedSprites);
        RootNode = MapTree.getRoot();
    }
}
