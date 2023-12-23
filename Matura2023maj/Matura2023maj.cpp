#include <iostream>

const int DATA[] = {14, 18, 12, 9, 20, 15, 17};
const int ROWS = sizeof(DATA) / sizeof(DATA[0]);

int** buildLibrary()
{
    int** lib = new int* [ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        lib[i] = new int[pow(2, i)];
        for (int j = 0; j < pow(2, i); j++)
        {
            lib[i][j] = 0;
            std::cout << lib[i][j] << ',';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return lib;
}   

void readLibrary(int* lib[])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < pow(2, i); j++)
        {
            std::cout << lib[i][j] << ',';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void insertToLibrary(int* lib[], int x, int y, int i)
{
    if (i == (sizeof(DATA) / sizeof(DATA[0])))
        return readLibrary(lib);

    if (lib[x][y-1]==0)
    {
        lib[x][y-1] = DATA[i];
        return insertToLibrary(lib, 0, 1, i+1);
    }
    else if (lib[x][y-1]<DATA[i])
    {
        return insertToLibrary(lib, x+1, y*2, i);
    }
    else if (lib[x][y-1] > DATA[i])
    {
        return insertToLibrary(lib, x+1, (y * 2)-1, i);
    }
}

int main()
{
    int** lib = buildLibrary();
    
    insertToLibrary(lib, 0, 1, 0);    
}
