#include <iostream>

#include "sir.hpp"

int main() {
  bool valid_input{false};

  Param param{};

  /*se il primo if non funziona il programma riparte, continue indica che va
  avanti e riparte il while *il try catch serve a gestire principalmente
  l'inserimento di caratteri che non sono numeri se sei inseriscono numeri non
  consentiti il messaggio di errore parte ad opera dell'else, altrimenti se si
  inserisce un carattere il messaggio di errore parte ad opera del catch, sono
  quindi entrambi necessari*/

  while (!valid_input) {
    std::cout << "beta: ";
    std::string input;
    std::cin >> input;
    if (input.find(',') != std::string::npos) {
      std::cout << "Invalid value for beta. Please use a dot (.) as the "
                   "decimal separator."
                << '\n';
      continue;
    }
    try {
      double check_beta = std::stod(input);
      if (check_beta >= 0 && check_beta <= 1) {
        param.beta = check_beta;
        valid_input = true;
      } else {
        std::cout
            << "Invalid value for beta. Please enter a number between 0 and 1."
            << '\n';
      }
    } catch (const std::invalid_argument& e) {
      std::cout
          << "Invalid value for beta. Please enter a number between 0 and 1."
          << '\n';
    }
  }

  valid_input = false;

  while (!valid_input) {
    std::cout << "gamma: ";
    std::string input;
    std::cin >> input;
    if (input.find(',') != std::string::npos) {
      std::cout << "Invalid value for gamma. Please use a dot (.) as the "
                   "decimal separator."
                << '\n';
      continue;
    }
    try {
      double check_gamma = std::stod(input);
      if (check_gamma >= 0 && check_gamma <= 1) {
        param.gamma = check_gamma;
        valid_input = true;
      } else {
        std::cout
            << "Invalid value for gamma. Please enter a number between 0 and 1."
            << '\n';
      }
    } catch (const std::invalid_argument& e) {
      std::cout
          << "Invalid value for gamma. Please enter a number between 0 and 1."
          << '\n';
    }
  }

  int new_s{};
  int new_i{};
  int new_r{};

  valid_input = false;

  while (!valid_input) {
    std::cout << "s: ";
    std::string input;
    std::cin >> input;
    if (input.find(',') != std::string::npos) {
      std::cout << "Invalid value for beta. Please use a dot (.) as the "
                   "decimal separator."
                << '\n';
      continue;  // Ask for input again
    }
    try {
      // qui avviene il troncamento se uso stoi() o dichiato int
      double check_s = std::stod(input);
      if (check_s == static_cast<int>(check_s) && check_s >= 0) {
        new_s = static_cast<int>(check_s);
        valid_input = true;
      } else {
        std::cout << "Invalid value for s. Please enter a valid integer."
                  << '\n';
      }
    } catch (const std::invalid_argument& e) {
      std::cout << "Invalid value for s. Please enter a valid integer." << '\n';
    }
  }

  valid_input = false;

  while (!valid_input) {
    std::cout << "i: ";
    std::string input;
    std::cin >> input;
    if (input.find(',') != std::string::npos) {
      std::cout << "Invalid value for i. Please use a dot (.) as the "
                   "decimal separator."
                << '\n';
      continue;
    }
    try {
      double check_i = std::stod(input);
      if (check_i == static_cast<int>(check_i) && check_i >= 0) {
        new_i = static_cast<int>(check_i);
        valid_input = true;
      } else {
        std::cout << "Invalid value for i. Please enter a valid integer."
                  << '\n';
      }
    } catch (const std::invalid_argument& e) {
      std::cout << "Invalid value for i. Please enter a valid integer." << '\n';
    }
  }

  valid_input = false;

  while (!valid_input) {
    std::cout << "r: ";
    std::string input;
    std::cin >> input;
    if (input.find(',') != std::string::npos) {
      std::cout << "Invalid value for r. Please use a dot (.) as the "
                   "decimal separator."
                << '\n';
      continue;
    }
    try {
      double check_r = std::stod(input);
      if (check_r == static_cast<int>(check_r) && check_r >= 0) {
        new_r = static_cast<int>(check_r);
        valid_input = true;
      } else {
        std::cout << "Invalid value for r. Please enter a valid integer."
                  << '\n';
      }
    } catch (const std::invalid_argument& e) {
      std::cout << "Invalid value for r. Please enter a valid integer." << '\n';
    }
  }

  State state(new_s, new_i, new_r);
  SIR sir{state, param};

  int days{};

  valid_input = false;

  while (!valid_input) {
    std::cout << "epidemic duration : ";
    std::string input;
    std::cin >> input;
    if (input.find(',') != std::string::npos) {
      std::cout
          << "Invalid value for epidemic duration. Please use a dot (.) as the "
             "decimal separator."
          << '\n';
      continue;
    }
    try {
      double check_days = std::stod(input);
      if (check_days == static_cast<int>(check_days) && check_days >= 0) {
        days = static_cast<int>(check_days);
        valid_input = true;
      } else {
        std::cout << "Invalid value for epidemic duration. Please enter a "
                     "valid integer."
                  << '\n';
      }
    } catch (const std::invalid_argument& e) {
      std::cout << "Invalid value for epidemic duration. Please enter a valid "
                   "integer."
                << '\n';
    }
  }

  std::cout << "total: " << sir.get_total() << '\n';
  std::cout << "------" << '\n';

  std::vector<State> epidemic = sir.evolve(days);

  int day{};
  int size = epidemic.size();
  for (auto const& _sir : epidemic) {
    std::cout << "day: " << day << '\n';
    std::cout << "s: " << _sir.s << '\n';
    std::cout << "i: " << _sir.i << '\n';
    std::cout << "r: " << _sir.r << '\n';
    std::cout << "total: " << _sir.s + _sir.i + _sir.r << '\n';
    std::cout << "------" << '\n';

    if (day < size) {
      ++day;
    } else {
      break;
    }
  }
  std::cout << "the epidemic lasts for: " << day - 1 << " days" << '\n';
}
