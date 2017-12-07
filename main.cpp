#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << argc << endl;
        cout << "Please give a dump file!" << endl;
        return -1;
    }

    string strFilePath = argv[1];

    ifstream ifs;
    ifs.open(strFilePath, ios::binary|ios::ate);
    if(!ifs.is_open())
    {
        cout << "Open file faild!" << endl;
        return -1;
    }

    ifs.seekg(0, ios_base::end);
    int nFileLength = ifs.tellg();
    if(nFileLength != 1024)
    {
        cout << "File size must be 1024!" << endl;
        return -1;
    }

    char* pBuffers = new char[4096];
    memset(pBuffers, 0, 4096);
    ifs.seekg (0, ios::beg);
    ifs.read(pBuffers, nFileLength);
    ifs.close();

    cout << "Read file success!" << endl;

    strFilePath.replace(strFilePath.find_last_of("."), 1, "_fix.");
    ofstream ofs(strFilePath, ios::binary|ios::ate);
    if(!ofs.is_open())
    {
        cout << "Write file faild!" << endl;
    }
    ofs.write(pBuffers,4096);
    ofs.flush();
    ofs.close();
    cout << "Fix success!" << endl;

    return 0;
}
