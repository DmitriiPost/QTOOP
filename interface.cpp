#include "interface.h"
#include "polynom.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(400, 300);
    setWindowTitle("Polynom");

    polynom_degree = new QLabel("Polynom size:", this);
    polynom_degree->setGeometry(20, 20, 80, 25);
    size = new QSpinBox(this);
    size->setGeometry(110, 20, 40, 25);

    a_n = new QLabel("Senior coeff =", this);
    a_n->setGeometry(20, 50, 100, 25);

    sen_coeff_re = new QLineEdit("1", this);
    sen_coeff_re->setGeometry(100, 50, 20, 25);

    sen_coeff_im = new QLineEdit("0", this);
    sen_coeff_im->setGeometry(130, 50, 20, 25);

    polynom_roots = new QLabel("Polynom roots:", this);
    polynom_roots->setGeometry(20, 80, 100, 25);

    elems = new QLineEdit("1 0", this);
    elems->setGeometry(20, 110, 200, 25);

    x_Label = new QLabel("x =", this);
    x_Label->setGeometry(20, 140, 20, 25);

    x_re = new QLineEdit("1", this);
    x_re->setGeometry(50, 140, 20, 25);

    x_im = new QLineEdit("0", this);
    x_im->setGeometry(80, 140, 20, 25);

    canon_polynom_btn = new QPushButton("Canon", this);
    canon_polynom_btn->setGeometry(300, 50, 90, 30);

    clas_polynom_btn = new QPushButton("Classic", this);
    clas_polynom_btn->setGeometry(300, 85, 90, 30);

    change_elem_btn = new QPushButton("Change elem", this);
    change_elem_btn->setGeometry(300, 120, 90, 30);

    calc_polynom_btn = new QPushButton("Calc polynom", this);
    calc_polynom_btn->setGeometry(300, 155, 90, 30);

    change_size_btn = new QPushButton("Change size", this);
    change_size_btn->setGeometry(300, 190, 90, 30);

    exit_btn = new QPushButton("Exit", this);
    exit_btn->setGeometry(300, 225, 90, 30);

    output = new QLabel(this);
    output->setGeometry(20, 230, 370, 70);

    connect(canon_polynom_btn, SIGNAL(pressed()), this, SLOT(printCanon()));
}

TInterface::~TInterface() {
    delete polynom_degree;
    delete polynom_roots;
    delete a_n;
    delete sen_coeff_re;
    delete sen_coeff_im;
    delete size;
    delete elems;
    delete x_Label;
    delete x_re;
    delete x_im;
    delete output;
    delete canon_polynom_btn;
    delete clas_polynom_btn;
    delete change_elem_btn;
    delete calc_polynom_btn;
    delete change_size_btn;
    delete exit_btn;
}

TArray TInterface::readArr(){
    QString s = elems->text();
    int sizeArr = size->text().toInt();
    TArray arr(sizeArr);
    QStringList strList = s.split(" ");
    for (int i = 0; i < strList.length(); i+=2) {
        if (i + 1 >= strList.length())
        {
            break;
        }
        double elem_re, elem_im;
        elem_re = strList[i].toDouble();
        elem_im = strList[i + 1].toDouble();
        number elem(elem_re, elem_im);
        arr.changeElement(elem, int(i / 2));
    }
    return arr;
}

void TInterface::printCanon() {
    QString s;
    s += "Polynom: ";
    double seniorCoeff_re, seniorCoeff_im;
    seniorCoeff_re = sen_coeff_re->text().toDouble();
    seniorCoeff_im = sen_coeff_im->text().toDouble();
    number seniorCoeff(seniorCoeff_re, seniorCoeff_im);
    int sizeArr = size->text().toInt();
    TArray arr = readArr();
    //s += QString().setNum(sizeArr);
    //s << arr.getElem(1);
    TPolynom p(seniorCoeff, arr, sizeArr);
    s += p.polynomCanonToQString();
    output->setText(s);
}
