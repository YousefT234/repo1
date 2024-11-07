
### 1. Introduction

This report presents the design of a machine emulator software system that simulates the operation of a CPU, memory, registers, and control units. The system is implemented using C++ and is organized into several main components, including the `Machine`, `CPU`, `Memory`, `Register`, `CU` (Control Unit), and `ALU` (Arithmetic Logic Unit) classes.

---

### 2. Class Diagrams

The class diagram below provides a high-level view of the system, showing each class and their relationships. Classes `CPU`, `Memory`, `Register`, `CU`, and `ALU` interact to emulate the functionality of a machine.

**Class Diagram** (This would ideally be created using a UML tool to visually show classes, attributes, and relationships):

- **Machine** - Contains a `CPU` instance and provides methods to load and operate a program.
- **CPU** - Contains instances of `Memory`, `Register`, `CU`, and `ALU`. Manages the execution of instructions.
- **CU (Control Unit)** - Communicates with `Memory`, `Register`, and `ALU` to execute specific control instructions.
- **ALU (Arithmetic Logic Unit)** - Provides methods for arithmetic and logical operations, working with `Register`.
- **Memory** - Stores data in a vector of strings, representing memory cells.
- **Register** - Stores data in a vector of strings, representing registers.

---

### 3. Class Descriptions

#### 3.1 `Machine`
- **Purpose**: Manages the loading and operation of programs in the machine.
- **Attributes**:
  - None directly declared in this class.
- **Methods**:
  - `Machine()`: Constructor to initialize the machine.
  - `void load_program(string filename, string Start)`: Loads a program from a file.
  - `void operate(string filename, string Start)`: Operates the loaded program.
  - `~Machine()`: Destructor.

#### 3.2 `CPU`
- **Purpose**: Acts as the central processing unit, managing the control flow and executing instructions.
- **Attributes**:
  - `Memory Mem`: Instance of the memory class.
  - `Register Reg`: Instance of the register class.
  - `CU cu`: Control unit that manages control instructions.
  - `ALU alu`: Arithmetic and logic unit for arithmetic operations.
  - `int program_counter`: Keeps track of the instruction location in memory.
  - `string instruction_register`: Stores the current instruction.
  - `int screen`: Tracks screen output, initialized to `-1`.
  - `bool running`: Indicates if the machine is running, initialized to `true`.
  - `bool valid`: Indicates the validity of an operation, initialized to `true`.
- **Methods**:
  - `CPU()`: Constructor to initialize the CPU.
  - `void store_instructions(vector<string> instructions, string Start)`: Stores instructions in memory starting at `Start`.
  - `void fetch()`: Fetches the next instruction.
  - `bool decode_execute()`: Decodes and executes the fetched instruction.
  - `bool isvalid(string str)`: Checks the validity of an instruction.
  - `void run_one_cycle()`: Executes one cycle of CPU operation.
  - `void output()`: Outputs the current CPU state.
  - `~CPU()`: Destructor.

#### 3.3 `Memory`
- **Purpose**: Represents the memory unit of the machine.
- **Attributes**:
  - `vector<string> memo_cells`: Stores data in memory cells as a vector of strings.
- **Methods**:
  - `Memory()`: Constructor to initialize memory.
  - `string get_cell(int address)`: Retrieves the value at the specified memory address.
  - `void set_cell(int address, string value)`: Sets the value at a specified memory address.
  - `void print()`: Prints the current state of memory.
  - `~Memory()`: Destructor.

#### 3.4 `Register`
- **Purpose**: Represents the registers in the CPU for storing temporary data.
- **Attributes**:
  - `vector<string> reg_values`: Stores values for registers as a vector of strings.
- **Methods**:
  - `Register()`: Constructor to initialize registers.
  - `string get_value(int address)`: Retrieves the value at the specified register address.
  - `void set_value(int address, string value)`: Sets the value at a specified register address.
  - `void print()`: Prints the current state of registers.
  - `~Register()`: Destructor.

#### 3.5 `CU` (Control Unit)
- **Purpose**: Manages the control operations of the CPU and interfaces with `Memory`, `Register`, and `ALU`.
- **Attributes**:
  - `ALU alu`: Instance of the ALU used for arithmetic operations.
- **Methods**:
  - `CU()`: Constructor to initialize the control unit.
  - `int string_to_decimal(string s)`: Converts a string to decimal.
  - `void load(int R, int XY, Memory &Mem, Register &Reg)`: Loads data into register `R` from memory address `XY`.
  - `void load(int R, string XY, Register &Reg)`: Loads data into register `R` from a string address.
  - `void store(int R, int XY, Memory &Mem, Register &Reg, int &screen)`: Stores data from register `R` to memory address `XY`.
  - `void move(int R, int S, Register &Reg)`: Moves data from one register to another.
  - `void jump(int R, int XY, int &program_counter, Register &Reg)`: Jumps to a specific instruction if a condition is met.
  - `void jump_greater(int R, int XY, int &program_counter, Register &Reg)`: Jumps if a register value is greater than a condition.
  - `~CU()`: Destructor.

#### 3.6 `ALU` (Arithmetic Logic Unit)
- **Purpose**: Performs arithmetic and logical operations.
- **Methods**:
  - `int hex_To_Dec(string hexstr)`: Converts a hexadecimal string to decimal.
  - `string dec_to_hex(int decval)`: Converts a decimal value to hexadecimal.
  - `string decToBinary(int n)`: Converts a decimal number to binary.
  - `int binaryToDecimal(string n)`: Converts a binary string to decimal.
  - `float binary_to_float(string s)`: Converts a binary string to float.
  - `string float_to_binary(float x)`: Converts a float to binary string.
  - `int twosComplement(int num)`: Computes the two's complement of an integer.
  - `void add2s_complement(int R, int S, int T, Register& reg)`: Adds two registers using two's complement.
  - `void add_floating(int R, int S, int T, Register& reg)`: Adds two floating-point registers.
  - `void And(int R, int S, int T, Register& reg)`: Performs bitwise AND.
  - `void Or(int R, int S, int T, Register& reg)`: Performs bitwise OR.
  - `void Xor(int R, int S, int T, Register& reg)`: Performs bitwise XOR.
  - `void Rotate(int R, string XY, Register &reg)`: Rotates the bits in a register.

---

### 4. Relationship Descriptions

- **Machine - CPU**: `Machine` class contains an instance of `CPU`.
- **CPU - Memory**: `CPU` uses `Memory` for storing and retrieving data.
- **CPU - Register**: `CPU` contains `Register` for temporary data storage.
- **CPU - CU**: `CPU` contains `CU` to execute control functions.
- **CPU - ALU**: `CPU` contains `ALU` for arithmetic and logical functions.
- **CU - Memory/ Register/ ALU**: `CU` accesses `Memory`, `Register`, and `ALU` to perform control operations.
- **ALU - Register**: `ALU` performs operations on values stored in `Register`.
