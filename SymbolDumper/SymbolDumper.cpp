#include <iostream>
#include <string>
#include <iostream>
#include <filesystem>
#include <direct.h>
using namespace std;
namespace fs = std::filesystem;

int main()
{
    string path;
    string finalPath;
    cout << "Insert .lib directory location: ";
    cin >> path;
    (void)_mkdir("logs");
    for (const auto& entry : fs::directory_iterator(path)) {
        finalPath = entry.path().string().substr(entry.path().string().find_last_of("/\\") + 1);
        std::cout << finalPath << std::endl;
        string commandToRun = "DUMPBIN /SYMBOLS " + entry.path().string() + " > logs/" + finalPath + ".txt";
        cout << commandToRun;
        system(commandToRun.c_str());
    }
}