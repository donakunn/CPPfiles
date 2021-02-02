#ifndef GRID_H
#define GRID_H
#include "linked_list.h"
#include "exceptions.h"
#include <iostream>

class grid;
class cell
{
    friend class grid;

public:
    cell(){};
    cell(int x, int y) : X(x), Y(y){};
    bool operator==(const cell &c1)
    {
        return ((this->X == c1.X) && (this->Y == c1.Y));
    }

private:
    int X;
    int Y;
};

class grid
{
public:
    // inserisce una cella viva nella griglia
    void insert(cell &);
    // rimuove una cella nella griglia
    void remove(cell &);
    // sposta a sinistra di una posizione la cella viva presente in posizione (x,y)
    void moveLeft(int x, int y);
    // sposta a destra di una posizione la cella viva presente in posizione (x,y)
    void moveRight(int x, int y);
    // sposta in alto di una posizione la cella viva presente in posizione (x,y)
    void moveUpper(int x, int y);
    // sposta in basso di una posizione la cella viva presente in posizione (x,y)
    void moveDown(int x, int y);
    // stabilisce se la cella viva presente in posizione (x,y) `e circondata,
    // ovvero tutte le celle vicine alla cella data sono vive
    bool surrounded(int x, int y);
    // rimuove dalla griglia tutte le celle circondate
    void removeSurrounded();

    void print()
    {
        Linked_list<cell>::position pos;
        pos = cells.begin();
        while (!cells.end(pos))
        {
            std::cout << " (" << cells.read(pos).X << "," << cells.read(pos).Y << ") ";
            pos = cells.next(pos);
        }
        std::cout << endl;
    }

private:
    bool contiene(int, int);
    Linked_list<cell> cells;
};

bool grid::contiene(int x, int y)
{
    Linked_list<cell>::position pos;
    pos = cells.begin();
    while (!cells.end(pos))
    {
        if (cells.read(pos).X == x && cells.read(pos).Y == y)
            return true;
        pos = cells.next(pos);
    }
    return false;
}
void grid::insert(cell &C)
{
    Linked_list<cell>::position pos;
    pos = cells.begin();
    while (!cells.end(pos))
    {
        if (cells.read(pos) == C)
            return;
        pos = cells.next(pos);
    }
    cells.insert(C, pos);
}

void grid::remove(cell &C)
{
    Linked_list<cell>::position pos;
    pos = cells.begin();
    while (!cells.end(pos))
    {
        if (cells.read(pos) == C)
        {
            cells.erase(pos);
            return;
        }
        pos = cells.next(pos);
    }
}
void grid::moveLeft(int x, int y)
{
    Linked_list<cell>::position pos;
    pos = cells.begin();
    while (!cells.end(pos))
    {
        if (cells.read(pos).X == x && cells.read(pos).Y == y)
        {
            Linked_list<cell>::position pos2;
            pos2 = cells.begin();
            while (!cells.end(pos2))
            {
                if (cells.read(pos).Y == y - 1)
                {
                    throw AliveCell();
                }
                pos2 = cells.next(pos2);
            }
            cells.erase(pos);
            cell newCell(x, y - 1);
            pos = cells.next(pos);
            cells.insert(newCell, pos);
            return;
        }
        pos = cells.next(pos);
    }
}

void grid::moveRight(int x, int y)
{
    Linked_list<cell>::position pos;
    pos = cells.begin();
    while (!cells.end(pos))
    {
        if (cells.read(pos).X == x && cells.read(pos).Y == y)
        {
            Linked_list<cell>::position pos2;
            pos2 = cells.begin();
            while (!cells.end(pos2))
            {
                if (cells.read(pos).Y == y + 1)
                {
                    throw AliveCell();
                }
                pos2 = cells.next(pos2);
            }
            cells.erase(pos);
            pos = cells.next(pos);
            cell newCell(x, y + 1);
            cells.insert(newCell, pos);
            return;
        }
        pos = cells.next(pos);
    }
}
void grid::moveDown(int x, int y)
{
    Linked_list<cell>::position pos;
    pos = cells.begin();
    while (!cells.end(pos))
    {
        if (cells.read(pos).X == x && cells.read(pos).Y == y)
        {
            Linked_list<cell>::position pos2;
            pos2 = cells.begin();
            while (!cells.end(pos2))
            {
                if (cells.read(pos).X == x + 1)
                {
                    throw AliveCell();
                }
                pos2 = cells.next(pos2);
            }
            cells.erase(pos);
            pos = cells.next(pos);
            cell newCell(x + 1, y);
            cells.insert(newCell, pos);
            return;
        }
        pos = cells.next(pos);
    }
}

void grid::moveUpper(int x, int y)
{
    Linked_list<cell>::position pos;
    pos = cells.begin();
    while (!cells.end(pos))
    {
        if (cells.read(pos).X == x && cells.read(pos).Y == y)
        {
            Linked_list<cell>::position pos2;
            pos2 = cells.begin();
            while (!cells.end(pos2))
            {
                if (cells.read(pos).X == x - 1)
                {
                    throw AliveCell();
                }
                pos2 = cells.next(pos2);
            }
            cells.erase(pos);
            pos = cells.next(pos);
            cell newCell(x - 1, y);
            cells.insert(newCell, pos);
            return;
        }
        pos = cells.next(pos);
    }
}

bool grid::surrounded(int x, int y)
{
    if (contiene(x, y))
    {
        if (contiene(x + 1, y) && contiene(x - 1, y) && contiene(x, y + 1) && contiene(x, y - 1))
            return true;
    }
    return false;
}

void grid::removeSurrounded()
{
    Linked_list<cell>::position pos;
    pos = cells.begin();
    while (!cells.end(pos))
    {
        if (surrounded(cells.read(pos).X, cells.read(pos).Y))
            cells.erase(pos);
        pos = cells.next(pos);
    }
}

#endif