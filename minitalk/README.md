# minitalk

*This project has been created as part of the 42 curriculum by olshklya.*

## Description

**minitalk** is a client-server communication program that uses UNIX signals to transmit messages. The project demonstrates inter-process communication (IPC) using only two signals: `SIGUSR1` and `SIGUSR2`.

The server receives and displays strings sent by the client, which encodes characters as binary sequences and transmits them bit by bit using signals. This project teaches signal handling, binary operations, and process communication in UNIX systems.

### Key Features

- Server displays its PID upon launch
- Client sends strings to the server using the server's PID
- Communication using only `SIGUSR1` and `SIGUSR2` signals
- **Bonus**: Unicode character support for extended character sets
- **Bonus**: Server acknowledgment system for reliable communication

## Instructions

### Compilation
```bash
make
```

This compiles both `server` and `client` executables.

### Usage

**1. Start the server:**
```bash
./server
```

The server will display its PID (Process ID).

**2. Send a message from the client:**
```bash
./client [server_PID] "Your message here"
```

Example:
```bash
./client 12345 "Hello, World!"
```

### How It Works

1. The client converts each character into its binary representation (8 bits)
2. Each bit is sent as a signal: `SIGUSR1` for 0, `SIGUSR2` for 1
3. The server receives signals and reconstructs the bits into characters
4. The reconstructed message is displayed by the server

### Bonus Features

- **Unicode Support**: The implementation handles extended ASCII and Unicode characters
- **Acknowledgment System**: Server confirms receipt of each character back to the client

## Resources

### Documentation
- [Signal Handling in Linux](https://man7.org/linux/man-pages/man7/signal.7.html) - Linux man page for signals
- [SIGUSR1 and SIGUSR2](https://www.gnu.org/software/libc/manual/html_node/Miscellaneous-Signals.html) - User-defined signals documentation
- [Bitwise Operations in C](https://en.wikipedia.org/wiki/Bitwise_operation) - Understanding bit manipulation

### Tutorials
- [Inter-Process Communication](https://www.geeksforgeeks.org/inter-process-communication-ipc/) - IPC concepts and methods
- [Signal Handling Tutorial](https://www.tutorialspoint.com/unix/unix-signals-traps.htm) - UNIX signals tutorial

### AI Usage

This project was completed entirely without AI assistance. All implementation, debugging, and documentation were done independently.
