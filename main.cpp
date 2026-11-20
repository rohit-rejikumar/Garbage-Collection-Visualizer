#include <iostream>
#include <vector>
using namespace std;

struct MemoryObject
{
    char name;
    int referenceCount;
    bool alive;
    vector<int> references;
};

vector<MemoryObject> memory;

// Display all memory objects
void displayMemory()
{
    cout << "\n===== MEMORY STATUS =====\n";

    for (int i = 0; i < memory.size(); i++)
    {
        cout << "Object " << memory[i].name;

        if (memory[i].alive)
        {
            cout << " | Reference Count: "
                 << memory[i].referenceCount;
        }
        else
        {
            cout << " | COLLECTED";
        }

        cout << endl;
    }
}

// Add reference
void addReference()
{
    char from, to;

    cout << "Enter source object (A-F): ";
    cin >> from;

    cout << "Enter destination object (A-F): ";
    cin >> to;

    int source = from - 'A';
    int destination = to - 'A';

    if (source < 0 || source >= memory.size() ||
        destination < 0 || destination >= memory.size())
    {
        cout << "Invalid object!\n";
        return;
    }

    if (!memory[source].alive || !memory[destination].alive)
    {
        cout << "Object is already collected!\n";
        return;
    }

    memory[source].references.push_back(destination);

    memory[destination].referenceCount++;

    cout << "Reference added successfully!\n";
}

// Remove reference
void removeReference()
{
    char from, to;

    cout << "Enter source object (A-F): ";
    cin >> from;

    cout << "Enter destination object (A-F): ";
    cin >> to;

    int source = from - 'A';
    int destination = to - 'A';

    if (source < 0 || source >= memory.size() ||
        destination < 0 || destination >= memory.size())
    {
        cout << "Invalid object!\n";
        return;
    }

    if (!memory[source].alive || !memory[destination].alive)
    {
        cout << "Object is already collected!\n";
        return;
    }

    for (int i = 0; i < memory[source].references.size(); i++)
    {
        if (memory[source].references[i] == destination)
        {
            memory[source].references.erase(
                memory[source].references.begin() + i);

            memory[destination].referenceCount--;

            cout << "Reference removed successfully!\n";
            return;
        }
    }

    cout << "Reference does not exist!\n";
}

// Garbage Collection
void garbageCollection()
{
    cout << "\n===== GARBAGE COLLECTION =====\n";

    int collected = 0;

    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i].alive && memory[i].referenceCount == 0)
        {
            cout << "Collecting Object "
                 << memory[i].name << endl;

            memory[i].alive = false;

            // Remove references held by this object
            for (int j = 0; j < memory[i].references.size(); j++)
            {
                int target = memory[i].references[j];

                if (memory[target].alive)
                {
                    memory[target].referenceCount--;
                }
            }

            memory[i].references.clear();

            collected++;
        }
    }

    cout << "\nTotal objects collected: "
         << collected << endl;

    displayMemory();
}

int main()
{
    // Create six objects
    for (int i = 0; i < 6; i++)
    {
        MemoryObject obj;

        obj.name = 'A' + i;
        obj.referenceCount = 0;
        obj.alive = true;

        memory.push_back(obj);
    }

    // Root reference for object A
    memory[0].referenceCount = 1;

    // Initial references
    memory[0].references.push_back(1);
    memory[1].referenceCount++;

    memory[1].references.push_back(2);
    memory[2].referenceCount++;

    int choice;

    while (true)
    {
        cout << "\n================================\n";
        cout << " GARBAGE COLLECTION VISUALIZER\n";
        cout << "================================\n";

        cout << "1. Display Memory\n";
        cout << "2. Add Reference\n";
        cout << "3. Remove Reference\n";
        cout << "4. Run Garbage Collection\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            displayMemory();
        }
        else if (choice == 2)
        {
            addReference();
        }
        else if (choice == 3)
        {
            removeReference();
        }
        else if (choice == 4)
        {
            garbageCollection();
        }
        else if (choice == 5)
        {
            cout << "Thank you!\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}