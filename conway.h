#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum CWY_Entities {
    DEAD_CELL,
    LIVE_CELL,
};

typedef unsigned short int CWY_int;

const CWY_int CWY_neighboursForLiveCellSpawn = 3;
const CWY_int CWY_maxNeighboursToLive = 3;
const CWY_int CWY_minNeighboursToLive = 2;

const CWY_int CWY_deltaVector[] = { -1, 0, 1 };

CWY_int* generateEmptyConwayMatrixVector(int m) {
    CWY_int* cellVector = (CWY_int *) malloc(m * sizeof(CWY_int));

    for(int i = 0; i < m; i++) {
        cellVector[i] = DEAD_CELL;
    }

    return cellVector;
}


CWY_int **generateEmptyConwayMatrix(int n, int m) {
    CWY_int **conwayMatrix = (CWY_int **) malloc(n * sizeof(CWY_int *));

    for(int i = 0; i<n; i++) {
        conwayMatrix[i] = generateEmptyConwayMatrixVector(m);
    }

    return conwayMatrix;
}

void logConwayMatrix(CWY_int **conwayMatrix, int n, int m) {
    printf("\n");
    for(int i=0; i<n;i++) {
        for(int j=0; j<m; j++) {
            printf("%i", conwayMatrix[i][j]);
        }
        printf("\n");
    }
}

int checkIfCoordsAreInBounds(int n, int m, int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int canCellSurvive(CWY_int currentCellValue, CWY_int cellNeighbours) {
    return currentCellValue == LIVE_CELL 
            && cellNeighbours >= CWY_minNeighboursToLive 
            && cellNeighbours <= CWY_maxNeighboursToLive;
}

int canCellBeSpawned(CWY_int currentCellValue, CWY_int cellNeighbours) {
    return currentCellValue == DEAD_CELL 
        && cellNeighbours == CWY_neighboursForLiveCellSpawn;
}

int getCellState(CWY_int currentCellValue, CWY_int cellNeighbours) {
    if(!canCellSurvive(currentCellValue, cellNeighbours) 
        && !canCellBeSpawned(currentCellValue, cellNeighbours)) {

        return DEAD_CELL;
    }
    return LIVE_CELL;
}



int checkConwayCellState(CWY_int **conwayMatrix, int n, int m, int i, int j) {
    int sum = 0;
    for(int iCoord = -1; iCoord <= 1; iCoord++) {
        for(int jCoord = -1; jCoord <= 1; jCoord++) {
            int newICoord = iCoord + i;
            int newJCoord = jCoord + j;

            if(checkIfCoordsAreInBounds(n,m,newICoord,newJCoord) && (i != 0 || j != 0)) {
                sum+= conwayMatrix[newICoord][newJCoord];
            }
        }
    }
    return sum;
}
CWY_int **updateConwayMatrix(CWY_int **conwayMatrix, int n, int m) {
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            int cellNeighbours = checkConwayCellState(conwayMatrix,n,m,i,j);
            int currentCellValue = conwayMatrix[i][j];
            int cellState = getCellState(currentCellValue, cellNeighbours);
            conwayMatrix[i][j] = cellState;
        }
    }

    return conwayMatrix;
}




void runConway() {
    int n = 50; 
    int m = 50;
    int counter = 0;
    time_t startTime = (unsigned)time(NULL);
    CWY_int** conwayMatrix = generateEmptyConwayMatrix(n, m);
    conwayMatrix[15][24] = LIVE_CELL;
    conwayMatrix[15][25] = LIVE_CELL;
    conwayMatrix[15][26] = LIVE_CELL;
    while(1){
        counter++;
        if((unsigned)time(NULL) - startTime > 1) {
            printf("Cycles: %i\n", counter);
            startTime = (unsigned)time(NULL);
            counter = 0;
        }
        updateConwayMatrix(conwayMatrix, n, m);
        // logConwayMatrix(conwayMatrix, n, m);
    }

}

