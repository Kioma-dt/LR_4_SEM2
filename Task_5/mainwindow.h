#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "iterator.cpp"
#include "pair.cpp"
#include "vector.cpp"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    Ui::MainWindow* ui_;
    Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> vector_;
    uint columsFirst_ = 1;
    uint columsSecond_ = 2;
    size_t size_ = 1;

    template <typename T>
    void WriteToTable(QTableWidget* table, const Vector<T>& vector);
    void WriteItem(QTableWidget* table, int number, int pos);
    void WriteItem(QTableWidget* table, const Pair<int, double>& pair, int pos);

   private slots:
    void AddFirst();
    void AddSecond();
};
#endif	// MAINWINDOW_H
