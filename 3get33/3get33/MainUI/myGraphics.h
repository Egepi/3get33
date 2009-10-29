#ifndef MYGRAPHICS_H
#define MYGRAPHICS_H
#include <QGraphicsItem>

class myGraphics : public QGraphicsItem
{
    public:
        myGraphics();
        int graphicType;
        int getGraphicType();
        void setGraphicType(int newVal);
};
#endif // MYGRAPHICS_H
