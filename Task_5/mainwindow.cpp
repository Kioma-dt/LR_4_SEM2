#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow), vector_(size_) {
    ui_->setupUi(this);

    ui_->tableWidget1->setRowCount(0);
    ui_->tableWidget1->setColumnCount(columsFirst_);
    ui_->tableWidget1->setHorizontalHeaderLabels({"Int"});
    ui_->tableWidget1->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch);
    ui_->tableWidget1->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui_->tableWidget1->setSelectionMode(QAbstractItemView::SingleSelection);
    ui_->tableWidget1->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui_->tableWidget2->setRowCount(0);
    ui_->tableWidget2->setColumnCount(columsSecond_);
    ui_->tableWidget2->setHorizontalHeaderLabels({"Int", "Double"});
    ui_->tableWidget2->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch);
    ui_->tableWidget2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui_->tableWidget2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui_->tableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui_->buttonAddFirst, &QPushButton::clicked, this,
            &MainWindow::AddFirst);
    connect(ui_->buttonAddSecond, &QPushButton::clicked, this,
            &MainWindow::AddSecond);
}

MainWindow::~MainWindow() {
    delete ui_;
}

template <typename T>
void MainWindow::WriteToTable(QTableWidget* table, const Vector<T>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        WriteItem(table, vector[i], i);
    }
}

void MainWindow::WriteItem(QTableWidget* table, int number, int pos) {
    QTableWidgetItem* item;

    item = new QTableWidgetItem(QString::number(number));
    item->setTextAlignment(Qt::AlignCenter);
    table->setItem(pos, 0, item);
}

void MainWindow::WriteItem(QTableWidget* table, const Pair<int, double>& pair,
                           int pos) {
    QTableWidgetItem* item;

    item = new QTableWidgetItem(QString::number(pair.first));
    item->setTextAlignment(Qt::AlignCenter);
    table->setItem(pos, 0, item);

    item = new QTableWidgetItem(QString::number(pair.second));
    item->setTextAlignment(Qt::AlignCenter);
    table->setItem(pos, 1, item);
}

void MainWindow::AddFirst() {
    try {
        bool ok = false;
        int number = ui_->lineEditFirstInt->text().toInt(&ok);


        if (!ok) {
            throw std::runtime_error("Wrong Number Format");
        }

        Vector<int>& vector = vector_.front().first;

        size_t selected_row = vector.size() - 1;

        if (!ui_->tableWidget1->selectedItems().empty()) {
            selected_row = ui_->tableWidget1->currentRow();
        }

        if (selected_row == vector.size() - 1) {
            vector.push_back(number);
        } else {
            vector.insert(vector.begin() + selected_row + 1, number);
        }

        ui_->tableWidget1->setRowCount(vector.size());
        WriteToTable(ui_->tableWidget1, vector);
    }


    catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Can't Add to First Matrix", e.what());
    }
}

void MainWindow::AddSecond() {
    try {
        bool ok_1 = false, ok_2 = false;
        int number_1 = ui_->lineEditSecondInt->text().toInt(&ok_1);
        double number_2 = ui_->lineEditSecondDouble->text().toDouble(&ok_2);


        if (!ok_1 || !ok_2) {
            throw std::runtime_error("Wrong Number Format");
        }

        Vector<Pair<int, double>>& vector = vector_.front().second;
        Pair<int, double> pair = make_pair(number_1, number_2);

        size_t selected_row = vector.size() - 1;

        if (!ui_->tableWidget2->selectedItems().empty()) {
            selected_row = ui_->tableWidget2->currentRow();
        }

        if (selected_row == vector.size() - 1) {
            vector.push_back(pair);
        } else {
            vector.insert(vector.begin() + selected_row + 1, pair);
        }

        ui_->tableWidget2->setRowCount(vector.size());
        WriteToTable(ui_->tableWidget2, vector);
    }


    catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Can't Add to Second Matrix", e.what());
    }
}
