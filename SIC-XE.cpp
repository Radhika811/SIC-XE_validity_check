#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>

using namespace std;

string convertHexToBinary(string hexString) {
    int length = hexString.length();

    // Convert hexadecimal string to integer
    unsigned int integerValue;
    stringstream ss;
    ss << hex << hexString;
    ss >> integerValue;

    // Calculate the number of bits needed based on the length of the hexadecimal string
    int numBits = hexString.length() * 4; // Each hexadecimal digit represents 4 bits

    // Convert integer to binary
    bitset<32> binaryValue(integerValue);
    return binaryValue.to_string().substr(32 - numBits);
}

bool isValidRegister(int reg) {
    vector<int> registers(8);
    registers[0] = 0;
    registers[1] = 1;
    registers[2] = 2;
    registers[3] = 3;
    registers[4] = 4;
    registers[5] = 5;
    registers[6] = 6;
    registers[7] = 8;
    registers[8] = 9;
    auto it = find(registers.begin(), registers.end(), reg) - registers.begin();
    if (it != 9){
        // cout<<reg<<endl;
        return true;
    }
    else
        return false;
}

void handleCase1(string hexInstruction) {
    string binaryInstruction = convertHexToBinary(hexInstruction);
    cout << "Valid Instruction" << endl;
    // n==2 1 byte
}

void handleCase2(string hexInstruction) {
    // n==4 && 2 byte && string length 16 char
    int reg1 = hexInstruction[2] - 48;
    int reg2 = hexInstruction[3] - 48;
    cout << "Registers: " << reg1 << " " << reg2 << endl;
    if (isValidRegister(reg1) && isValidRegister(reg2))
        cout << "Valid Instruction" << endl;
    else
        cout << "Invalid Instruction: One or more provided register numbers are invalid" << endl;
}

void handleCase3(string hexInstruction) {
    // n==6 3 byte
    string binaryInstruction = convertHexToBinary(hexInstruction);
    binaryInstruction = binaryInstruction.substr(6);
    int valid = true;
    int n = binaryInstruction[0] - 48;
    int i = binaryInstruction[1] - 48;
    int x = binaryInstruction[2] - 48;
    int b = binaryInstruction[3] - 48;
    int p = binaryInstruction[4] - 48;
    int e = binaryInstruction[5] - 48;
    if ((n || i) == 0) {
        valid = true;
    } else {
        if (e == 1) {
            cout << "Invalid Instruction: The 'e' flag must be set to 0 for 3-byte instructions" << endl;
            valid = false;
        }
        if (((n ^ i) == 1) && (x == 1)) {
            cout << "Invalid Instruction: Index registers cannot be used with immediate or indirect addressing" << endl;
            valid = false;
        }
        if (b == 1 && p == 1) {
            cout << "Invalid Instruction: Both PC and base relative addressing cannot be used simultaneously" << endl;
            valid = false;
        }
    }

    if (valid)
        cout << "Valid Instruction" << endl;
}

void handleCase4(string hexInstruction) {
    // n==8 4 byte
    string binaryInstruction = convertHexToBinary(hexInstruction);
    binaryInstruction = binaryInstruction.substr(6);
    int valid = true;
    int n = binaryInstruction[0] - 48;
    int i = binaryInstruction[1] - 48;
    int x = binaryInstruction[2] - 48;
    int b = binaryInstruction[3] - 48;
    int p = binaryInstruction[4] - 48;
    int e = binaryInstruction[5] - 48;
    if ((n || i) == 0) {
        cout << "Invalid Instruction: It must be a SIC instruction and should be 3 bytes long" << endl;
        valid = false;
    }

    if (e == 0) {
        cout << "Invalid Instruction: The 'e' flag must be set to 1 for 4-byte instructions" << endl;
        valid = false;
    }
    if (b == 1 || p == 1) {
        cout << "Invalid Instruction: Format 4 does not support base relative or PC relative addressing" << endl;
        valid = false;
    }
    if (((n ^ i) == 1) && (x == 1)) {
        cout << "Invalid Instruction: Index registers cannot be used with immediate or indirect addressing" << endl;
        valid = false;
    }

    if (valid)
        cout << "Valid Instruction" << endl;
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        string instruction;
        cin >> instruction;
        int length = instruction.length();

        if (length == 2)
            handleCase1(instruction);
        else if (length == 4)
            handleCase2(instruction);
        else if (length == 6)
            handleCase3(instruction);
        else if (length == 8)
            handleCase4(instruction);
        else
            cout << "Invalid Instruction: Not a recognized instruction format of SIC/SIC-XE";
    }

    return 0;
}
