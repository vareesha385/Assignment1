#include <iostream>
#include <string>

using namespace std;

// Define the structure for a task node
struct NODE {
    int taskID;
    string description;
    int priority;
    NODE* next;
};

// Function to create a new task node
NODE* createTaskNode(int id, string desc, int priority) {
    NODE* newTaskNode = new NODE();
    newTaskNode->taskID = id;
    newTaskNode->description = desc;
    newTaskNode->priority = priority;
    newTaskNode->next = NULL;
    return newTaskNode;
}

// Function to add a task to the list based on priority
void addTaskNode(NODE*& head, int id, string desc, int priority) {
    NODE* newTaskNode = createTaskNode(id, desc, priority);
    if (!head || head->priority < priority) {
        newTaskNode->next = head;
        head = newTaskNode;
    } else {
        NODE* current = head;
        while (current->next && current->next->priority >= priority) {
            current = current->next;
        }
        newTaskNode->next = current->next;
        current->next = newTaskNode;
    }
}

// Function to remove the task with the highest priority
void removeHighestPriorityTaskNode(NODE*& head) {
    if (head) {
        NODE* temp = head;
        head = head->next;
        delete temp;
        cout << "Highest priority task removed." << endl;
    } else {
        cout << "No tasks to remove." << endl;
    }}
// Function to remove a specific task by ID
void removeTaskNodeByID(NODE*& head, int id) {
    if (!head) {
        cout << "No tasks to remove." << endl;
        return;}
    if (head->taskID == id) {
        NODE* temp = head;
        head = head->next;
        delete temp;
        return; }
    NODE* current = head;
    while (current->next && current->next->taskID != id) {
        current = current->next;}
    if (current->next) {
        NODE* temp = current->next;
        current->next = current->next->next;
        delete temp;
    } else {
        cout << "Task ID not found." << endl;}}

// Function to view all tasks
void viewTaskNodes(NODE* head) {
    if (!head) {
        cout << "No tasks available." << endl;
        return;
    }
    NODE* current = head;
    while (current) {
        cout << "Task ID: " << current->taskID << ", Description: " << current->description << ", Priority: " << current->priority << endl;
        current = current->next;
    }
}

// Function to display the menu
void displayMenu() {
    cout << "1. Add a new task" << endl;
    cout << "2. View all tasks" << endl;
    cout << "3. Remove the highest priority task" << endl;
    cout << "4. Remove a task by ID" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    NODE* head = NULL;
    int choice, id, priority;
    string description;
 while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
    switch (choice) {
            case 1:
                cout << "Enter task ID: ";
                cin >> id;
                cin.ignore(); // Ignore newline character
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter task priority: ";
                cin >> priority;
                addTaskNode(head, id, description, priority);
                break;
            case 2:
                viewTaskNodes(head);
                break;
            case 3:
                removeHighestPriorityTaskNode(head);
                break;
            case 4:
                cout << "Enter task ID to remove: ";
                cin >> id;
                removeTaskNodeByID(head, id);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        } }
    return 0;}
