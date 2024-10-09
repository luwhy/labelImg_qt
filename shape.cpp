#include "shape.h"

Shape::Shape(QString label, QColor line_color, bool difficult, bool paintLabel, QString extra_label)
{
    this->label              = label;
    this->line_color         = line_color;
    this->fill_color         = QColor(255, 0, 0, 128);
    this->select_line_color  = QColor(255, 255, 255);
    this->vertex_fill_color  = QColor(0, 255, 0, 255);
    this->hvertex_fill_color = QColor(255, 0, 0);

    this->fill            = false;
    this->selected        = false;
    this->difficult       = difficult;
    this->paintLabel      = paintLabel;
    this->extra_label     = extra_label;
    this->direction       = 0;
    this->isRotated       = true;
    this->highlightCorner = false;
    this->_closed         = false;
}
