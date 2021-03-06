/* 
 * File:   Board.h
 * Author: Akshat Khare Divyanshu Saxena
 * 
 */
#ifndef BOARD_H
#define	BOARD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TimeHelper.h"
using namespace std;

extern int n, m, k, l;  
// n is hexagon size
// m is the number of rings each player has
// k is number of markers in line each player has to create to remove k markers
// l is number of rings one player must remove before other player to win

extern int time_limit;
extern int max_depth;
extern ofstream outfile;
extern ofstream outfileShaved;
extern TimeHelper * timeHelper;

// Hyper Parameters
extern bool DEBUG_EVAL;
extern bool NON_FLIP;
extern bool WRITE_FILE;
extern bool TIME_DEBUG;

class Board{
    public:
        int ** config;
        vector<pair<int,int>> p1Rings;
        vector<pair<int,int>> p2Rings;
        int ** getConfig();
        
        // Initialization
        Board();
        Board(int, int, int, int);

        // Accessor Methods
        pair <int, int> getCoordinates(int, int);
        vector<pair<int,int>> showPossibleMoves(int, int);
        vector<pair<int,int>> getFreePointsAdjacentToPoint(pair<int,int>, int);
        pair<int,int> getPairAfterMarkers(pair<int,int>, int);
        void updateRingPositions();
        void printnormalconfig();
        void printnormalconfigShaved();
        void printBeautifiedconfig();
        void printBeautifiedconfigShaved();
        void printMoreBeautifiedconfig();
        // Operate on rings and markers on board
        bool addRing(int, int, int);
        pair<int,int> occupyCorners();
        pair<int,int> blockOpponentRings();
        pair<int,int> makeInitialMoves(int);

        pair<int, int> checkKRingsInRow();
        bool setMarker(pair<int,int>, int);
        bool selectAndMoveRing(int, int, int, int);
        bool removeMarkers(int, int, int, int);
        bool removeRing(int, int);
        bool isFlippable(int, int);
        pair<int, int> getHexagonalCoordinate(int, int);
        void printhexagonalconfig();
        pair<int,int> getDirectionVector(pair<int,int> inipoint, pair<int,int> finpoint);
        void createBoardFromFile(string);
};

extern Board* board;
extern int player_id;

#endif /* Board_H */