#include "class.h"

int main(void)
{
    Person persona1("ivanov", "ivan", "ivanovich");
    Person person2("ivanova", "Alina", "ivanovna");

    persona1.Show();
    persona1.Show_formal();

    person2.Show();
    person2.Show_formal();

    return 0;
}
