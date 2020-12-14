#ifndef DEQUEUE_
#define DEQUEUE_

template <class T>
class cella
{
    T e;
    cella *prev;
    cella *succ;
};

template <class elem>
class dequeue
{
public:
    dequeue();
    ~dequeue();
    void push_back(const elem &);
    void push_front(const elem &);
    elem pop_back();
    elem pop_front();
    bool dequeueVuota();

private:
    cella<elem> *testa;
    cella<elem> *coda;
};

template <class elem>
dequeue<elem>::dequeue(){
    testa = nullptr;
    coda = nullptr;
}

template <class elem>
dequeue<elem>::~dequeue(){
    while(!dequeueVuota()) {
        pop_back();
    }
}

template <class elem>
bool dequeue<elem>::dequeueVuota(){
    return testa == nullptr;
}
template <class elem>
void dequeue<elem>::push_back(const elem &el){
    cella<elem> *tmp = new cella<elem>();
    tmp->e = el;
    tmp->prev = coda;
    tmp->succ = nullptr;
    coda = tmp;
}

template <class elem>
void dequeue<elem>::push_front(const elem &el){
    cella<elem> *tmp = new cella<elem>();
    tmp->e = el;
    tmp->prev = nullptr;
    tmp->succ = testa;
    testa = tmp;
}

template <class elem>
elem dequeue<elem>::pop_back() {
    if (!dequeueVuota()) {
        elem tmp = coda->e;
        cella<elem> *t = coda;
        coda = coda->prev;
        delete t;
        return tmp;
    }
    else throw "Dequeue empty";
}

template <class elem>
elem dequeue<elem>::pop_front() {
    if (!dequeueVuota()) {
        elem tmp = testa->e;
        cella<elem> *t = testa;
        testa = testa->succ;
        delete t;
        return tmp;
    }
    else throw "Dequeue empty";
}
#endif