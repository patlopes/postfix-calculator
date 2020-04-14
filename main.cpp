#include <iostream>
#include <locale>

using namespace std;

#define length 15

float run_operation(float num1, float num2, int operation)
{

    switch (operation)
    {
    case 42: //Multiplicação *
        return num1 * num2;
    case 43: //Soma          +
        return num1 + num2;
    case 45: //Subtração     -
        return num1 - num2;
    case 47: //Divisão       /
        return num1 / num2;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "");

    char expression[length];
    int operations[length];
    int index_op = 0;
    float pilha[length];
    int topo = 0;
    float result;

    cout << "\nInsira sua RPN: ";
    scanf("%s", expression);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            pilha[topo] = (float)expression[i] - 48.0;
            topo++;
        }
        else
        {
            operations[index_op] = (int)expression[i];
            index_op++;
        }
    }
    for (int i = 1; i < topo; i++)
    {
        result = run_operation(pilha[topo - i - 1], pilha[topo - i], operations[index_op - i]);
        pilha[topo - i] = 0;
        pilha[topo - i - 1] = result;
    }

    cout << "Resposta: " << result;

    main();
    return 0;
}