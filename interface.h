#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>

#include "polynom.h"

class TInterface : public QWidget
{
    Q_OBJECT

    QLabel *polynom_degree, *polynom_roots, *a_n, *x_Label, *output;
    QSpinBox *size;
    QLineEdit *elems, *sen_coeff_re, *sen_coeff_im, *x_re, *x_im;
    QPushButton *canon_polynom_btn;
    QPushButton *clas_polynom_btn;
    QPushButton *change_elem_btn;
    QPushButton *calc_polynom_btn;
    QPushButton *change_size_btn;
    QPushButton *exit_btn;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

    TArray readArr();


public slots:
    void printCanon();
};
#endif // INTERFACE_H
