#ifndef FIELD_H
#define FIELD_H

class Field
{
    public:
        Field();
        void drawField();
        int *getField();
        void setField(int position, int playerNumber)        { positions[position] = playerNumber; }
        ~Field();
    protected:
        int positions[9];
};

#endif // FIELD_H
