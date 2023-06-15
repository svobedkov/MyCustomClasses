#ifndef PROJECTCPP_HEADERS_H
#define PROJECTCPP_HEADERS_H

#include <memory>
#include <iostream>

template<typename T>
struct node {
    T value;
    std::unique_ptr<node> next = nullptr;

    node();
    explicit node(T temp) : value(temp) {}
    ~node() = default;    //Check destructor
};

template<typename T>
node<T>::node() = default;

template<typename T>
class stack {
public:
    bool isEmpty{true};

    explicit stack();
    ~stack() = default; //Check destructor

    void map();
    virtual void push(T val);
    T pop();
    int size();

    virtual void clear();
    T check();

protected:
    std::unique_ptr<node<T>> root;
    int m_size{0};
};

template<typename T>
void stack<T>::map() {
    node<T> *p;
    p = this->root.get();
    if (isEmpty) {
        return;
    }
    do {
        std::cout << p->value;
        if (p->next.get() != nullptr) {
            p = p->next.get();
            std::cout << ", ";
        }
    } while (p->next.get() != nullptr);
    if (m_size >= 2) {
        std::cout << p->value;
    }
    return;
}

template<typename T>
void stack<T>::clear() {
    while (!isEmpty) {
        this->pop();
    }
}

template<typename T>
T stack<T>::check() {
    T res;
    if (isEmpty) {
        exit(1);
    }
    res = root->value;
    return res;
}

template<typename T>
int stack<T>::size() {
    return m_size;
}

template<typename T>
T stack<T>::pop() {
    if (isEmpty) {
        exit(1);
    } else {
        std::unique_ptr<node<T>> p = nullptr;
        p = std::move(root);
        root = std::move(p->next);
        T res{p->value};
        p.release();
        m_size -= 1;
        if (m_size == 0) {isEmpty = true;}
        return res;
    }
}

template<typename T>
void stack<T>::push(T val) {
    if (isEmpty) {
        std::unique_ptr<node<T>> temp(new node<T>);
        root = std::move(temp);
        root->value = val;
        m_size += 1;
        isEmpty = false;
        return;
    } else {
        std::unique_ptr<node<T>> temp(new node<T>);
        temp->value = val;
        temp->next = std::move(root);
        root = std::move(temp);
        m_size += 1;
        isEmpty = false;
        return;
    }
}

template<typename T>
stack<T>::stack() {
    m_size = 0;
    isEmpty = true;
}

template<typename T>
class queue: public stack<T> {
public:
    queue();
    ~queue() = default;
    void push(T val);
    void clear();
    T check_other_side();
protected:
    node<T> *p_cur;
};

template<typename T>
T queue<T>::check_other_side() {
    if (this->isEmpty) {
        exit(1);
    } else {return p_cur->value;}
}

template<typename T>
void queue<T>::clear() {
    stack<T>::clear();
    p_cur = nullptr;
    return;
}

template<typename T>
void queue<T>::push(T val) {
    if (this->isEmpty) {
        std::unique_ptr<node<T>> temp(new node<T>);
        this->root = std::move(temp);
        this->root->value = val;
        this->m_size += 1;
        this->isEmpty = false;
        p_cur = this->root.get();
        return;
    } else {
        std::unique_ptr<node<T>> temp(new node<T>);
        p_cur->next = std::move(temp);
        p_cur = p_cur->next.get();
        p_cur->value = val;
        this->m_size += 1;
        return;
    }
}

template<typename T>
queue<T>::queue() {
    this->m_size = 0;
    this->isEmpty = true;
    p_cur = nullptr;
}

template<typename T>
struct node_mod {
    node_mod *prev = nullptr;
    T value;
    std::unique_ptr<node_mod> next = nullptr;

    node_mod();
    node_mod(T temp) : value(temp) {}
    ~node_mod() = default;    //Check destructor
};

template<typename T>
node_mod<T>::node_mod() = default;

template<typename T>
class deque {
public:
    bool isEmpty{true};

    deque();
    ~deque() = default; //Check destructor

    void push_front(T val);
    void push_back(T val);
    T pop_front();
    T pop_back();
    int size();
    void clear();
    T front();
    T back();
protected:
    std::unique_ptr<node_mod<T>> root;
    int m_size{0};
    node_mod<T> *p_cur;
};

template<typename T>
void deque<T>::clear() {
    while (!isEmpty) {
        this->pop_front();
    }
}

template<typename T>
T deque<T>::pop_back() {
    if (isEmpty) {
        exit(1);
    }
    T res;
    res = root->value;
    if (m_size >= 2) {
        std::unique_ptr<node_mod<T>> temp;
        temp = std::move(root);
        root = std::move(temp->next);
        temp.release();
        root->prev = nullptr;
        m_size -= 1;
        return res;
    } else {
        root.release();
        m_size = 0;
        isEmpty = true;
        return res;
    }
}

template<typename T>
T deque<T>::pop_front() {
    if (isEmpty) {
        exit(1);
    }
    T res;
    res = p_cur->value;
    if (m_size >= 2) {
        p_cur = p_cur->prev;
        p_cur->next.release();
        m_size -= 1;
        return res;
    } else {
        root.release();
        m_size = 0;
        isEmpty = true;
        return res;
    }
}

template<typename T>
T deque<T>::back() {
    return root->value;
}

template<typename T>
T deque<T>::front() {
    return p_cur->value;
}

template<typename T>
int deque<T>::size() {
    return m_size;
}

template<typename T>
void deque<T>::push_back(T val) {
    if (isEmpty) {
        std::unique_ptr<node_mod<T>> temp(new node_mod<T>);
        root = std::move(temp);
        root->value = val;
        m_size += 1;
        isEmpty = false;
        p_cur = this->root.get();
        return;
    } else {
        std::unique_ptr<node_mod<T>> temp(new node_mod<T>);
        root->prev = temp.get();
        temp->value = val;
        temp->next = std::move(root);
        root = std::move(temp);
        m_size += 1;
        return;
    }
}

template<typename T>
void deque<T>::push_front(T val) {
    if (isEmpty) {
        std::unique_ptr<node_mod<T>> temp(new node_mod<T>);
        root = std::move(temp);
        root->value = val;
        m_size += 1;
        isEmpty = false;
        p_cur = this->root.get();
        return;
    } else {
        std::unique_ptr<node_mod<T>> temp(new node_mod<T>);
        p_cur->next = std::move(temp);
        p_cur->next->prev = p_cur;
        p_cur = p_cur->next.get();
        p_cur->value = val;
        m_size += 1;
        return;
    }
}

template<typename T>
deque<T>::deque() {
    this->m_size = 0;
    this->isEmpty = true;
    this->p_cur = nullptr;
}

#endif