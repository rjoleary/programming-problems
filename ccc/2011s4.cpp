#include <iostream>
#include <fstream>

// Transfer as much blood as possible and return the number of units transferred.
int TransferMaxBlood(int &units, int &patients);

int main()
{
    std::ifstream in("s4.in");
    if (!in)
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    // Read in all the available units of blood and patient blood types.
    int uOn, uOp, uAn, uAp, uBn, uBp, uABn, uABp;
    in >> uOn >> uOp >> uAn >> uAp >> uBn >> uBp >> uABn >> uABp;
    int pOn, pOp, pAn, pAp, pBn, pBp, pABn, pABp;
    in >> pOn >> pOp >> pAn >> pAp >> pBn >> pBp >> pABn >> pABp;

    int transfers = 0;

    // O negative patients are most restricted, give all possible blood to them
    transfers += TransferMaxBlood(uOn, pOn);

    // O positive patients are second so give them the left over O negative
    //  blood and as much O positive blood as possible
    transfers += TransferMaxBlood(uOp, pOp);
    transfers += TransferMaxBlood(uOn, pOp);

    // Type a and b patients must receive their own blood type first.
    transfers += TransferMaxBlood(uAn, pAn);
    transfers += TransferMaxBlood(uAp, pAp);
    transfers += TransferMaxBlood(uAn, pAp);

    transfers += TransferMaxBlood(uBn, pBn);
    transfers += TransferMaxBlood(uBp, pBp);
    transfers += TransferMaxBlood(uBn, pBp);

    // Type a and b can now receive O type blood.
    transfers += TransferMaxBlood(uOn, pAn);
    transfers += TransferMaxBlood(uOn, pBn);

    transfers += TransferMaxBlood(uOp, pAp);
    transfers += TransferMaxBlood(uOp, pBp);
    transfers += TransferMaxBlood(uOn, pAp);
    transfers += TransferMaxBlood(uOn, pBp);

    // All the left over blood goes to AB negative then to AB positive.
    transfers += TransferMaxBlood(uOn, pABn);
    transfers += TransferMaxBlood(uAn, pABn);
    transfers += TransferMaxBlood(uBn, pABn);
    transfers += TransferMaxBlood(uABn, pABn);

    transfers += TransferMaxBlood(uOn, pABp);
    transfers += TransferMaxBlood(uOp, pABp);
    transfers += TransferMaxBlood(uAn, pABp);
    transfers += TransferMaxBlood(uAp, pABp);
    transfers += TransferMaxBlood(uBn, pABp);
    transfers += TransferMaxBlood(uBp, pABp);
    transfers += TransferMaxBlood(uABn, pABp);
    transfers += TransferMaxBlood(uABp, pABp);

    std::cout << transfers << '\n';
}

int TransferMaxBlood(int &units, int &patients)
{
    int transfers = 0;
    if (units > patients)
        transfers = patients;
    else if (units < patients)
        transfers = units;
    else if (units == patients)
        transfers = units;

    units -= transfers;
    patients -= transfers;
    return transfers;
}

