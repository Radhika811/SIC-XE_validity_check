# SIC/XE Validity_Check

This C++ program validates SIC/XE instructions of various formats. It takes hexadecimal instructions as input and checks their validity based on the SIC/XE architecture specifications.

## Features

- Supports validation of SIC/XE instructions of formats 1, 2, 3, and 4.
- Validates the format, opcode, and register numbers.
- Provides detailed error messages for invalid instructions.
- Implemented with clear and concise code structure.

## Usage

1. Compile the source code using a C++ compiler.
2. Run the executable file.
3. Enter the number of test cases.
4. Input hexadecimal instructions one by one.
5. View validation results for each instruction.

## Examples

**Valid SIC/XE Instructions:**
- `07`: Format 1 instruction.
- `14A0`: Format 2 instruction with register numbers.
- `5A0F30`: Format 3 instruction with opcode and address field.
- `2310000A`: Format 4 instruction with opcode and extended address field.

**Invalid SIC/XE Instructions:**
- `B`: Invalid Format 1 instruction.
- `1234`: Invalid Format 2 instruction.
- `5A1F30`: Invalid Format 3 instruction.
- `2000000A`: Invalid Format 4 instruction.
