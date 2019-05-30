#ifndef CANDY1_H
#define CANDY1_H



class candy1
{
    public:
        candy1(){};
        candy1(char c):col(c){};
        virtual ~candy1();
        void affiche(){}
    protected:

    private:
        char col;
};

#endif // CANDY1_H
