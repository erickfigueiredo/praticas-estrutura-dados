#include "Agenda.h"

int main()
{
    int numCompromissos, numConsultas;
    cin >> numCompromissos >> numConsultas;
    Agenda ag;
    //cerr << numCompromissos << numConsultas << endl;
    //Le os compromissos
    for (int i = 0; i < numCompromissos; i++)
    {
        string compr;
        cin.ignore();
        getline(cin, compr);
        Data d;
        Horario h;
        cin >> d >> h;

        //abaixo declaramos versoes constantes dos objetos data/horario e item agenda
        //com o objetivo de testar se os metodos que nao deveriam modificar tais dados
        //realmente estao funcionando com objetos constantes
        const Data d2 = d;
        const Horario h2 = h;
        const ItemAgenda ia = ItemAgenda(compr, d2, h2);
        //cerr << dia << mes << ano << hora << min << sec << compr << endl;
        ag.inserirItem(ia);
    }

    //Como as consultas nao modificam o objeto da classe agenda, o codigo abaixo
    //deve compilar e executar sem erros
    const Agenda ag2 = ag;

    for (int i = 0; i < numConsultas; i++)
    {
        Data d;
        cin >> d;

        const Data d2 = d;
        cout << d2 << endl;
        ag2.compromissosData(d2);
        cout << endl;
    }

    return 0;
}
