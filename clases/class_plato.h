#ifndef CLASS_PLATO_H
#define CLASS_PLATO_H
class Plato
{
    private:
        bool limpio; /* True o False */
    public:
        Plato(){
            limpio = false;
        }
        bool getPlato(){
            return limpio;
        }
        void cambiarLimpio(){
            limpio = !limpio;
        }
};
#endif // CLASS_PLATO_H