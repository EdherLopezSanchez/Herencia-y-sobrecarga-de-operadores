#include <iostream>
#include <string.h>

class Mamifero
{
    protected:
        int FechaNacimiento;
        std::string LugarNacimiento;

    public:
        Mamifero(int fn, std::string ln): FechaNacimiento(fn), LugarNacimiento(ln){}

        void ImprimirNacimiento()
        {
            std::cout<<FechaNacimiento<<std::endl<<LugarNacimiento<<std::endl;
        }

        friend Mamifero operator + (Mamifero a,Mamifero b)
        {
            return Mamifero(a.FechaNacimiento + b.FechaNacimiento, a.LugarNacimiento + b.LugarNacimiento);
        }

        bool operator == (const Mamifero &a)
        {
            if(FechaNacimiento == a.FechaNacimiento && LugarNacimiento == a.LugarNacimiento)
            {
                return true;
            }
            return false;
        }

        bool operator != (const Mamifero &a)
        {
            if(FechaNacimiento < a.FechaNacimiento)
            {
                return true;
            }
            return false;
        }

        bool operator > (const Mamifero &a)
        {
            if(FechaNacimiento > a.FechaNacimiento)
            {
                return true;
            }
            return false;
        }
};

class Felino : public Mamifero
{
    protected:
        std::string Dieta;
        std::string Raza;
        std::string Circo;

    protected:
    public:
        Felino(int fn, std::string ln, std::string diet, std::string ra, std::string cir): Mamifero(fn, ln), Dieta(diet), Raza(ra), Circo(cir){}

        void ImprimirDieta()
        {
            std::cout<<Dieta<<std::endl;
        }

        void ImprimirRaza()
        {
            std::cout<<Raza<<std::endl;
        }

        void CambiarCirco(std::string NuevoCirco)
        {
            Circo = NuevoCirco;
        }

        friend Felino operator + (Felino a, Felino b)
        {
            a.FechaNacimiento += b.FechaNacimiento;
            a.LugarNacimiento += b.LugarNacimiento;
            a.Dieta += b.Dieta;
            a.Raza += b.Raza;
            a.Circo += b.Circo;
            return Felino(a);
        }

        bool operator == (const Felino &a)
        {
            if (FechaNacimiento == a.FechaNacimiento && LugarNacimiento == a.LugarNacimiento && Dieta == a.Dieta && Raza == a.Raza && Circo == a.Circo)
            {
                return true;
            }
            return false;
        }

        bool operator != (const Felino &a)
        {
            if (FechaNacimiento != a.FechaNacimiento || LugarNacimiento != a.LugarNacimiento || Dieta != a.Dieta || Raza != a.Raza || Circo != a.Circo)
            {
                return true;
            }
            return false;
        }

        bool operator < (const Felino &a)
        {
            if (FechaNacimiento < a.FechaNacimiento && LugarNacimiento < a.LugarNacimiento && Dieta < a.Dieta && Raza < a.Raza && Circo < a.Circo)
            {
                return true;
            }
            return false;
        }

        bool operator > (const Felino &a)
        {
            if (FechaNacimiento > a.FechaNacimiento && LugarNacimiento > a.LugarNacimiento && Dieta > a.Dieta && Raza > a.Raza && Circo > a.Circo)
            {
                return true;
            }
            return false;
        }
};

class GatoDomestico : public Felino
{
    protected:
        std::string Dueno;

    protected:
    public:
        GatoDomestico(int fn, std::string ln, std::string diet, std::string ra, std::string cir, std::string due): Felino(fn, ln, diet, ra, cir), Dueno(due){}

        void CambiarDueno(std::string Due)
        {
            Dueno = Due;
        }

        friend GatoDomestico operator + (GatoDomestico a, GatoDomestico b)
        {
            a.FechaNacimiento += b.FechaNacimiento;
            a.LugarNacimiento += b.LugarNacimiento;
            a.Dieta += b.Dieta;
            a.Raza += b.Raza;
            a.Circo += b.Circo;
            a.Dueno += b.Dueno;
            return GatoDomestico(a);
        }

        bool operator == (const GatoDomestico &a)
        {
            if (FechaNacimiento == a.FechaNacimiento && LugarNacimiento == a.LugarNacimiento && Dieta == a.Dieta && Raza == a.Raza && Circo == a.Circo && Dueno == a.Dueno)
            {
                return true;
            }
            return false;
        }

        bool operator != (const GatoDomestico &a)
        {
            if (FechaNacimiento != a.FechaNacimiento || LugarNacimiento != a.LugarNacimiento || Dieta != a.Dieta || Raza != a.Raza || Circo != a.Circo || Dueno == a.Dueno)
            {
                return true;
            }
            return false;
        }

        bool operator < (const GatoDomestico &a)
        {
            if (FechaNacimiento < a.FechaNacimiento && LugarNacimiento < a.LugarNacimiento && Dieta < a.Dieta && Raza < a.Raza && Circo < a.Circo && Dueno < a.Dueno)
            {
                return true;
            }
            return false;
        }

        bool operator > (const GatoDomestico &a)
        {
            if (FechaNacimiento > a.FechaNacimiento && LugarNacimiento > a.LugarNacimiento && Dieta > a.Dieta && Raza > a.Raza && Circo > a.Circo && Dueno > a.Dueno)
            {
                return true;
            }
            return false;
        }
};

int main()
{
    GatoDomestico Minino(2020, "Jalisco", "Pescado,res,pollo,etc", "Birbano", "", "Edher Lopez Sanchez");
    Felino EstellaCirco(2021, "España", "Peces,carne de pollo, res, ciertas verduras", "Balines", "Circus Soleil");

    int opc;
    std::string x;

    do
    {
        std::cout<<"Elija una opccion:"<<std::endl<<std::endl;
        std::cout<<" 1.Imprimir dietas"<<std::endl;
        std::cout<<" 2.Imprimir ano y lugar de nacimiento"<<std::endl;
        std::cout<<" 3.Cambiar el nombre del dueno de minino"<<std::endl;
        std::cout<<" 4.Imprimir la raza "<<std::endl;
        std::cout<<" 5.Cambiar el nombre del circo de estrella de circo"<<std::endl;
        std::cout<<" 6.Salir"<<std::endl<<" : ";
        std::cin>>opc;

        switch (opc)
        {
            case 1:
                std::cout<<"Minino: ";
                Minino.ImprimirDieta();
                std::cout<<"EstrellaCirco: ";
                EstellaCirco.ImprimirDieta();
            break;
            case 2:
                std::cout<<"Minino: ";
                Minino.ImprimirNacimiento();
                std::cout<<"EstrellaCirco: ";
                EstellaCirco.ImprimirNacimiento();

            break;
            case 3:
                fflush(stdin);
                std::cin>>x;
                Minino.CambiarDueno(x);
            break;
            case 4:
                std::cout<<"Minino: ";
                Minino.ImprimirRaza();
                std::cout<<"EstrellaCirco: ";
                EstellaCirco.ImprimirRaza();
            break;
            case 5:
                std::cout<<"Ingrese el nuevo circo: ";
                fflush(stdin);
                std::cin>>x;
                EstellaCirco.CambiarCirco(x);
            break;
        }
    } while (opc != 6);


    return 0;
}
