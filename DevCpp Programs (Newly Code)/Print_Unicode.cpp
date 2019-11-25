#include <iostream>
#include <io.h>
#include <fcntl.h>

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"\u0434 \u0435 \u0436 \u0437 \u0438 \u0439 \u0440 \u0441 \u0442 \u0443 \u0444 \u0445 \u0446 \u0447 \u0448 \u0449 \u0450 \u0451 \u0452 \n";
}
