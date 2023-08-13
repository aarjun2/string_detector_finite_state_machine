#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//states and inputs
enum class State {
    s1,
    one,
    two,
    plus,
    times,
    one_one,
    one_two,
    one_plus,
    one_times,
    two_two,
    two_plus,
    two_times
};

enum class Input {
    one,
    two,
    plus,
    times,
    invalid
};

// outputs
enum class Output {
    junk,
    none,
    one,
    two,
    three,
    four
};

// transition function
State transition(State s, Input i, Output& o) {
    switch (s) {
    case State::s1:
        switch (i) {
        case Input::one:
            o = Output::none;
            return State::one;
        case Input::two:
            o = Output::none;
            return State::two;
        case Input::plus:
            o = Output::none;
            return State::plus;
        case Input::times:
            o = Output::none;
            return State::times;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::one:
        switch (i) {
        case Input::one:
            o = Output::none;
            return State::one_one;
        case Input::two:
            o = Output::none;
            return State::one_two;
        case Input::plus:
            o = Output::none;
            return State::one_plus;
        case Input::times:
            o = Output::none;
            return State::one_times;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::two:
        switch (i) {
        case Input::one:
            o = Output::none;
            return State::one_two;
        case Input::two:
            o = Output::none;
            return State::two_two;
        case Input::plus:
            o = Output::none;
            return State::two_plus;
        case Input::times:
            o = Output::none;
            return State::two_times;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::plus:
        switch (i) {
        case Input::one:
            o = Output::none;
            return State::one_plus;
        case Input::two:
            o = Output::none;
            return State::two_plus;
        case Input::plus:
            o = Output::junk;
            return State::s1;
        case Input::times:
            o = Output::junk;
            return State::s1;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::times:
        switch (i) {
        case Input::one:
            o = Output::none;
            return State::one_times;
        case Input::two:
            o = Output::none;
            return State::two_times;
        case Input::plus:
            o = Output::junk;
            return State::s1;
        case Input::times:
            o = Output::junk;
            return State::s1;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::one_one:
        switch (i) {
        case Input::one:
            o = Output::junk;
            return State::s1;
        case Input::two:
            o = Output::junk;
            return State::s1;
        case Input::plus:
            o = Output::two;
            return State::s1;
        case Input::times:
            o = Output::one;
            return State::s1;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::one_two:
        switch (i) {
        case Input::one:
            o = Output::junk;
            return State::s1;
        case Input::two:
            o = Output::junk;
            return State::s1;
        case Input::plus:
            o = Output::three;
            return State::s1;
        case Input::times:
            o = Output::two;
            return State::s1;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::one_plus:
        switch (i) {
        case Input::one:
            o = Output::two;
            return State::s1;
        case Input::two:
            o = Output::three;
            return State::s1;
        case Input::plus:
            o = Output::junk;
            return State::s1;
        case Input::times:
            o = Output::junk;
            return State::s1;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::one_times:
        switch (i) {
        case Input::one:
            o = Output::one;
            return State::s1;
        case Input::two:
            o = Output::two;
            return State::s1;
        case Input::plus:
            o = Output::junk;
            return State::s1;
        case Input::times:
            o = Output::junk;
            return State::s1;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::two_two:
        switch (i) {
        case Input::one:
            o = Output::junk;
            return State::s1;
        case Input::two:
            o = Output::junk;
            return State::s1;
        case Input::plus:
            o = Output::four;
            return State::s1;
        case Input::times:
            o = Output::four;
            return State::s1;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::two_plus:
        switch (i) {
        case Input::one:
            o = Output::three;
            return State::s1;
        case Input::two:
            o = Output::four;
            return State::s1;
        case Input::plus:
            o = Output::junk;
            return State::s1;
        case Input::times:
            o = Output::junk;
            return State::s1;
        default:
            o = Output::junk;
            return State::s1;
        }
    case State::two_times:
        switch (i) {
        case Input::one:
            o = Output::two;
            return State::s1;
        case Input::two:
            o = Output::four;
            return State::s1;
        case Input::plus:
            o = Output::junk;
            return State::s1;
        case Input::times:
            o = Output::junk;
            return State::s1;
        default:
            o = Output::junk;
            return State::s1;
        }
    }
}

int main() {
    unordered_map<char, Input> input_map{ {'1', Input::one},
        {'2', Input::two}, {'+', Input::plus}, {'*', Input::times} };
    //stores all valid inputs, the way it should be typed and 
    //the way it is stored
    State current_state = State::s1;
    Output output;
    string input_str;

    cout << "Enter input string: ";
    cin >> input_str;
    //cout << input_str;

    for (char c : input_str) {
        auto it = input_map.find(c);
        if (it == input_map.end()) {
            cout << "Invalid input character: " << c << endl;
            return -1;
        }
        Input input = it->second;
        current_state = transition(current_state, input, output);
    }

    switch (output) {
    case Output::none:
        cout << "No output" << endl;
        break;
    case Output::one:
        cout << "Output: 1" << endl;
        break;
    case Output::two:
        cout << "Output: 2" << endl;
        break;
    case Output::three:
        cout << "Output: 3" << endl;
        break;
    case Output::four:
        cout << "Output: 4" << endl;
        break;
    case Output::junk:
        cout << "Junk input" << endl;
        break;
    }

    return 0;
}



