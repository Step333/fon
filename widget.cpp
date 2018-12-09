#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(time()));
    timer.start(0.000001);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::time()
{
    if (r < 255 and g == 0 and b == 0) {
        r++;
    } else if (r == 255 and g < 255 and b == 0) {
        g++;
    } else if (r == 255 and g == 255 and b < 255) {
        b++;
    } else if (r > 0 and g == 255 and b == 255) {
        r--;
    } else if (r == 0 and g > 0 and b == 255) {
        g--;
    } else if (r == 0 and g == 0 and b > 0) {
        b--;
    }
    repaint();
}

void Widget::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor::fromRgb(r, g, b)));
    int width = this->width();
    int height = this->height();
    painter.drawRect(-10, -10, width + 20, height + 20);
}
