#include "class.h"

int main(void)
{
    Person persona1("Ivanov", "Ivan", "Ivanovich");
    Person person2("Ivanov", "Andrey", "Ivanovich");

    persona1.Show();
    persona1.Show_formal();

    person2.Show();
    person2.Show_formal();


    return 0;
}
