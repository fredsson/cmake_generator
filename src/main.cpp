#include <iostream>
#include "../include/cmakeproject.h"
#include "../include/cmakegenerator.h"

class StdIoHandler : public IoHandler {
public:
  StdIoHandler() {}
  void write(const std::string& text) override {
    std::cout << text << "\n";
  }

  std::string input() {
    std::string input;
    std::getline(std::cin, input);
    return input;
  }
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "no arguments provided\n";
    return 0;
  }

  auto ioHandler = StdIoHandler{};

  const auto command = std::string(argv[1]); 
  if (command == "--watch" || command == "-w") {
    std::cout << "received watch command\n";
  } else if (command == "--gen" || command == "-g") {
    auto generator = CmakeGenerator{ioHandler, {"test", "2.8.9", "c++11", {"test", "cool test2"}}};
    const auto project = generator.run();
    std::cout << "created project with name " << project.name() << "\n";
  } else if (command == "--dep" || command == "-d") {
    std::cout << "received dep command\n";
  } else {
    // print help
  }

  return 0;
}