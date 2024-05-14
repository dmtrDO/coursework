||||| Field of Wonders |||
1. Description
  Field of Wonders is C++ console app that let's you play Fields of Wonders.
2. Compilation instructions
  1. Install Cygwin with g++(for compiling C++)
  2. Download this repository
  3. Place the downloaded sources into Cygwin's working folder
  4. Open Cygwin terminal
  5. Go into project's folder, where src and include folders are located
  6. Run this command: g++ -Wall -Iinclude -o FieldOfWonders $(find src -name "*.cpp")
  7. Now, you have FieldOfWonders.exe. Launch it with ./FieldOfWonders
