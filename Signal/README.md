# Signal

Un **Signal** est une grandeur qui peut varier dans le temps.  

# Programme de Test

Le programme de test :

```
//===============================================
void GProcess::run() {
    GSignal::Instance()->sinus();

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

Les signaux d�velopp�s :

```
public:
    void sinus(); //signal sinus
    void cosinus(); // signal cosinus
    void halfwave(); // signal mono-alternance
    void fullwave(); // signal double-alternance
    void square(); // signal carr�
    void triangle(); // signal triangle
    void sawtooth(); // signal dent de scie
    void polynomial(); // signal polyn�me
```

G�n�ration d'un Signal

**GSignal** est la classe charg�e de la g�n�ration de signaux.
GSignal::Instance()->sinus();

# Signal Sinus

Le signal sinus :

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/sinus.png)

# Signal Cosinus

Le signal cosinus :

![Signal Cosinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/cosinus.png)

# Signal Mono-Alternance

Le signal mono-alternance :

![Signal Mono-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/halfwave.png)

# Signal Double-Alternance

Le signal double-alternance :

![Signal Double-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/fullwave.png)

# Signal Carr�

Le signal carr� :

![Signal Carr�](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/square.png)

# Signal Triangle

Le signal triangle :

![Signal Triangle](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/triangle.png)

# Signal Dent de Scie

Le signal dent de scie :

![Signal Dent de Scie](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/sawtooth.png)

# Signal Polyn�me

Le signal polyn�me :

![Signal Polyn�me](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/polynomial.png)
