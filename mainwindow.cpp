#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,330,30);
    trem2 = new Trem(2,730,90);
    trem3 = new Trem(3,60,210);
    trem4 = new Trem(4,460,270);
    trem5 = new Trem(5,830,210);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    connect(QCoreApplication::instance(), &QCoreApplication::aboutToQuit, this, &MainWindow::onAboutToQuit);

    init();
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao iniciar, trens começam execução
 */
void MainWindow::init()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::onAboutToQuit() {
    QMessageBox::information(this, "Fechando o Programa", "O programa foi encerrado com sucesso!");

    trem1->desbloquearMutexes();
}

void MainWindow::on_horizontalSlider1_valueChanged(int value)
{
    trem1->atualizarVelocidade(value);
    trem1->startTrem();
}

void MainWindow::on_horizontalSlider2_valueChanged(int value)
{
    trem2->atualizarVelocidade(value);
    trem2->startTrem();
}

void MainWindow::on_horizontalSlider3_valueChanged(int value)
{
    trem3->atualizarVelocidade(value);
    trem3->startTrem();
}

void MainWindow::on_horizontalSlider4_valueChanged(int value)
{
    trem4->atualizarVelocidade(value);
    trem4->startTrem();
}

void MainWindow::on_horizontalSlider5_valueChanged(int value)
{
    trem5->atualizarVelocidade(value);
    trem5->startTrem();
}
