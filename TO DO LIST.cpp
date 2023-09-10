#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the to-do list
void displayTodoList(const vector<string>& todoList) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". " << todoList[i] << endl;
    }
    cout << endl;
}

int main() {
    vector<string> todoList;
    
    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Remove Task" << endl;
        cout << "4. Quit" << endl;
        
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                cin.ignore();  // Consume the newline character
                getline(cin, task);
                todoList.push_back(task);
                cout << "Task added!" << endl;
                break;
            }
            case 2:
                if (todoList.empty()) {
                    cout << "The to-do list is empty." << endl;
                } else {
                    displayTodoList(todoList);
                }
                break;
            case 3: {
                if (todoList.empty()) {
                    cout << "The to-do list is empty." << endl;
                } else {
                    displayTodoList(todoList);
                    int index;
                    cout << "Enter the index of the task to remove: ";
                    cin >> index;
                    if (index >= 1 && index <= static_cast<int>(todoList.size())) {
                        todoList.erase(todoList.begin() + index - 1);
                        cout << "Task removed!" << endl;
                    } else {
                        cout << "Invalid index. Please try again." << endl;
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting the to-do list program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

