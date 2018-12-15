#ifndef GAMESTATUT_H
#define GAMESTATUT_H
#include <vector>

class GameStatut
{
    public:
        GameStatut(int nbLaser,int maxIter);
        /** accesseur de base */
        const bool inMove(int n) const;
        const bool touch(int n)const;
        const int score()const;
        const int iteration() const;

        /**modificateur de base*/
        void setInMoveFalse(int n);
        void setTouchTrue(int n);
        void addScore(int score);
        void increaseIter();

    private:
        std::vector<bool> in_move;
        std::vector<bool> d_touch;
        int d_score;
        int d_iteration;
        const int maxIter;
};

#endif // GAMESTATUT_H
