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