# Signal

Un **Signal** est une grandeur qui peut varier dans le temps.  

# Programme de Test

Le programme de test :

```
//===============================================
void GProcess::run() {
    GSignal::Instance()->sawtooth();

    QVector<double> m_x = GSignal::Instance()->getX();
    QVector<double> m_y = GSignal::Instance()->getY();
    double m_xmin = GSignal::Instance()->getXmin();
    double m_xmax = GSignal::Instance()->getXmax();
    double m_ymin = GSignal::Instance()->getYmin();
    double m_ymax = GSignal::Instance()->getYmax();

    QCustomPlot* m_graph = GGraphView::Instance()->graph();
    m_graph->addGraph();
    m_graph->graph(0)->setData(m_x, m_y);
    m_graph->graph(0)->setPen(QPen(QBrush("blue"), 1));

    m_graph->xAxis->setRange(m_xmin, m_xmax);
    m_graph->yAxis->setRange(m_ymin, m_ymax);
}
//===============================================
```

Les signaux développés :

```
public:
    void sinus(); //signal sinus
    void cosinus(); // signal cosinus
    void halfwave(); // signal mono-alternance
    void fullwave(); // signal mono-alternance
    void square(); // signal carré
    void triangle(); // signal triangle
    void sawtooth(); // signal dent de scie
    void polynomial(); // signal polynome
```

# Dent de Scie

Le signal dent de scie :

![Dent de Scie](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/sawtooth.png)

